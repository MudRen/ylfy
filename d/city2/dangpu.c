// Room: /city2/dangpu.c
inherit ROOM;
void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子(paizi)，柜台后坐着贾老板，一双精明的眼睛上上
下下打量着你。
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi": @TEXT
    本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。客倌可以在这里
看货(list)、购买(buy)、估价(value)、典当(pawn)、赎回(redeem)、卖
断(sell)各种货物，还可以查看出售物品属性(look_item 物品英文名,同名物品排列序号)。
TEXT
	]) );
	set("objects", ([
		"/d/city2/npc/jia" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandaj1",
	]));
	setup();
	replace_program(ROOM);
}
