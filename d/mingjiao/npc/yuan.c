// yuan.c 
inherit NPC;

void create()
{
        set_name("Բ��", ({ "yuan zhen", "yuan" }) );
        set("age", 56);
        set("long", "���ֵĵ��ӣ��������˳ơ���Ԫ�����֡��ı���,\n������������������\n");
       set("gender", "����");
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 28);
        set("con", 24);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 200);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 60);
        set("combat_exp", 1000000);
        set("shen",-500000);
        set("score", -100);

        set_skill("force", 201);
        set_skill("sword", 201);
        set_skill("dodge", 180);
        set_skill("unarmed",201);
        set_skill("parry", 201);
        set_skill("sword", 201);
       set_skill("hunyuan-yiqi",201);
        set_skill("fumo-jian",201);
       set_skill("shaolin-shenfa",280);

       map_skill("dodge","shaolin-shenfa");
       map_skill("sword","fumo-jian");
       map_skill("parry","fumo-jian");
       map_skill("force","hunyuan-yiqi");
       setup();
       carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/cloth/cloth")->wear();
        add_money("gold", 1);

}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
void unconcious()
{
        object ob;
        tell_room(environment(this_player()), "Բ��Һ�һ�������ڵ��ϣ�ͷ­��Ȼ�����ˣ�\n");
        ob = new(__DIR__"obj/rentou");
        ob->move(environment(this_object()));
        this_object()->set("long", "���ֵĵ��ӣ��������˳ơ���Ԫ�����֡��ı���,\n������������������ֻ�ǣ�Ŀǰ�Ѿ�û����ͷ­��\n");
        ::die();
}

void die()
{
        unconcious();
}

