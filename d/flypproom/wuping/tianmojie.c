// shou zhuo.c

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
set_name(HIB "��ħ��" NOR, ({ "tianmo ring", "ring" }));
set("long", "����Ǵ�˵�е���ħ�䣬����ī�ڣ�ɢ�������������⣡һ����ǿ�ҵ�ɱ�������治�ϴ����������������ܾ������ﲻ�Ծ���\n");
set("weight", 400);
if (clonep())
set_default_object(__FILE__);
else {
set("material", "gold");
set("unit", "ֻ");
set("armor_prop/personality", 5);
set("armor_prop/karma", 5);
set("armor_prop/intelligence", 5);
set("armor_prop/unarmed", 100);
set("armor_prop/armor_vs_force", 10);
set("value", 5000000);
set("no_get",1);
set("wear_msg", GRN "$N����ʳָ�����һָ��"HIR"��ʱɱ�����죬"HIW"���Ʊ�ɫ���׵罻��,"NOR"һֻī�ڵ�$n��Ȼ����" NOR);
set("remove_msg", GRN "$N����$n ��������أ�������̾�˿���...��" NOR);
set("armor_prop/armor", 1000);
}
setup();
}
int query_autoload() { return 1; }
