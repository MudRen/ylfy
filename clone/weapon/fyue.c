#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
set_name(HIW"月"+HIC"痕"NOR, ({ "yue hen","yue hen jian","jian", "sword" }) );
set_weight(8000);
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 15);   
set("weapon_prop/intelligence", 3);     
set("weapon_prop/strength", 5); 
set("weapon_prop/sword", 50);           
 set("badao", 1);
 set("icon", "10019");
set("unit", "把");
set("value", 10000000); 
set("material", "steel");
set("long", "一把月型软剑，据说是碧云才女纪嫣然的随身佩剑，据说这把剑还有个美丽的传说，其中蕴藏着神秘的力量。\n");   
set("wield_msg", HIR"$N低吟一声,嫦娥应悔偷灵药 碧海青天夜夜心.一声脆响,$N手里无声无息的多了把月型软剑.\n"NOR);
set("wield_msg", HIR"$N低吟一声...\n"            
HIM"嫦娥应悔偷灵药 碧海青天夜夜心\n"           
HIC"一道道月光不断向$N手中聚集...光亮越来越强,让人不能直视,天上明月如同共鸣般也发出强烈的光芒\n"              
HIY"$N的手上忽地发出眩目的光芒...,$N手里已多了把闪耀着月光的"HIC"软剑.\n"NOR);              
} 
init_sword(1000,2);
setup();
}
void init()	
{
add_action("do_wield", "wield");	
}
mixed hit_ob(object me, object victim)
{
int damage_bonus = 0;

damage_bonus = (damage_bonus+random(damage_bonus))/2;

victim->receive_wound("qi",damage_bonus);
return HIC"天上明月发出强烈的光芒照在"+HIW"月"+HIC"痕"+HIM"的剑痕上,"+HIW"月"+HIC"痕"+HIY"忽地闪出夺目的光芒！\n" NOR;

}
int do_wield(string arg)
{
object me;	
me=this_player();
if ( !wizardp(me) ) 	
{
write(HIW"神剑认主，不是你的武器，你怎么能使用!\n"NOR);
return 1;	
}
//   return 1;	
}
int query_autoload() { return 1; }                      	
