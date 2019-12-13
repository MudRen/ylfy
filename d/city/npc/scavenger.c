// scavenger.c
inherit NPC;
void get_all();
void create()
{
	set_name("收破烂的", ({ "scavenger" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人不但自己收破烂，身上也穿得破烂不堪。\n");
	set("combat_exp", 10);
	set("per",10);
        set("str", 80);
	set("neili", 30);
	set("max_neili", 30);
	set("jiali", 1);
	setup();
	set("chat_chance", 20);
	set("chat_msg", ({
		"收破烂的吆喝道：收～破～烂～哪～\n",
                (: get_all :),
		"收破烂的嘴里嘟哝著，不知道说些什麽。\n",
                (: get_all :),
		"收破烂的伸手捉住了身上的虱子，一脚踩得扁扁的。 \n",
                (: get_all :),
                (: random_move :),
	}) );
	carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 5);
}
int accept_object(object me, object obj)
{
	if (userp(obj)){
		command("fear "+me->query("id"));
		return 0;
	}
	command("smile");
	command("say 多谢这位" + RANK_D->query_respect(me) + "！");
	return 1;
}
int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	return 0;
}
void get_all()
{

      int i=0;
     if (base_name(environment())=="/d/city/guangchang")
          command("climb up");
     else if (base_name(environment())=="/d/city/chatroom")
          command("tiao down");
        if (is_fighting() || is_busy() ) return;
         foreach (object ob in all_inventory(environment())){
                if( ob->is_character()) continue;
				if(ob->query("board_id")) continue;	
				if(ob->query("no_get")) continue;	
                if( ob->move(this_object()) ) {
                 i++;
                message_vision("$N捡起一"+ob->query("unit")+ob->name()+"。\n",this_object());
                 destruct(ob);
                }
       }
     if (i)      command("smile scavenger");
}
