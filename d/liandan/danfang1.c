// By zjb@ty 2002-5-15

#include <ansi.h>
inherit ROOM; 
int do_dan(object me,object obj);
int do_yao(object me,object obj);
void create()
{
        set("short", HIY"炼丹房"NOR);
        set("long", @LONG
这里是华佗的炼丹室,房间中央放着一个炼丹炉,
玩家们可以拿着自己挖掘来的草药练出自己所需的丹丹药!
LONG
        );
        set("exits", ([
			//"south" : __DIR__"danfang1",
			"north" : __DIR__"yaopuls",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

#include "danfang.h"