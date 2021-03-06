// breakup.c
//重新编译

#include <ansi.h>
inherit F_CLEAN_UP;	

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        
        object where;
      
        seteuid(getuid());
        where = environment(me);

		if ( !interactive(me) ) return 0;

		if ( arg == "-stop" )               	
        {
			if ( me->query_temp("breakuping") )
			{
				me->delete_temp("breakuping");
				BIGUAN_D->del_breaking_user(me);
				message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);
				message("chat", HIY"【镜花水月】"+HIM"听说"+me->query("name")+HIM"闭关中途突然复出,似乎没有太大的进展！\n"NOR,users() );
				return 1;
			}
			else
				return notify_fail("你现在并没有运功冲穴。\n");	
        }
        
        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

        if (me->query("breakup"))
                return notify_fail("你已经打通了任督二脉了，似乎没有必要再来一次。\n");

        if (me->query_temp("breakuping", 1))
                return notify_fail("你现在正在运功冲穴，试图打通任督二脉!\n");		

        if (where->query("no_fight"))	
                return notify_fail("在这里不能运功行气,无法打通任督二脉!\n");	

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if (me->query("potential") < 10000)              	
                return notify_fail("你的潜能不够，没法闭关修行以打通任督二脉。\n");

        if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
                return notify_fail("你现在的气太少了，无法静心闭关。\n");

        if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
                return notify_fail("你现在的精太少了，无法静心闭关。\n");

        if ((int)me->query("max_neili") < 150000)   	
                return notify_fail("你觉得内力颇有不足，看来目前还难以打通任督二脉。\n");

        if ((int)me->query("neili") * 100 / me->query("max_neili") < 90)
                return notify_fail("你现在的内力太少了，无法静心闭关。\n");

        if ((int)me->query_skill("force", 1) < 1000)	
                return notify_fail("你觉得自己的内功火候还有限，看来需要先锻炼好内功才行。\n");

        message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
        me->start_busy(5);                     	
        message("chat", HIY"【镜花水月】"+HIM"听说"+me->query("name")+HIM"开始闭关修行,试图打通任督二脉！\n"NOR,users() );	
		BIGUAN_D->add_breaking_user(me);
        
		return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : biguan

闭关修行以打通任督二脉，需要非常深厚的内力和内功功底才能做到。
而且会消耗潜能。一旦打通了任督二脉可以同时扩展精、气、精力、
内力的上限。
如你想中断闭关修行，输入
biguan -stop
就可以了。
HELP );
        return 1;
}
