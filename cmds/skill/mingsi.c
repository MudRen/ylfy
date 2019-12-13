// respirate.c

#include <skill.h>
// inherit F_CLEAN_UP;
private int mingsi_cost;
int mingsing(object me);
int halt_mingsi(object me);
int main(object me, string arg)
{
	object where = environment(me);
	seteuid(getuid());
	
	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
	if (me->is_busy()) 
		return notify_fail("��������æ���أ�\n");
	if( me->is_fighting() )
		return notify_fail("ս��Ҳ��һ�����У������ܺͷ���������ͬʱ���С�\n");
	if (me->query_skill("spells")<15)
		return notify_fail("�������ѧЩ����������\n");
	if( !arg || !sscanf(arg, "%d", mingsi_cost))
		return notify_fail("��Ҫ�����پ������У�\n");
	if (mingsi_cost < 10)
		return notify_fail("������Ҫ�� 10 �㾫�����ܽ������С�\n");
	if( (int)me->query("jingli") < mingsi_cost )
		return notify_fail("�����ھ������㣬�޷����з�����\n");
	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("����������״��̫���ˣ��޷����о���\n");
        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("����������״��̫���ˣ��޷����о���\n");
	write("������۾���ʼڤ˼��\n");
	me->set_temp("pending/mingsi", 1);
	me->set_temp("mingsi_cost", mingsi_cost);
	message("vision",me->name()+"��ϥ���£���ʼڤ˼�����\n", environment(me),({me}));
	me->start_busy((: mingsing :), (: halt_mingsi :));
	return 1;
}
int mingsing(object me)
{
	int mingsi_cost = (int)me->query_temp("mingsi_cost");
	int fashufali_gain =2*(int)me->query_skill("spells",1);
	if (mingsi_cost < 1)
		return 0;
        if (mingsi_cost < fashufali_gain) fashufali_gain = mingsi_cost;
	if (mingsi_cost>2*fashufali_gain) fashufali_gain = mingsi_cost/2;
	
	me->add("fashufali", fashufali_gain);
	me->set_temp("mingsi_cost", mingsi_cost -= fashufali_gain);
	me->add("jingli", -fashufali_gain);
	if (mingsi_cost > 0)
		return 1;
	me->set_temp("pending/mingsi", 0);
	mingsi_cost = 0;
	message_vision("$Nڤ˼��ϣ�����˫�ۣ�վ��������\n", me);
	if((int)me->query("fashufali") < (int)me->query("max_fashufali") * 2)
		return 0;
	else {
		if ((int)me->query("max_fashufali") > (int)me->query_skill("spells") * 5 +15)
		{
			write("��ķ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
me->set("fashufali", (int)me->query("max_fashufali")*2);	
			return 0;
		}
		else
		{
			me->add("max_fashufali", 1);
			me->set("fashufali", (int)me->query("max_fashufali"));
			write("��ķ��������ˣ���\n");
			return 0;
		}
	}
}
int halt_mingsi(object me)
{
//	mingsi_cost = 0;
	if ((int)me->query("fashufali") > (int)me->query("max_fashufali") * 2)
		me->set("fashufali", (int)me->query("max_fashufali") * 2);
	me->set_temp("pending/mingsi", 0);
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : mingsi [<�ķѡ�����������>]
 
ڤ˼���У����á��������������޷�������������ķ�������ľ���
ת��ɷ�����
HELP
        );
        return 1;
}
