//wuming.c  by:pipip
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
void greeting(object);
void init();
void create()
{
    set_name("无名老人", ({ "wuming laoren","wuming","laoren"}) );
    set("gender", "男性" );
    set("age", 55);
    set("long", "失去记忆的武林前辈奇人，曾经以一柄短刀连败正派四十九位高手。\n");
    set("attitude", "peaceful");
    set("shen_type", 0);
    set("str", 130);
    set("int", 60);
    set("con", 70);
    set("dex", 70);
	set("max_qi", 1200000);
    set("max_jing", 700000);
    set("jing",700000);
    set("neili", 1500000);
    set("max_neili", 200000);
    set("jiali",1800);
    set("combat_exp", 160000000);
    set("score", 20);
    set_skill("force", 1500);
    set_skill("taoism", 1500);
    set_skill("qimen-wuxing", 1500);
    set_skill("dodge", 2200);
    set_skill("art", 1500);
    set_skill("unarmed", 1500);
    set_skill("parry", 2000);
    set_skill("blade",2000);
    set_skill("yijing-force",1500);
    set_skill("lingyunbu", 2100);
    set_skill("cuixin-zhang", 1500);
    set_skill("tianxin-blade", 1500);
    map_skill("force", "yijing-force");
    map_skill("dodge", "lingyunbu");
    map_skill("parry", "cuixin-zhang");
    map_skill("unarmed", "cuixin-zhang");
    map_skill("blade", "tianxin-blade");
    create_family("玄天派",1,"开山祖师");
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.pai" :),
                (: perform_action, "blade.zhan" :),
                (: perform_action, "blade.sanfen" :),
                (: exert_function, "recover" :),
        }) );
    set("chat_chance", 2);
    set("chat_msg", ({
        "无名老人低声叹道：我到底是谁.....\n",
        "无名老人迷惑的望着你，他那一对蕴藏精光而又充满迷惑的眼睛使你觉得很不舒服。\n",
       "无名老人叹了口气道：真儿悟性根骨都是上等之选，可惜戾气过重....\n",
    }) );
    setup();
    carry_object("/d/xuantian/obj/cloth")->wear();
    carry_object("/d/xuantian/obj/xblade")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("dodge", 1) < 600) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"的轻功身法还不够矫健。");
                return;
                  } 
        if ((int)ob->query_skill("force", 1) < 600) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"的内功底子还没打好。");
                return;
                  } 
        if ((int)ob->query_skill("qimen-wuxing", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"对易经五行之理还领悟的不够啊。");
                return;
                  } 
        if ((int)ob->query_skill("art", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"对琴棋书画的技巧还不纯熟。");
                return;
                  } 

        if ((int)ob->query_skill("unarmed", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"似乎还没掌握拳脚功夫的要领。");
                return;
                  } 
        if ((int)ob->query_skill("blade", 1) < 300) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"的刀刃运用还不够熟练。");
                return;
                  } 
             if (ob->query_int() < 200) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"悟性不足，不能领悟我的武功。");
                return;
                  } 
             if (ob->query_con() < 60) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"手无缚鸡之力，怎能习武？");
                return;
                  } 
        if ((int)ob->query("kar") < 28) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"看上去不像福缘深厚之人。");
                return;
                  } 
        if ((int)ob->query("per") < 28) {
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"的长相似乎....");
                return;
                  } 

     command("say 你既然能够到这里来，也说明你我有缘，我就收下你吧。\n");
     message("vision",HIC"〖"HIR"江湖奇闻"HIC"〗"NOR+":"+HIG" 听说"HIM+ob->short()+NOR HIG"找到了失踪已久的无名老人，并且成为他的关门弟子！\n"NOR,users());
     command("recruit "+ob->query("id"));
     return;
}

