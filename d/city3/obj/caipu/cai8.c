// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "���ٸ�ʿ�" , ({"clam"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "����һ��������İ������ˡ�\n" NOR);
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N�ÿ��Ӽ���һЩ$n�������۾������ķ�����С�\n");
        }
}

