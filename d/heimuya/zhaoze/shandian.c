// Room: /d/heimuya/zhaoze/shandian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "山巅");
	set("long", @LONG
又走了一阵，过了两个急滩，一转弯，眼前景色如画，清溪潺潺，水
流平稳之极，几似定住不动。那溪水宽约丈许，两旁垂柳拂水，绿柳之间
夹植着无数桃树，若在春日桃花盛开之时，想必是一片锦绣，繁华耀眼。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"penquan",
  "northdown" : __DIR__"pubupang",
]));
	set("outdoors", "shandian");

	setup();
	replace_program(ROOM);
}
