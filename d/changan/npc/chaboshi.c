inherit  NPC;
inherit  F_DEALER;

void  create()
{
//      reload("teawaiter");
        set_name("�販ʿ",  ({"cha boshi","waiter"}));
        set("shop_id",  ({"boshi",  "waiter"}));
        set("gender",  "����");
        set("class",  "scholar");
        set("combat_exp",  1000);
        set("age",  26);
        set("per",  14);
        set("attitude",  "friendly");
        set("shen_type",  1);
        set_skill("unarmed",  10);
        set("vendor_goods",  ({
                "/clone/food/jiudai",
                "/clone/food/jitui",
        })  );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void  init()
{
        ::init();
        add_action("do_list",  "list");
        add_action("do_buy",  "buy");
}
