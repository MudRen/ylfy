// Room: /d/shaolin/zhonglou7.c
// Date: YZC 96/01/19
inherit ROOM;
string look_bell();
string look_out();
void create()
{
    set("short", "钟楼七层");
    set("long", @LONG
这里就是钟楼之顶。直入眼帘的便是那口大钟和一根悬挂空
中的巨杵。细看大钟，整整有两丈来高，直径也有丈许。钟身似
由青铜浇铸，上面满是密密麻麻的印文古篆，估计重逾数千斤。
巨杵粗可合抱，丈把来长，一头裹以厚皮，正对着钟腰。尽管山
风吹人欲倒，谁都禁不住想撞一下钟(bell)试试。往外看，有个很
大的汉白玉窗台(window)，上面足可站一个人,你如果想不开的话，
可以试一试跳楼(tiao lou)。
LONG
    );
    set("exits", ([
        "down" : __DIR__"zhonglou6",
    ]));
    set("item_desc",([
        "bell"      :   (: look_bell :),
        "out"       :   (: look_out :),
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/qing-xiao" : 1,
    ]));
    setup();
}
void init()
{
    add_action("do_knock", "knock");
    add_action("do_out", "tiao");
}
int do_knock(string arg)
{
    object me,killer;
    me = this_player();
    if ( !arg || ( arg != "bell" ) ) return notify_fail("你要敲什麽？\n");
    if((int)me->query("qi")*100/(int)me->query("max_qi") < 40 && random((int)me->query_str()) < 15)
    {
        killer = new(CLASS_D("shaolin") + "/qing-xiao");
        me->set_temp("last_damage_from",killer);
        me->die();
        destruct(killer);
        return 1;
    }
    else
        me->add("qi", -20);
    if ( random((int)me->query_dex()) < 20 )
    {
        message_vision("$N一不小心敲到自己头上了。\n", me);
        //me->add("qi", -10 - me->query("qi"));
        me->unconcious();
    } else {
        mapping mine;
        mine = me->query_entire_dbase();
        message_vision("$N敲了一下大钟，『咣……』声音传遍整个寺庙。\n", me);
        write("钟声如迅雷般在你耳边炸响，你头脑中一片糊涂，\n"
            "全身摇摇欲坠，勉力支撑着不倒在地上。心中一个\n"
            "声音告诉你，得赶快离开这里，不然就没命了。\n");
        mine["combat_exp"] += 1;
    }
    return 1;
}

    int do_out(string arg)
{
        object me;
    int i,j,my_dex, ging_cost, qi_cost, my_kar,tiaolou_cnt;
    me = this_player();
    my_dex = (int)me->query_dex();
    my_kar = (int)me->query_kar();
    i = (my_dex + my_kar)*5+ random(200);
    j = random(i);
    ging_cost = 600 / (int)me->query_int();
    qi_cost = 800 / (int)me->query_int();
    tiaolou_cnt=0;
    if (!arg||arg!="lou") {
    tell_room(environment(me), me->name() +"想不开想跳楼，可是双腿却不听使唤，瑟瑟发抖!\n", ({me}));
    write("你高兴得跳得老高，不知道出了什么毛病\n");
    return 1;
    }
     if((int)me->query("tiaolou_cnt")>=6000)
{     if(random((int)me->query("kar"))>20){
    	me->set_skill("dodge",(int)me->query_skill("dodge",1)+1);
    	 write(HIG"你的轻功增加了!\n");
         CHANNEL_D->do_channel(this_object(), "rumor",
            sprintf("由于%s坚持不懈的跳楼,轻功技能取得了长足的进展。\n", me->name(1)));}
         me->set("tiaolou_cnt",0);
         return 1;
     }
    if((int)me->query("jing") < ging_cost || (int)me->query("qi") < qi_cost)
     { 
    message_vision("$N满脸失望,哎,的一声叹了口气,就从楼上跳了下去。\n", me);
    message_vision("只听『砰』地一声$N从钟楼上落了下来。\n", me);
    me->move(__DIR__"gulou");
    me->unconcious();
    return 1;
    }
    if ((int)me->query_skill("dodge", 1)<100 && j < 30)
    {

                me->move(__DIR__"zhonglou");
            
                me->unconcious();


    }
    else if((int)me->query("neili")<2000 && j < 15) {
        message_vision("$N爬上窗户，一个纵身，跳了出去。\n", me);
        
       me->move(__DIR__"zhonglou");
       message_vision("只听『砰』地一声$N摔了个半死。\n", me);
        me->unconcious();
        }
    else {
    	message_vision("$N爬上窗户，一个纵身，跳了出去。\n", me);
        me->move(__DIR__"zhonglou1");

        message_vision("只听『砰』地一声$N从楼上跳了下来。\n", me);
        tell_object(me,"你感觉到自己的轻功又有进境了！\n");
                if (me->query_skill("dodge", 1)<200)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else if (me->query_skill("dodge", 1)<700)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1)*my_kar/30);
                else if (random(my_kar)>15)
                 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/2);

        me->add("tiaolou_cnt",1);
        me->receive_damage("jing", ging_cost );
        me->receive_damage("qi", qi_cost );

        me->set_temp("die_for","从钟楼上跳下来摔");
        me->delete_temp("last_damage_from");
    
   }
    return 1;
}
string look_bell()
{
    return
    "※※※※※※※※※※※※※※※※※※※※※※※\n"
    "※※※※　　　　　　　　　　　　　　　※※※※\n"
    "※※※※　　　　　佛语有曰：　　　　　※※※※\n"
    "※※※※　　　　　　　　　　　　　　　※※※※\n"
    "※※※※　『做一天和尚，撞一天钟』　　※※※※\n"
    "※※※※　　　　　　　　　　　　　　　※※※※\n"
    "※※※※　（ｋｎｏｃｋ　ｂｅｌｌ）　　※※※※\n"
    "※※※※　　　　　　　　　　　　　　　※※※※\n"
    "※※※※※※※※※※※※※※※※※※※※※※※\n";
}
string look_out()
{
    return  "这里是钟楼顶层的窗台，从这里可以遥望整个少室山脉，\n"
"以及高耸入云的嵩山。浮世烟尘，尽在眼底。据说在此地\n"
"可以与天界诸佛直接交流，对禅修大有益处。\n";
}

