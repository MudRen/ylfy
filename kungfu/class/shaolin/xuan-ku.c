// Npc: /kungfu/class/shaolin/xuan-ku.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("�����ʦ", ({
        "xuanku dashi",
        "xuanku",
        "dashi",
    }));
    set("long",
        "����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�������ݸߣ�\n"
        "�����������ƣ��ֱ۴������¶���ƺ��þ���˪��\n"
    );
    set("nickname", "�޺�������");
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 70);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("qi", 3500);
    set("max_qi", 3500);
    set("jing", 1500);
    set("max_jing", 1500);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 150);
    set("combat_exp", 1200000);
// before the modification, all the skills are 120
    set_skill("force", 200);
    set_skill("hunyuan-yiqi", 200);
    set_skill("dodge", 200);
    set_skill("shaolin-shenfa", 200);
    set_skill("parry", 200);
    set_skill("unarmed", 200);
    set_skill("club", 200);
    set_skill("blade", 200);
    set_skill("sword", 200);
    set_skill("luohan-quan", 200);
    set_skill("weituo-gun", 200);
    set_skill("xiuluo-dao", 200);
    set_skill("fumo-jian", 200);
    set_skill("buddhism", 200);
    set_skill("literate", 200);
    map_skill("force", "hunyuan-yiqi");
    map_skill("club", "weituo-gun");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("parry", "luohan-quan");
    map_skill("unarmed", "luohan-quan");
    map_skill("blade", "xiuluo-dao");
    map_skill("sword", "fumo-jian");
    
    create_family("������", 36, "����");
    set("inquiry", ([
        "ʮ���޺���"       : (: ask_me :),
        "�޺�����"     : (: ask_me :)
    ]));
    set("chat_chance_combat", 45);
    set("chat_msg_combat", ({
      (: exert_function, "roar" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/d/shaolin/obj/jiedao")->wield();
    carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
#include "/kungfu/class/shaolin/xuan-ku.h"
