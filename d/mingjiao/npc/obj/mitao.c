// mitao.c　

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蜜桃", ({"mi tao", "tao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个水灵灵的蜜桃。\n");
                set("unit", "个");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 10);
        }
}


int query_autoload() { return 1; }