// gaibang npc code
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("�����", ({"yu hongxing", "yu", "hongxing"}));
    set("title", "ؤ��˴�����");
    set("gender", "����");
    set("age", 30);
    set("long", 
        "����λЦ���е�ؤ��˴����ӣ����Զ��ǣ����С���á�\n");
    set("attitude", "peaceful");
    set("str", 20);
    set("int", 30);
    set("con", 22);
    set("dex", 20);
    set("qi", 420);
    set("max_qi", 420);
    set("jing", 330);
    set("max_jing", 330);
    set("neili", 780);
    set("max_neili", 780);
    set("jiali", 42);
    
    set("combat_exp", 82000);
    
    set_skill("force", 148); 
    set_skill("huntian-qigong", 146); 
    set_skill("unarmed", 148); 
    set_skill("xianglong-zhang", 140); 
    set_skill("dodge", 140); 
    set_skill("xiaoyaoyou", 148); 
    set_skill("parry", 141); 
    set_skill("begging", 140); 
    set_skill("stealing", 140); 
    set_skill("checking", 140); 
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    
    create_family("ؤ��", 19, "����");
    setup();
    carry_object("//clone/cloth/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if( ob->query("int") < 25 ) return;
    command("say �����������Ϊ����ֻ���߹������˼Һ��Ҳ��ر���Щ����ͽ����");
    command("say ��Ҷ�ҪΪ��Զ���밡��");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}
