// beijinyi.c 贝锦仪
// create by host dec,16 1997

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("贝锦仪", ({ "bei jinyi", "bei", "jinyi"}));
        set("long",
      "她是一位峨嵋派的俗家女弟子，长的清丽脱俗，在峨嵋派中专门收一些喜好武功的俗家弟子。\n");
        set("gender", "女性");
        set("age", 28);
//  14          set("attitude", "friendly");	
        set("shen_type", 1);
        set("str", 21);
        set("int", 21);
        set("con", 23);
        set("dex", 20);

        set("qi", 650);
        set("max_qi", 650);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 500);
        set("max_neili", 500);

        set("combat_exp", 200000);
      
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("huifeng-jian",100);
        set_skill("zhutian-bu",100);
        set_skill("linji-zhuang",100);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");
        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");  
      
        create_family("峨嵋派", 5,"弟子");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }
#include "/kungfu/class/emei/sujia.h"
