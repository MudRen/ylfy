#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
       set_name("����", ({ "han ling", "han"}));
        set("long",
            "ͨ�԰������Са��Ů��\n");
        set("gender", "Ů��");
        set("age", 18); 
        set("nickname", HIW "а��" NOR);
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
        create_family("ͨ�԰�",2,"��������");
        setup();
    carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  } 
        if ((int)ob->query_skill("fanyun-force", 1) < 400) {
                command("say ��ķ����񹦻�ѧ�Ĳ�������");
                return;
}
             command("recruit " + ob->query("id"));
               return;
}
