
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
	int pts;
        if( !arg || ((arg != "max" && arg!="none") && !sscanf(arg, "%d", pts))) 
          return help(me);
	  if( me->query_condition("no_enforce") )
                return notify_fail("�㵤�ﱻ�ƣ���ʱ���ܼ�����\n");
	if( arg=="none" || me->query("neili") < me->query("jiali") ) //��� ����С��jiali ֮����jiali Ч��������
		me->delete("jiali");
	else {
             if (arg=="max")
                  pts=(int)me->query_skill("force") / 2;
           else
		if( pts < 0 || pts > (int)me->query_skill("force") / 2 )
                  pts=(int)me->query_skill("force") / 2;
		me->set("jiali", pts);
	}
	write("Ok.\n");
	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: enforce <ʹ�����������˵�>|none|max

���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С�
enforce none ���ʾ�㲻ʹ�������� 
enforce max ���ʾ��ʹ������������ 
See Also: enable
HELP
        );
        return 1;
}
