// yuqingzi.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("������", ({ "yuqing zi", "zi", "yuqing" }) );
        set("gender", "����");
        set("class", "taishan");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 250000);
        set("max_neili", 500);
        set("jiali", 700);
        set("max_qi",22000);
        set("max_jing",13000);
        set("combat_exp", 10000000);
        set("shen_type", 1);

        set_skill("sword", 450);
        set_skill("force", 450);
        set_skill("parry", 450);
        set_skill("dodge", 450);
        set_skill("unarmed", 450);
        set_skill("taiji-shengong", 110);
        set_skill("taizu-quan", 110);
        set_skill("taishan-jianfa", 450);
        set_skill("qingmang-jian", 450);

        map_skill("sword", "taishan-jianfa");
        map_skill("parry", "taishan-jianfa");
        map_skill("dodge", "qingmang-jian");
        map_skill("force","taiji-shengong");
        map_skill("unarmed","taizu-quan");
        prepare_skill("unarmed", "taizu-quan");


        create_family("̩ɽ��", 12, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("d/taishan/obj/daopao")->wear();
}
