// roar.c ��Ȼ������

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if( (int)me->query("neili") < 500 )
                return notify_fail("�㳤̾һ�����������һ����\n");
 
        if((string)me->query("family/family_name") != "��Ĺ��" )
                return notify_fail("���ֲ��ǹ�Ĺ���ӣ���ô������˸������Ů�ľ�? \n");

        if((int)me->query_skill("yunv-xinjing", 1) < 180)
                return notify_fail("�����Ů�ľ���Ϊ��������! \n");        

        skill = me->query_skill("force");

        me->add("neili", -150);
        me->receive_damage("qi", 30);

        me->start_busy(3);
        message_vision(
   BLINK MAG "\n $N���ָ��أ�����������һ������Ȼ���꡹,����һ��������������˵����������о�ȻƯ�Ʋ�����\n" NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me )
                        continue;

                if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
                        continue;

				if( !me->is_killing(ob[i]) )
					me->fight_ob(ob[i]);
				
				if( !ob[i]->is_killing(me) )
					ob[i]->kill_ob(me);

                damage = skill - ((int)ob[i]->query("max_neili") / 11);
                if( damage > 0 ) {
                        ob[i]->receive_damage("jing", damage);
                        if( (int)ob[i]->query("neili") < skill * 2 )
                                ob[i]->receive_wound("jing", damage);
                tell_object(ob[i], "���Ȼ����һ�����������������������Ư�Ʋ�����\n");
                }
        }

return 1;
}

