// zixuan pifeng.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name(HIY"��"HIG"��"HIB"��"HIM"ϼ"HIC"��"NOR, ({"yanxia yi","cloth"}));
set_weight(2000);
if (clonep())
set_default_object(__FILE__);
else {
set("long", "��˵����������������ϼ�¡�\n");
set("material", "cloth");
set("owner_id",1);
set("no_get",1);
set("no_give",1);
set("no_drop",1);
set("no_put",1);
set("unit", "��");
set("armor_prop/personality", 10);
set("armor_prop/karma", 10);
set("armor_prop/intelligence", 10);
set("armor_prop/constitution", 10);
set("armor_prop/dexerity", 5);
set("armor_prop/strength", 10);
set("armor_prop/dodge", 100);
set("armor_prop/force", 100);
set("armor_prop/unarmed", 100);
set("armor_prop/parry", 100);
set("armor_prop/sword", 100);
set("armor_prop/blade", 100);
set("armor_prop/armor_vs_force", 10);
set("value", 0);
set("armor_prop/armor", 2000);
}
setup();
}
void owner_is_killed() { destruct(this_object()); }