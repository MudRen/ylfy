// shou zhuo.c

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
set_name(HIG "��������" NOR, ({ "baiyu shouzhuo", "zhuo" }));
       	set("long", "����һ�Դ�ǧ�꺮������������İ������������覣���Ȼ���Ժ���������������ȴ���С�Ө������������ˣ�����ϡ�����С�\n");
	set("weight", 300);
if (clonep())
set_default_object(__FILE__);
else {
set("material", "��");
set("unit", "��");
set("armor_prop/personality", 5);
set("armor_prop/karma", 5);
set("armor_prop/intelligence", 5);
set("armor_prop/parry", 100);
set("armor_prop/armor_vs_force", 10);
set("value", 5000000);
set("wear_msg", HIW "һ�ɰ׹��$N���ڳ����$N�Ĺؽ�һ�󿦿�������,�������Ѷ���һ�Ծ��ɵ�$n" NOR);
set("remove_msg", GRN "$N˫��һ����$n ����һ���׹�����������ڡ�" NOR);
set("armor_prop/armor", 1000);
}
setup();
}
int query_autoload() { return 1; }
