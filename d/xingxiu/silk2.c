// /d/xingxiu/silk2.c
// Jay 3/17/96
inherit ROOM;
void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵����������������ɽ���������������
������һ���������������ԭ��������ͨ������
LONG
        );
        set("outdoors", "xingxiuhai");
        set("exits", ([
                "east" : __DIR__"silk1",
                "north" : "/d/mingjiao/luzhou",
        "northwest" : __DIR__"silk3",
        ]));
        setup();
        replace_program(ROOM);
}
