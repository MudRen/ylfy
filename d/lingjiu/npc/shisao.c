// /NPC shisao.c
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("石嫂", ({ "shi sao", "shi", "sao" }));
    set("long",
        "她是「灵鹫宫」九天九部中朱天部的首领.\n"+
        "她跟随童姥多年, 出生入死,饱经风霜.\n");
    set("title", "朱天部首领");
    set("gender", "女性");
    set("age", 30);
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 25);
    set("con", 30);
    set("dex", 30);
    set("qi", 800);
    set("max_qi", 800);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 20);
    set("combat_exp", 100000);

    set_skill("force", 100);
    set_skill("unarmed", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("zhemei-shou",80);
    set_skill("liuyang-zhang",80);
    set_skill("yueying-wubu",80);
    set_skill("bahuang-gong", 70);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    set("chat_chance_combat", 40);  
    set("chat_msg_combat", ({
    (: command("enable unarmed zhemei-shou") :),
    (: command("enable unarmed liuyang-zhang") :),
}));
    create_family("灵鹫宫",3,"弟子");
    setup();
    carry_object("/d/lingjiu/obj/qingyi")->wear();
            carry_object("/d/lingjiu/obj/doupeng")->wear();
    add_money("silver",25);
}
