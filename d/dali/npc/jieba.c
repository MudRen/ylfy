//jieba.c ����ְ�

inherit NPC;

void create()
{
        set_name("����ְ�",({"jie ba","jie","ba" }));
        set("gender", "����");
        set("age",24);
        set("long",
"����һ�ʹ������Զ��Ľְԣ��书���߾ͻ��˶�������. \n");
        set_skill("blade", 80);
        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 15);
        set("combat_exp", 55000);
        set("attitude", "friendly");
        set("chat_chance_combat", 10);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

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

int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        //me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
