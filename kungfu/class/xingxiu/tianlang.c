// tianlang.c ������
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("������", ({ "tianlang zi", "tianlang" }));
    set("nickname", "��������ʦ��");
    set("long", 
        "�����Ƕ�����������������ӡ�\n");
    set("gender", "����");
    set("age", 30);
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("str", 27);
    set("int", 16);
    set("con", 25);
    set("dex", 27);
    
    set("max_qi", 400);
    set("max_jing", 400);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 15);
    set("combat_exp", 150000);
    set("score", 30000);
    set_skill("force", 110);
    set_skill("huagong-dafa", 115);
    set_skill("dodge", 110);
    set_skill("zhaixinggong", 110);
    set_skill("unarmed", 110);
    set_skill("chousui-zhang", 110);
    set_skill("parry", 110);
    set_skill("staff", 110);
    set_skill("tianshan-zhang", 110);
    set_skill("literate", 110);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "chousui-zhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
    create_family("������", 2, "����");
    setup();
//      carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
}
