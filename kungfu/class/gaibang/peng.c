// sample master.c code
// xiake island master.c
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("���о�", ({"peng youjing", "peng", "youjing"}));
    set("title", "ؤ��Ŵ�����");
    set("nickname", "�Ʋ���ͷ");
    set("gender", "����");
    set("age", 50);
    set("long", 
        "���о���ؤ���о����ɵ����죬���Ÿɾ�����������л��ӡ�\n"
        "�����Ϲ��Ŵ����Ц�ݣ�һ˫�۾����������ǵ�������\n");
    set("attitude", "peaceful");
    
    set("str", 24);
    set("int", 20);
    set("con", 24);
    set("dex", 20);
    set("qi", 900);
    set("max_qi", 900);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 1300);
    set("max_neili", 1200);
    set("jiali", 100);
    
    set("combat_exp", 220000);
    
    set_skill("force", 120);                // �����ڹ�
    set_skill("huntian-qigong", 120);   // ��������
    set_skill("unarmed", 120);          // ����ȭ��
    set_skill("xianglong-zhang", 120);  // ����ʮ����
    set_skill("dodge", 120);            // ��������
    set_skill("xiaoyaoyou", 120);       // ��ң��
    set_skill("parry", 120);                // �����м�
    set_skill("club", 120);             // ��������
    
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
    command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}
