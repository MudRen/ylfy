//shushan2 by yushu@SHXY 2000.12 
// lilong alter 2002.01.19
inherit NPC;
void create()
{
       set_name("蜀山弟子", ({"shouwei dizi", "dizi"}));
       set("title", "禁地守卫");
       set("long","蜀山剑派的禁地守卫\n");
       set("gender", "男性");
       set("age", 28);
	set("str", 25);
       set("attitude", "aggressive");
        set("attitude", "aggressive");
        set("max_jingli", 400);
        set("jingli", 400);
        set("max_neili", 400);
        set("neili", 1000);
        set("jiali", 10000);
       set_skill("sword",200);
       set_skill("parry",200);
	set_skill("dodge",200);
        set_skill("fumozhang",200);
       set_skill("unarmed",200);
       set_skill("force",200);
      set_skill("shushan-force",200);
 	set_skill("yujianshu",200);
	set_skill("zuixian-steps",200);
	map_skill("dodge", "zuixian-steps");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("unarmed", "fumozhang");
	map_skill("force", "shushan-force");
       set("max_qi",5000);
	set("bellicosity", 5000);
       set("max_jing",1000);
       set("max_neili",1000);
       set("combat_exp", 3000000);
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
                (: perform_action, "sword", "wanjian" :),
}) );

       setup();
        carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/cloth/cloth")->wear();
       add_money("silver", 50);
       }
       void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "蜀山弟子喝道：那里来的人，擅闯蜀山禁地，不想活了！\n");
}
