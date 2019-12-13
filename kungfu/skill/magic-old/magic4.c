// ������

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object obj)
{
	int	damage, spells;

        if ((int)me->query_skill("magic-old", 1) < 100)
                return notify_fail(WHT"��ĹŴ�ħ��������죬��ʹ����������ն����\n"NOR);
	message_vision(YEL "\nһ���޴�ĳ������$N"YEL"�����ϴ�����\n" NOR, obj);
	obj->receive_damage("jing", 0, me);
	spells = me->query_skill("spells");
//me->start_busy(0);
	if(obj->is_ghost()==1) {
		message_vision(RED "$N"RED"�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(RED "$N"RED"�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->query("race")=="Ұ��") {
//		kar = obj->query("qi");
//		spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 5);
                damage = damage + random(damage);
//		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 10;
		if(damage != 0) {
			message_vision(RED "$N"RED"��ȫ���������ˣ�\n" NOR, obj);
  		            obj->receive_damage("qi", damage*2);
                            obj->receive_wound("qi", damage/2);               		    
               		obj->receive_damage("jing", damage/3);
	 		COMBAT_D->report_status(obj);
			if( !obj->is_fighting(me) ) {
                		if( living(obj) ) {
                        		if( userp(obj) ) 
						obj->fight_ob(me);
					else
						obj->kill_ob(me);
                		}
                		me->kill_ob(obj);
        		}
		} else 
			message_vision(RED "����$N"RED"����ˣ�\n" NOR, obj);
		return 1;
	}
//	kar = obj->query("qi");
//	spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 3);
                damage = damage + random(damage)+1000;
//	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 10;
	if(damage > 3000) damage = 3000;
	if(random(2)==1) {
		message_vision(RED "$N"RED"��ȫ����������\n" NOR, obj);
		obj->receive_damage("qi", damage*2);
                obj->receive_wound("qi", damage);               		    
 		COMBAT_D->report_status(obj);
		if( !obj->is_fighting(me) ) {
               		if( living(obj) ) {
                       		if( userp(obj) ) 
					obj->fight_ob(me);
				else
					obj->kill_ob(me);
               		}
               		me->kill_ob(obj);
       		}
	} else 
			message_vision(RED "����$N"RED"����ˣ�\n" NOR, obj);
	return 1;
	
}
int perform(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i, full, max_qi, max_jing, eff_qi, eff_jing;

	if ( (int)me->query_skill("spells") < 200 ) return notify_fail("��ķ��������ߣ�\n");
	if ( (int)me->query("neili") < 200 ) return notify_fail("��ķ���������\n");
	if ( (int)me->query("qi") < 500 ) return notify_fail("�������������\n");
	if ( (int)me->query("jing") < 100 ) return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("neili", -500);
	me->receive_damage("jing", 40);
	max_qi = me->query("max_qi");
	eff_qi = me->query("eff_qi");
	max_jing = me->query("max_jing");
	eff_jing = me->query("eff_jing");

	if ( eff_qi < max_qi || eff_jing < max_jing ) 
	{
		full = max_qi/50;
		me->receive_curing("qi", full);
		me->receive_heal("qi", full);
		full = max_jing/50;
		me->receive_curing("jing", full);
		me->receive_heal("jing", full);
		message_vision(HIW "\n�޴������������,$N"HIW"ȫ��������ʥ��Ĺ�â��ȫ����˺���ö��ˣ�\n" NOR, me);
	}
	
	msg = YEL "$N"YEL"�Ų���â�ǣ�˫���ճɷ�ħӡ�������૵��������ģ�\n" NOR;
	msg += RED"$N"RED"� �Ȼƻ軹Ҫ��೵Ķ���,��ѪҺ��Ҫ�ʺ�Ķ���...\n"NOR;
	msg += RED"$N"RED"����� ������ʱ��֮��  �ѵ�������ǰһ���޲��ɼ�������ݻ�...\n"NOR;
	msg += HIR"$N"HIR"���һ��  ����ն!!  �޴�ĵĳ����ֱ�����ܷ�ȥ��������Ŀ���.��\n"NOR;
	message_vision(msg, me);
	env = environment(me);
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) 
	{
		if( !playerp(me) && !playerp(inv[i]) && !inv[i]->fighting(me) ) continue;
		if( inv[i]==me ) continue;
		if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
	}
	me->start_busy(1);
	return 1;
}


