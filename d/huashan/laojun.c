// laojun.c
inherit ROOM;
void create()
{
    set("short", "�Ͼ���");
    set("long", @LONG
��������Ҫ�������£�������������ЪϢ���Ͼ�����һ������೤��
ɽ�����ഫΪ̫���Ͼ������������Ͼ�����
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "westdown" : __DIR__"baichi",
        "north" : __DIR__"liyubei",
        "southup" : __DIR__"husun",
    ]));
    set("objects", ([ 
        __DIR__"npc/laodenuo" : 1,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "huashan" );
    setup();
    replace_program(ROOM);
}
