// liangongfang.c 练功房
// by Xiang

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，地下凌乱地放着几个蒲团,几位杀手楼弟子正盘膝坐在上
面打坐。
LONG
	);
	set("exits", ([
                "west" : __DIR__"jiaochang",
	]));
	set("objects", ([
            "/clone/weapon/zhujian" : 2,
            "/d/taohua/npc/jiguan" : 2
			]));

	setup();
	replace_program(ROOM);
}
