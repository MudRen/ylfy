// gaibang npc code
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("�β���", ({"he bujing", "he", "bujing"}));
    set("title", "ؤ���ߴ�����");
    set("gender", "����");
    set("age", 30);
    set("long", 
        "����λ������������ͷ�����ؤ���ߴ����ӡ�\n");
    set("attitude", "heroism");
    set("class", "beggar");
    set("str", 28);
    set("int", 18);
    set("con", 24);
    set("dex", 20);
    set("qi", 380);
    set("max_qi", 380);
    set("max_jing", 300);
    set("neili", 680);
    set("max_neili", 680);
    set("jiali", 34);
    
    set("combat_exp", 90000);
    
    set_skill("force", 80); 
    set_skill("huntian-qigong", 85); 
    set_skill("unarmed", 85); 
    set_skill("xianglong-zhang", 85); 
    set_skill("dodge", 85); 
    set_skill("xiaoyaoyou", 80); 
    set_skill("parry", 85); 
    set_skill("begging", 80); 
    set_skill("stealing", 80); 
    
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
    if( ob->query("combat_exp") < 30000 ) return;
    command("say ��ܰ���ܰɣ� ���������ðɣ��Ҿ��������ˣ�");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}
