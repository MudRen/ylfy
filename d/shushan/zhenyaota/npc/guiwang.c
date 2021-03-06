// modified by vikee 2000.11
//【蜀山剑派】dhxy-evil 2000.7.5
// lilong 改于2002.01.12
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("天皇星", ({ "gui wang", "wang" }));
        set("title",HIR"鬼王"NOR);
        set("age", 300);
        set("attitude", "aggressive");
        set("str", 40);
        set("per", 20);
        set("con", 30);
        set("cor", 30);
        
        set("max_qi", 30000000);
        set("max_jing", 30000000);
        set("max_neili", 30000000);
        set("combat_exp", 2100000000);
        set("max_jingli", 30000000);
        set("neili", 30000000);
        set("jingli", 30000000);
        set("jiali", 10000);
		set("no_suck", 1);

        set_skill("force", 30000);
        set_skill("dodge", 30000);
        set_skill("parry", 30000);
        set_skill("unarmed", 30000);
        set_skill("shushan-force", 30000);
        set_skill("zuixian-steps", 30000);
        set_skill("fumozhang",30000);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 30);

   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", CYN"\n天皇星道：“请原谅我，因为这里的妖精都认为只要能吃九百九十九个妖精\n或者一百个人类就可以出去，所以...”\n", environment());
        message("sound", "\n天皇星又道：“从你身上，我发现了希望，希望你能够带我们离开这个塔...前面如果有麻烦的话，尽管找我！”\n", environment());
        message("sound", "\n天皇星消失得无影无踪...\n"NOR, environment());
        }
        destruct(this_object());
}
