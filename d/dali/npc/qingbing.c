//qingbing.c �����ױ�

#include <ansi.h>
inherit NPC;

void create()
{
   set_name(HIW"�����ױ�"NOR, ({ "qing bing", "qing", "bing" }));
	set("gender", "����");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "�����ոֵ���Ŀ��ǰ���������������ݡ�\n");
        set("combat_exp", 85000);
	set("shen_type", 1);
	set("attitude", "peaceful");

        set_skill("unarmed", 90);
        set_skill("force", 90);
        set_skill("blade", 90);
        set_skill("force", 80);
        set_skill("blade", 100);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	 carry_object("clone/armor/tiejia")->wear();
	add_money("silver", random(15));
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

