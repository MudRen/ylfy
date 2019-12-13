// /d/xingxiu/npc/woman.c
// by mei
inherit NPC;
void create()
{
        set_name("阿曼", ({ "aman", "girl" }) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "最美丽的哈萨克姑娘,身形袅娜,面目姣好, 眼光中闪烁著笑意。\n");
        set("shen_type", 1);
     set("per",30);
        set("shen", 200);
        set("combat_exp", 2000);
        set("str", 16);
        set("dex", 18);
        set("con", 12);
        set("int", 24);
        set("attitude", "friendly");
        set("inquiry", ([
            "苏普" : "嘻嘻, 不告诉你。\n",
            "毛毯" : "客人, 请到帐蓬里挑选。\n",
          "李文秀" : "她才是一个大美人呢。\n",
            "金针" : "我一直想要一根金针, 织出更精制的东西。\n",
          "柔丝索" : "很难做的。你要它干什么? \n",
            "雪蚕" : "它生长在雪地里，不过很难找的。 \n",
        ]) );
        setup();
        add_money("silver", 30);
        carry_object(__DIR__"obj/qcloth")->wear();
}
int accept_object(object who, object ob)
{

        if ((string)ob->query("id")=="jin zhen")
          {
                        this_player()->set_temp("marks/阿曼3", 1); {
                        write("阿曼对你说道：你有雪蚕吗? \n");
                return 1;
                      }
                if( who->query_temp("marks/阿曼2", 1) ) {
                        write("阿曼对你说道：一只雪蚕怎么够? \n");
                        this_player()->set_temp("marks/阿曼4", 1);
                        this_player()->set_temp("marks/阿曼2", 0);
                        return 1;
                      }
                return 0;
          }
         if ((string)ob->query("id")=="xue can") {
                if( who->query_temp("marks/阿曼4") ) {
                       write("阿曼对你说道：柔丝索做好了。\n");
                       say("阿曼给了" + who->query("name") + "一摞柔丝索。\n");
                       this_player()->set_temp("marks/阿曼4", 0);
                       new(__DIR__"obj/rousisuo")->move(who);
                       return 1;
                     }
                  if( who->query_temp("marks/阿曼3", 1) ) {
                       write("阿曼对你说道：一只雪蚕怎么够? \n");
                        this_player()->set_temp("marks/阿曼4", 1);
                        this_player()->set_temp("marks/阿曼3", 0);
                        return 1;
                     }
                  say("阿曼把蚕收起来，说道：这么可爱的蚕, 真可怜。\n");
                  return 1;
                }
           if ((string)ob->query("id")=="xue can") {
                  say("阿曼笑嘻嘻说道：柔丝索做好了。\n");
                  return 1;
                }
            return 0;
      }

