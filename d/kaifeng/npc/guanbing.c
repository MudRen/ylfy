#include <ansi.h>
inherit NPC;

void create()
{
        set_name("官兵", ({ "guan bing", "bing" }));
        set("age", 22);
        set("gender", "男性");
        set("long", "虽然官兵的武艺不能和武林人士相比，可是他们讲究的是人多力量大。\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 510000);
        set("shen_type", 1);

        set_skill("unarmed", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("blade", 140);
        set_skill("force", 140);
        set_temp("apply/attack", 140);
        set_temp("apply/defense", 140);
        set_temp("apply/damage", 120);
        set_temp("apply/armor", 140);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                CYN "官兵喝道：大胆刁民，竟敢造反不成？\n" NOR,
                CYN "官兵喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n" NOR,
        }));
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/junfu")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int accept_fight(object me)
{
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        kill_ob(me);
        return 1;
}
