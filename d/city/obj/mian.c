// mian.c
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("��", ({ "mian" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ���������ڵ�������\n");
		set("unit", "��");
		set("value", 1000);
		set("food_remaining", 1);
		set("food_supply", 250);
        }
    setup();
}
int query_autoload() { return 1; }