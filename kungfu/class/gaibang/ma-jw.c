// gaibang npc code
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("���Ϊ", ({"ma juwei", "ma", "juwei"}));
    set("title", "ؤ���ߴ�����");
    set("gender", "����");
    set("age", 35);
    set("long", 
        "����λ���վ�ǿ��ȴ��Ĭ���Ե�ؤ��˴����ӡ�\n");
    set("attitude", "peaceful");
    set("str", 23);
    set("int", 22);
    set("con", 18);
    set("dex", 25);
    set("qi", 460);
    set("max_qi", 460);
    set("jing", 300);
    set("max_jing", 300);
    set("neili", 710);
    set("max_neili", 710);
    set("jiali", 36);
    
    set("combat_exp", 95000);
    
    set_skill("force", 100); 
    set_skill("huntian-qigong", 100); 
    set_skill("unarmed", 100); 
    set_skill("xianglong-zhang", 100); 
    set_skill("dodge", 100); 
    set_skill("xiaoyaoyou", 100); 
    set_skill("parry", 100); 
    set_skill("club", 100);             // ��������
    set_skill("begging", 100); 
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("parry", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    
    create_family("ؤ��", 19, "����");
    setup();
    carry_object("//clone/cloth/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if( ob->query("con") < 20 ) return;
    command("say �����Ϊʦ����Ҫ���óԿ��׼�����ú�����ؤ����ӣ�");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}
