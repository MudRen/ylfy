// putao.c
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("����", ({"putao"}));
    set_weight(1);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ��ˮ��������ѡ�\n");
        set("unit", "��");
        set("food_remaining", 1);
        set("food_supplay", 5);
    }
}
int query_autoload() { return 1; }