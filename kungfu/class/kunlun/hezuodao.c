// masteryue.c
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�����", ({ "he zudao", "master","he" }) );
        set("title", "������ʥ");
        set("nickname", "����ʥ");        
        set("gender", "����");
        set("age", 162);
        set("long","�����������ɵĿ�ɽ��ʦ���������˳ơ�������ʥ���ĺ������\n");        
        set("attitude", "peaceful");
        set("str", 85);
        set("int", 85);
        set("con", 80);
        set("per", 25);
        set("dex", 140);		
		set("xyzx_sys/level", 2000);
		set("max_qi", 2000000);
		set("max_jing", 1000000);
        set("jingli", 800000);
        set("max_jingli",1000000);
        set("neili", 3150000);
        set("max_neili", 700000);
        set("jiali", 13000);
        set("rank_info/respect", "��ʦ��");        
        set("combat_exp",27500000);
 
        set_skill("force", 2650);
        set_skill("dodge", 2650);
        set_skill("parry", 2650);
        set_skill("xuantian-wuji", 1650);
        set_skill("sword", 2650);
        set_skill("literate",2600);
        set_skill("xunlei-sword", 1650);
        set_skill("unarmed", 2650);
        set_skill("kunlun-zhang",1650);
        set_skill("throwing",2650);
        set_skill("yaoming-dodge", 1650);
        set_skill("mantianhuayu", 1250);
    
        map_skill("dodge", "yaoming-dodge");
        map_skill("force", "xuantian-wuji");
        map_skill("unarmed","kunlun-zhang");
        map_skill("throwing","mantianhuayu");
        map_skill("parry", "xunlei-sword");
        map_skill("sword", "xunlei-sword");
    
    create_family("������", 13, "��ʥ");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
    carry_object("/d/kunlun/obj/qizi")->wield();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{   
        if ((int)ob->query_skill("xuantian-wuji", 1) < 276) 
           {
        command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö��������ŵ��ڹ��ķ���");
        return;
       }
    command("recruit " + ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
