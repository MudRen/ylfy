// guanjia.c
#include "/quest/quest.h"
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("���ؽ", ({ "chen sahan","chen" }) );
        set("title", "�컨���ܹ�");
        set("gender", "����" );
        set("age", 30);
        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
            "������ȥһ����Ϊ�����ܸɵ�ģ����\n"
            "�컨���д��СС����������ȫ�����ܡ�\n");
        create_family("�컨��",2, "����");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("env/wimpy", 30);
        set("max_neili", 1000);  
        set("neili", 1000);             
        set("jiali", 70);

    set_skill("force", 100);
    set_skill("honghua-shengong",100);
    set_skill("dodge", 100);
    set_skill("youlong-shenfa", 100);
    set_skill("unarmed", 100);
    set_skill("parry",100);
    set_skill("sword",100);
    set_skill("luohua-jian",100);
    set_skill("literate",170);

    map_skill("force", "honghua-shengong");
    map_skill("dodge", "youlong-shenfa");
    map_skill("parry", "luohua-jian");
    map_skill("sword", "luohua-jian");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("gold", 10);

}