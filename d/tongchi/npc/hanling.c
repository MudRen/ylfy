#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
       set_name("寒玲", ({ "han ling", "han"}));
        set("long",
            "通吃帮帮主杨小邪的女友\n");
        set("gender", "女性");
        set("age", 18); 
        set("nickname", HIW "邪妹" NOR);
          set("shen",0);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("qi", 20000);
        set("max_qi", 20000);
          set("jing", 6000);
         set("max_jing", 6000);
          set("neili", 6000);
          set("max_neili", 6000);
        set("jiali", 500);

        set("combat_exp", 30000000);
        set("score", 10000);
        set_skill("force", 600);
        set_skill("dodge", 650);
        set_skill("parry", 640);
        set_skill("sword",640);
        set_skill("unarmed",650);

        set_skill("dabei-zhang",650);
        set_skill("damo-force",650);
        set_skill("guxing-sword",640);
          set_skill("literate",600);
        set_skill("piaomiao-shenfa",650);

        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "damo-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "guxing-sword");

        prepare_skill("sword","guxing-sword");
        create_family("通吃帮",2,"帮主夫人");
        setup();
    carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "无性") {
                                 command("say 这位公公不要开玩笑了。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是快去伺候皇上吧！");
                return;
                  } 
        if ((int)ob->query_skill("fanyun-force", 1) < 400) {
                command("say 你的翻云神功还学的不够啊。");
                return;
}
             command("recruit " + ob->query("id"));
               return;
}
