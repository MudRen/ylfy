//【蜀山派】mhxy-yushu 2001/2
// lilong alter 2002.01.19
inherit NPC;
#include <ansi.h>
string expell_me(object me);
int ask_jiu();
void create()
{
       set_name("酒剑仙", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", HIC"醉道士"NOR);   
       set("long", "一人人送外号“酒剑仙”，行踪不定，或游历于名山大川之畔，或隐匿于街头闹市之中。\n");
       set("gender", "男性");
       set("age", 68);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("max_qi", 10000000);
       set("max_jing", 10000000);
       set("neili", 10000000);
	   set("jingli", 10000000);
       set("max_neili", 10000000);
        set("max_jingli", 10000000);
		set("combat_exp", 2100000000);
         set("jiali",30000);
		 set("no_suck", 1);
        set_skill("shushan-force", 1500);
      set_skill("yujianshu", 1500);
      set_skill("fumozhang", 1500); 
      set_skill("zuixian-steps", 1500);
       set_skill("sword", 1500);
       set_skill("unarmed", 1500);
       set_skill("dodge", 1500);
       set_skill("literate",1500);
       set_skill("force", 1500);
       set_skill("parry", 1500);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
       set("inquiry", ([
                  "下山": (: expell_me :),
                 "leave": (: expell_me :),

       ]) );
       create_family("蜀山派", 2, "弟子");
       setup();
      carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="蜀山派") {
         if ((int)ob->query("combat_exp") < 8000000 ) {
  	command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力才行。\n");
	return;
	}
       if( (int)ob->query_skill("force", 1) < 500 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "你看你的猴样还来找我拜师? 你还是找追云子他们练着吧!\n");
	command("sigh");
	return;
	}
       command("haha");
       command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
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
                ob->set("title", "蜀山酒剑仙弟子");

               } 
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="蜀山派") {
                me->set_temp("betray", 1);
                return ("你真的要离开吗?你要付出一些代价,你可愿意(agree)?");
        }
        return ("不知。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/shushan", 1);
		  this_player()->set("combat_exp", this_player()->query("combat_exp")/100*95);
                if( this_player()->query_skill("shushan-force") )
		  this_player()->delete_skill("shushan-force");
                command("say 那你去吧！\n");
                return 1;
                }
        return 0;
}

int ask_jiu()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "蜀山派")
    {
    command("say 你又不是蜀山派的，谁管你！");
    return 1;
    }
}