// surrender.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	
	if( !me->is_fighting() )
		return notify_fail("Ͷ��������û�����ڴ��㰡....��\n");
	ob = me->query_temp("last_opponent");
	if (!ob)
		return notify_fail("Ͷ��������û�����ڴ��㰡....��\n");
	if(living(ob))
	if ( ob->is_killing()) {
		message_vision(RED "$N��$n���ģ�����$n����˵����"
			+ RANK_D->query_rude(me) + "�ϻ���˵����������\n " NOR, me,ob);
		return notify_fail("�������˲���Ź��㰡....\n");
	}
        me->remove_enemy(ob);
        ob->remove_enemy(me);
        ob->remove_killer(me);
        me->remove_killer(ob);
	if (ob->query_leader()==me)
		ob->set_leader(0);
if( (int)me->query("weiwang") >= 100 )	
		me->add("weiwang", -10 );
	message_vision( HIW "\n$N˵�����������ˣ������ˣ���Ͷ��....����\n\n" NOR, me);
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : surrender
 
���ָ��������������Ͷ������ֹս�������ǣ������ή����Ľ���������
 
HELP
    );
    return 1;
}
 
