// zixuan pifeng.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name(MAG"�������"NOR, ({ "zixuan pifeng", "zixuan","pifeng" }));
set_weight(2000);
if (clonep())
set_default_object(__FILE__);
else {
set("long", "��˵����������硣\n");
set("material", "cloth");
set("unit", "��");
set("armor_prop/personality", 5);
set("armor_prop/karma", 5);
set("armor_prop/intelligence", 3);
set("armor_prop/dodge", 100);
set("armor_prop/armor_vs_force", 10);
set("value", 10000000);
set("wear_msg", CYN "ֻ������է�죬ƽ������һ���߲�����,$N����һָ�����ж�Ȼ�ֳ�һ��ϼ�������$n��$n"CYN"���������$N���ϡ�\n"	
HIM"˲ʱ����ط���ɫ�䣬�׵罻�ӣ����ֳ�һƬ��ɱ֮����\n" NOR);
set("remove_msg", GRN "$N˫��һ����$n�û���һƬϼ������ʧ������\n" NOR);
set("armor_prop/armor", 1000);
}
setup();
}
int query_autoload() { return 1; }
