inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("ÁõÕÆ¹ñ", ({ "liu zhanggui", "liu", "zhanggui" }) );
        set("gender", "ÄÐÐÔ" );
        set("age", 25);
        set("title", "ÑÅç÷ÐùÀÏ°å");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 130);

        set("vendor_goods", ({
                "d/kaifeng/obj/ciwan",
                "d/kaifeng/obj/luowenhai",
                "d/kaifeng/obj/bibohu",
        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{       
       add_action("do_buy", "buy");
        add_action("do_list", "list");
        ::init();
}
