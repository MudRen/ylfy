// worker.c

inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "yahuan", "ya" }) );
        set("gender", "Ů��" );
        set("age", 11);
        set("long", "����ɰ���Ѿ�������໥��ͷ����˽� \n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set("chat_chance", 10);
        set("chat_msg", ({
"һ��Ѿ��ߴߴ�����ĸ�����һ��Ѿ�����������˸����ˣ������ϰ˸����һ��һ��ˮ���飮\n",
"һ��Ѿ��ߴߴ�����ĸ�����һ��Ѿ������������һͷ�㷢��������Ľ��\n",
        }) );

        setup();
        carry_object(__DIR__"obj/wch_skirt")->wear();
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
/*
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
*/
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
