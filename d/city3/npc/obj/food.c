// food.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���޷�Ƭ", ({"piang", "fei"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ�ֳɶ��ط�С�ԡ�\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 10);
                set("food_supply", 100);
	}
}
int query_autoload() { return 1; }