#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
        set_name("����", ({ "a si", "si"}));
        set("long",
            "ͨ�԰ﲻ�������е�,���װ���\n");
        set("gender", "����");
        set("age", 18); 
        set("nickname", HIR "����" NOR);
        set("shen_type",1);
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
          set("max_neili", 9000);
        set("jiali", 200);
    set("shen", 50000);

        set("combat_exp", 10000000);
        set("score", 10000);
        set_skill("force", 450);
        set_skill("dodge", 450);
        set_skill("parry", 440);
        set_skill("sword",440);
        set_skill("unarmed",450);

        set_skill("dabei-zhang",450);
        set_skill("fanyun-force",450);
        set_skill("guxing-sword",440);
        set_skill("piaomiao-shenfa",450);

        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "fanyun-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "guxing-sword");

        prepare_skill("sword","guxing-sword");
        create_family("ͨ�԰�",3,"��������");
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

             command("recruit " + ob->query("id"));
               return;
}
