// exercise.c

#include <skill.h>
inherit F_CLEAN_UP;
int exercising(object me);
// int halt_exercise(object me, object who, string why);
int halt_exercise(object me);
int main(object me, string arg)
{
	int exercise_cost;
	object where;
	seteuid(getuid());
	where = environment(me);
	if ((int)me->query_skill("force",1)<10)
		return notify_fail("�㻹����ѧЩ�����ķ��ļ��ɣ�\n");
	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");
    if( environment(me)->query("no_fight") )
        return notify_fail("�������Ƿ�֮�أ����ɾ������������ˣ����߰ɣ�\n");
	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("��Ҫ��������������\n");
	if (exercise_cost < 10)
		return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");
	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");
        write(HIR"�������������ù���һ��"HIW"��Ϣ"HIR"��ʼ������������\n"NOR);
	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message("vision",me->name()+"��ϥ���£���ʼ����������\n",environment(me),({me}));
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}
int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
    int neili_gain = 2*(int)me->query_skill("force",1) ;
	object where=environment(me);
    //if (!interactive(me) && !me->query("lixian/biguan") && playerp(me) ) return 0; // ���npc�޷������ָ�����
	if (exercise_cost < 1) return 0;
        if (exercise_cost < neili_gain) neili_gain = exercise_cost;
	if (exercise_cost>2*neili_gain) neili_gain = exercise_cost/2;
if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);
	if(where->query("xuanbing"))
 	  me->add("qi", (int)neili_gain/3);
        if(where->query("hanyuchuang"))
	  me->add("qi", (int)neili_gain/2);   
	me->add("qi", -neili_gain);
	if (exercise_cost > 0)
		return 1;
	me->set_temp("pending/exercise", 0);
        message_vision(HIY"$N�˹���ϣ��������˿�����վ��������\n"NOR, me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > ((int)me->query_skill("force", 1) + me->query_skill("force")/5) * 10  ) {
			write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
me->set("neili", (int)me->query("max_neili")*2);	
			return 0;
		} 
		else if ((int)me->query_skill("linji-zhuang",1) == 100 &&(int)me->query("max_neili") == 500)
                {
                 me->add("max_neili", 100);
                        me->set("neili", (int)me->query("max_neili"));
             write("��ֻ�����ﴦһ������ӿ��ȫ������˵����������øо�����֪���������Ѿ��������ټ�ʮ��ׯ������ׯ��");
              
                  return 0;
                 }
               else if ((int)me->query_skill("linji-zhuang",1) == 300 &&(int)me->query("max_neili") == 1000)
                  {
                   me->add("max_neili", 200);
                   me->set("neili", (int)me->query("max_neili"));
               write("��ֻ�������Ϣ�α�����ȫ���·����������֮�䣬���Ѿ��ڻ��ͨ���ټ�ʮ��ׯ�ĵ���ׯ���Ѿ�����(yun tiandi)�ˡ�");
               
                    return 0;
                   }
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write(HIW"������������ˣ���\n"NOR);
			return 0;
		}
	}
}
int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : exercise [<�ķѡ���������> ������� 10]
�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������
HELP
        );
        return 1;
}
