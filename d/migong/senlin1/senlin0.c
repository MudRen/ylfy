#include <room.h>
#include <ansi.h>

#define MAX_MAP_NUM 1000
inherit ROOM;
void create()
{
    string tmp;
    int n;
    set("short", "原始森林");
    set("long", @LONG
  森林里静谧的夜色渐渐地被霞光洗去,朝阳在树顶上涂抹出一层闪耀的红色光晕来，
一束一束笔直的光线,从树冠的缝隙里刺进森林的深处,照耀着地面厚厚的苔藓。
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
    n=sizeof(__DIR__)+sizeof("senlin");
    tmp = __FILE__[n..<3];
    n = atoi(tmp);
    if(sizeof(tmp)>=1 && sizeof(tmp)<=2 && (n%50)==0)
    {
	set("objects",([
		    "/clone/migong/npc/guai3" : 1,
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
