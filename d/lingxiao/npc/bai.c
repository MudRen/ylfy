//LUCAS 2000-6-18
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("白自在",({"bai zizai","bai"}));
        set("nickname", HIC"威德先生"NOR);
        set("gender", "男性");
        set("age", 55);
        set("long", 
             "他就是雪山剑派的掌门人，习武成性，自认为天下武功第一,\n"
             "他大约五十多岁，精明能干，嫉恶如仇，性如烈火。\n");
        set("attitude", "peaceful");
        set("str", 35);
        set("con", 35);
        set("int", 30);
        set("dex", 30);
        set("per", 25);
        set("neili", 2400000);
        set("max_neili", 1900000);	
        set("jing", 800000);
        set("max_jing", 800000);
        set("qi", 1800000);
        set("max_qi", 1800000);
        set("jiali", 8000);
        set("xyzx_sys/level", 1500);
        set("combat_exp", 3000000);
        set("shen_type", 1);
        set("score", 100000);

        set_skill("unarmed", 2500);
        set_skill("sword", 3000);
        set_skill("force", 3000);
        set_skill("parry", 2500);
        set_skill("dodge", 2500);
        set_skill("literate", 2000);

        set_skill("xueshan-jianfa", 1300);	
        set_skill("bingxue-xinfa", 1300);
        set_skill("snow-zhang", 1300);
        set_skill("snowstep", 1300);

        map_skill("sword", "xueshan-jianfa");	
        map_skill("parry", "xueshan-jianfa");	
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("凌霄城", 5, "掌门");
		set("inquiry", ([
            "石中玉"   : "如果让我逮到这个小王八蛋,我非剥了他的皮不可。",
        ]) );

        setup();
		
        carry_object("/d/lingxiao/obj/icesword")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say 你这种资质,也好意思来找我！");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 80 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
                return;
    } 
    if ((int)ob->query("shen") < 50000 ) {
         command("say 我威德先生乃堂堂正人君子，怎能收你。"); 
                return;
    } 
    if ((int)ob->query("max_neili") < 800 ) {
         command("say 你内力不足，怎能领悟我神功的精妙。"); 
                return;
    }
if ((int)ob->query_skill("xueshan-jianfa",1) < 150 ) { 	
        command("say 你的本门剑法太低了,还是先找你原来的师父提高吧!"); 
                return;
    }
    if ((int)ob->query_skill("sword",1) < 100 ) {  
        command("say 你的基本剑法太低了,还是先提高基本功吧!"); 
                return; 
    }
    command("say 很好，很好,老子今天心情好,就收下你吧。");
    command("say 这个城老子没心情管了，你就先帮我管着吧。");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", HIW"凌霄城城主"NOR); 
}

