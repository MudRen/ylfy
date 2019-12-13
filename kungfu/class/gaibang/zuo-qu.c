// gaibang npc code
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��ȫ", ({"zuo quan", "zuo", "quan"}));
    set("title", "ؤ���ߴ�����");
    set("gender", "����");
    set("age", 35);
    set("long", 
        "����λ��ˬ�󷽵�ؤ���ߴ����ӣ������Ǹ����غ��ܡ�\n");
    set("attitude", "peaceful");
    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 26);
    set("qi", 360);
    set("max_qi", 360);
    set("jing", 300);
    set("max_jing", 300);
    set("neili", 710);
    set("max_neili", 710);
    set("jiali", 36);
    
    set("combat_exp", 68000);
    
    set_skill("force", 110); 
    set_skill("huntian-qigong", 110); 
    set_skill("unarmed", 110); 
    set_skill("xianglong-zhang", 110); 
    set_skill("dodge", 110); 
    set_skill("xiaoyaoyou", 110); 
    set_skill("parry", 110); 
    set_skill("begging", 110); 
    set_skill("checking", 110); 
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    
    create_family("ؤ��", 19, "����");
    setup();
    carry_object("//clone/cloth/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if( ob->query("gender") != "����") return;
    command("say �ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}
