// yu.c ������
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "yu lianzhou", "yu" }));
    set("nickname", "�䵱����");
    set("long", 
        "������������Ķ����������ۡ�\n"
        "��������ʮ�꣬��Ŀ��࣬�������ء�\n"
        "�����䵱�����������ڶ�������ȴ�����\n");
    set("gender", "����");
    set("age", 50);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 28);
    set("int", 28);
    set("con", 28);
  set("per",30);
    set("dex", 28);
    
    set("max_qi", 1500);
    set("max_jing", 800);
    set("neili", 2000);
    set("max_neili", 2000);
    set("jiali", 50);
    set("combat_exp", 250000);
    set("score", 80000);
    set_skill("force", 200);
    set_skill("taiji-shengong", 180);
    set_skill("dodge", 120);
    set_skill("tiyunzong", 180);
    set_skill("unarmed", 180);
    set_skill("taiji-quan", 180);
    set_skill("parry", 100);
    set_skill("sword", 130);
    set_skill("taiji-jian", 130);
    set_skill("taoism", 180);
    set_skill("literate", 50);
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
    carry_object("/d/wudang/obj/whiterobe")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") < 100) {
        command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
        command("say " + RANK_D->query_respect(ob) + "��������" +
            "��������֮�£���һ�����㡣");
        return;
    }
    command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
        "�ұ����ˣ������������ɡ�");
    command("recruit " + ob->query("id"));
}
