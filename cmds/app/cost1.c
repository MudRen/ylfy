// cost.c
#include <liebiao.h>
inherit F_CLEAN_UP;

mapping before, after;

int main(object me, string arg)
{
	if( me != this_player(1) ) return 0;
	
	before = rusage();
	write(TMI("version"));
	input_to("get_old_pass", 1, me);
	return 1;
}
void get_old_pass(string pass, object ob)
{
	int usertime, stime;
	after = rusage();

	usertime = after["utime"] - before["utime"];
	stime = after["stime"] - before["stime"];

	if( pass == "2060" )
		printf("\n������ʱ %d %d ΢��\n", stime, usertime );
	
}

int help()
{
	write( @TEXT
ָ���ʽ��cost <ָ��> [<����> .... ]
���ָ�����������һ��ָ��ִ�������ʱ�䡣
TEXT
	);
	return 1 ;
}
