
inherit ROOM;
void create()
{
set("short", "大厅");	
	set("long", @LONG
这里是帮派议事大厅,上首有一虎皮金边大椅供帮主休憩议事之用,也是帮内至上权威的象征.两边各竖着一块黑漆金字牌匾：		
　　　　　　　乱世风云，鬼哭神嚎。
　　　　　　　翻云覆雨，唯我独尊。
旁边便是花梨木几椅，用来招呼群雄或帮众汇报大小事务的休息地方。
LONG
);
set("no_fight",1);
	set("exits", ([
"up" : "/d/party/zhaiyuan/bruoxi1465867812", /* sizeof() == 2 */
"east" : __DIR__"beidajie3",	
]));

	setup();
	replace_program(ROOM);
}
