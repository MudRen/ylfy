//make by yixiang
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ҩ������");
        set("long", @LONG
����ҩ�̵����ң������������ҡ�
LONG
        );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([
            "east" : "/d/changan/ca14",
			"south" : __DIR__"danfang1",
			"north" : __DIR__"danfang2",

        ]));


		set("objects", ([
           __DIR__"npc/huatuo" : 1,
		

		]));

        setup();
}
