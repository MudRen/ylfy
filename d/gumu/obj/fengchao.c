#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(BLU"�䳲"NOR, ({
              "fengchao",
              "chao"
             }));
     set_weight(25);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "ֻ");
     set("long", 
     "����һֻ�ܴ�ķ䳲����Ȼ������ͨ�۷����졣\n");
     set("value", 100);
     setup();
}
}

