// Room: /d/city/shangchang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�����̳�");
	set("long", @LONG
������Ϧ��������֯���Ʋ��Խ�������,��"��"³��߻��˽�.�ܶ཭������	
�����⹺����ɵ��������ܸ��õع����Լ�������.	
LONG
);
//   set("no_fight",1);	
	set("exits", ([ /* sizeof() == 1 */
		"south" : "/d/city/ximen",
]));
set("objects", ([
	__DIR__"npc/luban" : 1,
]));

	setup();
	replace_program(ROOM);
}
