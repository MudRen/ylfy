// mo.c Ī����
inherit NPC;
void create()
{
    set_name("Ī����", ({ "mo shenggu", "mo" }));
    set("nickname", "�䵱����");
    set("long", 
        "��������������ߵ���Ī���ȡ�\n"
        "����������ʮ���꣬�Ե�����δ�ѡ�\n"
        "��Ҳ�ǽ������������壬����Զ�������͡�\n");
    set("gender", "����");
    set("age", 40);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 26);
    set("int", 30);
    set("con", 26);
    set("dex", 28);
    
    set("max_qi", 1000);
    set("max_jing", 800);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 50);
    set("combat_exp", 1100000);
    set_skill("force", 180);
    set_skill("taiji-shengong", 160);
    set_skill("dodge", 180);
    set_skill("tiyunzong", 160);
    set_skill("unarmed", 160);
    set_skill("taiji-quan", 150);
    set_skill("parry", 160);
    set_skill("sword", 160);
    set_skill("taiji-jian", 160);
    set_skill("literate", 180);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    create_family("�䵱��", 2, "����");
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: perform_action, "sword.chan" :),
        (: perform_action, "sword.lian" :),
        (: perform_action, "sword.sui" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}
