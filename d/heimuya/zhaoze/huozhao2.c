// Room: /d/heimuya/zhaoze/huozhao2.c
inherit ROOM;
int do_pull(string);
void create()
{
        set("short", "洪荒古泽");
        set("long", @LONG
你站在齐腰深的水里，周围是烧得乌黑的古树和芦苇。你发现一
种十分怪异的现象，一束束的火焰在水面上燃烧。阵阵热气扑面而来，
使人不禁生起快点离开此地的感觉。
LONG
);
        set("exits", ([ 
  "west" : __DIR__"huozhao1",
  "south" : __DIR__"huozhao3",
]));

        setup();
}
void init()
{
        object me=this_player();

        if( interactive(me) ) {
            add_action("do_pull", "pull");
        if (random(me->query("kar"))<10){
            message_vision(RED "$N身子突然下沉... ...\n" NOR,me);
            me->set_temp("drop_zhaoze",1);
            }
            call_out("hurn", 1, me);
        }
        
}
int do_pull(string arg)
{
    object ob;
    object me = this_player(); 

    if (!arg)
        return notify_fail("你要拉谁？\n");

    if (!ob = present(arg,this_object()))
        return notify_fail("你要拉谁？\n");

    if (me->query_temp("drop_zhaoze"))
        return notify_fail("你自己都自身难保了，还想拉别人？\n");

    if (!ob->query_temp("drop_zhaoze"))
        return notify_fail(ob->name()+"不用你拉！\n");

    message_vision("你扯住$N的手，使劲把$n扯了上来。\n",me,ob);
    ob->delete_temp("drop_zhaoze");
    return 1;
}
int valid_leave(object me, string dir)
{
        if (dir=="south" && me->query_temp("drop_zhaoze")){
                message_vision("$N使劲挣扎一下，试图爬出泥潭.....\n",me);
                if (random(10)>5){   
                        me->apply_condition("scorpoin_poison",20);
                        tell_object(me,RED "\n你突然觉得脚被什么东西刺了一下... ...\n" NOR);
                }
                if (random(me->query_skill("dodge",1))>600){
                        message_vision("$N身形一纵，跃出泥潭。\n",me);
                        return 1;
                }else{
                        message_vision("$N结果越陷越深！\n",me);
                        me->set_temp("die_for","陷进沼泽闷");
                        me->receive_wound("qi",200);
                       return notify_fail("你陷入沼泽，动弹不得。\n");
                }
        }
        return 1;
}
void hurn(object me)
{
        object ob;

        if( !me || environment(me) != this_object() ) return;
            me->apply_condition("fire_poison",50);            
        ob=me->query_temp("armor/cloth");
        if (!ob)        return;
        if ( ob->query("material")==("cloth") || ob->query("material")==("leather")){
            message_vision( HIR+"$N身穿的"+ob->query("name")+HIR+"突然着火燃烧起来，$N手忙脚乱地把它脱了下来，丢在地上！\n"+NOR, me);
            ob->unequip();
            ob->move(this_object());
            ob->set("long", "这是一件烧得无法再穿的"+ob->query("name")+"。\n");
            ob->set("name","烧破的"+ob->query("name"));
            ob->set("value",0);
            ob->set("armor_prop",0);
        }
}

