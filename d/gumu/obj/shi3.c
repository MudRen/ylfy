// shi3.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("Сʯͷ", ({"xiao shitou", "shitou"}));
        set("long","����һ����ͨ��Сʯͷ��\n");
        set("unit", "��");
        set_weight(5000);
}
int query_autoload() { return 1; }