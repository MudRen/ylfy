
// buwei1.c
inherit ROOM;
//int valid_leave();
void create()
{
      set("short", "石壁");
    set("long", @LONG
你拖着疲惫的身体来到了一个洞穴前，只听道一阵悠扬的
琴声从里面传出来，你精神一振。
LONG
        );
    set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 2 */
        "north" : "d/xuantian/door",
    ]));
        set("objects", ([ 
        "d/xuantian/npc/menwei" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
    object ob;
    if (dir != "north")
        return ::valid_leave(me, dir);
    ob=present("han zhen", environment(me));
        if (dir == "north" && objectp(ob) && living(ob))
    {
        if ((me->query("family/family_name") == "玄天派"))
            {
            
            return 1;
            }
                else 
            return notify_fail("铁手挡住你的去路，冷冷的道：" + RANK_D->query_respect(me) + "请止步。\n");
    }
    return ::valid_leave(me, dir);
}


