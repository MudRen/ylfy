// coin.c
inherit MONEY;

void create()
{
        set_name(HIY "ͭ��" NOR, ({"coin", "coins", "coin_money" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "coin");
                set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ����ͭ���ֵ��һ��������\n");
                set("unit", "Щ");
                set("icon", "00013");
                set("base_value", 1);
                set("base_unit", "ö");
                set("base_weight", 30);
                set("wield_msg", "$N�����ȡ��һ��$n�����ף��������С�\n");
                set("unwield_msg", "$N�����е�$n�Żض��\n");
        }
        set_amount(1);
        init_throwing(10);
        setup();

}


