// /NPC meijian.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void greeting(object);
void init();
void create()
{
    set_name("梅剑", ({ "mei jian", "mei"}));
    set("long",
        "这是个容貌姣好的女子, 瓜子脸蛋,\n"+
        "眼如点漆, 清秀绝俗.\n"+
        "你总觉得在哪见过她.\n");
    set("gender", "女性");
    set("age", 18);
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 25);
        set("per",27);
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 20);
    set("combat_exp", 270000);
    set("score", 10000);
    set_skill("force", 140);
    set_skill("unarmed",140);
    set_skill("dodge", 140);
    set_skill("parry", 140);
    set_skill("sword",140);
    set_skill("zhemei-shou",140);
    set_skill("liuyang-zhang",140);
    set_skill("tianyu-qijian",140);
    set_skill("yueying-wubu",140);
    set_skill("bahuang-gong", 140);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    map_skill("sword", "tianyu-qijian");
    
    set("chat_chance_combat", 40);  
    set("chat_msg_combat", ({
    (: command("enable unarmed zhemei-shou") :),
    (: command("enable unarmed liuyang-zhang") :),
}));

    create_family("灵鹫宫",3,"弟子");
    setup();
    carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
    carry_object("/clone/weapon/changjian")->wield();
    add_money("silver",15);
}
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player())) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if (is_fighting() || !living(this_object())) return;
        if( !ob || environment(ob) != environment() ) return;
       if ((string)ob->query("family/family_name") == "灵鹫宫") 
             {
               message_vision("梅剑冲着$N点点头，微微笑了笑。\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name") && ob->query("gender")=="女性")
             {
               message_vision("梅剑冲着$N微笑说：你是来拜师的吧，拜我吧。\n",ob);
               return;
              }
}
void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="女性")
   {
        message_vision("梅剑垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "dancer")
            ob->set("class", "dancer");
       return;}
   else
      {
        message_vision("梅剑瞪着你看了半天,说道：“阁下是否该去做做手术?”\n",ob);
       return;}
}
