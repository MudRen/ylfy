// yuxudong.c ���鶴 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���鶴");
	set("long", @LONG
��ǰ��һ������Ȼ�����˹���ɽ�������ܵ��ż�յ�����ƣ����з���һ�����ӣ���
����⼸���顣�������ҵķ����߸����˴����õ����š������ϸ�Ĺ۲�һ�£���
��е����еİ������ʲô������
LONG
	);
       
	set("exits", ([
		"out" : __DIR__"yadi",
	    ]));
	set("objects",([
	     __DIR__"npc/chongyang":1,
	     ]));
	setup();
	replace_program(ROOM);
}



