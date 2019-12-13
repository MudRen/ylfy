// Npc: /kungfu/class/shaolin/hui-he.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("�ۺ�����", ({
        "huihe zunzhe",
        "huihe",
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
    set_skill("unarmed", 108);
    set_skill("nianhua-zhi", 108);
    set_skill("parry", 100);
    set_skill("sword", 100);
    set_skill("damo-jian", 100);
    set_skill("buddhism", 100);
    set_skill("literate", 100);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "nianhua-zhi");
    map_skill("parry", "damo-jian");
    map_skill("sword", "damo-jian");
    
    create_family("������", 38, "����");
    set("inquiry", ([
        "����" :    (: ask_me :),
    ]));
    setup();
         carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
#include "/kungfu/class/shaolin/hui.h"
string ask_me()
{
    return "������ �������ֲ�ȱ���� ǰ�����ǲ��Ǹ�����һ�����飬������ʲ��ĸ����𣿣�";
}
