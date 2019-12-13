
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
		return notify_fail("ָ���ʽ��enchant <ÿ��ʹ�ü��ɾ���>|none");

	if( !me->query_skill_mapped("taoism") )
		return notify_fail("������� enable һ����ͨ��\n");

	if( arg=="none" )
		me->delete("jiajing");
	else {
		if( pts < 0 || pts > (int)me->query_skill("force") / 2 )
			return notify_fail("��ֻ���� none ��ʾ���þ����������ֱ�ʾÿһ���ü��㾫����\n");
		me->set("jiajing", pts);
	}

	write("Ok.\n");
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: enchant <ʹ�ü��㾫��>|none
 
enchant none ���ʾ�㲻ʹ�þ����� 

See Also: enable
HELP
        );
        return 1;
}
