
#include <combat.h>
int help(object me);

int main(object me, string arg)
{
	int pot;
    if( !arg)		pot=30;
	else	if(!sscanf(arg, "%d", pot))			return help(me);
	if (pot<1)	return notify_fail("��û����ô��Ǳ����ת�ƣ�\n");

	if (me->query("jing")*10 < pot )	return notify_fail("��ľ���״̬������ת����ô��Ǳ�ܣ�\n");

    if( ((int)me->query("potential")-(int)me->query("learned_points")) >= pot ){
		me->add("jing",-pot/10);
		me->add("potential",-pot);
		me->add("combat_exp",2*pot);
       	write("OK!\n");
	} else 	write ( "��û����ô��Ǳ����ת�ƣ�\n" );

   return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ :transfer <Ǳ�ܵ�>

      ��Ǳ��ת�ɾ��顣
see also : hp

HELP
    );
    return 1;
}
