// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "三絲干巴菌" , ({"jun"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "这是一碟香喷喷的云南名菜。\n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N用筷子小心翼翼的夹起一块$n，放入口中,细嚼慢咽起来。\n");
        }
}

