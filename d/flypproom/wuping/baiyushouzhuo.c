// shou zhuo.c

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
set_name(HIG "白玉手镯" NOR, ({ "baiyu shouzhuo", "zhuo" }));
       	set("long", "这是一对从千年寒冰中提炼打造的白玉手镯，光洁无瑕，虽然出自寒冰，但戴在手上却倍感“莹滑温润”舒服极了，真是稀世罕有。\n");
	set("weight", 300);
if (clonep())
set_default_object(__FILE__);
else {
set("material", "玉");
set("unit", "对");
set("armor_prop/personality", 5);
set("armor_prop/karma", 5);
set("armor_prop/intelligence", 5);
set("armor_prop/parry", 100);
set("armor_prop/armor_vs_force", 10);
set("value", 5000000);
set("wear_msg", HIW "一股白光从$N体内冲出，$N的关节一阵喀喀响声后,手腕上已多了一对精巧的$n" NOR);
set("remove_msg", GRN "$N双手一抖，$n 化成一道白光钻入你的体内。" NOR);
set("armor_prop/armor", 1000);
}
setup();
}
int query_autoload() { return 1; }
