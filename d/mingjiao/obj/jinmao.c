// jinmao.c

#include <ansi.h>

inherit ITEM;

void setup()
{}
void create()
{
        set_name(RED"��ë"NOR, ({"jin mao", "mao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
        }
        setup();
}

