// niqiu.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��������", ({"niqiu","food"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ĸ���������\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 15);
	}
}
