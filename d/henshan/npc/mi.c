// mi.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("��Ϊ��", ({ "mi weiyi", "mi", "weiyi" }) );
        set("gender", "����");
        set("class", "swordsman");
        set("age", 25);
        set("attitude", "peaceful");
        set("per", 20);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 30);
        set("max_qi",1500);
        set("max_jing",800);
        set("combat_exp", 300000);
        set("shen_type", 1);

        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("luoyan-jian", 80);
        set_skill("lingxu-bu", 80);

        map_skill("sword", "luoyan-jian");
        map_skill("parry", "luoyan-jian");
        map_skill("dodge", "lingxu-bu");

        create_family("��ɽ��", 14, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
