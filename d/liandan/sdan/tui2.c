// By zjb@ty 2002-5-15

inherit ITEM;
void create()
{
        set_name(HIB"宋氏接骨散"NOR, ({ "songshi jiegusan","jiegusan","san"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗宋氏接骨散,听说是治疗腿伤的圣药!\n");
                set("unit", "颗"); 
                set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);   
        }
    setup();
}
void init()
{
    if (environment()==this_player())
        add_action("do_eat", "eat");
}
int do_eat(string arg)
{ 
    object fae, shangshan, mengzhu, xinxiu;
    int maxneili,neili,shoubi;
    object me = this_player();
    neili = me->query("neili");
    maxneili = me->query("max_neili");

    fae = load_object("/d/taishan/npc/fa-e");
    fae->restore();
    shangshan = load_object("/d/taishan/npc/shang-shan");
    shangshan->restore();
    mengzhu = load_object("/d/taishan/npc/meng-zhu");
    mengzhu->restore();
    xinxiu = load_object("/d/taishan/npc/xinxiu");
    xinxiu->restore();

  if(!id(arg)) return 0;  

  if( me->query("id")==fae->query("winner") )
  return notify_fail("您是当今罚恶使者，吃这个药难道想用bug？\n");

  if( me->query("id")==shangshan->query("winner") )
  return notify_fail("您是当今赏善使者，吃这个药难道想用bug\n");

  if( me->query("id")==mengzhu->query("winner") )
  return notify_fail("您是当今武林盟主，还想吃这个药难道想用bug？\n");

  if( me->query("id")==xinxiu->query("winner") )
  return notify_fail("您是当今新秀使者，还想吃这个药难道想用bug？\n");
  if(me->is_busy()) return notify_fail("你上一个动作还没有完成。\n");

  if(me->query("id")!=query("zhuren"))
  return notify_fail("这棵丹药不是你练的,你吃个屁!!\n");

  if (me->query("daoxin/dex")) {
  if (me->query("daoxin/dex")>=3) {
    shoubi = random(3);
    me->add("dex",shoubi);
    me->add("daoxin/dex",-shoubi);    
    tell_object(me,HIC"你感到你的腿伤似乎好点了!\n"NOR); 
    } else {
    me->add("dex",1);
    me->add("daoxin/dex",-1);
    tell_object(me,HIG"你感到你的腿伤似乎好点了!\n"NOR); 
}
}
    me->add("combat_exp",random(10000));
    me->add("potential",random(5000));

    message_vision(HIY"$N拿出宋氏接骨散吃了下去,感觉身上一阵暖洋洋的,有一股说不出的舒服。\n"NOR,me);
       destruct(this_object());
       return 1;
}


