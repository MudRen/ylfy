//shusheng.c
inherit NPC;
void create()
{
    set_name(HIY "����" NOR, ({"shu sheng"}));
    set("gender", "����");
    set("age", 42);
        set("per",28);
    set("long", 
        "�������������֮���������Ե��������ݣ����Ȳ�����\n");
    set("attitude", "peaceful");
    
    set("str", 71);
    set("int", 80);
    set("con", 86);
    set("dex", 140);
    set("chat_chance", 1);
    set("chat_msg", ({
        "������������һ���飬��ʱ�������С�\n",
    }));
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
    set_skill("yunlong-jian", 200);
    set_skill("yiyang-zhi", 200);
    set_skill("yunlong-shengong", 200);
    set_skill("yunlong-shenfa", 200);
    set_skill("unarmed", 200);           // ����ȭ��
    set_skill("dodge", 200);             // ��������
    set_skill("parry", 200);             // �����м�
    set_skill("sword", 200);             // ��������
    set_skill("literate",550);           // ����ʶ��
    
    map_skill("force"  , "yunlong-shengong");
    map_skill("unarmed", "yiyang-zhi");
    map_skill("dodge"  , "yunlong-shenfa");
    map_skill("parry"  , "yunlong-jian");
    map_skill("sword"  , "yunlong-jian");
    
    setup();
    carry_object("/clone/cloth/changpao")->wear();
    carry_object("/clone/weapon/changjian")->wield();   
}

void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("kill_shi",1);
           ::die();
}

