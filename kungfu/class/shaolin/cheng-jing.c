// Npc: /kungfu/class/shaolin/cheng-jing.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("澄净", ({
        "chengjing luohan",
        "chengjing",
        "jingjing",
        "luohan",
    }));
    set("long",
        "他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
        "太阳穴高高鼓起，似乎身怀绝世武功。\n"
    );
    set("nickname", "精进罗汉");
    set("gender", "男性");
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
    set_skill("unarmed", 120);
    set_skill("longzhua-gong", 90);
    set_skill("parry", 125);
    set_skill("buddhism", 125);
    set_skill("literate", 125);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "longzhua-gong");
    map_skill("parry", "longzhua-gong");
    
    create_family("少林派", 37, "弟子");
    setup();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}
#include "/kungfu/class/shaolin/cheng.h"
