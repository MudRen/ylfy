// taoshu.c 

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("С����", ({ "tao shu", "shu" }) );
        set_weight(30000);
        set_max_encumbrance(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ý�����ʵ��С������\n");
                set("value", 1000);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
        }
        setup();
}

