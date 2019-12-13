// hunpofeiyang.c ���Ƿ���

#include "/kungfu/skill/eff_msg.h";
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
void remove_effect(object target);
string *songs = ( {"����֮��������","�����˷δݸγ�","���뾫ʧ����","������������Ƿ���"});

int perform(object me)
{
	int extra;
	object target;
	string msg, song;
	int p;
	song = songs[random(sizeof(songs))];

	me->clean_up_enemy();
	target = me->select_opponent();

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����Ƿ��ֻ����ս����ʹ�á�\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("��������������ߣ�\n");

	if( (int)me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷�ʹ�û��Ƿ��\n");

	if( (int)me->query_skill("qishang-quan", 1) < 2600)
		return notify_fail("������ȭ����Ϊ����������ʹ�û��Ƿ���! \n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 1000 )
		return notify_fail("�㱾���ڹ���򲻹���ʹ���������Ƿ����\n");

	if(target->query_temp("qishang"))
		return notify_fail("�Է��Ѿ����ܡ������ܾ������㲻�÷Ѿ��ˣ�\n");

// not tiezhang-zhangfa, should be qishang-quan (by xbd)
	extra = me->query_skill("qishang-quan",1) / 2;
	extra += me->query_skill("force",1) /2;
	me->add_temp("apply/attack", (extra*4));
	me->add_temp("apply/damage", (extra*5));
	msg = HIY "$N���һ����ʹ������ȭ�ľ��������Ƿ����˫ȭ������������$n��ȥ��\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add_temp("apply/attack", -(extra*4));
	me->add_temp("apply/damage", -(extra*5));

	if (userp(me))
	{
		message_vision(HIR"\nͻȻ$N���侫�⣬����������Ƹ�Ǹ衢��ʫ��ʫ��ȭ������"+song+"������������ǰȥ�����һȭ����$n��\n"NOR,me, target);

		if (random((int)me->query("xyzx_sys/level")) > (int)target->query("xyzx_sys/level")/3 )
		{
			target->receive_damage("qi", me->query_skill("force"));
			target->receive_wound("qi", me->query_skill("force"));
			me->add("neili", -300);
			me->start_busy(3);
			target->start_busy(1);
			if(me->query("neili")*2 < target->query("neili"))
				tell_object(me, HIR"��ֻ��"+target->name()+"����������ǿ���㰵����ȭ�ڵĸ������������Ͳ���ȥ��\n"NOR);
			else
			{
				tell_object(me, HIW"�ڸ�һ����"+target->name()+"������ʱ����㰵������������������ȭ�ڵ������������˹�ȥ��\n"NOR);
				tell_object(target, HIW"��һ���ۣ�ֻ��"+me->name()+"��ȭ�Ѿ�����������ϣ����ż���˵�����İ���˳�ƴ��˹�����\n"NOR);
				target->set_temp("qishang", 1);
				target->add_temp("apply/strength", -(target->query("str")/2));
				target->add_temp("apply/dexerity", -(target->query("dex")/2));
				target->add_temp("apply/intelligence", -(target->query("int")/2));
				target->add_temp("apply/constitution", -(target->query("con")/2));
				target->apply_condition("qishang_poison", 50+target->query_condition("qishang_poison"));
                target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), me->query_skill("force",1)/2);
			}
			target->receive_damage("qi", me->query_skill("force")*3);
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg = damage_msg(me->query_skill("force")*3, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
		else
		{
			me->start_busy(3);
			me->add("neili", -(100+random(100)));
			msg = "ֻ��$p����һת���Ѿ��Ƶ���$P��󡣶�$Nȴ������ղ��ܿ��ƣ�ͷ��ѣ�Σ�\n";
		}
	}
	message_vision(msg, me, target);
	return 1;
}
void remove_effect(object target)
{
	if(!target) return;
	target->add_temp("apply/strength", target->query("str")/2);
	target->add_temp("apply/dexerity", target->query("dex")/2);
	target->add_temp("apply/intelligence", target->query("int")/2);
	target->add_temp("apply/constitution", target->query("con")/2);
	target->delete_temp("qishang");
	tell_object(target, HIW"���ڣ������Ǽ��ɰ����ڱ鲼���ȫ���ʼ����ɢȥ�ˡ�\n"NOR);
}
