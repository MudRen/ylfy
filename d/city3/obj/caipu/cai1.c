// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name( "干蒸黃魚" , ({"fish"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "这是一碟香喷喷的四川名菜。 \n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N夹起$n，一口咬了下去，只觉清滑无比，香甜满颊。\n");
        }
}

