// study.c
#include <skill.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	int n=1,all=0;
	string zhao_name,id;
	mapping skill;
	int my_skill, cost;
	reset_eval_cost();
	
	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (!arg)	
		return notify_fail("��Ҫ��ʲô?\n");	
	
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	
	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");
	
	if (sscanf(arg, "%s at all", id)==1 )
	{
		if(!id || !objectp(ob = present(id, me)) )
			return notify_fail("��Ҫ��ʲô��\n");
		
		all = 1;
	}
	else 
	{
		if(!arg || !objectp(ob = present(arg, me)) )
			return notify_fail("��Ҫ��ʲô��\n");
	}

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("���޷�����������ѧ���κζ�����\n");
	
	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
	
	if ( sscanf(base_name(ob),"/u/%*s") )
		return notify_fail("�����Ʒδ��QC,������õ���?С�ı�ɱ��!\n");
	
	message("vision", me->name() + "��ר�ĵ��ж�" + ob->name() + "��\n", environment(me), me);
	
	/*if( (int)me->query("combat_exp") < skill["exp_required"] ) 
	{
		write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
		return 1;
	}*/
	
	if ( skill["difficulty"] - (int)me->query_int() > 0 )
		return notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
	
	if( !SKILL_D(skill["name"])->valid_learn(me) ) 
		return 0;
	
	cost = skill["jing_cost"] + skill["jing_cost"] * (skill["difficulty"] - (int)me->query_int()) / 12;
	
	if (cost < 1) cost = 1; // minimum cost
	
	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) 
	{
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1;
	}

	if( !me->query_skill(skill["name"], 1) ) 
		me->set_skill(skill["name"], 0);
	
	my_skill = me->query_skill(skill["name"], 1);

	if( (int)me->query("jing") > cost ) 
	{
		n = (int)(me->query("jing") / cost);

		if ( n > 100000)
			n = 100000;

		/*if( (string)SKILL_D(skill["name"])->type()=="martial" 
			&& my_skill * my_skill * my_skill / 20 > (int)me->query("combat_exp") )
		{
			printf("Ҳ����ȱ��ʵս���飬���%s������˵�Ķ��������޷���ᡣ\n", ob->name());
		}
		else*/
		{
			if( !me->query("env/block_study_msg") && zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill) )
				printf("���ж��й�%s�ļ��ɣ��ԡ�%s����һ���ƺ���Щ�ĵá�\n", to_chinese(skill["name"]), zhao_name);
			else
				printf("���ж��й�%s�ļ��ɣ��ƺ��е��ĵá�\n", to_chinese(skill["name"]));
			
			if (all == 1 )
			{
				me->improve_skill(skill["name"], n * random((int)me->query_skill("literate", 1) / 2) + 1);
				me->receive_damage("jing", n * cost );
			}
			else 
			{
				me->improve_skill(skill["name"], random((int)me->query_skill("literate", 1) / 2) + 1);
				me->receive_damage("jing", cost );
			}
		}
	}
	else
	{
		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}
	
	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: study <��Ʒ����>
���ָ��ʹ�����ͨ���Ķ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: �㲻���Ǹ�����ä����
see also : learn
HELP
   );
   return 1;
}
