// lingyun.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
set_name(YEL"����ѥ"NOR, ({ "lingyun xue","lingyun", "xue" }) 
);
set_weight(800);
if( clonep() )
set_default_object(__FILE__);
else {
set("material", "leather");
set("unit", "˫");
set("long", "����һ˫�÷������ɵ�ѥ�ӣ��⻬���ͣ���˵��������Ԫ��Ч����\n");	
set("value", 10000000);	
set("armor_prop/dodge", 50);
set("armor_prop/karma", 7);
set("armor_prop/constitution", 5);
set("armor_prop/intelligence", 3);
set("armor_prop/dexerity", 5);
set("armor_prop/personality", 3);
set("armor_prop/armor", 500);
set("wear_msg", CYN "$N����һ˫$n,"CYN"�ŵ�ѣ��һ��"HIM"�߲ʹ⻪��"HIB"$N�پ�"HIC"ȫ��һ�ᣬ"HIY"����"GRN"�˷��ȥ��\n" NOR);	
set("remove_msg", GRN "���������$N��$n���������������\n" NOR);	
}
setup();
}
int query_autoload() { return 1; }	
