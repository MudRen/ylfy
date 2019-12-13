//NPC /npc/shizhe3.c

inherit NPC;

void greeting(object);
void init();

void create()
{
        set_name("����", ( { "shizhe", "zhe" }) );
        set("title", "���͵����ӵ���");
        set("gender", "����" );
        set("age", 30);
        set("long",
              "���Ǹ����Ż��µ���ʮ���꺺�ӣ�����վ�������ޱ��顣\n"
             );
        set("attitude", "friendly");
        set("shen_type", 1);

        set("str", 200);
        set("int", 20);
        set("con", 20);
        set("dex", 200);

        set("max_qi", 33000);
        set("max_jing", 3200);
        set("neili", 30000);
        set("max_neili", 300);

        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("unarmed", 400);
        set_skill("parry", 400);
        set_temp("apply/attack", 240);
        set_temp("apply/defense", 250);
        set_temp("apply/damage", 240);
        set_temp("apply/armor", 240);

        create_family("���͵�", 2, "����");

        set("inquiry", ([
            "here" : "������������е������ˣ�С�������������ô�ã������е�����Ҳ���������\n",
            "cha"  : "�����Դ�����������С�����ڲ����뿪�˵أ�\n",
            "yezi" : "�����Դ�����������С�����ڲ����뿪�˵أ�\n",
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/xiakedao/obj/key1")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        say("��������˵������λ" + RANK_D->query_respect(ob)
           + "�����Ҳ���������������ܵİɡ��������������\n"
           + "�������ģ���Χ���ж�ʮ�ļ�ʯ�ң����������ȥ�ۿ�����һ��\n"
           + "ҪС�����⣬ǧ�򲻿�çײ���¡����ҿɹ�Ӧ��ʳ���������Ǿ�\n"
           + "����ȥΪ�á�\n"
             );
        return;
}

int accept_object(object who, object ob)
{
        command("smile");

        if( ob->query("money_id") && ob->value() >= 5000  )
        {command("say " + RANK_D->query_respect(who) +
                "��˹ŵ��ȳ������������գ���������������˵�ģ�" +
                "����ʵ�ڲ����ļ������ȡ���������Ž�ȥ����ǽ���ϵ�" +
                "�ǰ�ľ��ȡ�£��������ϣ������кô�������ǧ������" +
                "���ˣ��������Ҷ���ɱ��֮�����м��мǣ�����" );
        }
        return 1;

}
void die()
{
        object room;

        say("���ɱ�ң����ӵ�����Ҳ����Ź��㡣\n");
        message_vision("$N�Һ�һ�������ˣ�\n", this_object());

        room = environment(this_object());
message("vision", "������������ˤ����һ�ԣ���ʱ��ŷ��ָղ���վ�ĵط��е���֡�\n"
        "�ذ�������ʯ����ɣ��ƺ��Ǹ���.���滹��һԿ�׿�(kong) \n", room);

        ::die();
}

