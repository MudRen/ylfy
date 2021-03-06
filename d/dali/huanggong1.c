// Room: /d/dali/huanggong1.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时39分13秒。

inherit ROOM;

void create()
{
	set("short", "[1;33m圣慈宫[2;37;0m");
	set("long", @LONG
圣慈宫是大理皇宫的前殿，殿上朱梁玉柱，龙盘凤舞，画栋雕栏，
巧夺天工。大殿上挂着一幅南唐李后主绘的「林泉渡水人物」。放眼
望去，宫中金殿林立，金碧辉煌。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"paifang",
  "north" : __DIR__"huanggong2",
]));

	setup();
}

