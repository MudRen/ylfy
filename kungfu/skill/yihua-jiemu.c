// yihua-jiemu.c �ƻ���ľ
// by King 97.05

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string  *msg_weapon = (
{
	YEL"$N����һ�ӣ�����б$w"YEL"���ƣ����ϵ���ô����һ��֮�����ػ�����������˴�����Ѱ����\n"NOR,
	RED"��֪$N��$W"RED"΢ת��ƽƽ�Ĵ���$w"RED"֮�ϣ�һ����͵ľ����ͳ�����$w"RED"ֱ���˿�ȥ��\n"NOR,
	HIY"$N����̤������������$W"HIY"�ӳ���һ�ɾ�������$n�ĺ��ģ���λʱ�������ǡ���ô���\n"NOR,
	HIC"$n��������һ�У�ԭ�Ǽ�����������������$N��ָһ����������ббж�˿�ȥ��\n"NOR,
	BLU"$N��$n��$w"BLU"��Ҫ�����Ŀ�ʱ������ͻȻ�߳���ѹ��$w"BLU"��һ����˳��̤�䣡\n"NOR,
	HIB"$N˫��ͬʱʩչ�ƻ���ľ�ķ���һ����Х����������ڰ��������һ��ת�ۣ�ƮȻ����$n���ԣ�\n"NOR,
	HIW"$n�书��ߣ�����$N��������Ϯ�����������$w"HIW"��Ҳ���Բ��$N��$W"HIW"��ʽ��\n"NOR,
	YEL"$N������ָ���縧�ٹ�ɪ�������������������������㲻����Ƭ�̼佫$n����������ж�ˣ�\n"NOR,
	GRN"$N�Ҵ��һ��̩ɽ������������Ȫ��������ȴ��ʹ���ƻ���ľ���ַ�������$n����$w"GRN"��\n"NOR,
	CYN"$N����$W"CYN"������$n$w"CYN"���ϣ������������ƻ���ľ�ķ���΢һ�˾����㽫$n�ľ��������ƿ��ˣ�\n"NOR,
});

string  *msg_unarmed = (
{
	HIC"һɲ�Ǽ�$N����Ϊ��ļ���ת�ۣ���ʹ�����ƻ���ľ�ķ��ĵ��߲��񹦣�\n"NOR,
	HIW"$N��Ҳ��������$n������ǰ���ƻ���ľ����б������$n����Ų����ж�˿�ȥ��\n"NOR,
	GRN"��֪�ո��ഥ��ͻȻһ����Ͷ����صľ�����$N���Ϸ�������ס��$n�ľ�����ͬʱ��$N������ָҲ�Ѱ���$n�ؿ�����Ѩ�����⣡\n"NOR,
	RED"���$Nʹ���ƻ���ľ�ķ������Ű��Է�λ��������$n���е�ȥ�ơ�\n"NOR,
	CYN"$N��ʹ�ƻ���ľ��Խ��Խ�죬�����������Ƶ磬���������ǰ������̽��ץ��$n��\n"NOR,
	BLU"$N��ʱ����������ת��һ����������Ȼ��Ȼ������������֮$n�����������ִ�ö��ˣ�\n"NOR,
	BLU"$n����һָ����$N��ͷ��ȴ��֪��α�����һ�����۵�һ�죬���������Լ��ֱۣ�ֻʹ����ǰ����ֱð��\n"NOR,
	YEL"���������Ա���һ��������������$n������һ������$N����бб������\n"NOR,
	YEL"$N����Ǳ���ƻ���ľ�ķ���ʹ$n����$N��һ��Ī��������ﻬ��һ�ԡ�\n"NOR,
	HIR"$N��ʹ�ƻ���ľ�ķ���һǣһ�����е�һ�죬��$n��������ƫ��\n"NOR,
	YEL"$N������ָ���縧�ٹ�ɪ�����������������Σ������㲻������$n���л������Σ�\n"NOR,
	WHT"$N�����ƻ���ľ�ķ���ʹ$n����Ī�����������;ת�˷��������������Σ�\n"NOR,
	CYN"�ƻ���ľ�񹦱�ã��εȰ�����$N��ָ�������ѵ�����$n˫��Ѩ����\n"NOR,
	GRN"$Nʹ���ƻ���ľ��$n����Ī�����������;ת�˷��򣬴�����������Լ����˻�����\n"NOR,
});
string *parry_msg = (
{
	"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ������������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
	"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
	"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
	"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

string *dodge_msg = (
{
	"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ������������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
	"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
	"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
	"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage)
{
	return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_teach(object me)
{
	if ((int)me->query_skill("yihua-jiemu", 1) > 1)
		return notify_fail("�ƻ���ľ���ƻ�����������,�����������ӡ�\n");
	return 1;
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
        return notify_fail("�������̫���ˣ��������ƻ���ľ��\n");
    if ((int)me->query_skill("mingyu-shengong", 1) < 120)
        return notify_fail("���ڤ���񹦻��̫ǳ���������ƻ���ľ��\n");
    me->receive_damage("qi", 30);
    return 1;
}
int valid_learn(object me)
{
	int lvl = (int)me->query_skill("yihua-jimu", 1);

	if ( !wizardp(this_player()) && (me->query("family/family_name") != "�ƻ���"))
		return notify_fail("�㲻���ƻ������Ӳ���ʹ��ڤ����.\n�ƻ���ľ������, ���ƻ������Ӳ���, �治֪��������ôѧ���!\nҪ������λ����֪������ɲ���.\n");

	if ( me->query("gender") != "Ů��")
		return notify_fail("�ƻ���ľ���ƻ�����������,�����������ӡ�\n");

	if ((int)me->query_skill("mingyu-shengong", 1) < 180)
		return notify_fail("���ڤ���񹦻���������ô��ѧ�ƻ���ľ�أ�\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("����ô������ڹ�����ѧ�ƻ���ľ��\n");

	if ((int)me->query("max_neili", 1) < 15000)
		return notify_fail("����ô����������ѧ�ƻ���ľ��\n");

	if ((int)me->query_skill("force", 1) < lvl)
		return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yihua-jiemu/"  + action;
}

int ob_hit(object ob, object me, int damage)
{
	object wp,wp1;
	string msg;
	int p,j,skill, neili, neili1, exp, exp1;
	int level2,damage2;
	wp = me->query_temp("weapon");
	wp1 = ob->query_temp("weapon");
	neili = me->query("neili");
	neili1 = ob->query("neili");
	exp = me->query("xyzx_sys/level");
	exp1 = ob->query("xyzx_sys/level");

	level2= (int) me->query_skill("mingyu-shengong",1);
	skill = me->query_skill("yihua-jiemu", 1);
	neili = me->query("neili");
	neili1 = ob->query("neili");

	damage2= (int) ob->query("neili",1)/10;
	if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "mingyu-shengong" )
	{
		j = -damage/2;
		j = 0;
		if (damage2> 10000)	damage2=10000;
		if (damage2 < 0 ) damage2=0;
		msg = HIC+"$N����ڤ���� ȫ���������������ֳ�һ������ľ���! !\n" +NOR;
		message_vision(msg, me, ob);
		if ( me->is_busy())
		{
			me->start_busy(1);
			ob->start_busy(2);
		}
		if (me->query("neili") > me->query("max_neili")*2)
		{

			me->add("neili", damage2);
		}

	}

	if (random(me->query_skill("mingyu-shengong",1)) > 120
	        && me->query("neili") < me->query("max_neili")
	        && me->query_skill_mapped("force") == "mingyu-shengong")

	{
		message_vision(HIR"$N����ڤ���񹦣�ȫ������ԴԴ���ϵ�ӿ��!\n"NOR,me, ob);
		me->add("neili",random(me->query_skill("jiuyang-shengong",1))+200);
	}

	if (random(me->query_skill("mingyu-shengong",1)) > 120
	        && me->query("qi") < me->query("max_qi")
	        && me->query_skill_mapped("force") == "mingyu-shengong"
	        && random(2)==0
	   )
	{
		message_vision(RED"$N����ڤ���񹦣����ϵ��˺��˺ܶ�!\n"NOR,me, ob);
		me->add("qi",random(me->query_skill("mingyu-shengong",1))+380);
		if (me->query("eff_qi") < me->query("max_qi"))
			me->add("eff_qi",random(me->query_skill("mingyu-shengong",1))+380);
	}

	if (random(me->query_skill("yihua-jiemu",1)) > 120
	        && me->is_busy()
	        && me->query_skill_mapped("force") == "mingyu-shengong"
	        && random(3)==0)
	{
		message_vision(HIC"$N�����ƻ���ľ������æ�ҵĶ�����������!\n"NOR,me, ob);
		me->start_busy(1);
	}
	
	if(me->query_temp("fanzhen"))
	{
		me->delete_temp("fanzhen");
		return 1;
	}
	if(me->query("jiali") && living(me) &&
	        random(exp) < exp1/3 && skill > 50 && neili > 500 && living(ob)
	        && !ob->query("env/invisibility")
	        && me->query_skill_mapped("force") == "mingyu-shengong"
	  )
	{
		if(random(2)==1) me->add_temp("fanzhen", 1);
		me->add("neili", -(random(10)));
		if(wp && wp1 && userp(me))
		{
			msg = msg_weapon[random(sizeof(msg_weapon))];
			msg = replace_string(msg, "$W", wp->name());
			msg = replace_string(msg, "$w", wp1->name());
			if(neili >= neili1*2+damage)
			{
				if(random(me->query_str(1)) > ob->query_str(1)/2 && skill > 150)
				{
					msg += HIW"���$nһ���ֵ���ס������"+wp1->name()+HIW"���ַɳ���\n"NOR,
					       me->add("neili", -50);
					wp1->unequip();
					wp1->move(environment(ob));
					j = -5000;
				}
				else
				{
					if (damage>50)
					{
						ob->receive_damage("qi", damage/2?damage/2:10, me);
						ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
					}
					p = ob->query("qi")*100/ob->query("max_qi");
					msg += damage_msg(damage/2, "�˺�");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					j = -5000;
				}
			}
			else if(neili >= random(neili1)*2+damage)
			{
				msg += "���������ж����$n��������\n";
				j = -5000;
			}
			else
			{
				j = damage/2+random(damage/2);
				if(j<damage/2) msg += "���ж����һЩ$n��������\n";
				else msg += "���ж����$n����������\n";
				j = -j;
			}
			message_vision(msg, me, ob);
			return j;
		}
		else
		{
			msg = msg_unarmed[random(sizeof(msg_unarmed))];
			if(neili >= neili1*2+damage)
			{
				if (damage>50)
				{
					ob->receive_damage("qi", damage/2?damage/2:10, me);
					ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
				}
				p = ob->query("qi")*100/ob->query("max_qi");
				msg += damage_msg(damage, "����");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				j = -5000;
			}
			else if(neili >= random(neili1)*2+damage)
			{
				msg += "���������ж����$n��������\n";
				j = -5000;
			}
			else
			{
				j = damage/2+random(damage/2);
				if(j<damage/2) msg += "���ж����һЩ$n��������\n";
				else msg += "���ж����$nһ���������\n";
				j = -j;
			}
			message_vision(msg, me, ob);
			return j;
		}
	}
}