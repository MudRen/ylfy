// expclub.c 负攻击棍	
// Wenwu 2003.8.25
#include <weapon.h>	
inherit CLUB;  	
void create()	
{	
set_name("风火棍", ({ "fenghuo gun","club","fenghuo", "gun" }));
set_weight(5000);	
if (clonep())	
set_default_object(__FILE__);	
else {	
set("unit", "根");   
set("icon", "10041");   	
set("long", "这是一根攻击力为负数的棍，江湖人士通常都是用它来刷经验。\n");              	
set("value", 0);	
set("material", "steel");	
}	
init_club(-30000,2);                     	
setup();	
}	
