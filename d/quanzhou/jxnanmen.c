// Room: /d/quanzhou/jxnanmen.c
// Date: May 21, 96   Jay
inherit ROOM;
void create()
{
    set("short", "��������");
    set("long", @LONG
�����Ǽ��˵����š���Χ����ï�ܵ����֡������������
���Ͽ��븣����
LONG
    );
    set("exits", ([
                "north" : __DIR__"jiaxing",
                "east" : __DIR__"tieqiang",
        "south" : __DIR__"qzroad4",
    ]));
    set("outdoors", "quanzhou");
    setup();
    replace_program(ROOM);
}
