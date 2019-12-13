// chen.c 陈近南
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_weiwang();
string ask_me();
void create()
{
    set_name("陈近南", ({ "chen jin nan", "chen","nan" }));
    set("nickname", HIC "英雄无敌" NOR);
    set("long", 
        "\n这是一个文士打扮的中年书生，神色和蔼。\n"
        "他就是天下闻名的天地会总舵主陈近南,\n"
        "据说十八般武艺，样样精通。\n"
        "偶尔向这边看过来，顿觉他目光如电，英气逼人。\n");
    set("gender", "男性");
    set("age", 45);
    set("attitude", "peaceful");
    set("shen_type", 5);
    set("str", 50);
    set("int", 50);
    set("con", 60);
    set("dex", 160);
    
    set("max_qi", 2115000);
    set("max_jing", 1322000);
    set("neili", 3225000);
    set("max_neili", 525000);
    set("jiali", 13000);
    set("combat_exp", 6400000);
    set("score", 500000);
	set("xyzx_sys/level", 1500);//2015.9修改门派掌门级别的npc的强度
	
    set_skill("literate", 2420);
    set_skill("force", 2400);
    set_skill("dodge", 2400);
    set_skill("unarmed", 2400);
    set_skill("parry", 2400);
    set_skill("whip", 2400);
    set_skill("blade", 2400);
    set_skill("sword",2400);
    set_skill("houquan", 1400);
    set_skill("yunlong-xinfa", 1400);
    set_skill("yunlong-shengong", 1400);
    set_skill("wuhu-duanmendao", 1400);
    set_skill("yunlong-jian", 1400);
    set_skill("yunlong-shenfa", 1400);
    set_skill("yunlong-bian", 1400);
    set_skill("yunlong-shou", 1400);
    set_skill("yunlong-zhua", 1400);
    map_skill("dodge", "yunlong-shenfa");
    map_skill("force", "yunlong-shengong");
    map_skill("unarmed", "yunlong-zhua");
    map_skill("blade", "wuhu-duanmendao");
    map_skill("parry", "yunlong-zhua");
    map_skill("sword", "yunlong-jian");
    map_skill("whip", "yunlong-bian");
    create_family("云龙门",1, "开山祖师");
    set("class", "yunlong-xinfa");
    set("book_count", 1);
        set("inquiry", ([
        "天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
        "入会" :  "\n只要入我天地会，可以向各位好手学武艺。\n",
                "反清复明" : "去棺材店和回春堂仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
        "云龙剑谱" : (: ask_me :),
       ]) );
    set("chat_chance_combat", 70);  


    set("chat_msg_combat", ({
        "\n陈近南摇头叹道：螳臂当车，不自量力。唉，你这又是何苦呢?\n",
        (: command("smile") :),
        (: command("poem") :),
        (: command("nomatch") :),
        (: command("haha") :),
        (: command("chat 这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此?\n") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
(: perform_action, "sword.xunlei" :),	
(: perform_action, "sword.xunlei" :),	
(: perform_action, "sword.xian" :),	
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
                      }) );
    setup();
    carry_object("/clone/cloth/jinduan")->wear();
    carry_object("/d/city2/obj/yaodai")->wear();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/city2/obj/hlbian")->wield();
    carry_object("/clone/weapon/gangdao")->wield();
}
string ask_me()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) 
        || fam["family_name"] != "云龙门")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的云龙真经不在此处。";
        add("book_count", -1);
        ob = new("/d/city2/obj/yljianpu");
        ob->move(this_player());
        return "好吧，这本「云龙剑谱」你拿回去好好钻研。";
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("yunlong-shengong", 1) < 50) {
        command("say 我云龙神功乃内家武功，最重视内功心法。"); 
        command("say " + RANK_D->query_respect(ob) + 
            "是否还应该在云龙神功上多下点功夫？");
        return;
    }
    if ((int)ob->query("weiwang") <60) {
        command("say 我云龙门武功天下无敌，凡入我门，\n必闯荡江湖，行侠仗义，为天下苍生谋福利。\n"); 
        command("say " + RANK_D->query_respect(ob) + 
            "是否应该先出去闯一闯，做几件惊天动地的大事？");
    return ;
    }
    if ((int)ob->query("shen") >0&&(int)ob->query("shen") < 100000) {
        command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
            "是否还做得不够？");
    return ;
    }
    if(ob->query("weiwang")<80)
    {
    if((int)ob->query("shen")<0) command("say "+ RANK_D->query_respect(ob) +"虽然是邪派中人，但也还做了些好事。\n");
    command("chat 我天地会所作所为，无一不是前人所未行之事。\n");
    command("chat 万事开创在我，骇人听闻，物议沸然，又何足论？\n");
    command("chat 今天就收了你吧！！\n");
    command("chat 想不到我一身惊人艺业，今日终于有了传人，哈哈哈哈！！！！\n");
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    ob->set("weiwang",80);
    }
    command("recruit " + ob->query("id"));
    if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
        ob->set("class","fighter");
}
int do_skills(string arg)

{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="chen" )
     return 0;
   if(wizardp(ob))  return 0;
   if (ob->query("weiwang")<50)
  {
   message_vision("$N摇了摇头。\n",this_object());
   command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
   return 1;
   }
   tell_object(ob,this_object()->name()+"说：我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可测 2400/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 2400/    0\n"+
"  基本内功 (force)                         - 深不可测 2400/    0\n"+
"  读书写字 (literate)                      - 深不可测 2420/    0\n"+
"  基本招架 (parry)                         - 深不可测 2400/    0\n"+
"  基本剑法 (sword)                         - 深不可测 2400/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 2400/    0\n"+
"  基本鞭法 (whip)                          - 深不可测 2400/    0\n"+
"  云龙心法 (yunlong-xinfa)                 - 深不可测 2400/    0\n"+
"  云龙爪 (yunlong-zhua)                    - 深不可测 2400/    0\n"+
"□猴拳 (houquan)                           - 深不可测 1450/    0\n"+
"□五虎断门刀 (wuhu-duanmendao)             - 深不可测 1400/    0\n"+
"□云龙鞭 (yunlong-bian)                    - 深不可测 1400/    0\n"+
"□云龙剑法 (yunlong-jian)                  - 深不可测 1400/    0\n"+
"□云龙身法 (yunlong-shenfa)                - 深不可测 1400/    0\n"+
"□云龙神功 (yunlong-shengong)              - 深不可测 1400/    0\n"+
"□云龙手 (yunlong-shou)                    - 深不可测 1400/    0\n");
return 1;
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n陈近南说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("陈近南又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
    return notify_fail("你要加入什么组织？\n"); 
  if (ob->query("weiwang")<20)
        {
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    message_vision(HIC "陈近南对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
    return 1;
    }
   if(ob->query("weiwang")<50)
   {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;   
   }
   else message_vision(HIC "陈近南对$N摇了摇头说：你已经加入天地会了。\n" NOR,this_player());
   return 1;
}
