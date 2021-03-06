// info command.
#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;

#define TIME_TICK (time()*60)
mixed main(object me)
{
	object *ob;
	int i,ppl_cnt = 0, cnt = 0, wcnt = 0, f_cnt = 0, u_cnt = 0, i_cnt;

	ob = filter_array(children(USER_OB), (: playerp :));

	i = sizeof(ob);
	while( i-- ) {
            if (wizardp(ob[i]) && ((int)ob[i]->query("env/invisibility")<10)) wcnt++;
		else {
			 if (interactive(ob[i])) 
			{
				 ppl_cnt++;
				 if(query_idle(ob[i]) > 120) i_cnt++;
			}
			 else cnt++;
			 if(ob[i]->is_fighting()) f_cnt++;
			 if(!living(ob[i])) u_cnt++;
			 }
	}

	write("\n"HIM+MUD_NAME+NOR"目前共有 "HIC+wcnt+NOR" 位巫师， "HIG+ppl_cnt+NOR" 位玩家连线中。\n"+
"其中：\n"+
	"       在战斗的有： "HIB+f_cnt+NOR" 位\n"+
	"   昏迷或睡觉的有： "HIY+u_cnt+NOR" 位\n"NOR+
	"         发呆的有： "HIG+i_cnt+NOR" 位\n"+NOR+
	"         断线的有： "HIR+cnt+NOR" 位\n"NOR+
	"系统负担："HIW+query_load_average()+
	NOR"\n现在的 time() 是："HIW + time() + "。\n"NOR);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : users

这个指令可以列出目前的玩家数量。

相关指令： who
HELP
	);
	return 1;
}
