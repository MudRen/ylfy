// mitao.c��

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"mi tao", "tao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ˮ��������ҡ�\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 10);
        }
}


int query_autoload() { return 1; }