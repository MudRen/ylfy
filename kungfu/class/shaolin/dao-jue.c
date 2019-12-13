// Npc: /kungfu/class/shaolin/dao-jue.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������ʦ", ({
        "daojue chanshi",
        "daojue",
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
    set("str", 22);
    set("int", 20);
    set("con", 21);
    set("dex", 22);
	set("max_qi", 1400);
    set("max_jing", 1300);
    set("neili", 1500);
    set("max_neili", 500);
    set("jiali", 40);
    set("combat_exp", 52000);
    set("score", 100);
    set_skill("force", 80);
    set_skill("hunyuan-yiqi", 80);
    set_skill("dodge", 80);
    set_skill("shaolin-shenfa", 80);
    set_skill("unarmed", 83);
    set_skill("fengyun-shou", 83);
        set_skill("jingang-quan", 85);
    set_skill("parry", 80);
    set_skill("buddhism", 80);
    set_skill("literate", 80);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "fengyun-shou");
    map_skill("parry", "jingang-quan");
    create_family("������", 39, "����");
    setup();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}
#include "/kungfu/class/shaolin/dao.h"
