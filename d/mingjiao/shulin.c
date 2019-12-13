inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
一片茂盛的树林，你一进来就好象迷失了方向，林中有着一块空
地，竖立着六十四根高低不等的木桩(zhuang)，隐隐似有八卦之象。
许多教中弟子正在此练习武艺。
LONG
        );

        set("exits", ([
                "east" : __DIR__"jumuqi",
                "west" : __DIR__"shulin1",
        ]));

        set("item_desc", ([
                "zhuang" : "这些木桩由于经常有人在上面跳跃(jump),顶端异常光滑。\n",
        ]));
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}


int do_jump(string arg)
{
        int xianzhi;
        object me;

        me = this_player();

        if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("什么？\n");
        if ( (int)me->query("combat_exp") >0) xianzhi=10;
        if ( (int)me->query("combat_exp") >800) xianzhi=20;
        if ( (int)me->query("combat_exp") >900) xianzhi=30;
        if ( (int)me->query("combat_exp") >6400) xianzhi=40;
        if ( (int)me->query("combat_exp") >12500) xianzhi=50;
        if ( (int)me->query("combat_exp") >21600) xianzhi=60;

        if ( (int)me->query("jing") < 40)
                return notify_fail("你已经很累的了，先休息一下吧。\n");


        me->add("jing", (-1)*random(40));

        message_vision("$N纵身跃上了木桩，在木桩间高低来回地跳跃着。\n", me);

        if ( (int)me->query_skill("dodge", 1) < xianzhi)
        {
        me->improve_skill("dodge", me->query("int"));
        write("你在纵身跳跃之间若有所悟，似乎对基本轻功有点心得。\n");
        me->set_temp("stone_learned",1);
        }
        else
        {
 write("你拼命地跳来跳去，却感觉不到任何进展，可能是你经\n"
       "验不足或基本轻功已经大于六十级了。\n");
        }
        return 1;
}


