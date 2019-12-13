// alias.c

inherit F_CLEAN_UP;
#include <ansi.h>;

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs;

	if( !arg )
	{
		alias = me->query_all_alias();
		
		if( !sizeof(alias) )
		{
			write(HIW"��Ŀǰ��û���趨�κ� alias��\n"NOR);
			return 1;
		}
		else 
		{
			write(RED"��Ŀǰ�趨�� alias �У�\n\n"NOR);
			write(HIW"------------------------------------------------\n");
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				printf(HIY"%-15s"NOR" = "CYN"%s\n"NOR, vrbs[i], alias[vrbs[i]]);
			write(HIW"------------------------------------------------\n");
			return 1;
			
		}
		
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
	{
		if ( me->set_alias(arg, 0) )
			write("��ȡ���� "MAG+arg+NOR" ���������\n");
	}
	else if( verb=="alias" )
		return notify_fail("�㲻�ܽ� \"alias\" ָ���趨������;��\n");
	else if( verb=="" )
		return notify_fail("��Ҫ��ʲô alias��\n");
	else
	{
		if ( me->set_alias(verb, replace) )
			write("���� "MAG+verb+NOR" ��ʾ "CYN+replace+NOR" ��\n");
	}
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ : alias <���趨ָ֮��> <ϵͳ�ṩָ֮��>
 
��ʱϵͳ���ṩָ֮����Ҫ����ܳ����ִ�, ��ʹ��ʱ(�����Ǿ����õ���)
�����о�������, ��ʱ��(��)�����ô�һָ���趨�����ԭ��ָ֮�
 
����:
	'alias sc score' ���� sc ȡ�� score ָ�
	'alias' �󲻼Ӳ������г������е����ָ�
	'alias sc' ������ sc ������ָ� (���������Ļ�)
 
���п����� $1, $2, $3 .... ��ȡ����һ���ڶ������������������� $* ȡ��
���еĲ������磺
	'alias pb put $1 in $2'

��ÿ����(��)��
	pb bandage bag

�ͻ�ȡ���ɣ�
	put bandage in bag
	
HELP
);
        return 1;
}
