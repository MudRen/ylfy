#include <room.h>
#include <ansi.h>

#define MAX_MAP_NUM 1000
inherit ROOM;
void create()
{
    set("short", "寂静森林");
    set("long", @LONG
  这里就是传说中的寂静之森，树茂林密难见天日，四周静悄悄的充斥着一片死寂。
看似的幽静却不知吞没了多少英雄侠士，宁静的表面下正汹涌着澎湃的杀机，真所谓的步步危机。
LONG);
    set("exits",([
		"east" : __DIR__"senlin"+random(1000),
		"south" : __DIR__"senlin"+random(1000),
		"west" : __DIR__"senlin"+random(1000),
		"north" : __DIR__"senlin"+random(1000),
		"southeast" : __DIR__"senlin"+random(1000),
		"southwest" : __DIR__"senlin"+random(1000),
		"northeast" : __DIR__"senlin"+random(1000),
		"northwest" : __DIR__"senlin"+random(1000),
		]));
		
    if(random(100) > 30)
    {
	set("objects",([
		    "/clone/migong/npc/guai1" : 1,
		    ]));
    }
    set("no_clean_up", 0);
    setup();
}

void init()
{
    object me = this_player();
    if(wizhood(me)=="(boss)")
    {
	add_action("do_create_map","createmap");
    }
}

int do_create_map()
{
    int i;
    object me = this_player();
    if(!me || wizhood(me)!="(boss)")
	return 0;
    for(i=1;i<MAX_MAP_NUM;i++)
    {
	if(cp(__DIR__"senlin0.c",__DIR__"senlin"+i+".c"))
	    write("ok:");
	else
	    write("failed:");
	write("senlin"+i+"\n");
    }
    return 1;
}
