// wdroad4.c
// by Xiang
inherit ROOM;
void create()
{
    set("short", "��ʯ���");
    set("long", @LONG
    ������һ����ʯ����ϣ����ܾ����ĵġ�
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "east" : "/d/xiaoyao/shulin3",
        "south" : __DIR__"wdroad5",
        "north" : __DIR__"wdroad3",
"southup" : "/d/henshan/hsroad1",	
    ]));
    setup();
    replace_program(ROOM);
}
