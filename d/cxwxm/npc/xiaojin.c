// xiaojin.c 萧劲
// marry 99.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("萧劲", ({ "xiao jin", "xiao","jin" }));
        set("nickname", HIB "旋风斧" NOR);
        create_family("痴心妄想门", 3,"弟子");
        set("jihao",1);
        set("long","他就是痴心妄想门的二师兄“旋风斧”萧劲。");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 100);
        set("combat_exp", 10000000);
        set("score", 100000);

        set_skill("force", 230);
        set_skill("dodge", 240);
        set_skill("unarmed",250);
        set_skill("parry", 220);
        set_skill("axe", 250);
        set_skill("literate", 250);
        set_skill("wangxiang-fufa", 260);
        set_skill("shuiyue", 270);
        set_skill("wangran-xinfa", 230);
        set_skill("cxwx-quan", 200);
    
        map_skill("force", "wangran-xinfa");
        map_skill("axe", "wangxiang-fufa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "wangxiang-fufa");
        map_skill("dodge", "shuiyue");
               
        set("chat_chance_combat", 60);
        setup();
        carry_object("/d/cxwxm/obj/axe.c")->wield();
        carry_object("/d/cxwxm/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        int n;
        n = ob->query("combat_exp");
        if ((int)ob->query("shen") < 0) {
                command("say 本门最忌无耻之徒，快滚吧！");
                command("say 你这种败类，" + RANK_D->query_respect(ob) +
                        "快滚吧！");
                return;
        }
/*
        if ((!ob->query("lunhui"))&&(n > 500000))
                {
                command("say 对不起！本门不收江湖人物！");
                return;
        }
        if ((ob->query("lunhui"))&&(n > 10000000))
                {                command("say 对不起！本门不收江湖人物！");
                return;
        }
*/
        if ((string)ob->query("family/family_name",1)) 
       {
                command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜我呢？");
                return;
        }
      if ((int)ob->query("per") < 28) {
                command("say 本门武功非绝世容貌不可习得！");
                command("say 你还是去美容后再来吧!");
                return;
        }
 
        if (ob->query_int() < 25) {
                command("say 本门武功全凭痴心妄想。");
                command("say 要想修到最高境界，你的悟性还不够");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
                 return;
        }
   if ((string)ob->query("gender")=="男性")
   {
                message_vision("萧劲仔细的望了你片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
                 ob->set("xiaojin",1);
                       return;}
   else
      {
                message_vision("对不起！我只收男徒。\n",ob);
       return;}
        

}

