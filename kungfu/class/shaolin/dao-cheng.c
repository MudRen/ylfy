// Npc: /kungfu/class/shaolin/dao-cheng.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������ʦ", ({
        "daocheng chanshi",
        "daocheng",
        "chanshi",
    }));
    set("long",
        "����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
        "�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
    );
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 40);
    set("str", 21);
    set("int", 20);
    set("con", 19);
    set("dex", 24);
    set("max_qi", 1400);
    set("max_jing", 1300);
    set("neili", 1450);
    set("max_neili", 450);
    set("jiali", 40);
    set("combat_exp", 52000);
    set_skill("force", 80);
    set_skill("hunyuan-yiqi", 80);
    set_skill("dodge", 80);
    set_skill("shaolin-shenfa", 80);
    set_skill("unarmed", 80);
    set_skill("banruo-zhang", 80);
    set_skill("unarmed", 82);
    set_skill("longzhua-gong", 82);
    set_skill("parry", 80);
    set_skill("buddhism", 80);
    set_skill("literate", 80);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "banruo-zhang");
    map_skill("parry", "longzhua-gong");
    create_family("������", 39, "����");
    setup();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}
#include "/kungfu/class/shaolin/dao.h"
