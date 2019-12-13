//ս��ϵͳ
//���ݵȼ��ƣ������㷨��������д�����������������
//����ħ������������ϵͳ��
//�����������ԣ���׼�����ݡ����ԡ���Ӧ����ʹ֮����ս��ϵͳ
//��׼������������������������ʣ����������������������½�
//���ԣ����ħ����������ħ�������ʣ����������������������½�
//���ݣ�����������������������ʣ����������������������½�
//��Ӧ�����������������������ʣ�����������ħ���������½�

// ս��������ʾ�ȼ���"env/no_combat_msg"����
// = 1��ȥ����ʽ��Ϣ
// = 2����ȥ�����ܺ��м���Ϣ
// = 3����ȥ��ÿ������˺��̶ȵ�����
// = 4��ȥ�����е�����Ч������(ֻ��ʾ�Է�������״̬����Ȼ�˺�Ϊ0Ҳ��ʾ)
// = 5��ֻ������˺����������ʾ��������״���������˺���ʲô������ʾ������˵��ˢ�����ʱ���˺�Ϊ0��ʲô������ʾ��

// ������������ս���㷨���� (ע��:�����ֵΪ int)
#define MAX_PLAYER_ATTACK 5

// �������� (ȡ������������ֵ)
#define MAX_CALL_SEC 3

// ��������������Ĺ�������(�ٷֱ�)
#define IS_ATTACK_RANDOM 30

// ����ÿ ID һ�������ɱ�˴���
#define MAX_KILL_PLAYER 100

// ����ÿ��ɱ�����ӵ� killer ֵ
#define MAX_CONDITION_KILLER 5000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

mapping limb_damage = ([
                           //�������岿λ
                           "ͷ��"  :   100,
                           "����"  :   90,
                           "�ؿ�"  :   90,
                           "����"  :   80,
                           "���"  :   50,
                           "�Ҽ�"  :   55,
                           "���"  :   40,
                           "�ұ�"  :   45,
                           "����"  :   20,
                           "����"  :   30,
                           "����"  :   60,
                           "С��"  :   70,
                           "����"  :   40,
                           "����"  :   50,
                           "���"  :   35,
                           "�ҽ�"  :   40,
                           //�������岿λ
                           "����"  :   80,
                           "ǰ��"  :   40,
                           "���"  :   50,
                           "�Ȳ�"  :   40,
                           "β��"  :   10,
                           "���"  :   50,
                           "צ��"  :   40
                       ]);

string *guard_msg = (
{
	CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
	CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
	CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
	CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
	CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR
});

string *catch_hunt_msg = (
{
	HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
	HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
	HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
	HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
	HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
	HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
	HIW "$N�ȵ�����$n�����У���\n" NOR
});

string *winner_msg = (
{
	CYN "\n$N������Ц������˵���������ˣ�\n\n" NOR,
	CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR,
	CYN "\n$N������Ц��˫��һ����Ц��˵�������ã�\n\n" NOR,
	CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
	CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
	CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
	CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR
});

#ifdef MAX_PLAYER_ATTACK
int player_attack = 0, attack_stop = 0;
object *series_attack = ( { });
#endif

void auto_skill_perform(object me, object obj);

void create()
{
	seteuid(getuid());
	set("name", "ս������");
	set("channel_id",HIM"ս������"HIR);
	set("id", "combatd");

}

//����ÿ���˺�ֵ�뵱ǰ���İٷֱȸ�����Ӧ�˺�����
string damage_msg(int damage, string type,object ob)
{
	string str;
	int qi;

	qi = ob->query("qi");

	if( damage == 0 )
		return "���û������κ��˺���\n";

	if ( qi > 0 )
	{
		damage = damage * 100;
		damage /= qi;
	}
	else
		damage = 120;

	switch( type )
	{
	case "����":
	case "����":
		if( damage < 5 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
		else if( damage < 10 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
		else if( damage < 20 ) return "������͡���һ������һ���˿ڣ�\n";
		else if( damage < 40 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
		else if( damage < 80 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
		else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
		break;
	case "����":
		if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
		else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
		else if( damage < 60 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
		else if( damage < 80 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
		else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
		break;
	case "����":
		if( damage < 5 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
		else if( damage < 10 ) return "�����$p��$l���һ�����ࡣ\n";
		else if( damage < 25 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
		else if( damage < 40 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
		else if( damage < 50 ) return "������项��һ����$n����������\n";
		else if( damage < 60 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
		else if( damage < 80 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
		else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
		break;
	case "����":
		if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
		else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
		else if( damage < 30 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
		else if( damage < 40 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
		else if( damage < 60 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
		else if( damage < 75 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
		else if( damage < 90 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
		else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
		break;
	default:
		if( !type ) type = "�˺�";
		if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
		else if( damage < 20 ) str = "��������΢��";
		else if( damage < 30 ) str = "������һ��";
		else if( damage < 50 ) str = "������һ������";
		else if( damage < 60 ) str = "��������Ϊ���ص�";
		else if( damage < 70 ) str = "�������൱���ص�";
		else if( damage < 80 ) str = "������ʮ�����ص�";
		else if( damage < 90 ) str = "�����ɼ������ص�";
		else str =  "�����ɷǳ����µ�����";
		return str + type + "��\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
	if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
	if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
	if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
	if( ratio > 40 ) return RED "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
	if( ratio > 30 ) return RED "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
	if( ratio > 20 ) return RED "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
	if( ratio > 10 ) return HIR "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	if( ratio > 5  ) return HIR "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
	return HIR "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}
string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
	if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
	if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
	if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
	if( ratio > 40 ) return RED "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
	if( ratio > 30 ) return RED "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
	if( ratio > 20 ) return RED "�������Ѿ����������ˡ�" NOR;
	if( ratio > 10 ) return HIR "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	return HIR "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

//����״������
varargs void report_status(object ob, int effective)
{
	if( effective )
		message_vision( "( $N" + eff_status_msg((int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) + " )\n", ob);
	else
		message_vision( "( $N" + status_msg((int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) + " )\n", ob);
}

//ս�����������㷨
varargs int skill_power(object ob, string skill, int usage)
{
	int status, than_encumb;
	int power, level, my_sx;
	string used_skill;

	if ( !living(ob) ) return 1; //���Ի�˯��
	// if( ob->over_encumbranced() )    return 1; // ����С����ʱ power ��Զ������
	//if( userp(ob) && ob->is_ghost() ) return 1;  // ���� power ��Զ������
	if ( stringp(used_skill=ob->query_skill_mapped(skill)) )
		level = (int)ob->query_skill(used_skill,1);
	else level = 0;

	level += (int)ob->query_skill(skill,1) / 2;

	switch ( usage )
	{
		// ����
	case SKILL_USAGE_ATTACK:
		level += (int)ob->query_temp("apply/attack");
		level += (int)ob->query_temp("apply/"+skill);
		level += (int)ob->query_str();
		level += (int)ob->query("jiali");
		if ( ob->is_fighting() )
			level += (int)ob->query_temp("fight/attack");
		my_sx = (int)ob->query("xyzx_sys/jingzhun");
		break;
		// �м�
	case SKILL_USAGE_DEFENSE:
		level += (int)ob->query_temp("apply/defense");
		level += (int)ob->query_temp("apply/"+skill);
		level += (int)ob->query_con();
		if ( ob->is_fighting() )
			level = level + ob->query_temp("fight/parry");
		my_sx = (int)ob->query("xyzx_sys/fanying");
		break;
		// ����
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

	if ( !objectp(me) || !objectp(victim) ) return 1;//�������
	if ( !living(me) ) return 1; //���ǻ�������
	if(me->query_temp("netdead") && !victim->is_player()) return 1; //������NPC,����Ѿ�����
	if ( environment(me) != environment(victim) ) return 1;//����һ��������
	if( (userp(me) && me->is_ghost()) || (userp(victim) && victim->is_ghost()) ) return 1; //�Լ����ˣ����߶Է��Ѿ�����
	if ( !me->visible(victim) ) return 0;
	if ( me->query_temp("block_msg/all") && !me->query("end_boss") ) return 1;

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
	prepare = me->query_skill_prepare();

	/******************�ȼ������ By Wenwu***********************************************/
	my_level = me->query("xyzx_sys/level");
	your_level = victim->query("xyzx_sys/level");
	desc = your_level/(my_level>0?my_level:1);
	if ( desc < 1 ) desc = 1;
	//--------------------������------------------------------------
	my_mj = me->query("xyzx_sys/minjie");
	my_fy = me->query("xyzx_sys/fanying");
	your_mj = victim->query("xyzx_sys/minjie");
	your_fy = victim->query("xyzx_sys/fanying");
	/**************************************************************************/
	// ս��������ʾ�ȼ����
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
	// ���⼼���⹦�Զ�ʹ��
	// auto_skill_perform(me, victim);
	//�Բ�ϣ����ʾս�����̵�������ε�����ս������������Ҳ���Լ���ϵͳ����
	if ( msg ) result = msg + "\n";
	else result = "";

	if ( combat_msg )
		result += "";
	else
	{
		if (stringp(me->query_temp("action_msg")))
		{
			result += (string)me->query_temp("action_msg")+ action["action"] + "��\n";
			me->delete_temp("action_msg");
		}
		else if (me->query_temp("action_flag") == 0) result += "" + action["action"] + "��\n";
		else
			result += "������"+action["action"] + "!\n";
	}

	limbs = victim->query("limbs");

	if ( !pointerp(limbs) || !sizeof(limbs) )
	{
		CHANNEL_D->do_channel( this_object(), "sys",sprintf("%s(%s): no such limbs",me->name(1), me->query("id")));
		return 0;
	}

	limb = limbs[random(sizeof(limbs))];

	// ���⹥��������
	// ����
	dodge_skill = victim->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(victim,limb);
	if (!dodge_msg || dodge_msg=="") dodge_msg = SKILL_D("dodge")->query_dodge_msg(victim,limb);
	//�м�
	parry_skill = victim->query_skill_mapped("parry");
	if( !parry_skill ) parry_skill = "parry";
	parry_msg = SKILL_D(parry_skill)->query_parry_msg(victim,weapon);
	if (!parry_msg || parry_msg=="") parry_msg = SKILL_D("parry")->query_parry_msg(victim,weapon);
	//--------------------------------------------------------
	//�������ӹ�����ʽ�����⹥��
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

	// ��Χ�������½�
	if ( (cost_a = sizeof(victim->query_enemy())) > 1 /*&& (!playerp(me) || !playerp(victim))*/ )
	{
		victim->delete_temp("fighting");
		dp = dp / cost_a;
	}
	// ��Է���������(�����)�ȶ��ֵ�,���������½�
	if ( !victim->visible(me) /*&& (!playerp(me) || !playerp(victim))*/ )
		dp = dp / 2;
	cost = skill_power(me, "dodge", SKILL_USAGE_DODGE)/10;
	// ��Է���������(�����)�ȶ��ֵ�,���������½�
	if ( !me->visible(victim) )
	{
		ap = ap / 2;
		cost = cost / 2;
	}

	//����
	if ( living(victim) && random(ap + cost)<random(dp) )
	{
		// ���ܿ������Ϸ����Ƚ����ף��� 30% ������
		if ( random(100) < 30 ) att_back = 1;
		// ս��������ʾ�ȼ� < 2 ����ʾ
		if ( combat_msg < 2 ) result += dodge_msg;
		//���ܿ������Ķ������Ӿ�����Ṧ������
		if( ap + cost > dp ) victim->improve_skill("dodge", random(victim->query_int())/20);

		damage = RESULT_DODGE;
	}
	else //û�����ܿ�ʱ
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
				pp = pp * 2; // ֧�ִ������㣬������Ҫ����ķ��������
			}
		}
		else if( weapon ) pp = pp / 2;

		if ( (cost_a=sizeof(victim->query_enemy())) > 1 /*&& (!playerp(me) || !playerp(victim)) */)
			pp = pp / cost_a;

		if ( !victim->visible(me)/* && (!playerp(me) || !playerp(victim)) */)
			pp = pp / 2;
		// �м�
		if( living(victim) && random(ap + cost) < random(pp) )
		{
			// ˫�ֶ����������м�ס��Ӧ�÷������ʻ��ǱȽϴ�ģ��� 50% ��������
			// �õ���˫�������мܣ���������Ӧ�ñȽ����ѣ��跴������ 20%
			// ��һ������һ��ȭ�ţ���˫�ֿ�ȭ���Ƿ��ܷ����Ƚ����跴������ 30%
			if ( victim->query_temp("secondary_weapon") )
			{
				if ( your_weapon = victim->query_temp("secondary_weapon") )
				{
					if ( your_weapon->query("flag") & 2 ) // ˫�ָ���������
					{
						if ( random(100) < 50 ) att_back = 1;
					}
					else // �õ�˫������
					{
						if ( random(100) < 20 ) att_back = 1;
					}
				}
			}
			else // һ��������˫�ֿ�ȭ
			{
				if ( random(100) < 30 ) att_back = 1;
			}

			if ( combat_msg < 2 ) result += parry_msg;
			// �м������Ķ��ֻ�þ��鼰�м�������
			if( ap + cost > pp ) victim->improve_skill("parry", random(victim->query_int())/20);

			damage = RESULT_PARRY;
		}
		else //��������
		{
			damage = (int)me->query_temp("apply/damage");
			damage = (damage + random(damage)) / 2;
			if( dam = action["damage"] )
			{
				if ( dam < 1 ) dam = 1;
				damage += dam * damage / 100;
			}
			damage_bonus = me->query_skill(attack_skill) + me->query_skill("force")/2; //2016.5.20�޸�
			if( weapon ) damage_bonus = (int)damage_bonus / 5;  //���������Ļ�ѧ�˺��ӳ�
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
			if(living(victim) )  //2015.12.30��ӣ�����״̬�� ���ٴ���ob_hit
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
			if ( userp(me) ) damage /= desc; // ������˺���Ӱ�� playerp
			damage -= damage*(to_int(sqrt(to_float(victim->query_temp("apply/armor")/1000))))/100; //2016.8.13����˺�����
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

			// npc���������
			foo = victim->weapon_ob(victim,me, damage);
			if( stringp(foo) )
			{
				if ( combat_msg < 4 ) result += foo;
			}
			else if(intp(foo) && foo > 0 ) damage += foo;

			if ( damage < 1 ) // ����ħ��ϵͳ��δ���ƣ���ʱע�͵����Զ������˺���Ӱ��
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
				me->add("combat_exp", me->query_int()/10, TEAMD->get_allot_type(me->query_temp("xyzx_team/name"))!="ƽ������");
				//my["combat_exp"] += me->query_int()/10;
				me->improve_skill(attack_skill, random(me->query_int()));
				//���ӻ�Ա��Ǳ���ۼ�����
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
		result = replace_string( result, "$w", "���ξ���" );
	else if( attack_skill == "finger" )
		result = replace_string( result, "$w", "ָ��һ������" );
	else if( attack_skill == "strike" )
		result = replace_string( result, "$w", "��������" );
	else result = replace_string( result, "$w", "   " );
	/*while ( strsrch(result, "\n\n") != -1 )
	{
		result = replace_string( result, "\n\n", "\n" );
		result = replace_string( result, " ", "" );
	}*/
	message_vision(result, me, victim ,damage,action["damage_type"]);

	if( wizardp(me) && me->query("env/combat") )
	{
		tell_object(me, sprintf( BBLU "����(attack])��������[ %d ], ����[ %d ], �м�[ %d ], �˺�[ %d ]\n" NOR,
		                         ap+cost, dp, pp, damage));
	}

	if( wizardp(victim) && victim->query("env/combat") )
	{
		tell_object(victim, sprintf( BRED "����(defend)��������[ %d ], ����[ %d ], �м�[ %d ], �˺�[ %d ]\n" NOR,
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
			if (me->query("family/family_name")!="������" && victim->query_temp("fighting")==me && me->query("family/master_id")==(string)victim->query("id"))
			{
				me->delete("family");
				me->set("title","��ͨ����");
				me->delete("class");
				victim->delete_temp("fighting");
				CHANNEL_D->do_channel(victim, "chat",sprintf("�治�������������ʤ������%s������Գ�ʦ�ˣ��Ӵ������Ż��ɣ�", me->query("name")));
			}
			else
				message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
		}

		//��¼�������˺��Ķ���
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
		// û�г��������� 50% �ж�ս��
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
				message_vision(HIY"$N�ۼ���������Σ���в���˼������һƫ˳�ַ���һʽ��\n"NOR, victim,me,0,"");
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
			break;
		case 1:
			if ( combat_msg < 4 )
				message_vision(HIY"$Nһ�����У�¶����������\n"NOR, me,victim,0,"");
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
			break;
		default:
			if ( combat_msg < 4 )
				message_vision(HIY"$N��$n����ʧ�󣬳û�����������\n"NOR, victim, me,0,"");
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}

	// ���ι��������������������³�ʼ��
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
	// ���⼼���⹦�Զ�ʹ��
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
	// NPC֮��
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

	// ��Һ����֮�䡢NPC �� NPC ֮�䲻ײ��
	if ( (playerp(me) && playerp(obj)) || (!playerp(me) && !playerp(obj)) )
		return;

	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

	if( (shen < -50000 || sb_shen>100000) && me->query_per()>random(obj->query_per())*2 &&  !wizardp(obj) )
	{
		message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me) + "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
		me->kill_ob(obj);
		obj->fight_ob(me);
	}
	else
	{
		message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj) + "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",me, obj);
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
		message_vision(HBRED"$Nһ��$n���̳����������ȵ������ٸ���������ͨ��$n��" +
		               RANK_D->query_self_rude(me) +
		               "���вƷ��ˡ���\n"NOR, me, obj);
		//tell_object(obj ,HIR "������" + me->name()+"��ɱ���㣡\n"NOR);
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
	message_vision(HIC"$Nŭ���������������$n��ɱ���ۣ�\n"NOR,me,obj);
	tell_object(obj,HIR "������" + me->name()+"��ɱ���㣡\n" NOR);
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
			message_vision( NOR"\n$N���ڵ��������˼��£���һ�죬�����������"HIR"��Ѫ"NOR"�����ˣ�\n\n" NOR, ob);
		else if(random(20)>10)
			message_vision( NOR"\n$N���һ�����ڵ��ϣ������˼��£�"HIR"����"NOR"��\n\n", ob);
		else
			message_vision( NOR"\n$N�����������"HIR"��Ѫ"NOR"�����ڵ���,���ˣ�\n\n", ob);
		break;
	case "unconcious":
		if(random(20) > 10)
			message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
		else
			message_vision("\n$NͻȻ����ͷ��Ŀѣ�����ڵ��ϲ�ʡ�����ˡ�\n\n", ob);
		break;
	case "revive":
		if(random(20) > 10)
			message_vision("\n$N���������۾��������˹�����\n\n", ob);
		else
			message_vision("\n������,$N�ָֻ������ǡ�\n\n", ob);

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

//��ս������ ����1%�ȼ�
int die_for(object victim)
{
	if ( !playerp(victim) && !(base_name(victim) == USER_OB && victim->query("lixian/biguan")) )
		return 0;

	victim->add("DIED",1);
	victim->clear_condition();

	// Give the death penalty to the dying user.
	victim->add("shen", -(int)victim->query("shen") / 10);

	//100�����µ�δ������Ҳ���ɱ�˷�����û�о�����ʧ
	if ( !(!victim->query_condition("killer") && victim->query("age") < 18 && victim->query("xyzx_sys/level") < 100) )
	{
		victim->add("xyzx_sys/level", -((int)victim->query("xyzx_sys/level")/100));
	}

	victim->delete("vendetta");
	victim->delete("bellicosity");

	if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);

	if( (int)victim->query("potential") )
		victim->add("potential",-(int)victim->query("potential")/4 );//��1/4Ǳ��

	victim->skill_death_penalty();//���Լ��ܵ�һ��

	if (stringp(victim->query_temp("die_for")))
	{
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("��˵%s%s���ˡ�", victim->name(1),victim->query_temp("die_for")));
		victim->delete_temp("die_for");
	}
	else
	{
		CHANNEL_D->do_channel(this_object(),"sys",victim->name(1)+"����"+environment(victim)->query("short")+"("+file_name(environment(victim))+")\n");
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf(HIW"��˵%s���ˣ��������ĺ����棡"NOR, victim->name(1)));
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
		//��ʦɱ��û�о�����ʧ
		if ( wiz_level(killer) > 1 && playerp(killer) )
			return;

		//���δ��������ھ�����������������������ɱ��ɱ���߲�Ϊɱ�˷�
		if ( victim->is_att_killing(killer) )
		{
			victim->set_temp("die_for","�������"+killer->query("name")+"ɱ");
			die_for(victim);
			return;
		}

		//__________________________________���������ж�___________________________________
		right_att = 0;
		if( (/*!killer->query_temp("kill_other/"+victim->query("id"))
			&& */victim->query_temp("kill_other/"+killer->query("id"))
		            && killer->query_temp("other_kill/"+victim->query("id")))
		        || AUTOSAVED->check_killer_ip(killer, victim) ) // ͬ IP ��ɱҲ������������
		{
			if ( playerp(killer) && playerp(victim) ) right_att = 1; // ��������
		}
		//______________________________________����_______________________________________

		if (playerp(killer))
		{
			//killer->add("PKS", 1);�ķŵ��������������ϵͳ�����ж�
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
		//ע�⣺����������Ź����Ļ������������������Ǳ���ˡ����Ź�����ʱ��ע���
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
		else//��ɱ����ʧ
		{
			victim->skill_death_penalty();//���Լ��ܵȼ�����һ��

			//��NPCɱ�� 1%����
			//100�����µ�δ������Ҳ���ɱ�˷�����û�о�����ʧ
			if ( !(!victim->query_condition("killer") && killer->query_condition("killer") && playerp(killer)
			        && victim->query("age") < 18 && victim->query("xyzx_sys/level") < 100))
			{
				victim->add("xyzx_sys/level", -1);
			}

			if((int)victim->query("potential"))
				victim->add("potential",-(int)(victim->query("potential")/2));//Ǳ�ܵ�һ��
		}

		bls = 10;

		if(objectp(killer))
		{
			if(environment(killer)&&environment(killer)->query("short"))
				msg = "��"+environment(killer)->query("short");
			else
				msg = "��δ֪�ص�";

			if (obb && obb != killer)
			{
				msg += "��"+obb->query("name")+"("+obb->query("id")+")���κ��ֱ�"+killer->query("name")+"("+killer->query("id")+")";
				msg_to = "��"+killer->query("name")+"("+killer->query("id")+")���Σ�"+killer->query("name")+"("+killer->query("id")+")";
			}
			else
			{
				msg += "��"+killer->query("name")+"("+killer->query("id")+")";
				msg_to = "��"+killer->query("name")+"("+killer->query("id")+")";
			}
			actions = killer->query("actions");

			switch(actions["damage_type"])
			{
			case "����":
			case "����":
				msg += HIR"�����������ˡ�";
				break;
			case "����":
				msg += HIR"�����������ˡ�";
				break;
			case "����":
				msg += HIR"�����������ˡ�";
				break;
			case "����":
				msg += HIR"�����������ˡ�";
				break;
			default:
				msg += HIR"ɱ���ˡ�";
			}
		}

		//ɱ����ɱ�˷�
		if ( playerp(killer) && (int)victim->query_condition("killer") )
		{
			CHANNEL_D->do_channel(this_object(), "rumor",sprintf(HIG"�ٸ�ͨ����%s��%s�͵�������Ϊ������һ��!"NOR,victim->query("name"),killer->query("name")));
			// killer->delete_temp("kill_killer");
		}//����
		else if( right_att )
			CHANNEL_D->do_channel(this_object(), "rumor",sprintf(HIM"��˵%s"+msg, victim->query("name")));
		else CHANNEL_D->do_channel(this_object(), "rumor",sprintf("��˵%s"+msg, victim->query("name")));

		if (playerp(killer))//ɱ���������
		{
			write_file("/log/static/KILL_PLAYER",sprintf("%s(%s) �� %s(%s) ɱ���� %s\n",victim->name(1), victim->query("id"),killer->name(1),killer->query("id"),CHINESE_D->chinese_time(7,ctime(time())) ));

			if(!victim->query_condition("killer"))
			{
				if( !right_att )
				{
					CHANNEL_D->do_channel(this_object(), "rumor",sprintf("�ٸ���ʼͨ��׽��ɱ�˷�%s��������֮ʿ����͵�������", killer->query("name")));

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
						tell_object(killer, HIY"���������� "HIR+killer->query("PKS_day")+HIY" ��PK�������㻹�� "HIR+(MAX_KILL_PLAYER-killer->query("PKS_day"))+HIY" ��PK���ᡣ\n"NOR);
					}

					if ( killer->query("PKS_day") > MAX_KILL_PLAYER )
					{
						killer->set("block/time",time()+24*3600);
						killer->move("/clone/misc/block");
						killer->set("startroom","/clone/misc/block.c");
						tell_object(killer, HIR"��һ����ɱ��������ﵽ"+MAX_KILL_PLAYER+"�����ϣ�����һ���Դ���ʡ��\n");
						message("channel:chat", HIY"������ˮ�¡�"+HIM"��˵"HIR+killer->query("name")+HIM"��Ϊ����PK��������ؽ��˼�����\n"NOR,users() );
					}
				}

				killer->delete_temp("kill_other/"+victim->query("id"));
				victim->delete_temp("kill_other/"+killer->query("id"));
				killer->delete_temp("other_kill/"+victim->query("id"));
				victim->delete_temp("other_kill/"+killer->query("id"));
			}

			//ɱ���������1%����
			//100�����µ�δ�����������û�о�����ʧ
			if ( !(!victim->query_condition("killer") && killer->query_condition("killer") && playerp(killer)
			        && victim->query("age") < 18 && victim->query("xyzx_sys/level") < 100))
			{
				victim->add("xyzx_sys/level", -1);
			}

			//��ɱ����ɱ�˷�10%����
			if( victim->query_condition("killer") )
			{
				victim->add("xyzx_sys/level", -10);
			}
		}
		// ɱ�˴ӷ�
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
			CHANNEL_D->do_channel(this_object(), "rumor",sprintf("�ٸ���ʼͨ��׽��ɱ�˴ӷ�%s��������֮ʿ����͵�������", obb->query("name")));

			if ((obb->query_temp("pker_starttime")+3600*obb->query_temp("pker_time"))
			        < obb->query("mud_age"))
			{
				obb->set_temp("pker_starttime", obb->query("mud_age"));
				obb->delete_temp("pker_time");
			}

			obb->add_temp("pker_time",1);
		}
		//��¼���ɱ�Լ������
		victim->set("xyzx_sys/kill_me", killer->name(1)+"("+killer->query("id")+")");
	}
	else
	{
		if ( playerp(killer) )
			killer->add("MKS", 1);

		bls = 1;
	}

	if (killer_master_id==(string)victim->query("id") && !playerp(victim))
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s���Լ���ʦ��%sɱ����,���ǲ����˵�����", killer->query("name"),victim->query("name")));

	//�����ж�ֻ����ҲŻ����
	if (!killer->is_ghost() && playerp(killer))
		killer->add("shen", -(int)victim->query("shen") / 10);

	//�ȼ��Ƴ�������ɱNPC�����㷨_________start_____________________________________________________________
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
		tell_object(killer, "��ɹ�ɱ����" + victim->name() + "�õ��� "HIM + (temp_exp*killer->query_exp_times()) + NOR" �㾭��� "HIY + (temp_exp / 30) + NOR" ��Ǳ�ܡ�\n"NOR);
	}
	//_______________________________________end_______________________________________________________________

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

	if( killer->query("family/master_id")==(string)victim->query("id"))
	{
		if ( victim->query_temp("fighting")==killer)
		{
			killer->delete("family");
			killer->set("title","��ͨ����");
			killer->delete("class");
			victim->delete_temp("fighting");
			CHANNEL_D->do_channel(victim, "chat",sprintf("�治�������������ʤ������%s������Գ�ʦ�ˣ��Ӵ������Ż��ɣ�", killer->query("name")));
		}
		else if (killer->query("class") == "bonze" && victim->query("class") == "bonze")
		{
			killer->set("kill_bonze",time());
			killer->delete("family");

			if (link_ob=killer->query_temp("link_ob"))
				killer->set("name",link_ob->query("name"));

			killer->set("title","��ͨ����");
			killer->delete("class");
			CHANNEL_D->do_channel(victim, "chat",sprintf("%s����ı���Լ���ʦ����Ϊ�ҷ��������ݣ����߰ɣ�", killer->query("name")));
		}
	}
}

// �Զ�ʹ�ü���
void auto_skill_perform(object me, object obj)
{
	object weapon, *ob, who, room;
	string weapon_type, skill;
	mixed *file;
	int flag, i, enemy;

	// ÿ����һ�ξͼ���һ��
	me->add_temp("xyzx_skill_perform_doing", -1);

	// if ( !living(me) ) return;
	// if ( playerp(me) ) return; // 2006.11.8 ����ֻ�� NPC �����Զ����⹦
	// if ( !playerp(obj) ) return;
	// if ( me->query_temp("xyzx_auto_skill_perform") ) return; // ʹ���У���ȴ���ɲ���ʹ��
	if ( me->query_temp("xyzx_skill_perform_doing") > 0 ) return;
	if ( !objectp(room = environment(me)) ) return;
	if ( me->query("no_zhineng") ) return; // ����"no_zhineng"����Ҫ���ܻ����ж���ʶ

	// ��־���Զ�ʹ�����⼼���⹦�У����������
	// me->set_temp("xyzx_auto_skill_perform", 1);
	// ���ݶ��ֵĶ�����Ŀ�����ͳ�perform�ļ��ʡ�����Ҫ��Ϊ�˽���ϵͳ������������ܣ�
	enemy = sizeof(obj->query_enemy());
	if ( enemy > 15 ) enemy = 15;
	me->set_temp("xyzx_skill_perform_doing", random(enemy) + 1);

	if ( me->query_skill("force",1) > 50 )
	{
		// �ָ�����
		if ( me->query("jing") < me->query("eff_jing")/2 )
		{
			me->command("exert regenerate");
			return;
		}
		//�ָ���Ѫ
		if ( me->query("qi") < me->query("eff_qi")/2 )
		{
			me->command("exert recover");
			return;
		}
	}
	/////////////////////////////////////////////////////////////////////

	/* һ����������ʹ���ڹ���2006.11.8���� by Wenwu */
	if ( random(100) < 95 )
	{
		weapon_type = "force";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/", -1);
		// ���bin�ļ����Ա㴿����������ʱ��Ч
		if ( !sizeof(file) )
			file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
		if ( sizeof(file) )
		{
			me->command("exert " + file[random(sizeof(file)-1)][0][0..<3]);
			return;
		}
	}

	/////////////////////////////////////////////////////////////////////
	/* �����⹦ʹ�� */

	// ���ʹ�õı���
	if ( me->query_temp("weapon") )
	{
		if ( !objectp(weapon = me->query_temp("weapon")) )
			return;
		weapon_type = weapon->query("skill_type"); // �ж���������
	}
	else
		weapon_type = "unarmed"; // �ж������ޱ���
	// ȡ��ʹ�ñ������ܻ���ּ���
	skill = me->query_skill_mapped(weapon_type);
	// ȡ�ü����⹦�ļ���
	file = get_dir("/kungfu/skill/"+skill+"/", -1);
	// ���bin�ļ����Ա㴿����������ʱ��Ч
	if ( !sizeof(file) )
		file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
	// ����б������ޱ��������⹦������ȭ��
	if ( me->query_temp("weapon") )
	{
		// û�п��õı��������⹦
		if ( !sizeof(file) )
		{
			flag = weapon->query("flag");
			// ����Ƿ�ʹ��˫��������˫�ֶ���������
			if ( !(flag & TWO_HANDED) && ((flag & SECONDARY) && !me->query_temp("secondary_weapon")) )
			{
				weapon_type = "unarmed";
				skill = me->query_skill_mapped(weapon_type);
				file = get_dir("/kungfu/skill/"+skill+"/", -1);
				// ���bin�ļ����Ա㴿����������ʱ��Ч
				if ( !sizeof(file) )
					file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
			}
		}

	}
	// ȭ�źͱ����϶��޿����⹦�����м�
	if ( !sizeof(file) )
	{
		weapon_type = "parry";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/", -1);
		// ���bin�ļ����Ա㴿����������ʱ��Ч
		if ( !sizeof(file) )
			file = get_dir("/binaries/kungfu/skill/"+skill+"/", -1);
	}
	// �м���Ҳ�޿����⹦����Ṧ
	if ( !sizeof(file) )
	{
		weapon_type = "dodge";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/",-1);
		// ���bin�ļ����Ա㴿����������ʱ��Ч
		if ( !sizeof(file) )
			file = get_dir("/binaries/kungfu/skill/"+skill+"/",-1);
	}
	// �п����⹦��ʹ���⹦
	if ( sizeof(file) )
	{
		// ��Ǭ����Ų����50%���ʳ���Ų��
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
				// Ǭ����Ų��ת�ƶ��ֹ���
				me->command("nuoyi " + obj->query("id") + " to " + who->query("id"));
			else
				// Ǭ����Ų�Ʒ������
				me->command("nuoyi " + obj->query("id"));
		}
		else
			// ʹ�����⼼���⹦
			me->command("perform " + weapon_type + "." + file[random(sizeof(file)-1)][0][0..<3]);
	}
	else if ( (me->query_skill_mapped("parry") == "qiankundanuoyi" || me->query_skill_mapped("dodge") == "qiankundanuoyi")
	          && me->query_skill("qiankundanuoyi", 1) > 50
	          && me->query("neili") > 1500
	          && random(100) > 50 ) // �޿������⼼���⹦������Ǭ����Ų�ƣ����Գ���Ų��
	{
		ob = all_inventory(room);
		for ( i = 0; i < sizeof(ob); i++ )
		{
			if ( !living(ob[i]) )
				ob -= ( { ob[i] });
		}
		who = ob[random(sizeof(ob))];
		if ( who != me && random(100) > 50 )
			// Ǭ����Ų��ת�ƶ��ֹ���
			me->command("nuoyi " + obj->query("id") + " to " + who->query("id"));
		else
			// Ǭ����Ų�Ʒ������
			me->command("nuoyi " + obj->query("id"));
	}
	else // ���޿������⼼�ܣ����ֻ�г����ڹ�������
	{
		weapon_type = "force";
		skill = me->query_skill_mapped(weapon_type);
		file = get_dir("/kungfu/skill/"+skill+"/", -1);
		// ���bin�ļ����Ա㴿����������ʱ��Ч
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
