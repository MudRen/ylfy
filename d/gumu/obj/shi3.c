// shi3.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("小石头", ({"xiao shitou", "shitou"}));
        set("long","这是一块普通的小石头。\n");
        set("unit", "块");
        set_weight(5000);
}
int query_autoload() { return 1; }