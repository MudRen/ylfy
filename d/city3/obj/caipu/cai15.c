// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name( "竹筒雞", ({"ji"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "这是一碟香喷喷的云南名菜。\n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N小心翼翼拨开竹片夹起一块$n，想也不想的塞进嘴里。\n");
        }
}

