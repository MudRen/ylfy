// shi1.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����ʯ", ({"da shitou", "shitou"}));
        set("long", "����һ��ܴ�Ķ���ʯ��\n");
        set("unit", "��");
        set_weight(100000);
}

int query_autoload() { return 1; }