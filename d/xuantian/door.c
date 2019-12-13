
// buwei1.c
inherit ROOM;
//int valid_leave();
void create()
{
      set("short", "石门");
    set("long", @LONG
你拖着疲惫的身体来到了一座石门前，只听道一阵悠扬的
琴声从门内传出来，你精神一振，想要进去看个究竟，可是一
位面带落寞的青衣少年站在门口，用冷冰冰的眼神望着你。
LONG
        );
    set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 2 */
        "north" : "d/xuantian/lyj",
		"south" : "d/xuantian/dongxue",
    ]));
        set("objects", ([ 
        "d/xuantian/npc/han" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("no_action", "ansuan");
     add_action("no_action", "set");


}

int no_action(string str)
{
      write("这里可不许这样哦.. \n");
        return 1;
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
            if ((me->query("gender") == "男性"))
                write("寒真盯着你看了一会，缓缓的让出了去路。\n");
            else if ((me->query("gender") == "女性"))
                write("寒真看了你一眼，脸上微微一红，退了开去。\n");
            return 1;
            }
                else 
            return notify_fail("寒真挡住你的去路，冷冷的道：" + RANK_D->query_respect(me) + "请止步。\n");
    }
    return ::valid_leave(me, dir);
}


