#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
        set_name("阿三", ({ "a san", "san"}));
        set("long", "通吃帮不明不白中的,不明阿三\n");
        set("gender", "男性");
        set("age", 18); 
        set("nickname", HIR "不明" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("qi", 10000);
         set("max_qi", 6000);
        set("jing", 6000);
         set("max_jing", 6000);
          set("neili", 6000);
          set("max_neili", 6000);
        set("jiali", 200);
    set("shen", 50000);

        set("combat_exp", 10000000);
        set("score", 10000);
        set_skill("force", 430);
        set_skill("dodge", 480);
        set_skill("parry", 470);
        set_skill("sword",440);
        set_skill("unarmed",450);

        set_skill("dabei-zhang",450);
        set_skill("fanyun-force",400);
        set_skill("guxing-sword",440);
        set_skill("piaomiao-shenfa",480);

        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "fanyun-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "guxing-sword");

        prepare_skill("sword","guxing-sword");
        create_family("通吃帮",3,"帮主护法");
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

             command("recruit " + ob->query("id"));
               return;
}

