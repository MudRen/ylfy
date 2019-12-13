// Npc: /kungfu/class/shaolin/hui-jie.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("�۽�����", ({
        "huijie zunzhe",
        "huijie",
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
        set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);
    set("max_qi", 450);
    set("max_jing", 300);
    set("neili", 600);
    set("max_neili", 600);
    set("jiali", 50);
    set("combat_exp", 100000);
    set("score", 100);
    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 100);
    set_skill("dodge", 100);
    set_skill("shaolin-shenfa", 100);
    set_skill("blade", 105);
    set_skill("cibei-dao", 105);
    set_skill("club", 107);
    set_skill("weituo-gun", 107);
    set_skill("parry", 100);
    set_skill("buddhism", 100);
    set_skill("literate", 100);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("blade", "cibei-dao");
    map_skill("club", "weituo-gun");
    map_skill("parry", "weituo-gun");
    create_family("������", 38, "����");
    setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
#include "/kungfu/class/shaolin/hui.h"
