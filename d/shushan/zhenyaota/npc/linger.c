//Cracked by Roath
//Ansi 99.12
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "zhao linger", "linger"}));
        set("title","");
        set("long", 
"�������Ů��֮�󣬵�Ȼ�ǰ����ߡ�\n");
        set("gender", "Ů��");
        set("age", 15);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("spi", 50);
        set("per", 40);
        set("class","xian");
        
        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 2000);
        set("neili_factor", 60);

        set("combat_exp", 15000000);
         set("max_jingli", 2000);
         set("jingli", 2000);
         set("jiali", 2000);
        set_skill("unarmed", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set("inquiry", ([
                "����ң" : "���ܴ���ȥ����ң����𣿣�\n",
        ]));
        setup();

         carry_object("/clone/cloth/daogu-cloth")->wear();
         carry_object("/clone/cloth/dao-xie")->wear();
}

void init()
{
        add_action("do_daying", "daying");
}

int do_daying(string arg)
{
        object who = this_player();
        object me = this_object();
        if(who->query("zhanyi/zhenyaota")) { 
        command("say ��Ҫ���Ҽ�����?");
        }
        else 
        { 
        if(me->query_temp("help_offer") != 0)
                return notify_fail("���������"+who->query("name")+"�Ѿ���Ӧ���ˣ�\n��");
        message_vision("$N��Ӧ�������\n", this_player());
        command("jump "+who->query("id"));
        command("kiss "+who->query("id"));
        command("follow "+who->query("id"));
        command("say "+"�ǾͰ���������\n");
        me->set_temp("help_offer",who->query("name"));
        who->set("shushan/zhanyi",1);
        }
        return 1;
}
