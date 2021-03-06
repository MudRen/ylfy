#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
         set_name("张博", ({ "zhang bo", "zhang"}));
         set("long", "通吃帮六怪之一琴怪张博\n");
        set("gender", "男性");
        set("age", 22); 
        set("nickname", HIM "琴怪" NOR);
          set("shen",0);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("qi", 10000);
        set("max_qi", 10000);
          set("jing", 6000);
         set("max_jing", 8000);
          set("neili", 9000);
          set("max_neili", 6000);
        set("jiali", 200);

        set("combat_exp", 3200000);
        set("score", 10000);
        set_skill("force", 320);
        set_skill("dodge", 320);
        set_skill("parry", 320);
        set_skill("sword",330);
        set_skill("unarmed",320);
        set_skill("dabei-zhang",320);
        set_skill("fanyun-force",320);
        set_skill("langzi-sword",330);
         set_skill("piaomiao-shenfa",330);

        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "fanyun-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "langzi-sword");

        prepare_skill("sword","guxing-sword");
        create_family("通吃帮",3,"弟子");
        setup();
    carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{

                      if ((string)ob->query("gender") == "男性") {
                command("say 这位" + RANK_D->query_respect(ob) +
                        ",不要开玩笑了！我只收女徒弟吧！");
                return;
                  }

             command("recruit " + ob->query("id"));
               return;
}
