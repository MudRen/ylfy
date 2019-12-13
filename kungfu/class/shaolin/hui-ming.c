// Npc: /kungfu/class/shaolin/hui-ming.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��������", ({
        "huiming zunzhe",
        "huiming",
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
    set("int", 20);
    set("con", 27);
    set("dex", 22);
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
    set_skill("banruo-zhang", 104);
        set_skill("yingzhua-gong", 70);
    set_skill("parry", 70);
    set_skill("buddhism", 70);
    set_skill("literate", 70);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "banruo-zhang");
        map_skill("parry", "yingzhua-gong");
    create_family("������", 38, "����");
    setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
#include "/kungfu/class/shaolin/hui.h"
