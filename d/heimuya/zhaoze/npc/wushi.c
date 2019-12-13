// wushi.c
inherit NPC;
void greeting(object ob);

void create()
{
        set_name("��ʿ", ({ "wushi" }) );
        set("gender", "����" );

        set("age", 45);
        set("long", "�����������ʿ��������ɱ�������\n");
        set("combat_exp", 60000);

        set("attitude", "aggressive");

        set("apply/attack", 20);
        set("apply/defense", 20);

        set("chat_chance", 30);
        set("chat_msg", ({
                "��ʿһ����: #$@%^&@#%#$@$%*^%$#@!!! \n",
        }) );

        set_skill("unarmed", 85);
        set_skill("blade", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/mutang")->wield();
        add_money("silver", 10);
}
void init()
{
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        else command("kill"+(string)ob->query("id"));
        return;
}
