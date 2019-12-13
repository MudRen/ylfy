// /NPC jujian.c
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�ս�", ({ "ju jian", "ju"}));
    set("long",
        "���Ǹ���ò毺õ�Ů��, ��������,\n"+
        "�������, �������.\n"+
        "���ܾ������ļ�����.\n");
    set("gender", "Ů��");
    set("age", 18);
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("per",21);
    set("dex", 25);
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 20);
    set("combat_exp", 50000);
    set_skill("force", 70);
    set_skill("unarmed", 70);
    set_skill("dodge", 80);
    set_skill("parry", 70);
    set_skill("sword",80);
    set_skill("zhemei-shou",80);
    set_skill("liuyang-zhang",80);
    set_skill("tianyu-qijian",80);
    set_skill("yueying-wubu",80);
    set_skill("bahuang-gong", 70);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    map_skill("sword", "tianyu-jianfa");

    set("chat_chance_combat", 40);  
    set("chat_msg_combat", ({
    (: command("enable unarmed zhemei-shou") :),
    (: command("enable unarmed liuyang-zhang") :),
}));

    create_family("���չ�",3,"����");
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",15);
}
