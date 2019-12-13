// yue-lingshan.c

inherit NPC;

void create()
{
        set_name("����ɺ", ({ "yue lingshan", "yue", "lingshan" }) );
        set("nickname", "Сʦ��");
        set("gender", "Ů��" );
        set("age", 17);
        set("per", 29);
        set("str", 16);
        set("con", 24);
        set("dex", 30);
        set("int", 27);

        set("attitude", "friendly");

        set("max_qi",800);
        set("max_jing",500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 80);
        set("combat_exp", 100000);

        set("long",     "����ɺ�ǻ�ɽ����������Ⱥ�Ķ���Ů����\n");

        create_family("��ɽ��", 14, "����");

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("force", 60);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("literate", 70);

        set_skill("huashan-jianfa", 50);
        set_skill("yunv-jian", 80);
        set_skill("huashan-zhangfa", 50);
        set_skill("feiyan-huixiang", 50);

        map_skill("sword", "yunv-jian");
        map_skill("parry", "yunv-jian");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "feiyan-huixiang");

        setup();

        carry_object(__DIR__"obj/green_water_sword")->wield();
        carry_object("/clone/cloth/cloth")->wear();

}

int accept_fight(object me)
{
        command("say СŮ����������Ķ���?");
        return 0;
}
