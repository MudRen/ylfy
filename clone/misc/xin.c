// /clone/misc/xin.c

#include <ansi.h>
#define XIN_NAME "��"	
inherit ITEM;
void create()
{
set_name(HIM + XIN_NAME + NOR, ({"xin"}));      	
set_weight(200);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "��");
set("long","����һ������д��������������,�������ƺ�������.��(chai)��������?");	
set("value", 0);
set("no_give",1);
set("no_get",1);
set("no_put",1);
set("no_drop",1);
}
setup();
}	
