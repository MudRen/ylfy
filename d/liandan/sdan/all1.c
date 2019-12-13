// By zjb@ty 2002-5-15

inherit ITEM;
void create()
{
        set_name(HIR"祛腐生肌散"NOR, ({ "qufu shengjisan","shengjisan","san"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗祛腐生肌散,听说是治疗内伤的圣药!\n");
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

  if (me->query("daoxin/con")) {
  if (me->query("daoxin/con")>=3) {
    shoubi = random(3);
    me->add("con",shoubi);
    me->add("daoxin/con",-shoubi);    
    tell_object(me,HIC"你感到你的内伤似乎好点了!\n"NOR); 
    } else {
    me->add("con",1);
    me->add("daoxin/con",-1);
    tell_object(me,HIG"你感到你的内伤似乎好点了!\n"NOR); 
}
}
    me->add("max_neili",random(100));
    me->add("max_jingli",random(100));
    message_vision(HIY"$N拿出祛腐生肌散吃了下去,感觉身上一阵暖洋洋的,有一股说不出的舒服。\n"NOR,me);
       destruct(this_object());
       return 1;
}


