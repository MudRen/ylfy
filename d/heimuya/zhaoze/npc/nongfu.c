//nongfu.c
inherit NPC;
void create()
{
    set_name(CYN "ũ��" NOR, ({"nong fu"}));
    set("gender", "����");
    set("age", 42);
    set("per", 20);
    set("long", 
        "����ɫ��׳����̬�뺷������������ƴ󽫾���������硣\n");
    set("attitude", "peaceful");
    
    set("str", 151);
    set("int", 80);
    set("con", 86);
    set("dex", 140);
    set("chat_chance", 5);

    set("qi", 2000);
    set("max_qi", 2000);
    set("jing", 2000);
    set("max_jing", 2000);
    set("max_jingli", 1000);

    set("jingli", 1000);
    set("neili", 10000);
    set("max_neili", 1000);
    set("jiali", 300);
    
    set("combat_exp", 400000);
     
    set_skill("force", 200);             // �����ڹ�
    set_skill("weituo-gun", 200);
    set_skill("yiyang-zhi", 200);
    set_skill("yunlong-shengong", 200);
    set_skill("yunlong-shenfa", 200);
    set_skill("club", 200);
    set_skill("unarmed", 200);           // ����ȭ��
    set_skill("dodge", 200);             // ��������
    set_skill("parry", 200);             // �����м�
    
    map_skill("force"  , "yunlong-shengong");
    map_skill("unarmed", "yiyang-zhi");
    map_skill("dodge"  , "yunlong-shenfa");
    map_skill("parry"  , "weituo-gun");
    map_skill("club"  , "weituo-gun");
    
    setup();
    carry_object("/clone/cloth/cloth")->wear();
    carry_object("/clone/weapon/club")->wield();   
}

void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("kill_shi",1);
           ::die();
}

