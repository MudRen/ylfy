// yelvqi.c 耶律齐

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;

void create()
{
set_name("耶律齐", ({ "yelv qi", "yelv", "qi" }));	
        set("title", "全真教第二代弟子 丐帮第二十一代帮主");
        set("gender", "男性");
        set("age", 25);
        set("per", 25);
        set("long",
        "郭靖和黄蓉的大女婿，郭芙的丈夫。\n",);

        set("combat_exp", 600000);
        set("shen_type", 1);

        set("max_neili", 2000);
        set("neili", 2000);
        set("jiali", 0);

        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("hubo" ,200);
        set_skill("haotian-zhang" ,200);
        set_skill("quanzhen-jianfa" ,200);
        set_skill("kongming-quan",200);
        map_skill("unarmed","kongming-quan");
        map_skill("strike","haotian-zhang");
        map_skill("sword","quanzhen-jianfa");
        map_skill("parry","quanzhen-jianfa");

        create_family("全真教", 2, "弟子");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
