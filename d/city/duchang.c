// Room: /city/duchang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ����������Ƕġ���С��
�ķ��䣬�����Ƕġ����ӡ��ķ��䣬��¥�ǹ�����
LONG
	);
	set("exits", ([
		"up" : __DIR__"duchang2",
        "down" : __DIR__"caipiao",	
		"east" : __DIR__"nandajie1",
		"west" : __DIR__"duchang3",
        "north" : __DIR__"duchang4",
         "south" : __DIR__"bobing",	
	]));
	setup();
}
int valid_leave(object me, string dir)
{
if (dir != "east" && dir != "down" && this_player()->query("age")<18)	
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");
        return ::valid_leave(me, dir);
}
