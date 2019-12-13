// Room: /city2/qianzhuang.c
inherit ROOM;
void create()
{
	set("short", "珠宝店");
	set("long", @LONG
这是金家在北京的珠宝分店，金家收藏的奇珍异宝可真是数不胜数。
据说金家随便拿出一件珍宝都是价值连城，富可敌国哪！但这些都是传闻
还不知真假，也没有人真正见过金家的任何珍贵宝物，但也不会就这么
空穴来风吧？其中定有古怪。
店铺正对面墙上挂着一个醒目的牌子(paizi)。
LONG
);
	set("item_desc", ([
		"paizi" : "\n本店收藏各珍贵宝物。\n"+"存珠宝：cun ID\n"+"取珠宝：qu ID\n"+"查询存放的珠宝：chaxun\n"
	]));
	
	set("exits", ([
		"north" : __DIR__"chaoyan1",
	]));
	
	set("objects", ([
		__DIR__"npc/zhubaoshang" : 1
	]));
	
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}
