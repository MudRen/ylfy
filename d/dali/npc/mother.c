// mother.c

inherit NPC;

void create()
{
        set_name("���ĸ", ({ "mother" }) );
        set("gender", "Ů��" );
        set("age", 39);
        set("str", 10);
        set("per", 6);
        set("long", @LONG
    �ĸ�Ǹ�Ũױ��Ĩ������Ů�ӣ����΢�֣�ȫ��������ⱦ����
LONG
);
        set("combat_exp", 10);
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
"�ĸ����������½ǣ�����˵�����������Ҹ����Ҹ���õģ�\n",
                (: random_move :)
        }) );

        set_skill("unarmed", 100);
        set_skill("parry", 50);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "�ĸ˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
        }) );
        setup();
        
        carry_object(__DIR__"obj/color_cloth")->wear();
}

/*
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
*/
