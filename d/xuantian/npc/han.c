//han.c  by:pipip
inherit NPC;
string ask_me();
void create()
{
    set_name("寒真", ({ "han zhen","han","zhen"}) );
    set("gender", "男性" );
    set("age", 35);
    set("long", "无名老人的唯一传人--寒真，据说他已得到无名老人七成真传。\n");
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("nickname", HIC "寒山飞"HIW"雪" NOR);
    set("str", 110);
    set("int", 90);
    set("con", 90);
    set("dex", 90);
    set("per", 25);
    set("max_qi", 6500000);
    set("max_jing", 150000);
    set("jing",15000);
    set("neili", 2000000);
    set("max_neili", 100000);
    set("jiali",1900);
    set("combat_exp", 90000000);
    set("score", 20); 
    set_skill("force", 1000);
    set_skill("dodge", 1800);
    set_skill("unarmed", 1000);
    set_skill("parry", 1000);
    set_skill("blade",1000);
	set_skill("art", 1000);
    set_skill("yijing-force",1000);
	set_skill("qimen-wuxing", 1000);
    set_skill("lingyunbu", 2000);
    set_skill("cuixin-zhang", 1300);
    set_skill("tianxin-blade", 1300);
    map_skill("force", "yijing-force");
    map_skill("dodge", "lingyunbu");
    map_skill("parry", "cuixin-zhang");
    map_skill("unarmed", "cuixin-zhang");
    map_skill("blade", "tianxin-blade");
    create_family("玄天派",2,"大弟子");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.pai" :),
                (: perform_action, "unarmed.pai" :),
                (: exert_function, "recover" :),
        }) );
    set("inquiry", ([
      "银鳞镖":(:ask_me:),
    ]) );
    set("biao_count", 1);
        setup();

    carry_object("/d/xuantian/obj/cloth")->wear();
    carry_object("/d/xuantian/obj/xblade")->wield();
}


int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/master_id") != "wuming laoren") {
              ob->apply_condition("cuixin_poison", 6000
              +(int)ob->query_condition("cuixin_poison") );
   tell_object(ob, HIB "寒真的招式带出一股摧心掌毒，迎面一股寒气向你扑来！！\n" NOR );
        }
}

string ask_me()
{
    object me,ob;
    ob=this_player(); 
      if ((string)ob->query("family/master_id") != "wuming laoren")
        return "你是何人？";  
    if (query("biao_count") < 1)
        return "你来晚了，那只银鳞飞镖我已经赠送给别入了。";   
    add("biao_count", -1);                  
    command("say 嗯，我身上的确藏有师傅为师娘所制的银鳞飞镖。");
    command("say 既然你问起来了，你就将它拿去吧。\n");
    message_vision(HIG"寒真从怀里掏出一枚飞镖，皱了皱眉头，转手交给了$N \n\n"NOR,ob);
    me=new("d/pipip/biao");
    me->move(ob);
    return HIR"此物霸气太重，希望你小心使用，切莫堕入魔道，以免永世不得翻身。\n";
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

     command("recruit "+ob->query("id"));
     return;
}