// rice.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ʻ���", ({ "zhou" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����԰ٻ����ɵ��ࡣ\n");
                set("unit", "��");
                set("value", 0);
                set("food_remaining", 50);
                set("food_supply", 60);
        }
}
int query_autoload() { return 1; }