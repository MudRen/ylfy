#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
        set_name("ŷ������", ({ "ouyang bukong", "ouyang"}));
        set("long",
            "ͨ�԰����ϯ����,һ���书\n"+
            "�����ڰ�����Са.\n");
        set("gender", "����");
        set("age", 58);
        set("nickname", HIY "а��" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("qi", 30000);
        set("max_qi", 30000);
          set("jing", 6000);
          set("max_jing", 6000);
          set("neili", 8000);
          set("max_neili", 8500);
    set("shen", 100000);
        set("jiali", 500);

        set("combat_exp", 60000000);
        set("score", 10000);
        set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set_skill("sword",1000);
        set_skill("unarmed",1000);

        set_skill("dabei-zhang",1000);
        set_skill("fanyun-force",1000);
        set_skill("guxing-sword",1000);
       set_skill("damo-force",1000);
          set_skill("literate",1000);
        set_skill("piaomiao-shenfa",1000);

        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "damo-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "guxing-sword");

        prepare_skill("sword","guxing-sword");
        create_family("ͨ�԰�",2,"��ϯ����");
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
        if ((int)ob->query_skill("damo-force", 1) < 800) {
                command("say ��Ĵ�Ħ�񹦻�ѧ�Ĳ�������");
                return;
}

             command("recruit " + ob->query("id"));
               return;
}
