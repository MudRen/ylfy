// dashou.c ����

inherit NPC;

void create()
{
        set_name("����", ({ "da shou", "da" }));
        set("age", 22);
        set("gender", "����");
        set("long", "��һ�������⣬���һ�����Զ����������ǵ����硣\n");
        set("attitude", "peaceful");
//      set("vendetta_mark", "authority");
//      set("pursuer", 1);

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 15000);
        set("shen_type", 1);

        set_skill("unarmed", 45);
        set_skill("dodge", 45);
        set_skill("parry", 45);
        set_skill("force", 45);
        set_skill("blade", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

//      if (random(2) == 1) {
//              set("chat_chance", 10);
//              set("chat_msg", ({
//                      (: random_move :),
//              }));
//      }

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "���ֺȵ����㾹��̫��ͷ������������\n",
                "���ֺȵ�����Ҳ����������˭�ĵط�������Ҫ�������������Ż�ȥ��\n",
        }));
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
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
        object ob;
        if (living(this_object()) && this_object()->id(arg)){
                command("say ���ܣ��ֵ��ǣ��ϣ�");
                if (ob=present("da shou",environment()))
                        ob->kill_ob(this_player());
        }
        this_player()->set_temp("dalikill", 1);
        return 0;
}
