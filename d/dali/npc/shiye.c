// shiye.c ֪��ʦү

inherit NPC;


void create()
{
   set_name("������", ({ "dai shao", "dai" }));
	set("title", "֪��ʦү");
	set("gender", "����");
	set("age", 57);

	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen_type", 0);


	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
	
void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}