// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "蘭花春筍" , ({"china cai", "bamboo"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "这是一碟香喷喷的浙江名菜。\n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

