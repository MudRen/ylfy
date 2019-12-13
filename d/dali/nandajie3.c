// Room: /d/dali/nandajie3.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "南城门");
	set("long", @LONG
大理南门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳头般大小的
柳钉。门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧帖满了悬赏捉
拿之类的官府通谍(gaoshi)。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"nandajie2",
	  //"west" : __DIR__"work3",
	 // "east" : __DIR__"work7",
  "south" : "/d/tianlongsi/dadao4",
]));

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n大理知府\n陈明镜\n";
}

