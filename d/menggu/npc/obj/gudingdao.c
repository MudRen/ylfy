// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// blade.c

#include <weapon.h>
inherit BLADE;

void create()
{
set_name(HIY"古锭刀"NOR, ({"guding dao", "dao", "blade", }) );	
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 0);
//     set("is_monitored", 1);
//    19       set("no_sell", 1);	
//    set("no_give", 1);	
//        set("no_drop", 1);	
//        set("no_put", 1);	
     set("material", "steel");
     set("long", "一把锈迹斑驳的长刀，份量相当的沉重。\n");
     set("wield_msg", "$N抹了抹$n上的灰尘，握在手里。\n");
     set("unequip_msg", "$N将$n绑到身后。\n");
   }
   init_blade(60);
   setup();
}
int query_autoload() { return 1; }	
