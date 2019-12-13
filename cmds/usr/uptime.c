// uptime.c
#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
int main()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = HIR+chinese_number(d) + "��"NOR;
	else time = "";

	if(h) time += HIR + chinese_number(h) + "Сʱ";
           if(m) time += HIR+ chinese_number(m) + "��";       	
//   if(m) time += HIB+ "???" + "��";       	
           time += chinese_number(s) + "��";	
//   time += CYN"???" + "��";        	

write( HIC"��"BBLU HIY"������ӡ"NOR HIC"��"NOR + "�Ѿ�������"+time+NOR"\n");	
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : uptime
 
���ָ���������������Ϸ�Ѿ�����ִ���˶��.
 
HELP
    );
    return 1;
}
