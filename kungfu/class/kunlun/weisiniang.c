//master ban by wyz
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({"wei shiniang","wei","shiniang"}) );
        set("title", MAG "������" NOR);
        set("gender", "Ů��");
        set("age", 25);
        set("long",
        "�����������ɣ����������˳ơ������֡����������\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",1000);
        set("max_jingli",2000);
        set("neili", 5500);
        set("max_neili", 2500);
        set("jiali",100);
        set("combat_exp",1064800);
 
           set_skill("force", 190);
           set_skill("dodge", 190);
           set_skill("parry", 190);
           set_skill("xuantian-wuji", 190);
           set_skill("sword", 190);
           set_skill("literate",190);
           set_skill("liangyi-jian", 190);
           set_skill("yaoming-dodge", 190);
           set_skill("kunlun-zhang",220);
           set_skill("unarmed",220);
           
           map_skill("dodge", "yaoming-dodge");
           map_skill("force", "xuantian-wuji");
           map_skill("parry", "liangyi-jian");
           map_skill("sword", "liangyi-jian");
           map_skill("unarmed","kunlun-zhang");   
 

    create_family("������", 15,"����");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {        
          command("say ���˶����Ǻö��������ҹ���");
            return;
                }

}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}

