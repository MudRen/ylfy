// woman.c

inherit NPC;

void create()
{
	set_name("Ѿ��", ({ "ya huan","ya","huan"}) );
	set("gender", "Ů��" );
	set("age", 14);
	set("long", "һ�����ܸɵ�Ѿ����\n");
	set("shen_type", 1);
	set("combat_exp", 300);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
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


