//Room /d/honghua/shanxia.c
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","Ͽ��");
	set("long",@LONG
������һ��Ͽ�ȣ�����ʯ�ڶ�Ȼ�����������õ����ɣ�̧ͷ����
��ֻ����ɫ��������������Ǳ�ں�������һ�㡣Ͽ����ʯȫϵ��ڣ�
�ڹⷢ������·������ȥ���쳣���ۡ�
LONG
	);
	
	set("outdoor", "honghua");	

	set("exits", ([
		"south" : __DIR__"caoyuan",
		"north" : __DIR__"xinxin-xia",
	]));

	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",70);
	set("coor/z",0);
	setup();
}
