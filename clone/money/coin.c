// coin.c
inherit MONEY;

void create()
{
        set_name(HIY "铜板" NOR, ({"coin", "coins", "coin_money" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "coin");
                set("long", "这是流通中单位最小的货币，约要一百文铜板才值得一两白银。\n");
                set("unit", "些");
                set("icon", "00013");
                set("base_value", 1);
                set("base_unit", "枚");
                set("base_weight", 30);
                set("wield_msg", "$N从袖口取出一串$n抛了抛，握在手中。\n");
                set("unwield_msg", "$N将手中的$n放回兜里。\n");
        }
        set_amount(1);
        init_throwing(10);
        setup();

}


