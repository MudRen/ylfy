//Room:/d/lingshedao/xiaowu.c
inherit ROOM;
void create()
{
        set("short", "Сé��");
        set("long", @LONG
�����谵����,��Ȼ��յ�͵�Ҳû��.����ĳ���
Ҳ�ǳ���ª,ֻ��һ��,һ��,һ������.
LONG );
        set("exits", ([
                "out"    : __DIR__"xiaowuout",
        ]));
        set("objects",([
                __DIR__"npc/xiexun" : 1,
        ]));
        //set("no_clean_up",0);
//        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
