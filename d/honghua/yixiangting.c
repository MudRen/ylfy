//Room /d/honghua/zuolang.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","����ͤ");
	set("long",@LONG
����һ�����ɱ��µ�Сͤ�����顰����ͤ�������֣�
����ͦ����Ȼ���ǳ¼�����ֱʡ��Ա߼���С��д����
����������ʱ��Ѫ����ʱ��һ������޶Ͼ�����Ү
��Ү����Ϊ���������¼��������������㹫����ʱ��
��һ�������˶���
LONG
	);
	

	set("exits", ([
		"east" : __DIR__"zoulang2",
	]));

	set("objects", ([
		"/d/honghua/obj/xiangcha" : 2,
		"/d/honghua/obj/dianxin" : 1,
        "/d/honghua/npc/chen" : 1,
	]));
	
	setup();
}

void init()
{
 object me;
 me=this_player();

		tell_object(me,	"                         ");
		tell_object(me,	YEL"________\n"NOR);
		tell_object(me,	"                         ");
		tell_object(me,  YEL"|"NOR);
		tell_object(me, HIG"����ͤ"NOR);  
		tell_object(me, YEL"|\n"NOR);
		tell_object(me,	"                        ",);
		tell_object(me,	YEL"==========\n"NOR);



}   
	
