// heiyu.c ���������
#include <ansi.h>

inherit ITEM;

int do_fu(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣���õ���! \n");
                set("no_drop","��ô�������ҩ����������! \n");
        }
                                              
        add_action("do_fu", "fu");
}

void create()
{
        set_name(HIY "���������" NOR, ({"heiyu gao", "gao"}));
        set_weight(40);
        set("unique", 1); 
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƿ");
                set("long", 
"����һƿ��ɽ������ʥҩ�������������˱�");
                set("value", 100000);
        }

        setup();
}

int do_fu(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->set("neili", (int)me->query("max_neili"));
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
 
        message_vision(BLU
 "$N�����������࣬���Լ����˴�����ֻ����ȫ����̹�����ڷ�! \n"NOR,me);

        destruct(this_object());
        return 1;
}

