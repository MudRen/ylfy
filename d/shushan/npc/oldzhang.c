//shushan2 by yushu@SHXY 2000.12
// lilong alter 2002.01.19
inherit NPC;
int max_tea = 20;
void create()
{
	set_name("张大爷", ({"old zhang", "zhang"}));
	set("gender", "男性" );
	set("age", 70);
	set("long", "一个送茶的大爷他姓张。\n");
	set("combat_exp", 10000);
	set("attitude", "peaceful");
	set("title", "茶仙");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
       set("per", 20);
	set("max_qi", 200);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{       
	object ob=this_player();
	object me=this_object();

	::init();

	if ( ((int)ob->query("env/invisibility")  == 0) && ((string)environment(me)->query("short")=="迎客亭") )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
    switch( random(3) ) {      
    case 0:
    say( "张大爷笑咪咪地说道：这位" + RANK_D->query_respect(ob)
            + "，进来歇歇脚，喝两口茶吧。\n");
      break;
  }
	if( !ob || environment(ob) != environment() ) return;
	if( max_tea <= 0 || ob->query_temp("tea_given") == 1 ) return;
       if ( (int)ob->query("combat_exp")>500000 )
	{
		carry_object("/d/shushan/obj/chahu");
		command("give teapot to " + ob->query("id"));
		max_tea=max_tea-1;
		ob->set_temp("tea_given", 1);
	}
	else if ( (int)ob->query("combat_exp")>100000 )
	{
		carry_object("/d/shushan/obj/chahu");
		command("give teapot to " + ob->query("id"));
		max_tea=max_tea-1;
		ob->set_temp("tea_given", 1);
	}
	else if ( (int)ob->query("combat_exp")>10000 )
	{
		carry_object("/d/shushan/obj/chahu");
		command("give teapot to " + ob->query("id"));
		max_tea=max_tea-1;
		ob->set_temp("tea_given", 1);
	}
	else
		return;
}