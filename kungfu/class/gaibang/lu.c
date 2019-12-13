// sample master.c code
// xiake island master.c
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
    set("title", "ؤ��Ŵ�����");
    set("nickname", "�ư���ͷ");
    set("gender", "����");
    set("age", 45);
    set("long", 
        "³�н���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
        "��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 12);
    set("con", 25);
    set("dex", 20);
    set("qi", 900);
    set("max_qi", 900);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 1200);
    set("max_neili", 1200);
    set("jiali", 100);
    
    set("combat_exp", 700000);
    
    set_skill("force", 150);                // �����ڹ�
    set_skill("huntian-qigong", 150);   // ��������
    set_skill("unarmed", 150);          // ����ȭ��
    set_skill("xianglong-zhang", 150);  // ����ʮ����
    set_skill("dodge", 150);                // ��������
    set_skill("xiaoyaoyou", 150);       // ��ң��
    set_skill("parry", 150);                // �����м�
    set_skill("club", 150);             // ��������
    set_skill("begging", 150);
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("parry", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    
    create_family("ؤ��", 18, "�Ŵ�����");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.xianglong" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("//clone/cloth/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") < 5000) {
        command("say ��ؤ��������֮�ţ����¹������䡣");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
    "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}
