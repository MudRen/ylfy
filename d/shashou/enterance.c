// enterance.c

inherit ROOM;

void create()
{
	set("short", "杀手楼大门");
	set("long", @LONG
走到这里，你发现这里居然别有洞天。前方是一栋豪门巨宅，
门前一对金刚神师，气焰威猛，成扑杀之势。门上牌匾笔落如刀，杀气
懔然，上书三个大字“杀手楼”。一对铁门环，也是搭造成金刚模样。
两旁立柱均雕龙画凤，舞爪张牙，不可一世。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//                   "south" : "/d/dali/dadao1",	
"south" : "/d/henshan/hsroad9",	
		"north" : __DIR__"xiaolu",
	]));
	set("no_clean_up", 0);
        set("objects",([
                      __DIR__"npc/weishi":2,
                        ]));
	set("outdoors", "shashou" );

	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
