// square.c
inherit ROOM;
void create()
{
    set("short", "���䳡");
    set("long", @LONG
�����ǻ�ɽ�ɵ����䳡��ͨ������໪ɽ�ɵ����ڴ�ϰ������������
����ӭ���ˡ����ߵķ������Ϲ���һ���ң����顸������Ϊ������������
��ɽ�ɵ��Ӵ�ű����ĵط���
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"yunu",
        "north" : __DIR__"buwei1",
        "east" : __DIR__"bingqifang",
        "west" : __DIR__"xiaodian",
    ]));
    set("objects", ([ 
        __DIR__"npc/shidaizi"   : 1,
        CLASS_D("huashan")+"/yue"  : 1,
    ]));
    //set("no_clean_up", 0);
    //set("outdoors", "huashan" );
    setup();
        "/clone/board/huashan_b"->foo();
    replace_program(ROOM);
}
