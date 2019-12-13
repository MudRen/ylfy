// Npc: /kungfu/class/shaolin/dao-pin.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��Ʒ��ʦ", ({
        "daopin chanshi",
        "daopin",
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
    set("str", 25);
    set("int", 18);
    set("con", 20);
    set("dex", 23);
    set("max_qi", 400);
    set("max_jing", 300);
    set("neili", 450);
    set("max_neili", 450);
    set("jiali", 40);
    set("combat_exp", 52000);
    set("score", 100);
    set_skill("force", 50);
    set_skill("hunyuan-yiqi", 50);
    set_skill("dodge", 50);
    set_skill("shaolin-shenfa", 50);
    set_skill("unarmed", 51);
    set_skill("nianhua-zhi", 51);
    set_skill("blade", 54);
    set_skill("cibei-dao", 54);
    set_skill("parry", 50);
    set_skill("buddhism", 50);
    set_skill("literate", 50);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "nianhua-zhi");
    map_skill("blade", "cibei-dao");
    map_skill("parry", "cibei-dao");
    
    create_family("������", 39, "����");
    setup();
        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}
#include "/kungfu/class/shaolin/dao.h"
