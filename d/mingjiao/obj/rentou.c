// rentou.c

#include <ansi.h>

inherit ITEM;

void setup()
{}
void create()
{
        set_name(RED"Բ�����ͷ"NOR, ({"ren tou", "tou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
        }
        setup();
}


