// Npc: /kungfu/class/shaolin/cheng-mie.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("����", ({
        "chengmie luohan",
        "chengmie",
        "miaoyin",
        "luohan",
    }));
    set("long",
        "����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
        "̫��Ѩ�߸߹����ƺ��������书��\n"
    );
    set("nickname", "�����޺�");
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 60);
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 25);
    set("max_qi", 1000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 100);
    set("combat_exp", 200000);
    set("score", 5000);
    set_skill("force", 125);
    set_skill("hunyuan-yiqi", 125);
    set_skill("dodge", 125);
    set_skill("shaolin-shenfa", 125);
    set_skill("staff", 120);
    set_skill("wuchang-zhang", 125);
    set_skill("parry", 125);
    set_skill("buddhism", 125);
    set_skill("literate", 125);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("staff", "wuchang-zhang");
    map_skill("parry", "wuchang-zhang");
    create_family("������", 37, "����");
    setup();
    carry_object("/d/shaolin/obj/chanzhang")->wield();
    carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}
#include "/kungfu/class/shaolin/cheng.h"
