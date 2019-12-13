// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
#include <ansi.h>
inherit NPC;
inherit F_BANKER;
void create()
{
 set_name("钱开眼", ({"qian kaiyan", "qian", "kaiyan"}));
        set("title", "钱庄老板");
set("nickname", BLU "一毛不拨" NOR);
        set("gender", "男性");
        set("age", 34);
        set("str", 100);
        set("int", 24);
        set("dex", 18);
        set("con", 18);
        set("neili", 200);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen", 0);
        set("combat_exp", 12500);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 2);
        set("banker","cun/qu");
        set("chat_msg", ({
        "钱开眼骄傲的说道：本银号已经有上百年的历史，在大理可以说是第一家。\n",
        "钱开眼说道：昨天我亲自看到一个杀手帮的人来取钱，看来杀手帮重出江湖了。\n"
        "钱开眼笑着说道：杀手帮重出江湖对本银号来说，真是求之不的呀！。\n"
        "钱开眼笑着说道：当年雾中楼在本银号存的钱可以说是最多的了。\n",
        "钱开眼笑着说道：在本店存钱无利息，取钱收百分之一的手续费，客官您看着办吧。\n",
        "钱开眼微微一笑，说道：本店还办理不同面额货币的兑换业务，是免费的。\n",
        }));
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
     set("no_put",1);
        set_temp("apply/damage", 40);
        setup();
        add_money("silver", 10);
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
    if (base_name(environment())!=this_object()->query("startroom")) return;
        add_action("do_check", "check");
        add_action("do_check", "cha");
        add_action("do_convert", "convert");
        add_action("do_convert", "huan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}