// qingcai.c ���

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���", ({"qing cai", "cai"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ�������͵���ˡ�\n");
                set("unit", "��");
                set("value", 30);
                set("food_remaining", 2);
		set("food_supply", 20);
	}
}
int query_autoload() { return 1; }
