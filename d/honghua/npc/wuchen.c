// wuchen.c �޳�����
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    set_name("�޳�����", ({ "wuchen daozhang", "wuchen" }));
    set("long", 
        "���Ǻ컨�����ڶ��ѽ��ε��޳�������\n"
        "�컨��������������ã�\n"
        "����ͺ�������ʮ�����ң�������������º����޷��Զ������ϱ��鲻ŭ������\n");

         set("gender", "����");
         create_family("�컨��",2, "����");
         set("age", 44);
         set("attitude", "peaceful");
         set("shen_type", 1);
         set("str", 25);
         set("int", 23);
         set("con", 26);
         set("dex", 27);
         set("max_qi", 2200);
         set("max_jing", 2000);
         set("neili", 2400);
         set("max_neili", 2400);
         set("jiali", 100);
         set("combat_exp", 3500000);
         set("score", 160000);

          set_skill("force", 300);
          set_skill("honghua-shengong",300);
          set_skill("dodge", 300);
          set_skill("youlong-shenfa", 300);
          set_skill("unarmed", 300);
          set_skill("parry",300);
          set_skill("sword",300);
          set_skill("luohua-jian",300);
        set_skill("literate",150);

    map_skill("force", "honghua-shengong");
    map_skill("dodge", "youlong-shenfa");
    map_skill("parry", "luohua-jian");
    map_skill("sword", "luohua-jian");

    setup();

    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") < 10000) {
        command("say �ߣ�");
        command("say ��λ" + RANK_D->query_respect(ob) +
            "Ϊ��֮���ƺ�����ô����");
        return;
    }
    command("say ���������Ҿ��������ˣ�");
    command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "yishi")
                ob->set("class", "yishi");
}