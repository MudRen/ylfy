#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
set_name(HIR"龙牙"NOR, ({ "long ya", "blade" }) );	
set_weight(8000);
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 15);	
set("weapon_prop/intelligence", 3);	
set("weapon_prop/strength", 5);	
set("weapon_prop/blade", 50);		
set("unit", "把");
set("icon", "10022");
set("value", 10000000);	
set("material", "steel");
set("long", "传说中的上古三大邪刀之一。造刀者不明，相传锻造原料中使用了许多恶毒之物，并有多种诅咒缠缚。\n");	
set("wield_msg", HIR"一声脆响,$N手里无声无息的多了把黑气缠绕的刀.\n"NOR);
set("wield_msg", HIR"空气突然变得沉闷..,但听...\n"            
HIB"杀........死........他...........们.....\n"   	
HIY"来自地府的声音...连绵不绝,$N手里已多了把"HIR"黑气缠绕的刀.\n"NOR);          	
} 

init_blade(500,2);	
setup();
}
int query_autoload() { return 1; }