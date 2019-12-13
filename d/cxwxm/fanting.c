// Room: /d/cxwxm/fanting.c
// marry 8,14
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", HIC"饭厅"NOR);
        set("long",
"这是一间非常大的房间，屋子里摆放着十几套红木桌椅，一根\n"
"粗大的"+RED"柱子"NOR+"直通黑糊糊的房顶。你如果饿了可以向厨师要( yao)份\n"
"“扬州炒饭”。\n\n"


);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dating",
]));

        setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
       object me;
       object food;
       me=this_player();
       if (arg)  return notify_fail("我们这里只有炒饭。\n");
       if (food = present("fan", me)) return notify_fail("吃完再说... ...\n");
       message_vision("一个肥头大耳的厨师在盘子中添了些炒饭，然后递给了$N。\n",me);
        food=new(__DIR__"obj/fan");
        food->move(me);
       return 1; 
}
int do_climb(string arg)
{
    int n;
        object me = this_player();

    if( !arg || arg!="柱子" )
        {
        write("你要上哪儿？\n");
        return 1;
    }

    message_vision(
    "$N看了看四下无人，便走到大柱子前，运起全身轻功，顺着柱子猛的往上爬。\n", this_player());

        if ((me->query("family/family_name") == "痴心妄想门"))
        {
                me->move(__DIR__"longfeng");
                return 1;
        }

    n = (int)me->query("dodge");
    if (n >= 300)
        {
        message_vision(
                HIR "只听“砰”的一声，$N掉在了地上，一动不动了?...\n" NOR, this_player());
        set("exits/up", __DIR__"longfeng");
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else
        {
                message_vision(
                HIR "只听“砰”的一声，$N掉在了地上，一动不动了?...\n" NOR, this_player());
                this_player()->set("qi",1);
                this_player()->unconcious();
    }

    return 1;
}
