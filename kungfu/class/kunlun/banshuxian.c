//master ban by wyz
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�����", ({ "ban shuxian", "ban", "shuxian"}) );
        set("title", YEL "���ŷ���" NOR);
        set("gender", "Ů��");
        set("age", 38);
        set("long",
         "���������������ź�̫������ӡ���Ƣ���ֱ���������խ
�������¶�����ʮ��η�塣��������ʮ��ͷ�ˣ����Ƿ����ȴ档\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",1000);
        set("max_jingli",2000);
        set("neili", 11500);
        set("max_neili", 5500);
        set("jiali",300);
        set("rank_info/respect", "���ŷ���");        
        set("combat_exp",3300000);
 
           set_skill("force", 290);
           set_skill("dodge", 290);
           set_skill("parry", 290);
           set_skill("xuantian-wuji", 290);
           set_skill("sword", 290);
           set_skill("literate",290);
           set_skill("liangyi-jian", 290);
           set_skill("yaoming-dodge", 320);
           set_skill("kunlun-zhang",300);
           set_skill("unarmed",300);
           
           map_skill("dodge", "yaoming-dodge");
           map_skill("force", "xuantian-wuji");
           map_skill("parry", "liangyi-jian");
           map_skill("sword", "liangyi-jian");
           map_skill("unarmed","kunlun-zhang");   
 

    create_family("������", 14, "���ŷ���");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {        
          command("say ���˶����Ǻö��������ҹ���");
            return;
		}

        if ((int)ob->query_skill("force", 1) < 50) 
           {
        command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������ڹ��ķ���");
        return;
       }

    command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
}
