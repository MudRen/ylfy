//box ....angle
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("С����", ({ "box"}) );
        set_weight(300);
        set_max_encumbrance(50000);
        set("unit", "��");
        set("long", "һ�����������С���䣬һ����֪����һ���������û������Ӧ�ÿ��Դ�����\n");
        set("no_get", 1);
        set("no_sell", 1);
        set("no_put", 1);
        set("no_give", 1);
        set("material", "steel"); 
        setup();

}

int query_autoload() { return 1; }
