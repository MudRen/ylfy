// guxu.c ����
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("�������", ({ "guxu daozhang", "guxu" }));
    set("long", 
        "�����������۵ĵ��ӹ��������\n"
        "��������ʮ�꣬�����䵱�ɵ����¡�\n");
    set("gender", "����");
    set("age", 40);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 25);
    
    set("max_qi", 1000);
    set("max_jing", 800);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 30);
    set("combat_exp", 70000);
    set("score", 8500);
    set_skill("force", 100);
    set_skill("taiji-shengong", 100);
    set_skill("dodge", 100);
    set_skill("tiyunzong", 100);
    set_skill("unarmed", 100);
    set_skill("taiji-quan", 100);
    set_skill("parry", 100);
    set_skill("sword", 100);
    set_skill("taiji-jian", 100);
    set_skill("taoism", 100);
    set_skill("literate", 100);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    create_family("�䵱��", 3, "����");
    set("class", "taoist");
    set("inquiry", 
        ([
            "���¾�" : (: ask_me :),
        ]));
                                
    set("book_count", 1);
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/greenrobe")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") < 0) {
        command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    command("say �ðɣ�ƶ�����������ˡ�");
    command("recruit " + ob->query("id"));
}
string ask_me()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) 
        || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵĵ����澭���ڴ˴���";
        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}
