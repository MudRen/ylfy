// tofu.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���Ŷ���", ({"mapo doufu", "doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
               set("long", "һ�������Ĵ󶹸����������ֺ�ζ�����������һ�顣\n");
		set("unit", "��");
                set("value", 80);
		set("food_remaining", 1);
               set("food_supply", 80);
	}
}
int query_autoload() { return 1; }