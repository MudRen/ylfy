// azi.c ����
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("����", ({ "azi" }));
    set("nickname", "������Сʦ��");
    set("long", 
        "�����Ƕ�������Ӱ��ϡ�\n"
        "������������������������͸��һ��а����\n");
    set("gender", "Ů��");
    set("age", 15);
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("str", 18);
    set("int", 28);
    set("con", 20);
    set("dex", 24);
    
    set("max_qi", 300);
    set("max_jing", 300);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 10);
    set("combat_exp", 60000);
    set("score", 10000);
    set_skill("force", 100);
    set_skill("huagong-dafa", 100);
    set_skill("dodge", 100);
    set_skill("zhaixinggong", 100);
    set_skill("unarmed", 100);
    set_skill("chousui-zhang", 100);
    set_skill("parry", 100);
    set_skill("staff", 100);
    set_skill("tianshan-zhang", 100);
        set_skill("literate", 100);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "chousui-zhang");
    map_skill("parry", "xingxiu-duzhang");
    create_family("������", 2, "����");
    setup();
    carry_object("/d/xingxiu/obj/xxqingxin-san");
    carry_object("/d/xingxiu/obj/xxqingxin-san");
    carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
}
