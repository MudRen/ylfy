
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
	int pts;
        if( !arg || ((arg != "max" && arg!="none") && !sscanf(arg, "%d", pts))) 
          return help(me);
	  if( me->query_condition("no_enforce") )
                return notify_fail("你丹田被破，暂时不能加力。\n");
	if( arg=="none" || me->query("neili") < me->query("jiali") ) //解决 内力小于jiali 之后还有jiali 效果的问题
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
指令格式: enforce <使出几点内力伤敌>|none|max

这个指令让你指定每次击中敌人时，要发出几点内力伤敌。
enforce none 则表示你不使用内力。 
enforce max 则表示你使用最大的内力。 
See Also: enable
HELP
        );
        return 1;
}
