// sample master.c code
// xiake island master.c
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("����", ({"jian zhanglao", "jian", "zhanglao"}));
    set("title", "ؤ��Ŵ�����");
    set("nickname", "ִ������");
    set("gender", "����");
    set("age", 50);
    set("long", 
        "������ؤ���ִ�����ϣ�������ִ�Ʒ����Լ�������ȡ�\n"
        "������������𣬵�������˭���������־������顣\n");
    set("attitude", "peaceful");
    
    set("str", 24);
    set("int", 20);
    set("con", 24);
    set("dex", 20);
    set("qi", 900);
    set("max_qi", 900);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 1500);
    set("max_neili", 1500);
    set("jiali", 100);
    
    set("combat_exp", 150000);
    
    set_skill("force", 105);            // �����ڹ�
    set_skill("huntian-qigong", 100);   // ��������
    set_skill("unarmed", 100);          // ����ȭ��
    set_skill("xianglong-zhang", 105);  // ����ʮ����
    set_skill("dodge", 100);            // ��������
    set_skill("xiaoyaoyou", 100);       // ��ң��
    set_skill("parry", 105);            // �����м�
    set_skill("club", 100);             // ��������
    
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
void init()
{
        object ob;
    mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
        myfam = (mapping)ob->query("family");
        if ((!myfam || myfam["family_name"] != "ؤ��") &&
            (!wizardp(ob))) {
            remove_call_out("saying");
            call_out("saying",5,ob);
        }
        }
}
void saying(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
    message_vision("\n���Ͽ���$Nһ�ۣ������˵����������������˼�˵�Ҳ���"
        "�������ؤ����ӣ�\n���ֲ�����ؤ��Ҵ����ܿ��԰ɣ���\n"
        "˵������һ̧��$N˳��Ӧ��һ������ɵġ�ƨ�����ƽɳ����ʽ��"
        "������ߴ\n\n", ob);
    remove_call_out("kicking");
    call_out("kicking",10,ob);
    
}
void kicking(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
    ob->move("/d/city/pomiao");
     message("vision","ֻ�����ء���һ����������" +  ob->query("name") +
        "��С������˳�����ƨ������һ�������Ьӡ��\n", environment(ob), ob);
}
void attempt_apprentice(object ob)
{
    command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}
