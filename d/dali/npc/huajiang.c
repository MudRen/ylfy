// beggar.c

inherit NPC;

void create()
{
        set_name("����", ({ "huajiang" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ���������ڽ�������԰�Ļ���\n");
        set("combat_exp", 100);
        set("str", 27);
        set("neili", 200);
        set("attitude", "friendly");
        set("max_neili", 200);
        set("jiali", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
"�������𻨺���С�ĵ�����Ʒĵ���Ͻ�ˮ\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ�����\n",
                "����ѩ" : "������������հǳ��ˣ�\n",
                "xue" : "��������ĺ����࣬���Լ���������綼���ܼ���\n",
        ]) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"����һ�����������Ŀ��ĵģ�");
        return 1;
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
