// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "過橋米線", ({"xian"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "这是一碟香喷喷的云南名菜。\n" NOR);
                set("unit", "碗");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N夹起一撮$n，放进嘴里。\n");
        }
}

