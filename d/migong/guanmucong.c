#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "��ľ��");
    set("long", @LONG
  ����һƬï�ܵĹ�ľ�ԣ�����������������ľ�����ⶼ�ڵ�ס�ˣ�
��ȫ�ֲ��嶫���������������ʱ����Ұ�޵ͳ��ĺ������
LONG);
    set("exits", ([
	    "north" :"/d/migong/senlin/senlin500",
		"east" : "/d/migong/senlin1/senlin300",
		"south" : "/d/migong/migong1.c",
		]));
	set("no_clean_up", 0);
	setup();
}
