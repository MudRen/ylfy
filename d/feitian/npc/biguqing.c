//Npc 比古清十郎
//diabio(青云)2003.3.1
#include <ansi.h>
inherit NPC;
int ask_tianxiang();
inherit F_MASTER;
void create()
{
        set_name("比古清十郎", ({ "biguqing shilang", "shilang" }));
        set("long", "他就是绯村剑心的师傅。 \n");
        set("title", HIR"飞天御剑流"HIY"当代掌门人"NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude","peaceful");
        set("str", 500);
        set("dex", 500);
        set("con", 500);
        set("int", 500);
        set("per", 500);  
        set("tianyu_1",1);
        set("jing", 2500000);
        set("max_jing", 2500000);  
        set("qi", 5200000);
        set("jiali", 200000);
        set("max_qi", 5200000);
        set("jingli", 320000);
		set("max_jingli", 320000);
        set("neili", 14000000);
        set("max_neili", 4000000);
        set("combat_exp", 2100000000);
        set("xyzx_sys/level", 3800); 
		
        set_skill("dodge",4000);      
        set_skill("unarmed",4000);
        set_skill("parry",4000);
        set_skill("blade",4800);
        set_skill("feitian-yujianliu",2800);
        set_skill("wuxing-dun",2800);
        set_skill("shayi",2800);
        set_skill("aikido",2800);
        set_skill("shayi-xinfa",2800);
        set_skill("shiren-jianfa",2800);
        set_skill("shiren-quanfa",2800);
        set_skill("force",3000);
        set_skill("huoxinliu-jianfa",2800);
        set_skill("literate",2500);

        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
        map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        create_family("飞天御剑流", 5, "传人");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
                set("inquiry", ([
           "飞天御剑流":     "自战国时代开始以流传了三百年的武功。",
           "天翔龙闪": (:ask_tianxiang:),
           "绯村剑心":   "他是我那不孝徒儿。"]) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/wushidao")->wield();
}

void attempt_apprentice(object ob)
{
        if(ob->query("family/family_name")!="飞天御剑流")
        {
                command("say 非我派弟子不能学我功夫。\n");
          return 0;
        }
        if(ob->query("combat_exp")<1000000)
        {
                 command("say 你的实战经练不够，我不能传授你功夫。\n");
            return 0;
        }
       	if ((int)ob->query_skill("huoxinliu-jianfa", 1) < 200) {
		command("say 你的活心流剑法太低了，还未能领悟活心二字如何学习我的武功呢。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把活心流剑法先提高了在来吧？");
		return;
        }
	if ((int)ob->query_skill("shayi-xinfa", 1) < 200) {
		command("say 你的杀意心法太低,恐怕控制不了杀意。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把杀意心法先提高了在来吧？");
		return;
	}
	if ((int)ob->query_skill("aikido", 1) < 200) {
		command("say 你的空手道太低。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把空手道先提高了在来吧？");
		return;
	}
	if ((int)ob->query_skill("wuxing-dun", 1) < 200) {
		command("say 你的五行遁太低。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把五行遁先提高了在来吧？");
		return;
	}
    if ((int)ob->query_skill("shayi", 1) < 200)
    {
        command("say 剑法之道在于杀意。");
        command("say " + RANK_D->query_respect(ob) +
            "你的杀意太低了？");
        return;
    }
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"【飞天御剑流】"HIR"传人"NOR);
       ob->set("class", "yujianliu");
}
int ask_tianxiang()
{
    object ob;
    ob = this_player();

    tell_object(ob,"比古清十郎说道：天降龙闪乃最高剑决，如要学会需和我以命相拼才行，你如想清楚了就跟我来陶窑！\n"); 
      command("go south");
      command("go west");
   command("sigh");
   return 1;
}
void kill_ob(object me)
{
if(!this_player())
{
::kill_ob(me);
return;
}
 if(this_player()->query("family/family_name")=="飞天御剑流")
{
	command("say 你可要小心了，拿出你必生功力来杀我。\n");
       this_player()->set("feitian/bigu",1);
	::kill_ob(me);
}
}
               
void die()
{
        object ob, me;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (me && me->query("family/family_name")=="飞天御剑流")
{ 
        message_vision("\n$N道：“你不必难过，飞天御剑流代代传人都是如此，如要学会最高剑决掌门就需陪上性命，你不必太难过。\n", this_object());
me->set("feitian/tianxiang",1);
message_vision("\n在生死一线中你体会到了天翔龙闪的精髓。\n", this_object());
}
::die();
}