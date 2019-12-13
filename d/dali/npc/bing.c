// bing.c �ٱ�
inherit NPC;
void create()
{
        set_name("����ٱ�", ({ "guan bing", "bing" }));
        set("age", 22);
        set("gender", "����");
        set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 20000);
        set("shen_type", 1);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("blade", 80);
        set_skill("force", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 80);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
                "�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
        }));
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/junfu")->wear();
}
void init()
{
        object ob;
        ::init();
        if (!living(this_object()))     return;
        if (interactive(ob = this_player())){
                if (    (int)ob->query_condition("killer") ){
                        command("say �����������ү��ס�ˣ�ɱ�˷��������ӣ�\n");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
        }

        if( this_player()->query_temp("dalikill") )
        kill_ob(this_player());
        add_action("do_kill","kill");
        add_action("do_kill","hit");
}
int do_kill(string arg)
{
        object ob;
        if (living(this_object()) && this_object()->id(arg)){
                command("say ���ܣ��ֵ��ǣ��ϣ�");
                if (ob=present("wu jiang",environment()))
                        ob->kill_ob(this_player());
                if (ob=present("guan bing",environment()))
                        ob->kill_ob(this_player());
        }
        if (living(this_object()) && this_object()->id(arg))
        {
         this_player()->set_temp("dalikill", 1);
        }
        return 0;
}
int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
//      me->apply_condition("killer", 500);	 //lisa ע����2003.8.29
        kill_ob(me);
        return 1;
}
