
inherit NPC;
inherit F_UNIQUE;
void create()
{
    set_name("鳌拜", ({
        "ao bai",
        "ao",
        "bai",
    }));
    set("long",
        "他就是满洲第一勇士，身穿一袭金边锦缎。他身材魁梧，\n"
        "相貌狰狞，太阳穴高高鼓起，似乎身怀绝世武功。\n"
    );
    set("nickname", "满洲第一勇士");
    set("gender", "男性");
    set("attitude", "aggressive");
    set("age", 50);
    set("shen_type", -1);
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 25);
    set("max_qi", 1500);
    set("max_jing", 1500);
    set("neili", 1500);
    set("max_neili", 1500);
    set("jiali", 150);
    set("combat_exp", 4280000);
    set("score", 50000);
    set_skill("force", 310);
    set_skill("hunyuan-yiqi", 210);
    set_skill("dodge", 350);
    set_skill("shaolin-shenfa", 300);
    set_skill("unarmed", 300);
    set_skill("parry", 300);
    set_skill("literate", 55);
    set_skill("fengyun-shou", 280);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "fengyun-shou");
    map_skill("parry", "fengyun-shou");
        set("chat_chance_combat", 10);  
        set("chat_msg_combat", ({
                " 鳌拜怒道：你敢不让我睡觉，老子宰了你 ！\n",
                (: command("say 老子宰了你这" + RANK_D->query_rude(this_player())+"!\n") :),
        (: command("pain") :),
                      }) );
        setup();
        carry_object("/d/city2/obj/anmenkey")->wield();
        carry_object("/d/city2/obj/jinduan")->wear();
        carry_object("/d/city2/obj/yaodai")->wear();
        carry_object("/d/city2/obj/yaoshi")->wield();
        add_money("gold",10);
}
void die()
{
        message("vision","\n鳌拜狂叫道：想不到我一世威名竟然毁于你手！\n","/d/city2/aobai6");            
        message("vision","鳌拜顿了一顿，叹道：唉，只可惜我的那么多宝贝啊！\n","/d/city2/aobai6");            
        message_vision("$N哀嚎一声，死了！\n", this_object());
        ::die();
}
#include "/kungfu/class/shaolin/cheng.h"
