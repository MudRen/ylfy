#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("锦盒", ({ "jinhe"}) );
        set_weight(300);
        set_max_encumbrance(50000);
        set("unit", "个");
        set("long", "一个很美观的锦盒里面似乎放这什么东西。\n");
        set("no_drop", "这样东西不能离开你。\n");
        set("no_get", 1);
        set("no_sell", 1);
        set("no_put", 1);
        set("no_give", 1);
        set("material", "steel"); 
        setup();

}
