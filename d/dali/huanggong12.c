// Room: /d/dali/huanggong12.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "[1;33m御书房[2;37;0m");
	set("long", @LONG
这里是皇宫的御书房。大理国人人信奉佛教，书房内也不乏
佛家经典。由于大理段氏世代习武，这里也收藏了大理段氏的不
少武功秘要。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"huanggong10",
]));

	setup();
}

