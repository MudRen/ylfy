// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name( "虾米茄子", ({"china cai", "eggplant"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "这是一碟香喷喷的中国名菜。 \n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

