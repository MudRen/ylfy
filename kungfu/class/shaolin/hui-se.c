// Npc: /kungfu/class/shaolin/hui-se.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��ɫ����", ({
        "huise zunzhe",
        "huise",
        "zunzhe",
    }));
    set("long",
        "����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
        "̫��Ѩ΢͹��˫Ŀ��������\n"
    );
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 50);
    set("str", 30);
    set("int", 18);
    set("con", 28);
    set("dex", 25);
    set("max_qi", 450);
    set("max_jing", 300);
    set("neili", 600);
    set("max_neili", 600);
    set("jiali", 70);
    set("combat_exp", 100000);
    set("score", 100);
    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 100);
    set_skill("dodge", 100);
    set_skill("shaolin-shenfa", 100);
    set_skill("unarmed", 104);
    set_skill("longzhua-gong", 104);
        set_skill("sanhua-zhang", 100);
    set_skill("parry", 100);
    set_skill("buddhism", 100);
    set_skill("literate", 100);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
        map_skill("unarmed", "sanhua-zhang");
    map_skill("parry", "longzhua-gong");
    
    create_family("������", 38, "����");
    setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
#include "/kungfu/class/shaolin/hui.h"
