#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
    set("nickname", HIY "东邪" NOR );
    set("gender", "男性");
    set("age", 42);
    set("long", 
        "他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。\n");
    set("attitude", "peaceful");
    
    set("str", 100);
    set("int", 80);
    set("con", 86);
    set("dex", 240);
    set("chat_chance", 1);
    set("chat_msg", ({
        "黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
        "黄药师低头沉思，悠然不语。\n",
    }));
    set("inquiry", ([
        "黄蓉"     : "你敢直称我女儿的闺名？ \n",
        "九阴真经" : "如果你能帮我取得真经上册，我一定重重谢你。\n",
    ]));
	
    set("qi", 3000000);
    set("max_qi", 3000000);
    set("jing", 1500000);
    set("max_jing", 1500000);
    set("max_jingli", 200000);
    set("jingli", 30000);
    set("neili", 4000000);	
    set("max_neili", 500000);
    set("jiali", 13500);
    set("xyzx_sys/level", 1500);
    set("combat_exp", 60000000);
     
    set_skill("force", 2900);   
    set_skill("finger", 1900);	
    set_skill("count", 1300);	    
    set_skill("unarmed", 2000);  
    set_skill("dodge", 2100);  
    set_skill("parry", 2900);
    set_skill("sword", 2900);  
    set_skill("literate",2550); // 读书识字
	set_skill("luoying-zhang", 1860);
	set_skill("lanhua-shou", 1900);		
    set_skill("yuxiao-jianfa",1800);
	set_skill("bibo-shengong", 2190);
    set_skill("tanzhi-shentong", 1900);
    set_skill("xuanfeng-tui",1800);
	set_skill("anying-fuxiang", 1800);
	set_skill("luoying-shenjian", 1950);
    set_skill("qimen-wuxing",1800);
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "tanzhi-shentong");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("finger"  , "tanzhi-shentong");	
    map_skill("parry"  , "yuxiao-jianfa");
    map_skill("sword"  , "yuxiao-jianfa");	
    
    create_family("桃花岛", 1, "岛主");
    set("chat_chance_combat", 80); 
	setup();
    
    carry_object(__DIR__"obj/yuxiao")->wield();
    carry_object(__DIR__"obj/bupao")->wear();
    carry_object("/clone/book/jiuyin2");
	carry_object("d/taohua/obj/xiang");
    
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say 我不收资质差的弟子，您请回吧！");
        return;
    }
    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
        return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say 我桃花岛与世隔绝，向来不与您这种成名人物打交道，您请回吧！");
        return;
    }
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}
int accept_object(object who, object ob)
{
    
    if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
        if (!(int)who->query_temp("tmark/黄")) who->set_temp("tmark/黄", 0);
        message_vision("黄药师看了看$N送来的秘籍，点了点头，说道：\n"
                               "难得你将真经送回。你送我的东西我就收下了。\n"
                               "作为补偿,你可以从我这里学点功夫。\n", who);
        who->add_temp("tmark/黄", 120);
        return 1;
    }
    return 0;
}
int prevent_learn(object me, string skill)
{
        if ((int)me->query_temp("tmark/黄") && me->query("family/family_name")!="桃花岛")
        {
        if (!(int)me->query_temp("tmark/黄") )
        return 1;
      else
        return 0;
      }else return ::prevent_learn(me,skill);
}
int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
   if (mapp(myfam))
        if ( myfam["family_name"] == "桃花岛") return 1 ;
        if ((int)ob->query_temp("tmark/黄") == 1 )
        message_vision("黄药师看了看$N，说道：咱们现在是谁也不欠谁,\n"
                          "你不要再找我学习技艺了。\n", ob);
        if (!(int)ob->query_temp("tmark/黄"))
                return 0; 
        ob->add_temp("tmark/黄", -1);
        return 1;
}
