// xiaoyaozi.c 逍遥子
// shilling 97.2

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("逍遥子", ({ "xiaoyao zi", "xiaoyao","zi" }));
       set("title", "逍遥派开山祖师");
       set("long", 
               "他就是逍遥派开山祖师、但是因为逍遥派属于一个在江湖中\n"
               "的秘密教派，所以他在江湖中不是很多人知道，但其实他的\n"
               "功夫却是。。。。他年满七旬，满脸红光，须眉皆白。\n");
       set("gender", "男性");
       set("age", 75);
       set("shen_type", 1);
       set("str", 40);
       set("int", 40);
       set("con", 40);
       set("dex", 40);
       set("per", 40);
       
       set("max_qi", 2005500);
       set("max_jing", 1553000);
       set("neili", 3000000);
       set("max_neili", 3000000);
       set("jingli", 200000);
       set("max_jingli", 100000);
       set("jiali", 5100);
       set("combat_exp", 15000000);
       set("score", 200000);
       set("xyzx_sys/level", 1500);
	   
      set_skill("force", 2500);
      set_skill("beiming-shengong", 600); 
       set_skill("dodge", 2550);   
      set_skill("lingboweibu", 1550);   
       set_skill("unarmed", 2500);    
       set_skill("liuyang-zhang", 1480);   
       set_skill("parry", 2500);   
       set_skill("blade", 2500);   
       set_skill("ruyi-dao", 1480);   
       set_skill("zhemei-shou", 1550);   
      set_skill("literate", 2600);

       map_skill("force", "beiming-shengong");
       map_skill("dodge", "lingboweibu");
       map_skill("unarmed", "zhemei-shou");
       map_skill("parry", "ruyi-dao");
       map_skill("blade", "ruyi-dao");

       create_family("逍遥派", 1, "开山祖师");
       set("class", "taoist");

       setup();
}

void attempt_apprentice(object ob)
{
       if ((int)ob->query_skill("beiming-shengong", 1) < 80) {
               command("say 我逍遥派内功的源泉来自于北冥神功的心法。"); 
               command("say " + RANK_D->query_respect(ob) + 
                       "的北冥神功是否还应该有所提高啊？");
               return;
       }

       if (ob->query_int() < 35) {
               command("say 我逍遥派武功最重视“逍遥”二字。");
               command("say 而何谓“逍遥”，这只能靠你自己去领悟。");
               command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
               return;
       }
       command("smile");
       command("say 想不到在这世上竟然还有人可以继承我的逍遥心法！");
       command("recruit " + ob->query("id"));
       ob->set("title","逍遥派护法使者");
}

