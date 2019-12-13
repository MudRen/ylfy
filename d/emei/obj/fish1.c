// fish.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鲤鱼", ({"liyu", "fish"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一条鲜活蹦跳的鱼。\n");
		set("unit", "条");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
int query_autoload() { return 1; }