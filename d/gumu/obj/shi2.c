// shi2.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("Сʯͷ", ({"xiao shitou", "shitou"}));
        set("long","����һ��ˮ����ͨ��Сʯͷ��\n");
        set("unit", "��");
        set_weight(40000);
}

int query_autoload() { return 1; }