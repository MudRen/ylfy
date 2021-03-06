//jiansheng.c by yushu 2000.11
inherit NPC;
#include <ansi.h>
void create()
{
       set_name("蜀山剑圣", ({"shushan jiansheng","jiansheng", "master"}));
       set("title", "蜀山派剑法之圣");
       set("gender", "男性");
       set("age", 120);
        set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
        set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
        set("int", 30);
       set("max_qi", 10000000);
       set("max_jing", 10000000);
       set("neili", 10000000);
	   set("jingli", 10000000);
       set("max_neili", 10000000);
        set("max_jingli", 10000000);
		set("combat_exp", 2100000000);
         set("jiali",30000);
		 set("no_suck", 1);
       set_skill("literate", 800);
       set_skill("dodge", 1500);
       set_skill("parry",  1500);
       set_skill("unarmed",  1500);
       set_skill("fumozhang", 1500); 
        set_skill("sword",  1500);
     set_skill("songhe-sword",  1500);
         set_skill("shushan-force",  1500);
        set_skill("force",  1500);
        set_skill("zuixian-steps",  1500);
       map_skill("force", "shushan-force");
        map_skill("sword", "songhe-sword");
        map_skill("parry", "songhe-sword");
        map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
                  (: cast_spell, "fu" :),
        }) );
        create_family("蜀山派", 2, "弟子");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
		carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{       ob=this_player();
       if ( !((string)ob->query("gender")=="男性")){
       command("shake");
       command("say 我只收男徒，这位" +RANK_D->query_respect(ob) + "还是去找酒剑仙吧。\n");
       return;
       }
       if( (string)ob->query("family/family_name")=="蜀山派") {
         if ((int)ob->query("combat_exp") < 300000 ) {
        command("say 你的道行还不够，对我的招法难以领悟。\n");
        return;
        }
        if( (int)ob->query_skill("force", 1) < 500 ) {
      command("say 这位" + RANK_D->query_respect(ob) + "你的身体这么差,你还是找追云子他们再练着吧!\n");
        command("sigh");
        return;
        }
       command("smile");
       command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，为蜀山争光。");
       command("recruit " + ob->query("id") );
        return;
        }
       command("shake");
       command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
       return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山剑圣亲传第子");

}

        return 0;
}
