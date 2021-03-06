
#define MY_WEAPON_TYPE "兵器"
#define MY_ARMOR_TYPE "防具"
#define GRANT_WIZ_LEVEL 8

#include <liebiao.h>

inherit F_CLEAN_UP;
inherit F_COLOR;

#include <item_sx.h>

mapping weapon_skill_type = ([
"sword"   :  "剑法",
"blade"   :  "刀法",
"axe"     :  "斧法",
"club"    :  "棍法",
"dagger"  :  "矛法",
"fork"    :  "叉法",
"hammer"  :  "锤法",
"staff"   :  "杖法",
"whip"    :  "鞭法",
"spear"   :  "枪法",
"unarmed" :  "拳套",
"throwing":  "暗器"
]);

mapping armor_type = ([
"cloth"   :  "衣服",
"armor"   :  "铠甲",
"boots"   :  "靴子",
"finger"  :  "戒指",
"hands"   :  "护手",
"head"    :  "帽子",
"neck"    :  "项链",
"shield"  :  "盾牌",
"surcoat" :  "披风",
"waist"   :  "腰带",
"wrists"  :  "护腕",
"pants"  :   "裤子"
]);

mapping wear_type = ([
"cloth"   :  "身体",
"armor"   :  "身体",
"boots"   :  "脚部",
"finger"  :  "手指",
"hands"   :  "手部",
"head"    :  "头部",
"neck"    :  "颈项",
"shield"  :  "左手",
"surcoat" :  "背部",
"waist"   :  "腰部",
"wrists"  :  "腕部",
"pants"  :   "腿上"
]);

string *look_level_boy = ({
	BLU "眉歪眼斜，瘌头癣脚，不象人样" NOR,
 	BLU "呲牙咧嘴，黑如锅底，奇丑无比" NOR,
 	BLU "面如桔皮，头肿如猪，让人不想再看第二眼" NOR,
	HIB "贼眉鼠眼，身高三尺，宛若猴状" NOR,
	HIB "肥头大耳，腹圆如鼓，手脚短粗，令人发笑" NOR,
 	NOR "面颊凹陷，瘦骨伶仃，可怜可叹" NOR,
 	NOR "傻头傻脑，痴痴憨憨，看来倒也老实" NOR,
 	NOR "相貌平平，不会给人留下什么印象" NOR,
 	YEL "膀大腰圆，满脸横肉，恶形恶相" NOR,
 	YEL "腰圆背厚，面阔口方，骨格不凡" NOR,
 	RED "眉目清秀，端正大方，一表人才" NOR,
 	RED "双眼光华莹润，透出摄人心魄的光芒" NOR,
 	HIY "举动如行云游水，独蕴风情，吸引所有异性目光" NOR,
 	HIY "双目如星，眉梢传情，所见者无不为之心动" NOR,
 	HIR "粉面朱唇，身姿俊俏，举止风流无限" NOR,
 	HIR "丰神如玉，目似朗星，令人过目难忘" NOR,
 	MAG "面如美玉，粉妆玉琢，俊美不凡" NOR,
 	MAG "飘逸出尘，潇洒绝伦" NOR,
 	MAG "丰神俊朗，长身玉立，宛如玉树临风" NOR,
 	HIM "神清气爽，骨格清奇，宛若仙人" NOR,
 	HIM "一派神人气度，仙风道骨，举止出尘" NOR,
});

string *look_level_girl = ({
	BLU "丑如无盐，状如夜叉" NOR,
	BLU "歪鼻斜眼，脸色灰败，直如鬼怪一般" NOR,
	BLU "八字眉，三角眼，鸡皮黄发，让人一见就想吐" NOR,
	HIB "眼小如豆，眉毛稀疏，手如猴爪，不成人样" NOR,
	HIB "一嘴大暴牙，让人一看就没好感" NOR,
  	NOR "满脸疙瘩，皮色粗黑，丑陋不堪" NOR,
  	NOR "干黄枯瘦，脸色腊黄，毫无女人味" NOR,
  	YEL "身材瘦小，肌肤无光，两眼无神" NOR,
  	YEL "虽不标致，倒也白净，有些动人之处" NOR,
  	RED "肌肤微丰，雅淡温宛，清新可人" NOR,
  	RED "鲜艳妍媚，肌肤莹透，引人遐思" NOR,
  	HIR "娇小玲珑，宛如飞燕再世，楚楚动人" NOR,
  	HIR "腮凝新荔，肌肤胜雪，目若秋水" NOR,
  	HIW "粉嫩白至，如芍药笼烟，雾里看花" NOR,
  	HIW "丰胸细腰，妖娆多姿，让人一看就心跳不已" NOR,
  	MAG "娇若春花，媚如秋月，真的能沉鱼落雁" NOR,
  	MAG "眉目如画，肌肤胜雪，真可谓闭月羞花" NOR,
  	MAG "气质美如兰，才华馥比山，令人见之忘俗" NOR,
  	HIM "灿若明霞，宝润如玉，恍如神妃仙子" NOR,
  	HIM "美若天仙，不沾一丝烟尘" NOR,
  	HIM "宛如"+HIW+"玉雕冰塑"+HIM+"，似梦似幻，已不再是凡间人物" NOR,
});

string look_item(object me, object obj);
string look_living(object me, object obj);

int main(object me, string arg)
{
	object ob, *inv, room;
	string id, *ids, *id_list, id1, id2, new_id, num, msg, pro;
	int win, i, m, v;

	m = 0;

	if ( !stringp(arg) ) return 0;
	if ( me->query("xieyi/zmud") ) return 0;
	if ( !me->query("env/myhp_show") ) return 0;
	if ( sscanf(arg, "%s,%d", id, win) != 2 ) return 0;
	
	msg = "";
	
	if ( !sscanf(id, "%s %s", id1, id2) )
	{
		new_id = id; // 不是特殊处理时的，传入的 id 就是 new_id
		v = 0;
	}
	else
	{
		id_list = explode(id , " ");
		if ( !stringp(num = id_list[sizeof(id_list)-1]) ) return 0; // 未知的类型，则直接退出
		
		if ( !(v = atoi(num)) ) new_id = id; // 不符合特殊处理的格式，则认为 new_id 还是原来的 id
		else new_id = replace_string(id, " "+v, ""); // 是特殊处理的格式，我们重新获得正确的 id(new_id)
	}
	// 我们把传入的常规格式命令看作是指向首位置的特殊格式命令
	if ( !v )
		v = 1;
	
	switch ( win )
	{
		// 同环境下菜单
		case 0 :
				// 检查 me 是否有环境，没有则直接返回
				if ( !objectp(room = environment(me)) )
						return 1;
				// 通过遍历来查找这个 ob
				inv = all_inventory(room);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// 我们首先验证 ob 的真实 id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						if ( m == v )
						{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
						}
						else
							continue; // 如并不在指定的位置上，则继续查找下一个位置
					}
					// 验证伪装后的 id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// 找到了伪装了的 ob 的 id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
							}
							else
								continue; // 如并不在指定的位置上，则继续查找下一个位置
						}
					}
				}
				break;
		
		case 1 :
				// 检查 me 是否有效存在，没有则直接返回
				if ( !objectp(me) )
						return 1;
				// 通过遍历来查找这个 ob
				inv = all_inventory(me);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// 我们首先验证 ob 的真实 id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						if ( m == v )
						{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
						}
						else
							continue; // 如并不在指定的位置上，则继续查找下一个位置
					}
					// 验证伪装后的 id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// 找到了伪装了的 ob 的 id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
							}
							else
								continue; // 如并不在指定的位置上，则继续查找下一个位置
						}
					}
				}
				break;
	}
	
	if ( !objectp(ob) ) return 1;

	if ( ob->is_corpse() ) 
	{
		msg += "【名称】："+ob->query("name")+"("+ob->query("id")+")$$";
		msg += "【简介】："+sort_string(ob->long(), 73, 10)+"$$";
		msg += " 类型：尸体$$$$";

		inv = all_inventory(ob);
		pro = (ob==me) ? gender_self(ob->query("gender")) : gender_pronoun(ob->query("gender"));
		if( sizeof(inv) ) 
		{
			inv = map_array(inv, "inventory_look", this_object());
			if( sizeof(inv) )
				msg += sprintf("%s的遗体上有：$$ %s$$", pro, implode(inv, "$$ ") );
		}
		else
			msg += sprintf("%s的遗体上什么也没有。$$", pro);
	}
	else if ( ob->is_character() )
	{
		if ( !playerp(ob) || wizardp(me) || !ob->query_temp("apply/id") )
		{
			msg += "【名称】："+ob->query("name")+"("+ob->query("id")+")$$";
			msg += "【简介】："+sort_string(replace_string(ob->long(1),"\n", ""), 73, 10)+"$$";
			if ( playerp(ob) ) 
				msg += " 类型：玩家$$$$";
			else
				msg += " 类型：NPC$$$$";
		}

		msg += look_living(me, ob);
	}
	else
	{
		if ( mapp(ob->query("weapon_prop")) || mapp(ob->query("armor_prop")) )
		{
			msg += look_item(me, ob);
		}
		else
		{
			msg += "【名称】："+ob->query("name")+"("+ob->query("id")+")$$";
			msg += "【简介】："+sort_string(ob->long(), 73, 10)+"$$";
			msg += " 类型：普通物品$$$$";
			inv = all_inventory(ob);
			if ( sizeof(inv) ) 
			{
				inv = map_array(inv, "inventory_look", this_object() );
				msg += sprintf("里面有：$$ %s$$", implode(inv, "$$ ") );
			}
		}
	}

	write(SHOWIETM(clean_color(msg)));
	return 1;
}

string look_item(object me, object obj)
{
	string msg;
	int v_num, i;

	// Add By Wenwu
	//------------------------------------------------------
	msg = "【名称】："+obj->query("name")+"("+obj->query("id")+")$$";
	//------------------------------------------------------
	//开光魔法戒指描述特殊处理
	if ( obj->query("old_copy_log") && obj->query("diablo/only_me") != me->query("id") )
		msg += "【简介】："+sort_string(replace_string(obj->query("old_copy_log"),"\n", ""), 73, 10)+"$$";
	else
		msg += "【简介】："+sort_string(replace_string(obj->long(),"\n", ""), 73, 10)+"$$";

	// 属性显示
	// 兵器
	if ( obj->query("weapon_prop") )
	{
		msg += " 类型："+MY_WEAPON_TYPE+"$$";
		v_num = 0;
		for (i = 0; i < sizeof(weapon_shuxing); i++)
		{
			if ( obj->query("weapon_prop/" + keys(weapon_shuxing)[i]) )
				v_num++;
		}
		msg += " 品阶："+v_num+"$$";
		msg += " 等级："+obj->query("weapon_prop/level")+"$$";

		if ( obj->query("flag") & 1 )
			msg += " 使用类型：双手$$";
		else 
			msg += " 使用类型：单手$$";

		msg += " 应用类型："+weapon_skill_type[obj->query("skill_type")]+"$$$$";

		if ( obj->query("weapon_prop/damage") )
			msg += " 物攻："+obj->query("weapon_prop/damage")+"$$";

		if ( obj->query("weapon_prop/strength") )
			msg += " 臂力："+obj->query("weapon_prop/strength")+"$$";

		if ( obj->query("weapon_prop/intelligence") )
			msg += " 悟性："+obj->query("weapon_prop/intelligence")+"$$";

		if ( obj->query("weapon_prop/constitution") )
			msg += " 根骨："+obj->query("weapon_prop/constitution")+"$$";

		if ( obj->query("weapon_prop/dexerity") )
			msg += " 身法："+obj->query("weapon_prop/dexerity")+"$$";

		if ( obj->query("weapon_prop/karma") )
			msg += " 福缘："+obj->query("weapon_prop/karma")+"$$";

		if ( obj->query("weapon_prop/personality") )
			msg += " 容貌："+obj->query("weapon_prop/personality")+"$$";

		if ( obj->query("weapon_prop/dodge") )
			msg += " 轻功："+obj->query("weapon_prop/dodge")+"$$";

		if ( obj->query("weapon_prop/unarmed") )
			msg += " 拳脚："+obj->query("weapon_prop/unarmed")+"$$";

		if ( obj->query("weapon_prop/force") )
			msg += " 内功："+obj->query("weapon_prop/force")+"$$";

		if ( obj->query("weapon_prop/parry") )
			msg += " 招架："+obj->query("weapon_prop/parry")+"$$";

		if ( obj->query("weapon_prop/sword") )
			msg += " 剑法："+obj->query("weapon_prop/sword")+"$$";

		if ( obj->query("weapon_prop/blade") )
			msg += " 刀法："+obj->query("weapon_prop/blade")+"$$";

		if ( obj->query("weapon_prop/axe") )
			msg += " 斧法："+obj->query("weapon_prop/axe")+"$$";

		if ( obj->query("weapon_prop/stick") )
			msg += " 棒法："+obj->query("weapon_prop/stick")+"$$";

		if ( obj->query("weapon_prop/staff") )
			msg +=" 杖法："+obj->query("weapon_prop/staff")+"$$";

		if ( obj->query("weapon_prop/spear") )
			msg+=" 枪法："+obj->query("weapon_prop/spear")+"$$";

		if ( obj->query("weapon_prop/fork") )
			msg+=" 叉法："+obj->query("weapon_prop/fork")+"$$";

		if ( obj->query("weapon_prop/club") )
			msg+=" 棍法："+obj->query("weapon_prop/club")+"$$";

		if ( obj->query("weapon_prop/throwing") )
			msg+=" 暗器："+obj->query("weapon_prop/throwing")+"$$";

		if ( obj->query("weapon_prop/hammer") )
			msg +=" 锤法："+obj->query("weapon_prop/hammer")+"$$";

		if ( obj->query("weapon_prop/taoism") )
			msg+=" 道学心法："+obj->query("weapon_prop/taoism")+"$$";

		if ( obj->query("weapon_prop/whip") )
			msg+=" 鞭法："+obj->query("weapon_prop/whip")+"$$";

		if ( obj->query("weapon_prop/strike") )
			msg+=" 掌法："+obj->query("weapon_prop/strike")+"$$";

		if ( obj->query("weapon_prop/finger") )
			msg+=" 指法："+obj->query("weapon_prop/finger")+"$$";

		if ( obj->query("weapon_prop/magic") )
			msg+=" 基本魔法："+obj->query("weapon_prop/magic")+"$$";

		if ( obj->query("weapon_prop/spells") )
			msg+=" 基本法术："+obj->query("weapon_prop/spells")+"$$";

		if ( obj->query("weapon_prop/poison") )
			msg+=" 毒功："+obj->query("weapon_prop/poison")+"$$";

		if ( obj->query("weapon_prop/hand") )
			msg+=" 手法："+obj->query("weapon_prop/hand")+"$$";

		if ( obj->query("weapon_prop/cuff") )
			msg+=" 拳法："+obj->query("weapon_prop/cuff")+"$$";

		if ( obj->query("weapon_prop/claw") )
			msg+=" 爪法："+obj->query("weapon_prop/claw")+"$$";
	}
	else if ( obj->query("armor_prop") ) // 防具
	{
		msg += " 类型："+MY_ARMOR_TYPE+"$$";
		v_num = 0;
		for (i = 0; i < sizeof(armor_shuxing); i++)
		{
			if ( obj->query("armor_prop/" + keys(armor_shuxing)[i]) )
				v_num++;
		}
		msg += " 品阶："+v_num+"$$";
		msg += " 等级："+obj->query("armor_prop/level")+"$$";

		if ( obj->query("armor_type") )
		{
			msg += " 使用类型："+armor_type[obj->query("armor_type")]+"$$";
			msg += " 应用类型："+wear_type[obj->query("armor_type")]+"$$$$";
		}

		if ( obj->query("armor_prop/armor") )
			msg += " 物防："+obj->query("armor_prop/armor")+"$$";

		if ( obj->query("armor_prop/strength") )
			msg += " 臂力："+obj->query("armor_prop/strength")+"$$";

		if ( obj->query("armor_prop/intelligence") )
			msg += " 悟性："+obj->query("armor_prop/intelligence")+"$$";

		if ( obj->query("armor_prop/constitution") )
			msg += " 根骨："+obj->query("armor_prop/constitution")+"$$";

		if ( obj->query("armor_prop/dexerity") )
			msg += " 身法："+obj->query("armor_prop/dexerity")+"$$";

		if ( obj->query("armor_prop/karma") )
			msg += " 福缘："+obj->query("armor_prop/karma")+"$$";

		if ( obj->query("armor_prop/personality") )
			msg += " 容貌："+obj->query("armor_prop/personality")+"$$";

		if ( obj->query("armor_prop/armor_vs_force") )
			msg += " 真气护体："+YEL+obj->query("armor_prop/armor_vs_force")+"$$";

		if ( obj->query("armor_prop/dodge") )
			msg += " 轻功："+obj->query("armor_prop/dodge")+"$$";

		if ( obj->query("armor_prop/unarmed") )
			msg += " 拳脚："+obj->query("armor_prop/unarmed")+"$$";

		if ( obj->query("armor_prop/force") )
			msg += " 内功："+obj->query("armor_prop/force")+"$$";

		if ( obj->query("armor_prop/parry") )
			msg += " 招架："+obj->query("armor_prop/parry")+"$$";

		if ( obj->query("armor_prop/sword") )
			msg += " 剑法："+obj->query("armor_prop/sword")+"$$";

		if ( obj->query("armor_prop/blade") )
			msg += " 刀法："+obj->query("armor_prop/blade")+"$$";

		if ( obj->query("armor_prop/axe") )
			msg += " 斧法："+obj->query("armor_prop/axe")+"$$";

		if ( obj->query("armor_prop/stick") )
			msg += " 棒法："+obj->query("armor_prop/stick")+"$$";

		if ( obj->query("armor_prop/staff") )
			msg += " 杖法："+obj->query("armor_prop/staff")+"$$";

		if ( obj->query("armor_prop/spear") )
			msg += " 枪法："+obj->query("armor_prop/spear")+"$$";

		if ( obj->query("armor_prop/fork") )
			msg += " 叉法："+obj->query("armor_prop/fork")+"$$";

		if ( obj->query("armor_prop/club") )
			msg += " 棍法："+obj->query("armor_prop/club")+"$$";

		if ( obj->query("armor_prop/throwing") )
			msg += " 暗器："+obj->query("armor_prop/throwing")+"$$";

		if ( obj->query("armor_prop/hammer") )
			msg += " 锤法："+obj->query("armor_prop/hammer")+"$$";

		if ( obj->query("armor_prop/taoism") )
			msg += " 道学心法："+obj->query("armor_prop/taoism")+"$$";

		if ( obj->query("armor_prop/whip") )
			msg += " 鞭法："+obj->query("armor_prop/whip")+"$$";

		if ( obj->query("armor_prop/strike") )
			msg += " 掌法："+obj->query("armor_prop/strike")+"$$";

		if ( obj->query("armor_prop/finger") )
			msg += " 指法："+obj->query("armor_prop/finger")+"$$";

		if ( obj->query("armor_prop/magic") )
			msg += " 基本魔法："+obj->query("armor_prop/magic")+"$$";

		if ( obj->query("armor_prop/spells") )
			msg += " 基本法术："+obj->query("armor_prop/spells")+"$$";

		if ( obj->query("armor_prop/poison") )
			msg += " 毒功："+obj->query("armor_prop/poison")+"$$";

		if ( obj->query("armor_prop/hand") )
			msg += " 手法："+obj->query("armor_prop/hand")+"$$";

		if ( obj->query("armor_prop/cuff") )
			msg += " 拳法："+obj->query("armor_prop/cuff")+"$$";

		if ( obj->query("armor_prop/claw") )
			msg += " 爪法："+obj->query("armor_prop/claw")+"$$";
	}

    return msg;
}

string inventory_look(object obj, int flag)
{
	string str;

	if ( !flag )
		return "     "+obj->short();

	if( obj->query("equipped") )
	{
		switch( obj->query("armor_type") ) 
		{
			case "cloth":
			case "armor":   str = "身穿";break; break;
			case "boots":   str = "脚穿";break; break;
			case "head":    str = "头戴";break;
			case "pants":   str = "腿上穿着";break;
			case "neck":    str = "颈围";break;
			case "wrists":  str = "手腕戴着";break;
			case "finger":  str = "手指上戴着";break;
			case "hands":   str = "手上拿着";break;
			case "waist":   str = "腰间绑着";break;
			default:
				if ( environment(obj)->query_temp("weapon")==obj ) 
					str = "右手执";
				else 
					str = "左手执";
		}
		str += "一" + obj->query("unit")+obj->query("name")+"。";
	}
    return str;
}

string look_living(object me, object obj)
{
    int per_temp,i;
    string str, pro,*skills_name;
    mixed *inv;
    mapping my_fam, fam,skills;
    
	str = "";

	if ( !objectp(present("fire", me)) 
		&& environment(me)->query("outdoors") 
		&& NATURE_D->outdoor_room() 
		&& !wizardp(me) )
	{
		str += sprintf("你看到前面似乎有个人影，可天太黑了，看不太清楚。$$");
        return str;
    }

	if ( obj->query_temp("apply/name") ) 
	{
		str += sprintf("对方似乎是经过易容改扮的，无法看出其虚实。$$");
        return str;
	}

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	
	if( (string)obj->query("race")=="人类" 
		&& intp(obj->query("age")) )
		str += sprintf("%s看起来约%s多岁。$$", pro, chinese_number(obj->query("age") / 10 * 10));
	per_temp= (obj->query_per()>=30)?20:(obj->query_per()-10);
	
	if ( per_temp<0 ) per_temp=0;
	
	if ( (string)obj->query("race")=="人类" ) 
	{
		if ( (string)obj->query("gender") == "女性")
			str += sprintf("%s长的%s。$$", pro, look_level_girl[per_temp]);
		else
			str += sprintf("%s长的%s。$$", pro, look_level_boy[per_temp]);
		skills=obj->query_skills();
		if (!sizeof(skills))
			str+=sprintf("%s看起来似乎不会任何武功。$$", pro);
		else
		{
			skills_name=sort_array( keys(skills), (: strcmp :) );
			i=random(sizeof(skills_name));
			if (SKILL_D(skills_name[i])->type()=="knowledge")
				str+=sprintf("%s看起来似乎不会任何武功。$$", pro);
			else
				str+=sprintf("%s的武功看起来似乎%s。$$", pro,"/cmds/usr/skills"->skill_level(SKILL_D(skills_name[i])->type(), skills[skills_name[i]]));
		}
	}
   
	// If we both has family, check if we have any relations.
	if(obj!=me && obj->query("id")==me->query("couple/couple_id"))
	{	
		if(me->query("gender")=="女性") 
			str+=pro+"是你的老公。$$";	
		else 
			if (me->query("gender")=="男性") 
			str+=pro+"是你的老婆。$$";	
	}
    
	if( obj!=me
		&& mapp(fam = obj->query("family"))
		&& mapp(my_fam = me->query("family")) 
		&& fam["family_name"] == my_fam["family_name"] ) 
	{
    
        if( fam["generation"]==my_fam["generation"] ) 
		{
            if( (string)obj->query("gender") == "男性" )
                str += sprintf( pro + "是你的%s%s。$$", 
					my_fam["master_id"] == fam["master_id"] ? "": "同门",
                    my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
			else
				str += sprintf( pro + "是你的%s%s。$$",
                    my_fam["master_id"] == fam["master_id"] ? "": "同门",
                    my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
        } 
		else if( fam["generation"] < my_fam["generation"] ) 
		{
            if( my_fam["master_id"] == obj->query("id") )
                str += pro + "是你的师父。$$";
            else if( my_fam["generation"] - fam["generation"] > 1 )
                str += pro + "是你的同门长辈。$$";
            else if( fam["enter_time"] < my_fam["enter_time"] )
                str += pro + "是你的师伯。$$";
            else
                str += pro + "是你的师叔。$$";
        } 
		else 
		{
            if( fam["generation"] - my_fam["generation"] > 1 )
                str += pro + "是你的同门晚辈。$$";
            else if( fam["master_id"] == me->query("id") )
                str += pro + "是你的弟子。$$";
            else
                str += pro + "是你的师侄。$$";
        }
    }

    if( obj->query("max_qi") )
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "$$";
    
	inv = all_inventory(obj);
    if( sizeof(inv) ) 
	{
        inv = map_array(inv, "inventory_look", this_object(), 1 );
		inv -= ({0});
        if( sizeof(inv) )
			str += sprintf( "$$%s%s$$", pro, implode(inv, "$$") );
        if (!obj->query_temp("armor/cloth") && obj->query("race")=="人类" )
            str+=pro+"光着"+YEL+"身子"+NOR+"，什么也没穿！$$";
    }
	else 
		str += sprintf((obj->query("race")=="人类"?"%s光着"+YEL+"身子"+NOR+"，什么也没穿！$$":"它的身上没有任何东西。$$"),pro);

	return str;
}