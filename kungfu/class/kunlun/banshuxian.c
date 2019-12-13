//master ban by wyz
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("班淑娴", ({ "ban shuxian", "ban", "shuxian"}) );
        set("title", YEL "掌门夫人" NOR);
        set("gender", "女性");
        set("age", 38);
        set("long",
         "她就是昆仑派掌门何太冲的妻子。她脾气粗暴，气量狭窄
昆仑上下都对她十分畏惧。她已是三十出头了，仍是风韵尤存。\n");        
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
        set("rank_info/respect", "掌门夫人");        
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
 

    create_family("昆仑派", 14, "掌门夫人");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "女性" )
          {        
          command("say 男人都不是好东西，给我滚。");
            return;
		}

        if ((int)ob->query_skill("force", 1) < 50) 
           {
        command("say " + RANK_D->query_respect(ob) + "是否还应该多练练内功心法？");
        return;
       }

    command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
}
