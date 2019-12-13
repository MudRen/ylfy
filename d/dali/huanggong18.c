// Room: /d/dali/huanggong18.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "[1;33m御厨房[2;37;0m");
	set("long", @LONG
这里是展中省所属的御厨，厨中烛火通明，几个厨子正忙着为
宫中准备晚餐。看着满屋的满味佳肴，你不由也想叫(serve) 一份
饭菜。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huanggong16",
]));

	setup();
}

