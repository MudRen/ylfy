// xi.c ����Ϫ
inherit NPC;
void create()
{
    set_name("����Ϫ", ({ "zhang songxi", "zhang" }));
    set("nickname", "�䵱����");
    set("long", 
        "��������������ĵ�������Ϫ��\n"
        "һ����İ�С����������֮ɫ�ĺ��ӣ������ܸɣ������Ƕ�ı���ơ�\n");
    set("gender", "����");
    set("age", 40);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 26);
    set("int", 30);
    set("con", 26);
  set("per",30);
    set("dex", 28);
    
    set("max_qi", 1500);
    set("max_jing", 800);
    set("neili", 1700);
    set("max_neili", 1700);
    set("jiali", 50);
    set("combat_exp", 1500000);
    set("score", 60000);
    set_skill("force", 180);
    set_skill("taiji-shengong", 160);
    set_skill("dodge", 180);
    set_skill("tiyunzong", 160);
    set_skill("unarmed", 180);
    set_skill("taiji-quan", 160);
    set_skill("parry", 180);
    set_skill("sword", 180);
    set_skill("taiji-jian", 160);
    set_skill("taoism", 180);
    set_skill("literate", 180);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    create_family("�䵱��", 2, "����");
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: perform_action, "sword.chan" :),
        (: perform_action, "sword.lian" :),
        (: perform_action, "sword.sui" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whitecloth")->wear();
}
