// bing.c �ٱ�
inherit NPC;
void create()
{
        set_name("�ٱ�", ({ "guan bing", "bing" }));
        set("age", 32);
        set("gender", "����");
        set("long", "���Ǹ����߶�����ϱ�����Ͳ�С�ˣ�����δ�ɼҡ�\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
                "�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
        }));
        setup();
        carry_object("clone/weapon/gangdao")->wield();
        carry_object("clone/cloth/junfu")->wear();
}
void init()
{
    object ob;
    ::init();
    if (!living(this_object())) return;
    if (interactive(ob = this_player())){
        if (    (int)ob->query_condition("killer") &&   this_player()->name()==this_player()->name(1)   ) {
            command("say �����������ү��ס�ˣ�ɱ�˷��������ӣ�\n");
            remove_call_out("kill_ob");
            call_out("kill_ob", 1, ob);
        }
        if( this_player()->query_temp("illicit") ){
            command("say ���ɣ������ӣ�\n");
            remove_call_out("kill_ob");
            call_out("kill_ob", 1, ob);
        }
    }
    add_action("do_kill","kill");
    add_action("do_kill","hit");
}
int do_kill(string arg)
{
    object ob;
    if (living(this_object()) && this_object()->id(arg)){
        command("say ���ܣ��ֵ��ǣ��ϣ�");
        if (ob=present("wu jiang",environment()))
                     if (!ob->is_killing(this_player()))  ob->kill_ob(this_player());
        if (ob=present("guan bing",environment()))
                     if (!ob->is_killing(this_player()))  ob->kill_ob(this_player());
    }
    return 0;
}
int accept_fight(object me)
{
        command("say ��ү���ر߹��۵�Ҫ����û�պ�" + RANK_D->query_respect(me)
        + "�����档\n");
        return 0;
}
