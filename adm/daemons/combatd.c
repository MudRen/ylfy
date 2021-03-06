//战斗系统
//兼容等级制，数据算法部分重新写过攻、防不再溢出。
//加入魔法、正当防卫系统，
//增加四项属性：精准、敏捷、灵性、反应。并使之加入战斗系统
//精准：提高物理攻击力及物理命中率，物理防御力及物理防御率下降
//灵性：提高魔法攻击力及魔法命中率，物理攻击力及物理命中率下降
//敏捷：提高物理防御力及物理防御率，物理攻击力及物理命中率下降
//反应：提高整体防御力及物理反击率，物理攻击力及魔法攻击力下降

// 战斗描述显示等级（"env/no_combat_msg"）：
// = 1：去掉招式信息
// = 2：再去掉闪避和招架信息
// = 3：再去掉每次造成伤害程度的描述
// = 4：去掉所有的特殊效果描述(只显示对方的受伤状态，当然伤害为0也显示)
// = 5：只在造成伤害的情况下显示对手受伤状况，如无伤害则什么都不显示，比如说你刷经验的时候伤害为0就什么都不显示了

// 定义这个则进行战斗算法缓冲 (注意:定义的值为 int)
#define MAX_PLAYER_ATTACK 5

// 缓冲秒数 (取的是这个的随机值)
#define MAX_CALL_SEC 3

// 缓冲中允许带动的攻击几率(百分比)
#define IS_ATTACK_RANDOM 30

// 定义每 ID 一天允许的杀人次数
#define MAX_KILL_PLAYER 100

// 定义每次杀人增加的 killer 值
#define MAX_CONDITION_KILLER 5000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

mapping limb_damage = ([
                           //人类身体部位
                           "头部"  :   100,
                           "颈部"  :   90,
                           "胸口"  :   90,
                           "后心"  :   80,
                           "左肩"  :   50,
                           "右肩"  :   55,
                           "左臂"  :   40,
                           "右臂"  :   45,
                           "左手"  :   20,
                           "右手"  :   30,
                           "腰间"  :   60,
                           "小腹"  :   70,
                           "左腿"  :   40,
                           "右腿"  :   50,
                           "左脚"  :   35,
                           "右脚"  :   40,
                           //动物身体部位
                           "身体"  :   80,
                           "前脚"  :   40,
                           "后脚"  :   50,
                           "腿部"  :   40,
                           "尾巴"  :   10,
                           "翅膀"  :   50,
                           "爪子"  :   40
                       ]);

string *guard_msg = (
{
	CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
	CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
	CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
	CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
	CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR
});

string *catch_hunt_msg = (
{
	HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
	HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
	HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
	HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
	HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
	HIW "$N喝道：「$n，看招！」\n" NOR
});

string *winner_msg = (
{
	CYN "\n$N哈哈大笑，愉快地说道：承让了！\n\n" NOR,
	CYN "\n$N双手一拱，笑著说道：知道我的利害了吧！\n\n" NOR,
	CYN "\n$N哈哈大笑，双手一拱，笑著说道：承让！\n\n" NOR,
	CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
	CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
	CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
	CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR
});

#ifdef MAX_PLAYER_ATTACK
int player_attack = 0, attack_stop = 0;
object *series_attack = ( { });
#endif

void auto_skill_perform(object me, object obj);

void create()
{
	seteuid(getuid());
	set("name", "战斗精灵");
	set("channel_id",HIM"战斗精灵"HIR);
	set("id", "combatd");

}

//根据每次伤害值与当前气的百分比给出相应伤害描述
string damage_msg(int damage, string type,object ob)
{
	string str;
	int qi;

	qi = ob->query("qi");

	if( damage == 0 )
		return "结果没有造成任何伤害。\n";

	if ( qi > 0 )
	{
		damage = damage * 100;
		damage /= qi;
	}
	else
		damage = 120;

	switch( type )
	{
	case "擦伤":
	case "割伤":
		if( damage < 5 ) return "结果只是轻轻地划破$p的皮肉。\n";
		else if( damage < 10 ) return "结果在$p$l划出一道细长的血痕。\n";
		else if( damage < 20 ) return "结果「嗤」地一声划出一道伤口！\n";
		else if( damage < 40 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
		else if( damage < 80 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
		break;
	case "刺伤":
		if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
		else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
		else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
		else if( damage < 60 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
		else if( damage < 80 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
		break;
	case "瘀伤":
		if( damage < 5 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
		else if( damage < 10 ) return "结果在$p的$l造成一处瘀青。\n";
		else if( damage < 25 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
		else if( damage < 40 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
		else if( damage < 50 ) return "结果「砰」地一声，$n退了两步！\n";
		else if( damage < 60 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
		else if( damage < 80 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
		break;
	case "内伤":
		if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
		else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
		else if( damage < 30 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
		else if( damage < 40 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
		else if( damage < 60 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
		else if( damage < 75 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		else if( damage < 90 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
		else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		break;
	default:
		if( !type ) type = "伤害";
		if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
		else if( damage < 20 ) str = "结果造成轻微的";
		else if( damage < 30 ) str = "结果造成一处";
		else if( damage < 50 ) str = "结果造成一处严重";
		else if( damage < 60 ) str = "结果造成颇为严重的";
		else if( damage < 70 ) str = "结果造成相当严重的";
		else if( damage < 80 ) str = "结果造成十分严重的";
		else if( damage < 90 ) str = "结果造成极其严重的";
		else str =  "结果造成非常可怕的严重";
		return str + type + "！\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
	if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return RED "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
	if( ratio > 30 ) return RED "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return RED "受了相当重的伤，只怕会有生命危险。" NOR;
	if( ratio > 10 ) return HIR "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if( ratio > 5  ) return HIR "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
	return HIR "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}
string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return RED "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio > 30 ) return RED "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return RED "看起来已经力不从心了。" NOR;
	if( ratio > 10 ) return HIR "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	return HIR "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

//身体状况描述
varargs void report_status(object ob, int effective)
{
	if( effective )
		message_vision( "( $N" + eff_status_msg((int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) + " )\n", ob);
	else
		message_vision( "( $N" + status_msg((int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) + " )\n", ob);
}

//战斗攻防核心算法
varargs int skill_power(object ob, string skill, int usage)
{
	int status, than_encumb;
	int power, level, my_sx;
	string used_skill;

	if ( !living(ob) ) return 1; //昏迷或睡觉
	// if( ob->over_encumbranced() )    return 1; // 负重小于零时 power 永远等于零
	//if( userp(ob) && ob->is_ghost() ) return 1;  // 鬼魂的 power 永远等于零
	if ( stringp(used_skill=ob->query_skill_mapped(skill)) )
		level = (int)ob->query_skill(used_skill,1);
	else level = 0;

	level += (int)ob->query_skill(skill,1) / 2;

	switch ( usage )
	{
		// 命中
	case SKILL_USAGE_ATTACK:
		level += (int)ob->query_temp("apply/attack");
		level += (int)ob->query_temp("apply/"+skill);
		level += (int)ob->query_str();
		level += (int)ob->query("jiali");
		if ( ob->is_fighting() )
			level += (int)ob->query_temp("fight/attack");
		my_sx = (int)ob->query("xyzx_sys/jingzhun");
		break;
		// 招架
	case SKILL_USAGE_DEFENSE:
		level += (int)ob->query_temp("apply/defense");
		level += (int)ob->query_temp("apply/"+skill);
		level += (int)ob->query_con();
		if ( ob->is_fighting() )
			level = level + ob->query_temp("fight/parry");
		my_sx = (int)ob->query("xyzx_sys/fanying");
		break;
		// 闪避
	case SKILL_USAGE_DODGE:
		level += (int)ob->query_temp("apply/defense");
		level += (int)ob->query_temp("apply/"+skill);
		level += (int)ob->query_dex();
		if ( ob->is_fighting() )
			level = level + ob->query_temp("fight/dodge");
		my_sx = (int)ob->query("xyzx_sys/minjie");
		break;
	}

	my_sx += (int)ob->query("xyzx_sys/lingxing")/3;
	//my_sx += (int)ob->query("xyzx_sys/level");
	level /= 10;

	level = level * level;
	my_sx = my_sx * my_sx;
	power = my_sx + level;

	if ( ob->query("is_boss") || ob->query("end_boss") ) return power;

	than_encumb = (100 - ob->than_encumbranced());
	status = ob->query("eff_qi") / ob->query("max_qi") * 100;
	status = ob->query("eff_jing") / ob->query("max_jing") * 100 + status;
	status = status + than_encumb;

	return power;

}

varargs int do_attack(object me, object victim, object weapon, int attack_type, string msg)
{
	object your_weapon;
	mapping my, your, action, prepare;
	string limb, *limbs, result, dodge_msg, parry_msg;
	string attack_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo, combat_msg;
	int ap, dp, pp, cost;
	int damage, damage_bonus, desc,cost_a, armor;
	int my_mj, my_fy, your_fy, your_mj;
	int wounded = 0, my_level = 0, your_level = 0, dam = 0,att_back = 0;

	//combat_msg_lvl

	if ( !objectp(me) || !objectp(victim) ) return 1;//不是物件
	if ( !living(me) ) return 1; //不是互动物体
	if(me->query_temp("netdead") && !victim->is_player()) return 1; //对手是NPC,玩家已经掉线
	if ( environment(me) != environment(victim) ) return 1;//不在一个房间里
	if( (userp(me) && me->is_ghost()) || (userp(victim) && victim->is_ghost()) ) return 1; //自己死了，或者对方已经死了
	if ( !me->visible(victim) ) return 0;
	if ( me->query_temp("block_msg/all") && !me->query("end_boss") ) return 1;

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
	prepare = me->query_skill_prepare();

	/******************等级制相关 By Wenwu***********************************************/
	my_level = me->query("xyzx_sys/level");
	your_level = victim->query("xyzx_sys/level");
	desc = your_level/(my_level>0?my_level:1);
	if ( desc < 1 ) desc = 1;
	//--------------------各属性------------------------------------
	my_mj = me->query("xyzx_sys/minjie");
	my_fy = me->query("xyzx_sys/fanying");
	your_mj = victim->query("xyzx_sys/minjie");
	your_fy = victim->query("xyzx_sys/fanying");
	/**************************************************************************/
	// 战斗描述显示等级相关
	// --------------------------------------------------------
	combat_msg = me->query("env/no_combat_msg");
	if ( !intp(combat_msg) ) combat_msg = 1;
	// --------------------------------------------------------
	me->delete_temp("fight");
	victim->delete_temp("fight");

	if (!prepare) prepare = ([]);
	if( objectp(weapon) ) attack_skill = weapon->query("skill_type");
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];

	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
        me->reset_action();
        action = me->query("action");
        if( !mapp(action) ) {
            CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): bad action = %O", me->name(1), me->query("id"), me->query("actions", 1)));
            return 0;
        }
    }
	// 特殊技能外功自动使用
	// auto_skill_perform(me, victim);
	//对不希望显示战斗过程的玩家屏蔽掉部分战斗描述，另方面也可以减轻系统负担
	if ( msg ) result = msg + "\n";
	else result = "";

	if ( combat_msg )
		result += "";
	else
	{
		if (stringp(me->query_temp("action_msg")))
		{
			result += (string)me->query_temp("action_msg")+ action["action"] + "！\n";
			me->delete_temp("action_msg");
		}
		else if (me->query_temp("action_flag") == 0) result += "" + action["action"] + "！\n";
		else
			result += "紧跟着"+action["action"] + "!\n";
	}

	limbs = victim->query("limbs");

	if ( !pointerp(limbs) || !sizeof(limbs) )
	{
		CHANNEL_D->do_channel( this_object(), "sys",sprintf("%s(%s): no such limbs",me->name(1), me->query("id")));
		return 0;
	}

	limb = limbs[random(sizeof(limbs))];

	// 特殊攻防参数。
	// 闪避
	dodge_skill = victim->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(victim,limb);
	if (!dodge_msg || dodge_msg=="") dodge_msg = SKILL_D("dodge")->query_dodge_msg(victim,limb);
	//招架
	parry_skill = victim->query_skill_mapped("parry");
	if( !parry_skill ) parry_skill = "parry";
	parry_msg = SKILL_D(parry_skill)->query_parry_msg(victim,weapon);
	if (!parry_msg || parry_msg=="") parry_msg = SKILL_D("parry")->query_parry_msg(victim,weapon);
	//--------------------------------------------------------
	//以下增加攻击招式的特殊攻防
	if (intp(action["dodge"])) victim->add_temp("fight/dodge", action["dodge"]);
	if (intp(action["attack"])) me->set_temp("fight/attack", action["attack"]);
	if (intp(action["parry"])) victim->add_temp("fight/parry", action["parry"]);
	//---------------------------------------------------------

	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	if ( sizeof(me->query_enemy()) > 1 ) me->delete_temp("fighting");

	dp = skill_power(victim, "dodge", SKILL_USAGE_DODGE);
	if ( victim->is_busy()/* && (!playerp(me) || !playerp(victim))*/ )
	{
		if ( victim->query("no_zhineng") ) dp = dp / 3;
		else dp = dp / 2;
	}

	// 被围攻闪避下降
	if ( (cost_a = sizeof(victim->query_enemy())) > 1 /*&& (!playerp(me) || !playerp(victim))*/ )
	{
		victim->delete_temp("fighting");
		dp = dp / cost_a;
	}
	// 如对方特殊属性(隐身等)比对手低,闪避能力下降
	if ( !victim->visible(me) /*&& (!playerp(me) || !playerp(victim))*/ )
		dp = dp / 2;
	cost = skill_power(me, "dodge", SKILL_USAGE_DODGE)/10;
	// 如对方特殊属性(隐身等)比对手低,闪避能力下降
	if ( !me->visible(victim) )
	{
		ap = ap / 2;
		cost = cost / 2;
	}

	//闪避
	if ( living(victim) && random(ap + cost)<random(dp) )
	{
		// 闪避开理论上反击比较容易，予 30% 反击率
		if ( random(100) < 30 ) att_back = 1;
		// 战斗描述显示等级 < 2 才显示
		if ( combat_msg < 2 ) result += dodge_msg;
		//闪避开厉害的对手增加经验和轻功熟练度
		if( ap + cost > dp ) victim->improve_skill("dodge", random(victim->query_int())/20);

		damage = RESULT_DODGE;
	}
	else //没有闪避开时
	{
		if ( intp(action["parry"]) ) victim->add_temp("fight/parry", action["parry"]);
		pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
		if( victim->is_busy() /*&& (!playerp(me) || !playerp(victim)) */)
		{
			if ( victim->query("no_zhineng") ) pp = pp / 3;
			else pp = pp / 2;
		}

		if( victim->query_temp("weapon") )
		{
			if( !weapon )
			{
				pp = pp * 2; // 支持大数运算，不再需要上面的防溢出处理
			}
		}
		else if( weapon ) pp = pp / 2;

		if ( (cost_a=sizeof(victim->query_enemy())) > 1 /*&& (!playerp(me) || !playerp(victim)) */)
			pp = pp / cost_a;

		if ( !victim->visible(me)/* && (!playerp(me) || !playerp(victim)) */)
			pp = pp / 2;
		// 招架
		if( living(victim) && random(ap + cost) < random(pp) )
		{
			// 双手都拿有武器招架住，应该反击几率还是比较大的，予 50% 反击几率
			// 拿的是双手武器招架，反击我想应该比较困难，予反击几率 20%
			// 如一手武器一手拳脚，或双手空拳，是否能反击比较灵活，予反击几率 30%
			if ( victim->query_temp("secondary_weapon") )
			{
				if ( your_weapon = victim->query_temp("secondary_weapon") )
				{
					if ( your_weapon->query("flag") & 2 ) // 双手各拿有武器
					{
						if ( random(100) < 50 ) att_back = 1;
					}
					else // 拿的双手武器
					{
						if ( random(100) < 20 ) att_back = 1;
					}
				}
			}
			else // 一手武器或双手空拳
			{
				if ( random(100) < 30 ) att_back = 1;
			}

			if ( combat_msg < 2 ) result += parry_msg;
			// 招架厉害的对手获得经验及招架熟练度
			if( ap + cost > pp ) victim->improve_skill("parry", random(victim->query_int())/20);

			damage = RESULT_PARRY;
		}
		else //被攻击到
		{
			damage = (int)me->query_temp("apply/damage");
			damage = (damage + random(damage)) / 2;
			if( dam = action["damage"] )
			{
				if ( dam < 1 ) dam = 1;
				damage += dam * damage / 100;
			}
			damage_bonus = me->query_skill(attack_skill) + me->query_skill("force")/2; //2016.5.20修改
			if( weapon ) damage_bonus = (int)damage_bonus / 5;  //削弱武器的化学伤害加成
			// Let force skill take effect.
			if ( (dam = my["jiali"]) > 0 && (my["neili"] >= dam) )
			{

				if( stringp(martial_skill = me->query_skill_mapped("force")) )
				{
					foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus, dam);
					if( stringp(foo) )
					{
						if ( combat_msg < 4 ) result += foo;
					}
					else if( intp(foo) ) damage_bonus += random(foo);
				}
			}

			if( dam = action["force"] )
			{
				if ( dam < 1 ) dam = 1;
				damage_bonus += dam * damage_bonus/100;
			}
			if( stringp(martial_skill = me->query_skill_mapped(attack_skill)) && martial_skill != me->query_skill_mapped("force"))
			{
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) )
				{
					if ( combat_msg < 4 ) result += foo;
				}
				else if(intp(foo) && foo > 0 ) damage_bonus += random(foo);
			}
			// Let weapon or monster have their special damage.
			if( weapon )
			{
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) )
				{
					if ( combat_msg < 4 ) result += foo;
				}
				else if(intp(foo) && foo > 0 ) damage_bonus += random(foo);
			}
			else
			{
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) )
				{
					if ( combat_msg < 4 ) result += foo;
				}
				else if(intp(foo) && foo > 0 ) damage_bonus += random(foo);
			}
			if(living(victim) )  //2015.12.30添加，昏迷状态下 不再触发ob_hit
			{

				if( martial_skill = victim->query_skill_mapped("dodge") )
				{
					foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
					if( stringp(foo) )
					{
						if ( combat_msg < 4 ) result += foo;
					}
					else if(intp(foo) && foo > 0 ) damage_bonus += random(foo);
				}

				if( martial_skill = victim->query_skill_mapped("parry") )
				{
					foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
					if( stringp(foo) )
					{
						if ( combat_msg < 4 ) result += foo;
					}
					else if(intp(foo) && foo > 0 ) damage_bonus += random(foo);
				}

				if( martial_skill = victim->query_skill_mapped("force") )
				{
					foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
					if( stringp(foo) )
					{
						if ( combat_msg < 4 ) result += foo;
					}
					else if(intp(foo) && foo > 0 ) damage_bonus += random(foo);
				}
			}
			if( damage_bonus > 0 )
				damage += (damage_bonus + random(damage_bonus))/2;
			if ( userp(me) ) damage /= desc; // 经验对伤害的影响 playerp
			damage -= damage*(to_int(sqrt(to_float(victim->query_temp("apply/armor")/1000))))/100; //2016.8.13添加伤害减免
			//  (6) Inflict the damage.
			if (!undefinedp(limb_damage[limb]))
				damage = (damage*limb_damage[limb]/100);
			if( stringp(martial_skill = victim->query_skill_mapped("force")) && (int)victim->query_temp("apply/armor_vs_force") )
			{
				foo = SKILL_D(martial_skill)->armor_ob(me, victim, damage,(int)victim->query_temp("apply/armor_vs_force"), combat_msg);
				if( stringp(foo) )
				{
					if ( combat_msg < 4 )
						result += foo;
					damage = 0;
					dam = 1;
				}
				else if( intp(foo) ) damage = foo;
			}

			// npc的特殊防御
			foo = victim->weapon_ob(victim,me, damage);
			if( stringp(foo) )
			{
				if ( combat_msg < 4 ) result += foo;
			}
			else if(intp(foo) && foo > 0 ) damage += foo;

			if ( damage < 1 ) // 由于魔法系统尚未完善，暂时注释掉灵性对物理伤害的影响
			{
				if ( userp(me) ) damage = 0;
				else dam?damage=0:damage=random(2);
			}
			damage = victim->receive_damage("qi", damage, me);
			if ( combat_msg < 3 )
				result += damage_msg(damage, action["damage_type"],victim);
			else if ( damage == 0 && combat_msg < 5 )
				result += damage_msg(damage, action["damage_type"],victim);

			if(  damage > 0 && random(damage) > (armor=(int)victim->query_temp("apply/armor")) )
			{
				if ( (!weapon && !random(9)) || (weapon && !random(5)) )
				{
					// We are sure that damage is greater than victim's armor here.
					victim->receive_wound("qi",damage - armor, me);
					wounded = 1;
				}
				if (me->query_temp("sum_power"))
				{
					victim->receive_wound("qi", damage - armor, me);
					wounded = 1;
				}
			}

			if( your_level >= my_level )
			{
				me->add("combat_exp", me->query_int()/10, TEAMD->get_allot_type(me->query_temp("xyzx_team/name"))!="平均分配");
				//my["combat_exp"] += me->query_int()/10;
				me->improve_skill(attack_skill, random(me->query_int()));
				//增加会员的潜能累计上限
				if (me->query("xy_huiyuan"))
				{
					if( my["potential"] < 100 * me->query_int() ) my["potential"] += 10;
				}
				else if( my["potential"] < 10 * me->query_int() ) my["potential"] += 10;
			}
		}
	}
	result = replace_string( result, "$l", limb );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "unarmed" )
		result = replace_string( result, "$w", "无形劲气" );
	else if( attack_skill == "finger" )
		result = replace_string( result, "$w", "指间一股真气" );
	else if( attack_skill == "strike" )
		result = replace_string( result, "$w", "无形掌力" );
	else result = replace_string( result, "$w", "   " );
	/*while ( strsrch(result, "\n\n") != -1 )
	{
		result = replace_string( result, "\n\n", "\n" );
		result = replace_string( result, " ", "" );
	}*/
	message_vision(result, me, victim ,damage,action["damage_type"]);

	if( wizardp(me) && me->query("env/combat") )
	{
		tell_object(me, sprintf( BBLU "进攻(attack])：攻击力[ %d ], 闪避[ %d ], 招架[ %d ], 伤害[ %d ]\n" NOR,
		                         ap+cost, dp, pp, damage));
	}

	if( wizardp(victim) && victim->query("env/combat") )
	{
		tell_object(victim, sprintf( BRED "防守(defend)：攻击力[ %d ], 闪避[ %d ], 招架[ %d ], 伤害[ %d ]\n" NOR,
		                             ap+cost, dp, pp, damage));
	}

	if( damage > 0 )
	{
		report_status(victim, wounded);
		if( victim->is_busy() )
			victim->interrupt_me(me);

		if( (!me->is_killing(victim)) && (!victim->is_killing(me)) && victim->query("qi")*2 <= victim->query("max_qi"))
		{
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			if (me->query("family/family_name")!="少林派" && victim->query_temp("fighting")==me && me->query("family/master_id")==(string)victim->query("id"))
			{
				me->delete("family");
				me->set("title","普通百姓");
				me->delete("class");
				victim->delete_temp("fighting");
				CHANNEL_D->do_channel(victim, "chat",sprintf("真不愧是青出于蓝而胜于蓝！%s，你可以出师了，从此另立门户吧！", me->query("name")));
			}
			else
				message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
		}

		//记录最后造成伤害的对手
		if ( playerp(victim) )
		{
			if ( playerp(me) ) victim->set("xyzx_sys/damage_me", me->query("id"));
			else victim->set("xyzx_sys/damage_me", me->name(1));
		}
	}

	if ( !(me->is_killing(victim))
	        && !(victim->is_killing(me))
	        && victim->query("jing")*2 <= victim->query("max_jing") )
	{
		// 没有仇恨则精神低于 50% 中断战斗
		me->remove_enemy(victim);
		victim->remove_enemy(me);
		message_vision( winner_msg[random(sizeof(winner_msg))], me, victim,0,"");
	}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);
	else
		WEAPON_D->bash_weapon(me, victim, weapon, damage);

	// See if the victim can make a riposte.
	if( attack_type == TYPE_REGULAR
	        && att_back == 1
	        && victim->query_temp("guarding")
	        && random(my_level+me->query_dex(1)) < random(your_level + victim->query_dex(1)) )
	{
		victim->set_temp("guarding", 0);

		switch ( random(3) )
		{
		case 0:
			if ( combat_msg < 4 )
				message_vision(HIY"$N眼见招已临身，危急中不假思索侧身一偏顺手反击一式！\n"NOR, victim,me,0,"");
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
			break;
		case 1:
			if ( combat_msg < 4 )
				message_vision(HIY"$N一击不中，露出了破绽！\n"NOR, me,victim,0,"");
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
			break;
		default:
			if ( combat_msg < 4 )
				message_vision(HIY"$N见$n攻击失误，趁机发动攻击！\n"NOR, victim, me,0,"");
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}

	// 本次攻击结束，反击参数重新初始化
	att_back = 0;
	return 1;
}

void fight(object me, object victim)
{
	object ob, now_attack_ob, *del_wait;
	string skill_name;

	int max_wait, i;

	if ( !living(me) || me->is_busy() ) return;
	if ( environment(me) != environment(victim) ) return;
	if (me->query_temp("no_fight")) return;
	// 特殊技能外功自动使用
	if ( !playerp(me) && playerp(victim) ) auto_skill_perform(me, victim);
	if ( me->is_busy() ) return;
	if ( !me->visible(victim) ) return;
	if ( me->query_temp("block_msg/all") && !me->query("end_boss") ) return;


#ifdef MAX_PLAYER_ATTACK
	if ( !arrayp(series_attack) ) series_attack = ( { });
	del_wait = ( { });
#endif

	// If victim is busy or unconcious, always take the chance to make an attack.
	if ( victim->is_busy() || !living(victim) )
	{
		me->set_temp("guarding", 0);

		if ( !victim->is_fighting(me) ) victim->fight_ob(me);

		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if ( (random(me->query_int())>50 || random(10)<3) && victim->is_fighting(me) )
		{
			me->set_temp("secondly_weapon",1);
			do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
			me->delete_temp("secondly_weapon");
		}
		else if( me->is_fighting(victim) && victim->is_fighting(me))
		{
			if( (!objectp(me->query_temp("weapon"))
			        && sizeof(me->query_skill_prepare()) > 1)
			        || ( objectp(me->query_temp("weapon"))
			             && (me->query_temp("weapon"))->query("skill_type") == "sword"
			             && me->query_skill("pixie-jian", 1) >= 60
			             && me->query_skill_mapped("sword") == "pixie-jian") )
			{
				me->set_temp("action_flag",1);
				do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
				me->set_temp("action_flag",0);
			}
		}

		if ( living(victim) )
		{
			if( !objectp(ob=me->query_temp("weapon")))
				skill_name="unarmed";
			else skill_name=ob->query("skill_type");

			skill_name=me->query_skill_mapped(skill_name);

			if ( stringp(skill_name) )
			{
#ifdef MAX_PLAYER_ATTACK
				if ( playerp(me) && SKILL_D(skill_name)->is_interlink() )
				{
					if ( attack_stop )
					{
						if ( member_array(me, series_attack) == -1 )
							series_attack += ( { me });
						if( !me->query_temp("guarding") )
							me->set_temp("guarding", 1);
						return;
					}
					if ( player_attack > MAX_PLAYER_ATTACK )
					{
						attack_stop = 1;
						remove_call_out("reset_player_attack");
						call_out("reset_player_attack", random(MAX_CALL_SEC));
						return;
					}
					if ( !(max_wait=sizeof(series_attack)) )
						now_attack_ob = me;
					else
					{
						for ( i=0; i<max_wait; i++ )
						{
							del_wait += ( { series_attack[i] });
							if ( objectp(series_attack[i]) )
							{
								now_attack_ob = series_attack[i];
								break;
							}
						}
						series_attack -= del_wait;
					}
					player_attack++;
				}

				if ( !objectp(now_attack_ob) ) now_attack_ob = me;
				if ( now_attack_ob != me && random(100) < IS_ATTACK_RANDOM )
				{
#endif
					me->set_temp("action_flag",1);
					SKILL_D(skill_name)->do_interlink(me, victim);
					me->set_temp("action_flag",0);
					if ( playerp(me) && player_attack>0 ) player_attack--;
#ifdef MAX_PLAYER_ATTACK
				}

				if( !objectp(ob=now_attack_ob->query_temp("weapon")))
					skill_name="unarmed";
				else skill_name=ob->query("skill_type");

				skill_name=now_attack_ob->query_skill_mapped(skill_name);

				if ( stringp(skill_name) )
				{
					now_attack_ob->set_temp("action_flag",1);
					SKILL_D(skill_name)->do_interlink(now_attack_ob, victim);
					now_attack_ob->set_temp("action_flag",0);
				}
#endif
			}
		}

		// Else, see if we are brave enough to make an aggressive action.
	}
	else if( random( (int)victim->query_dex() * 2 ) < (int)me->query_dex() || random(10)<3)
	{
		me->set_temp("guarding", 0);

		if( !victim->is_fighting(me) )
			victim->fight_ob(me);

		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

		if( me->is_fighting(victim) && victim->is_fighting(me) )
		{
			if( (!objectp(me->query_temp("weapon"))
			        && sizeof(me->query_skill_prepare()) > 1)
			        || ( objectp(me->query_temp("weapon")) &&
			             (me->query_temp("weapon"))->query("skill_type") == "sword"
			             && me->query_skill("pixie-jian", 1) >= 60
			             && me->query_skill_mapped("sword") == "pixie-jian") )
			{
				me->set_temp("action_flag",1);
				do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
				me->set_temp("action_flag",0);
			}
		}
		else if ((random(me->query_int())>50 || random(10)<2) && victim->is_fighting(me))
		{
			me->set_temp("secondly_weapon",1);
			do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
			me->delete_temp("secondly_weapon");
		}

		if( !objectp(ob=me->query_temp("weapon")))
			skill_name="unarmed";
		else
			skill_name=ob->query("skill_type");

		skill_name=me->query_skill_mapped(skill_name);

		if ( stringp(skill_name) )
		{
#ifdef MAX_PLAYER_ATTACK
			if ( playerp(me) && SKILL_D(skill_name)->is_interlink() )
			{
				if ( attack_stop )
				{
					if ( member_array(me, series_attack) == -1 )
						series_attack += ( { me });
					if( !me->query_temp("guarding") )
						me->set_temp("guarding", 1);
					return;
				}
				if ( player_attack > MAX_PLAYER_ATTACK )
				{
					attack_stop = 1;
					remove_call_out("reset_player_attack");
					call_out("reset_player_attack", random(MAX_CALL_SEC));
					return;
				}
				if ( !(max_wait=sizeof(series_attack)) )
					now_attack_ob = me;
				else
				{
					for ( i=0; i<max_wait; i++ )
					{
						del_wait += ( { series_attack[i] });
						if ( objectp(series_attack[i]) )
						{
							now_attack_ob = series_attack[i];
							break;
						}
					}
					series_attack -= del_wait;
				}
				player_attack++;
			}

			if ( !objectp(now_attack_ob) ) now_attack_ob = me;
			if ( now_attack_ob != me && random(100) < IS_ATTACK_RANDOM )
			{
#endif
				me->set_temp("action_flag",1);
				SKILL_D(skill_name)->do_interlink(me, victim);
				me->set_temp("action_flag",0);
#ifdef MAX_PLAYER_ATTACK
				if ( playerp(me) && player_attack>0 ) player_attack--;
			}

			if( !objectp(ob=now_attack_ob->query_temp("weapon")))
				skill_name="unarmed";
			else skill_name=ob->query("skill_type");

			skill_name=now_attack_ob->query_skill_mapped(skill_name);

			if ( stringp(skill_name) )
			{
				now_attack_ob->set_temp("action_flag",1);
				SKILL_D(skill_name)->do_interlink(now_attack_ob, victim);
				now_attack_ob->set_temp("action_flag",0);
			}
#endif
		}
	}
	else if( !me->query_temp("guarding") )
	{
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim,0,"");
		return;
	}
	else
		return;
}

void auto_fight(object me, object obj, string type)
{
	// NPC之间
	if( !playerp(me) && !playerp(obj) )
		return;

	if( me->query_temp("looking_for_"+type ) )
		return;

	me->set_temp("looking_for_"+type, 1);
	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen,sb_shen;

	if( !me || !obj )
		return;               // Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_berserk", 0);

	if( me->is_fighting(obj)
	        ||  !living(me)
	        ||  environment(me)!=environment(obj)
	        ||  environment(me)->query("no_fight") )
		return;

	// 玩家和玩家之间、NPC 和 NPC 之间不撞神
	if ( (playerp(me) && playerp(obj)) || (!playerp(me) && !playerp(obj)) )
		return;

	message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);

	if( (shen < -50000 || sb_shen>100000) && me->query_per()>random(obj->query_per())*2 &&  !wizardp(obj) )
	{
		message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me) + "看你实在很不顺眼，去死吧。\n", me, obj);
		me->kill_ob(obj);
		obj->fight_ob(me);
	}
	else
	{
		message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj) + "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	}
}

void start_hatred(object me, object obj)
{
	string ip1, ip2;

	if( !me || !obj )
		return;               // Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_hatred", 0);

	if (!me->query("demogorgon") && !obj->query("demogorgon")  )
		if( me->is_fighting(obj)
		        || !living(me)
		        || environment(me)!=environment(obj)
		        || environment(me)->query("no_fight") )
			return;

	if ( (!playerp(me) && playerp(obj) && obj->query_condition("killer"))
	        || (playerp(me) && playerp(obj)
	            && stringp(ip1=query_ip_number(me))
	            && stringp(ip2=query_ip_number(obj))
	            && ip1 == ip2
	            && (obj->query_condition("killer")
	                || me->query_condition("killer")))
	        || (me->query_condition("killer") && obj->query_condition("killer")) )
	{
		message_vision(HBRED"$N一见$n立刻冲了上来，喝道：“官府正在悬赏通缉$n，" +
		               RANK_D->query_self_rude(me) +
		               "可有财发了。”\n"NOR, me, obj);
		//tell_object(obj ,HIR "看起来" + me->name()+"想杀死你！\n"NOR);
		me->kill_ob(obj);
		obj->fight_ob(me);
		return;
	}

	//if ( !me->is_killing(obj) ) return;

	// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
	obj->fight_ob(me);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj )
		return;               // Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_vendetta", 0);

	if( me->is_fighting(obj)
	        || !living(me)
	        || environment(me)!=environment(obj)
	        || environment(me)->query("no_fight") )
		return;

	// We found our vendetta opponent! Charge!
	message_vision(HIC"$N怒道：帮主有令，见到$n格杀勿论！\n"NOR,me,obj);
	tell_object(obj,HIR "看起来" + me->name()+"想杀死你！\n" NOR);
	me->kill_ob(obj);
	obj->kill_ob(me);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj )
		return;               // Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_aggressive", 0);

	if( me->is_fighting(obj)
	        || !living(me)
	        || environment(me)!=environment(obj)
	        || environment(me)->query("no_fight") )
		return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
	obj->fight_ob(me);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
	object *target;
	int i;

	switch(event)
	{
	case "dead":
		if(random(20) > 10)
			message_vision( NOR"\n$N扑在地上挣扎了几下，腿一伸，口中喷出几口"HIR"鲜血"NOR"，死了！\n\n" NOR, ob);
		else if(random(20)>10)
			message_vision( NOR"\n$N大叫一声倒在地上，挣扎了几下，"HIR"死了"NOR"！\n\n", ob);
		else
			message_vision( NOR"\n$N口中喷出几口"HIR"鲜血"NOR"，倒在地上,死了！\n\n", ob);
		break;
	case "unconcious":
		if(random(20) > 10)
			message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
		else
			message_vision("\n$N突然觉得头晕目眩，跌在地上不省人事了。\n\n", ob);
		break;
	case "revive":
		if(random(20) > 10)
			message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", ob);
		else
			message_vision("\n慢慢的,$N又恢复了神智。\n\n", ob);

		if (sizeof(target=ob->query_killer())>0)
			for (i=0; i<sizeof(target); i++)
			{
				if (objectp(target[i]))
					if (present(target[i],environment(ob)))
					{
						auto_fight(ob, target[i], "hatred");
						return;
					}
				break;
			}
	}
}

void winner_reward(object killer, object victim)
{
	victim->set_temp("last_unconcious_from", killer);
	killer->defeated_enemy(victim);
}

//非战斗死亡 掉落1%等级
int die_for(object victim)
{
	if ( !playerp(victim) && !(base_name(victim) == USER_OB && victim->query("lixian/biguan")) )
		return 0;

	victim->add("DIED",1);
	victim->clear_condition();

	// Give the death penalty to the dying user.
	victim->add("shen", -(int)victim->query("shen") / 10);

	//100级以下的未成年玩家不是杀人犯死亡没有经验损失
	if ( !(!victim->query_condition("killer") && victim->query("age") < 18 && victim->query("xyzx_sys/level") < 100) )
	{
		victim->add("xyzx_sys/level", -((int)victim->query("xyzx_sys/level")/100));
	}

	victim->delete("vendetta");
	victim->delete("bellicosity");

	if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);

	if( (int)victim->query("potential") )
		victim->add("potential",-(int)victim->query("potential")/4 );//掉1/4潜能

	victim->skill_death_penalty();//所以技能掉一级

	if (stringp(victim->query_temp("die_for")))
	{
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("听说%s%s死了。", victim->name(1),victim->query_temp("die_for")));
		victim->delete_temp("die_for");
	}
	else
	{
		CHANNEL_D->do_channel(this_object(),"sys",victim->name(1)+"死于"+environment(victim)->query("short")+"("+file_name(environment(victim))+")\n");
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf(HIW"听说%s死了，而且死的很离奇！"NOR, victim->name(1)));
	}
}

void killer_reward(object killer, object victim)
{
	int bls, int_skill, right_att;
	string vmark,killer_master_id,msg, msg_to;
	object link_ob, obb;
	mapping actions;
	int temp_exp;
	int my_level, your_level;

	if (!killer) return;
	victim->set("xyzx_sys/levup_exp",0);

	killer->killed_enemy(victim);
	killer_master_id = killer->query("family/master_id");

	if( playerp(victim) )
	{
		//巫师杀人没有经验损失
		if ( wiz_level(killer) > 1 && playerp(killer) )
			return;

		//如果未成年玩家在经验悬殊的情况下主动攻击被杀，杀人者不为杀人犯
		if ( victim->is_att_killing(killer) )
		{
			victim->set_temp("die_for","活腻而被"+killer->query("name")+"杀");
			die_for(victim);
			return;
		}

		//__________________________________正当防卫判定___________________________________
		right_att = 0;
		if( (/*!killer->query_temp("kill_other/"+victim->query("id"))
			&& */victim->query_temp("kill_other/"+killer->query("id"))
		            && killer->query_temp("other_kill/"+victim->query("id")))
		        || AUTOSAVED->check_killer_ip(killer, victim) ) // 同 IP 误杀也算做正当防卫
		{
			if ( playerp(killer) && playerp(victim) ) right_att = 1; // 正当防卫
		}
		//______________________________________结束_______________________________________

		if (playerp(killer))
		{
			//killer->add("PKS", 1);改放到后面的正当防卫系统再做判断
			victim->add("PKD",1);
		}

		victim->add("DIED",1);
		victim->clear_condition();

		// Give the death penalty to the dying user.
		victim->add("shen", -(int)victim->query("shen") / 10);
		victim->delete("vendetta");
		victim->delete("bellicosity");

		if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 2);
		//注意：这里如果开放鬼王的话，成年玩家死亡不掉潜能了。开放鬼王的时候注意改
		if (!playerp(killer) && killer->query("id")=="demogorgon" && victim->query("age",1) > 18)
		{
			victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
			int_skill=victim->query_skill("literate",1);

			if (int_skill>10)
				victim->set_skill("literate",int_skill-10);
			else
			{
				if( (int)victim->query("potential") )
					victim->add("potential",-(int)(victim->query("potential")/2));

				victim->add("combat_exp", -(int)victim->query("combat_exp") / 20);
			}
		}
		else//被杀的损失
		{
			victim->skill_death_penalty();//所以技能等级降低一级

			//被NPC杀死 1%经验
			//100级以下的未成年玩家不是杀人犯死亡没有经验损失
			if ( !(!victim->query_condition("killer") && killer->query_condition("killer") && playerp(killer)
			        && victim->query("age") < 18 && victim->query("xyzx_sys/level") < 100))
			{
				victim->add("xyzx_sys/level", -1);
			}

			if((int)victim->query("potential"))
				victim->add("potential",-(int)(victim->query("potential")/2));//潜能掉一半
		}

		bls = 10;

		if(objectp(killer))
		{
			if(environment(killer)&&environment(killer)->query("short"))
				msg = "在"+environment(killer)->query("short");
			else
				msg = "在未知地点";

			if (obb && obb != killer)
			{
				msg += "被"+obb->query("name")+"("+obb->query("id")+")打晕后又被"+killer->query("name")+"("+killer->query("id")+")";
				msg_to = "被"+killer->query("name")+"("+killer->query("id")+")打晕，"+killer->query("name")+"("+killer->query("id")+")";
			}
			else
			{
				msg += "被"+killer->query("name")+"("+killer->query("id")+")";
				msg_to = "被"+killer->query("name")+"("+killer->query("id")+")";
			}
			actions = killer->query("actions");

			switch(actions["damage_type"])
			{
			case "擦伤":
			case "割伤":
				msg += HIR"用武器砍死了。";
				break;
			case "刺伤":
				msg += HIR"用利器刺死了。";
				break;
			case "瘀伤":
				msg += HIR"用掌力击毙了。";
				break;
			case "内伤":
				msg += HIR"用掌力震死了。";
				break;
			default:
				msg += HIR"杀害了。";
			}
		}

		//杀的是杀人犯
		if ( playerp(killer) && (int)victim->query_condition("killer") )
		{
			CHANNEL_D->do_channel(this_object(), "rumor",sprintf(HIG"官府通缉犯%s被%s就地正法，为江湖除一大害!"NOR,victim->query("name"),killer->query("name")));
			// killer->delete_temp("kill_killer");
		}//自卫
		else if( right_att )
			CHANNEL_D->do_channel(this_object(), "rumor",sprintf(HIM"听说%s"+msg, victim->query("name")));
		else CHANNEL_D->do_channel(this_object(), "rumor",sprintf("听说%s"+msg, victim->query("name")));

		if (playerp(killer))//杀人者是玩家
		{
			write_file("/log/static/KILL_PLAYER",sprintf("%s(%s) 被 %s(%s) 杀死于 %s\n",victim->name(1), victim->query("id"),killer->name(1),killer->query("id"),CHINESE_D->chinese_time(7,ctime(time())) ));

			if(!victim->query_condition("killer"))
			{
				if( !right_att )
				{
					CHANNEL_D->do_channel(this_object(), "rumor",sprintf("官府开始通缉捉拿杀人犯%s，望侠义之士将其就地正法。", killer->query("name")));

				}
			}

			if ( !right_att )
			{
				if ( !victim->query_condition("killer") )
				{
					if ((killer->query_temp("pker_starttime")+3600*killer->query_temp("pker_time")) < killer->query("mud_age"))
					{
						killer->set_temp("pker_starttime",killer->query("mud_age"));
						killer->delete_temp("pker_time");
					}

					killer->add_temp("pker_time",1);

					killer->apply_condition("killer", MAX_CONDITION_KILLER+killer->query_condition("killer"));
					killer->command("pretend cancel");
					AUTOSAVED->add_killer(killer);
					killer->add("PKS", 1);

					if(killer->query("PKS_day") && time()-killer->query("PKS_time") > 24*3600)
						killer->delete("PKS_day");

					if(!killer->query("PKS_time") || time()-killer->query("PKS_time") > 24*3600)
						killer->set("PKS_time",time());

					if ( !victim->query_condition("killer") && time() - killer->query("PKS_time") < 24 * 3600 )
					{
						killer->add("PKS_day",1);
						tell_object(killer, HIY"这是你今天第 "HIR+killer->query("PKS_day")+HIY" 次PK，今天你还有 "HIR+(MAX_KILL_PLAYER-killer->query("PKS_day"))+HIY" 次PK机会。\n"NOR);
					}

					if ( killer->query("PKS_day") > MAX_KILL_PLAYER )
					{
						killer->set("block/time",time()+24*3600);
						killer->move("/clone/misc/block");
						killer->set("startroom","/clone/misc/block.c");
						tell_object(killer, HIR"你一天内杀害玩家数达到"+MAX_KILL_PLAYER+"人以上，囚禁一天以待反省。\n");
						message("channel:chat", HIY"【镜花水月】"+HIM"听说"HIR+killer->query("name")+HIM"因为今天PK次数过多关进了监狱！\n"NOR,users() );
					}
				}

				killer->delete_temp("kill_other/"+victim->query("id"));
				victim->delete_temp("kill_other/"+killer->query("id"));
				killer->delete_temp("other_kill/"+victim->query("id"));
				victim->delete_temp("other_kill/"+killer->query("id"));
			}

			//杀人者是玩家1%经验
			//100级以下的未成年玩家死亡没有经验损失
			if ( !(!victim->query_condition("killer") && killer->query_condition("killer") && playerp(killer)
			        && victim->query("age") < 18 && victim->query("xyzx_sys/level") < 100))
			{
				victim->add("xyzx_sys/level", -1);
			}

			//被杀者是杀人犯10%经验
			if( victim->query_condition("killer") )
			{
				victim->add("xyzx_sys/level", -10);
			}
		}
		// 杀人从犯
		if ( objectp(obb)
		        && playerp(obb)
		        && obb != killer
		        && !victim->query_condition("killer")
		        && obb->query_temp("kill_other/"+victim->query("id"))
		        && !AUTOSAVED->check_killer_ip(obb, victim) )
		{
			obb->command("pretend cancel");
			obb->apply_condition("killer", MAX_CONDITION_KILLER/2+obb->query_condition("killer"));
			AUTOSAVED->add_killer(obb);
			CHANNEL_D->do_channel(this_object(), "rumor",sprintf("官府开始通缉捉拿杀人从犯%s，望侠义之士将其就地正法。", obb->query("name")));

			if ((obb->query_temp("pker_starttime")+3600*obb->query_temp("pker_time"))
			        < obb->query("mud_age"))
			{
				obb->set_temp("pker_starttime", obb->query("mud_age"));
				obb->delete_temp("pker_time");
			}

			obb->add_temp("pker_time",1);
		}
		//记录最后杀自己的玩家
		victim->set("xyzx_sys/kill_me", killer->name(1)+"("+killer->query("id")+")");
	}
	else
	{
		if ( playerp(killer) )
			killer->add("MKS", 1);

		bls = 1;
	}

	if (killer_master_id==(string)victim->query("id") && !playerp(victim))
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s将自己的师傅%s杀死了,真是惨无人道啊。", killer->query("name"),victim->query("name")));

	//增加判断只有玩家才会加神
	if (!killer->is_ghost() && playerp(killer))
		killer->add("shen", -(int)victim->query("shen") / 10);

	//等级制初期新手杀NPC练级算法_________start_____________________________________________________________
	my_level = killer->query("xyzx_sys/level");
	your_level = victim->query("xyzx_sys/level");
	if ( !playerp(victim) && your_level+5 >= my_level && your_level-my_level<=100 )
	{
		temp_exp = your_level+5-my_level;
		if ( temp_exp < 1 ) temp_exp = 1;
		temp_exp *= random(1000);
		temp_exp += 1000;
		killer->add("combat_exp", temp_exp, 1);
		killer->add("potential", temp_exp / 30, 1);
		tell_object(killer, "你成功杀死了" + victim->name() + "得到了 "HIM + (temp_exp*killer->query_exp_times()) + NOR" 点经验和 "HIY + (temp_exp / 30) + NOR" 点潜能。\n"NOR);
	}
	//_______________________________________end_______________________________________________________________

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

	if( killer->query("family/master_id")==(string)victim->query("id"))
	{
		if ( victim->query_temp("fighting")==killer)
		{
			killer->delete("family");
			killer->set("title","普通百姓");
			killer->delete("class");
			victim->delete_temp("fighting");
			CHANNEL_D->do_channel(victim, "chat",sprintf("真不愧是青出于蓝而胜于蓝！%s，你可以出师了，从此另立门户吧！", killer->query("name")));
		}
		else if (killer->query("class") == "bonze" && victim->query("class") == "bonze")
		{
			killer->set("kill_bonze",time());
			killer->delete("family");

			if (link_ob=killer->query_temp("link_ob"))
				killer->set("name",link_ob->query("name"));

			killer->set("title","普通百姓");
			killer->delete("class");
			CHANNEL_D->do_channel(victim, "chat",sprintf("%s，你谋害自己的师傅，为我佛门所不容，你走吧！", killer->query("name")));
		}
	}
}

// 自动使用技能
void auto_skill_perform(object me, object obj)
{
	object weapon, *ob, who, room;
	string weapon_type, skill;
	mixed *file;
	int flag, i, enemy;

	// 每调用一次就减少一点
	me->add_temp("xyzx_skill_perform_doing", -1);

	// if ( !living(me) ) return;
	// if ( playerp(me) ) return; // 2006.11.8 限制只有 NPC 才能自动出外功
	// if ( !playerp(obj) ) return;
	// if ( me->query_temp("xyzx_auto_skill_perform") ) return; // 使用中，则等待完成才能使用
	if ( me->query_temp("xyzx_skill_perform_doing") > 0 ) return;
	if ( !objectp(room = environment(me)) ) return;
	if ( me->query("no_zhineng") ) return; // 增加"no_zhineng"不需要智能化的判定标识

	// 标志正自动使用特殊技能外功中，心跳清除。
	// me->set_temp("xyzx_auto_skill_perform", 1);
	// 根据对手的对手数目来降低出perform的几率。（主要是为了降低系统负担，提高性能）
	enemy = sizeof(obj->query_enemy());
	if ( enemy > 15 ) enemy = 15;
	me->set_temp("xyzx_skill_perform_doing", random(enemy) + 1);

	if ( me->query_skill("force",1) > 50 )
	{
		// 恢复精神
		if ( me->query("jing") < me->query("eff_jing")/2 )
		{
			me->command("exert regenerate");
			return;
		}
		//恢复气血
		if ( me->query("qi") < me->query("eff_qi")/2 )
		{
			me->command("exert recover");
			return;
		}
	}
	/////////////////////////////////////////////////////////////////////

	/* 一定几率优先使用内功。2006.11.8增加 by Wenwu */
	if ( random(100) < 95 )
	{
		weapon_type = "force";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/", -1);
		// 检查bin文件，以便纯二进制运行时有效
		if ( !sizeof(file) )
			file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
		if ( sizeof(file) )
		{
			me->command("exert " + file[random(sizeof(file)-1)][0][0..<3]);
			return;
		}
	}

	/////////////////////////////////////////////////////////////////////
	/* 技能外功使用 */

	// 检查使用的兵器
	if ( me->query_temp("weapon") )
	{
		if ( !objectp(weapon = me->query_temp("weapon")) )
			return;
		weapon_type = weapon->query("skill_type"); // 判定兵器类型
	}
	else
		weapon_type = "unarmed"; // 判定空手无兵器
	// 取得使用兵器技能或空手技能
	skill = me->query_skill_mapped(weapon_type);
	// 取得技能外功文件名
	file = get_dir("/kungfu/skill/"+skill+"/", -1);
	// 检查bin文件，以便纯二进制运行时有效
	if ( !sizeof(file) )
		file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
	// 如果有兵器但无兵器技能外功，则检查拳脚
	if ( me->query_temp("weapon") )
	{
		// 没有可用的兵器技能外功
		if ( !sizeof(file) )
		{
			flag = weapon->query("flag");
			// 检查是否使用双手武器或双手都拿有武器
			if ( !(flag & TWO_HANDED) && ((flag & SECONDARY) && !me->query_temp("secondary_weapon")) )
			{
				weapon_type = "unarmed";
				skill = me->query_skill_mapped(weapon_type);
				file = get_dir("/kungfu/skill/"+skill+"/", -1);
				// 检查bin文件，以便纯二进制运行时有效
				if ( !sizeof(file) )
					file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
			}
		}

	}
	// 拳脚和兵器上都无可用外功则检查招架
	if ( !sizeof(file) )
	{
		weapon_type = "parry";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/", -1);
		// 检查bin文件，以便纯二进制运行时有效
		if ( !sizeof(file) )
			file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
	}
	// 招架上也无可用外功检查轻功
	if ( !sizeof(file) )
	{
		weapon_type = "dodge";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/",-1);
		// 检查bin文件，以便纯二进制运行时有效
		if ( !sizeof(file) )
			file = get_dir("/binaries/kungfu/skill/"+skill+"/",-1);
	}
	// 有可用外功则使出外功
	if ( sizeof(file) )
	{
		// 有乾坤大挪移则50%几率出大挪移
		if ( (me->query_skill_mapped("parry") == "qiankundanuoyi" || me->query_skill_mapped("dodge") == "qiankundanuoyi")
		        && me->query_skill("qiankundanuoyi", 1) > 50
		        && me->query("neili") > 1500
		        && random(100) > 50 )
		{
			ob = all_inventory(room);
			for ( i = 0; i < sizeof(ob); i++ )
			{
				if ( !living(ob[i]) )
					ob -= ( { ob[i] });
			}
			who = ob[random(sizeof(ob))];
			if ( who != me && random(100) > 50 )
				// 乾坤大挪移转移对手攻击
				me->command("nuoyi " + obj->query("id") + " to " + who->query("id"));
			else
				// 乾坤大挪移反震对手
				me->command("nuoyi " + obj->query("id"));
		}
		else
			// 使用特殊技能外功
			me->command("perform " + weapon_type + "." + file[random(sizeof(file)-1)][0][0..<3]);
	}
	else if ( (me->query_skill_mapped("parry") == "qiankundanuoyi" || me->query_skill_mapped("dodge") == "qiankundanuoyi")
	          && me->query_skill("qiankundanuoyi", 1) > 50
	          && me->query("neili") > 1500
	          && random(100) > 50 ) // 无可用特殊技能外功，但有乾坤大挪移，尝试出大挪移
	{
		ob = all_inventory(room);
		for ( i = 0; i < sizeof(ob); i++ )
		{
			if ( !living(ob[i]) )
				ob -= ( { ob[i] });
		}
		who = ob[random(sizeof(ob))];
		if ( who != me && random(100) > 50 )
			// 乾坤大挪移转移对手攻击
			me->command("nuoyi " + obj->query("id") + " to " + who->query("id"));
		else
			// 乾坤大挪移反震对手
			me->command("nuoyi " + obj->query("id"));
	}
	else // 都无可用特殊技能，最后只有尝试内功运用了
	{
		weapon_type = "force";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/", -1);
		// 检查bin文件，以便纯二进制运行时有效
		if ( !sizeof(file) )
			file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
		if ( sizeof(file) )
		{
			me->command("exert " + file[random(sizeof(file)-1)][0][0..<3]);
			return;
		}
	}
}

#ifdef MAX_PLAYER_ATTACK
void reset_player_attack()
{
	if ( !objectp(this_object()) ) return;
	player_attack = 0;
	attack_stop = 0;
}

void remove()
{
	remove_call_out("reset_player_attack");
	series_attack = ( { });
}

object *query_series_attack()
{
	return series_attack;
}
#endif
