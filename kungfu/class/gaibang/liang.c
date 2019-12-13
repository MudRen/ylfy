// sample master.c code
// xiake island master.c
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({"liang zhanglao", "liang", "zhanglao"}));
    set("title", "ؤ��Ŵ�����");
    set("nickname", "��������");
    set("gender", "����");
    set("age", 55);
    set("long", 
        "��������ؤ�������ã��书��ߵĳ��ϣ��������������Ѿá�\n"
        "ؤ���书������ǿ������������һ�����٣������������ϡ�\n");
    set("attitude", "peaceful");
    
    set("str", 28);
    set("int", 24);
    set("con", 24);
    set("dex", 25);
    set("qi", 900);
    set("max_qi", 900);
    set("jing", 400);
    set("max_jing", 400);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 120);
    
    set("combat_exp", 250000);
    
    set_skill("force", 200); 
    set_skill("huntian-qigong", 205); 
    set_skill("unarmed", 215); 
    set_skill("xianglong-zhang", 210); 
    set_skill("dodge", 210); 
    set_skill("xiaoyaoyou", 200); 
    set_skill("parry", 200); 
    set_skill("club", 200); 
    set_skill("dagou-bang", 200); 
    set_skill("begging", 200); 
    set_skill("checking", 200);
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("club", "dagou-bang");
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
        if (interactive(ob = this_player()) && !is_fighting()) 
    {
        myfam = (mapping)ob->query("family");
        if (!myfam || myfam["family_name"] != "ؤ��")
        {
            remove_call_out("saying");
            call_out("saying",1,ob);
        }
        }
}
void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;
    message_vision("\n�����Ͽ���$N�����������һ�����㲻��ؤ����ӣ����ҹ���ȥ��\n\n", ob);
    call_out("kicking", 0, ob); 
}
void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;
    ob->move("/d/gaibang/inhole");
    message("vision","ֻ����ƹ����һ����" + ob->query("name") +
        "��С������˳�����\n", environment(ob), ob);
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query("str") < 25) {
        command("say ����ؤ�������һ���Ը���Ϊ����" + 
        RANK_D->query_respect(ob) + "����̫�����ƺ�����ѧؤ��Ĺ���");
        return;
    }
    command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
    "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}
