inherit NPC;

void create()
{
        set_name("���ο�", ({ "piaoke", "ke"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�ʷ����ֵĴ��ο�\n");
        set("combat_exp", 50000);
        set_skill("dodge", 100);
        set_skill("unarmed", 120);
        set("chat_chance", 10);
        set("chat_msg", ({
"���οͻ�ͷ�����ʲô��ƨ�����ϰ˽�������ʲô�˲���ģ��������¶������ԣ�\n",
                (: random_move :)
        }) );
        
        setup();
        add_money("silver", 50);
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
