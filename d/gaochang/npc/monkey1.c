// monkey.c 
inherit NPC;
void create()
{
    set_name("瘸腿的猴子", ({ "monkey" }) );
    set("race", "野兽");
    set("long",
        "这只猴子瘸了条后腿，可怜巴巴地望着你。\n");
    set("combat_exp", 5000);
    set("attitude", "peaceful");
    set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("apply/attack", 10);
    set("apply/defense", 10);
    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20);
    setup();
}
void init()
{
     object me=this_player();
     if (userp(me) && !query_leader()){
       set_leader(me);
       add_action("do_bandage","bandage");
     }
}
int do_bandage(string arg)
{
     object kuzhi;
     object me=this_player();
     if (!arg || !living(this_object()) || !objectp(kuzhi=present("duan zhi",me)))
        return 0;
     if (!this_object()->id(arg))
         return 0;
    if (query("name")=="猴子") return 0;
     message_vision("$N用断掉的枯枝为$n包扎好瘸腿。\n\n\n",me,this_object());
     destruct(kuzhi);
     set_name("猴子", ({ "monkey" }) );
    set("long",
        "这只猴子感激地望着你。\n");
     message_vision("$n高兴地翻了几个跟斗。\n\n",me,this_object());
     call_out("do_get_book",3,me);
     return 1;
}
int do_get_book(object me)
{
    object book;
      if (!me || environment(me)!=environment(this_object()) || !living(this_object()) ){
     set_leader(0);
     return 1;
     }
     if (base_name(environment(this_object()))!=("/d/gaochang/room70")){
         call_out("do_get_book",3,me);
         return 1;
     }
    message_vision("$N从岩缝中取出一本油布包着的书交给$n\n",this_object(),me);
    book=new("/d/gaochang/obj/jiuyangbook");
    book->move(me);
    message_vision("$N跳上一棵树，尖叫了几声，跳走了！\n",this_object());
    destruct(this_object());
    return 1;
}
