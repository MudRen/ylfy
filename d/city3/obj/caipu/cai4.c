// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "С������ţ��" , ({ "powder" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ����������Ĵ����ˡ�\n" NOR);
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N���ֲ��ŵؼ���һ��$n��ҧ��һ�ڣ������Լ�����ͷҲ������ȥ��\n");
        }
}

