// gaibang npc code
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("����", ({"li sheng", "li", "sheng"}));
    set("title", "ؤ��˴�����");
    set("gender", "����");
    set("age", 38);
    set("long", 
        "����λ���Ը�ֱ����������ؤ��˴����ӡ�\n");
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 18);
    set("con", 20);
    set("dex", 23);
    set("max_qi", 390);
    set("max_jing", 300);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 40);
    
    set("combat_exp", 79000);
    
    set_skill("force", 100); 
    set_skill("huntian-qigong", 100); 
    set_skill("unarmed", 100); 
    set_skill("xianglong-zhang", 100); 
    set_skill("dodge", 100); 
    set_skill("xiaoyaoyou", 100); 
    set_skill("parry", 100); 
    set_skill("club", 100); 
    set_skill("begging", 100); 
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    
    create_family("ؤ��", 19, "����");
    setup();
    carry_object("//clone/cloth/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if( ob->query("shen") < 0 ) return;
    command("say �ã���������һ��һ���˲�����ͽ�ܣ��һ�ϲ���������أ�");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}
