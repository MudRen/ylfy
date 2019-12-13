inherit ROOM;

int do_drink();
void create()
{
        set("short", "储藏室");
        set("long", @LONG
由于你暂时还出不去，卫前辈特地在这里收集了一些鱼虾之类的东西
还特意凿开岩石，把潭里的水引进来，供你饮用。好让你心无杂念的钻研
他的独门内功。
LONG );
        set("resource/water", 1);

	set("valid_startroom",1);
        set("exits", ([
                "east" : __DIR__"mishi",
        ]));

/*
        set("objects", ([
            __DIR__"/obj/xia" : random(3),
            __DIR__"/obj/yu" : random(3),
        ]));
*/
//        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink()
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
		me->set("water", current_water+30);
		message("vision", me->name()+"喝了一口水。\n"
		, environment(me), ({me}) );
        }
        else write("你已经喝饱了。\n");

        return 1;
}

