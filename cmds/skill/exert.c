// exert.c

#include <skill.h>
inherit F_CLEAN_UP;

static string *allow_exert = ({"regenerate", "recover", "suck", "qisuck", "neilisuck", "maxsuck", 
		"jingsuck", "jinglisuck","roar"});

int main(object me, string arg)
{
	object *env;
	string force1, force2, str1, str2;
	int i, flag;
	
	seteuid(getuid());
	
	if( !arg )
		return notify_fail("��Ҫ���ڹ���ʲ�᣿\n");
	
	if( environment(me)->query("no_fight") )
		return notify_fail("�������Ƿ�֮�أ����ɾ������������ˣ����߰ɣ�\n");

	if (me->query("eff_qi") >= me->query("max_qi") && arg == "heal")
		return notify_fail("�����ڲ���Ҫ�˹����ˣ�\n");

	if (me->query("eff_jing") >= me->query("max_jing") && arg == "jingheal")
		return notify_fail("�����ڲ���Ҫ�˹����ˣ�\n");

	if (me->query("jing") >= me->query("eff_jing") && arg == "regenerate")
		return notify_fail("�����ھ������档\n");

	if (me->query("qi") >= me->query("eff_qi") && arg == "recover")
		return notify_fail("��������Ϣ���档\n");

	if (me->query("neili") <= 0)
	{
		if (me->query("neili") < 0)
			me->set("neili",0);
		
		return notify_fail("�������������\n");
	}

	if ( arg != "chong" && me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");
	
	if ( file_name(environment(me)) == "/d/shaolin/bagua" && arg == "roar" )
		return notify_fail("���ﲻ��ʹ���ڹ������޺�\n");

	if ( (sscanf(arg, "%*sroar%*s") || sscanf(arg, "%*sfanchang%*s"))
		&& !wizardp(me) )
	{
		env = all_inventory(environment(me));
		for ( i=0; i<sizeof(env); i++ )
		{
			if ( playerp(env[i]) && env[i] != me && env[i]->query("age") < 18 )
				return notify_fail(HIY"�ֳ���δ��18�������ң�������ʹ�����������»�������ˡ�\n"NOR);
		}
	}

	if ( !me->query("xy_huiyuan") )
	{
		if ( member_array(arg, allow_exert) == -1 )
			return notify_fail(HIY"ֻ�л�Ա����Ӧ���ڹ��ⷽ��Ĺ��ܡ�\n"NOR);
	}
	
	if (sscanf(arg,"%s %s",str1,str2)!=2)
		str1=arg;

	if ( stringp(force1 = me->query_skill_mapped("force")) 
		&& (file_size(SKILL_D(force1)->exert_function_file(str1)+".c") != -1 
			|| file_size("/binaries" + SKILL_D(force1)->exert_function_file(str1)+".b") != -1) )
		force2 = force1;
	else if ( me->query_skill("force", 1) > 0 
		&& (file_size(SKILL_D("force")->exert_function_file(str1)+".c") != -1 
			|| file_size("/binaries" + SKILL_D("force")->exert_function_file(str1)+".b") != -1) )
		force2 = "force";
	else
		return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

	if ( SKILL_D(force2)->exert_function(me, arg) )
	{
		flag = (int)me->query_skill(force2, 1)/500;
		flag += ((int)me->query_skill(force2, 1)/1000);
		if ( (int)me->query_skill(force2, 1) > 1500 )
			flag += (((int)me->query_skill(force2, 1)-1500)/100);
		if ( flag < 1 ) flag = 1;
		if( (int)me->query_skill(force2, 1) < 100 
			&& (int)me->query_skill(force2, 1) < (int)me->query_skill("force", 1) )
			me->improve_skill(force2, random(me->query_con()/flag)+1, 0);
		else
			me->improve_skill(force2, random(me->query_con()/flag)+1, 1);
		
		//ûbusy����busy����ֹ����ϵͳûBusy�ļ��ܲ����������Ч��
		if ( !me->is_busy() && member_array(arg, allow_exert) == -1 )
			me->start_busy(1);

		return 1;
	}
	else
		return SKILL_D(force2)->exert_function(me, arg);
}

int help (object me)
{
        write(@HELP
ָ���ʽ��exert <��������> [<ʩ�ö���>]
����������һЩ���칦�ܣ������Ҫָ��<��������>��<ʩ�ö���>����п��ޡ�
����ʹ��ĳһ���ڹ������칦��֮ǰ����������� enable ָ����ָ����Ҫʹ��
���ڹ���
��ο� help force �ɵ�֪һЩ�󲿷��ڹ����еĹ��ܣ����������õ��ڹ�����
��û�иù��ܣ���һ�Ի�ο�����˵����֪��
ע�������ı��Լ����ڹ�����ԭ�����������������ֱ��ת����ȥ������
    �ӣ���ʼ��
HELP
        );
        return 1;
}
