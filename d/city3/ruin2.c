// Room: /chengdu/ruin2.c
// oooc: 1998/06/26

inherit ROOM;

void create()
{
        set("short", "丐帮分舵");
	set("long", @LONG
这里是一栋破旧大宅的正厅，北面的墙壁跟屋顶已经整个坍塌
了，凉飕飕的冷风从北边的缺口直灌进来，另你觉得意外的是，这
里清扫得相当整洁，地上用乾草整整齐齐地铺著一个床。
LONG
	);

	set("exits", ([
                "west": __DIR__"ruin1"
	]));
        set("objects", ([
              __DIR__"npc/chen" : 1,
              "clone/food/jitui" : 1,
              "clone/food/jiudai": 1,
        ]));


	setup();
}
