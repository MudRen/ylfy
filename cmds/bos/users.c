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

	write("\n"HIM+MUD_NAME+NOR"Ŀǰ���� "HIC+wcnt+NOR" λ��ʦ�� "HIG+ppl_cnt+NOR" λ��������С�\n"+
"���У�\n"+
	"       ��ս�����У� "HIB+f_cnt+NOR" λ\n"+
	"   ���Ի�˯�����У� "HIY+u_cnt+NOR" λ\n"NOR+
	"         �������У� "HIG+i_cnt+NOR" λ\n"+NOR+
	"         ���ߵ��У� "HIR+cnt+NOR" λ\n"NOR+
	"ϵͳ������"HIW+query_load_average()+
	NOR"\n���ڵ� time() �ǣ�"HIW + time() + "��\n"NOR);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : users

���ָ������г�Ŀǰ�����������

���ָ� who
HELP
	);
	return 1;
}
