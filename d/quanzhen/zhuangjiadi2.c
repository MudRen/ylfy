// zhuangjiadi2.c ׯ�ڵ�

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
                "south" : __DIR__"zhuangjiadi1",
                "north" : __DIR__"zhuangjiadi2",
             "west" : "/d/wugongzhen/road1",
        ]));
        setup();
        replace_program(ROOM);
}

