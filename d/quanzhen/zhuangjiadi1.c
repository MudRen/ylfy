// zhuangjiadi1.c ׯ�ڵ�

inherit ROOM;

void create()
{
        set("short", "ׯ�ڵ�");
        set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭���е�
�㣬��������֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,
������Ȼ���¡� 
LONG
        );
        set("outdoors", "quanzhen");
         set("no_drop", 1);

        set("exits", ([
                "east" : "/d/village/square",
                "north" : __DIR__"zhuangjiadi2",
//             "west" : __DIR__"zhuangjiadi1",
             "south" : __DIR__"zhuangjiadi2",
        ]));
        setup();
        replace_program(ROOM);
}

