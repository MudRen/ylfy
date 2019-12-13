// Room: /d/dali/huanggong16.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "[1;33m嘉明殿[2;37;0m");
	set("long", @LONG
嘉明殿是大理皇宫供进御膳的所在，与寝宫所在的勤政殿相邻。
四周禁卫亲从、近侍中贵，提警得甚是禁严。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"huanggong17",
  "north" : __DIR__"huanggong15",
  "west" : __DIR__"huanggong18",
]));

                 set("objects", ([
                __DIR__"npc/weishi2" : 4,
        ]));

	setup();
}

