// gangzhang.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�ֲ�", ({ "gangcha" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λε�����ֲ棬��ר������׽��Ĺ��ߡ�\n");
		set("value", 1500);
		set("rigidity",100);
               set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_sword(25);
	setup();
}
int query_autoload() { return 1; }