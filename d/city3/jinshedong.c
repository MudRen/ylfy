//bye enter

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����Ǹ������ʯ�ң��и��������ڵ��ϣ��Աߵ���յ�綹
���͵ƣ���������ߣ��㿴��ʯ�����м��ٷ��������̳ɵļ�ª
���Σ�ÿ�����ξ�����ͬ������Ͷ�㣬�������䡣�㰤�ο�ȥ��
�������鶼��ͼ�Σ�������Ϊ���⡣
LONG
        );

        set("exits", ([
                "east" : __DIR__"jinshedong1",
        ]));
        set("objects", ([
//                __DIR__"wenzai/npc/jinshe" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


