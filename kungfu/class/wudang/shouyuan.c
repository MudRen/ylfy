// shouyuan.c ��԰
inherit NPC;
void create()
{
    set_name("��԰����", ({ "shouyuan daozhang", "shouyuan" }));
    set("long", 
        "�����䵱ɽ����԰������\n");
    set("gender", "����");
    set("age", 30);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 20);
    set("int", 20);
    set("con", 25);
    set("dex", 20);
    
    set("max_qi", 300);
    set("max_jing", 200);
    set("neili", 300);
    set("max_neili", 300);
    set("combat_exp", 115000);
    set("score", 1000);
    set_skill("force", 160);
    set_skill("dodge", 140);
    set_skill("unarmed", 140);
    set_skill("parry", 140);
    set_skill("blade", 140);
    set_skill("taiji-dao", 125);
    set_skill("taoism", 120);
    set_skill("blade", 140);
    set_skill("taiji-dao", 125);
    map_skill("blade", "taiji-dao");
    create_family("�䵱��", 4, "����");
    setup();
    carry_object("/clone/weapon/gangdao")->wield();
    carry_object("//clone/cloth/long_cloth")->wear();
}
