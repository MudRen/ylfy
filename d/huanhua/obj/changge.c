// changge.c ����
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIR"����"NOR, ({ "changge sword", "sword" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("icon", "10024");
		set("long", "��ѽ����ʮ��ƽ�������ʹ�׾�޹⣬ֻ�н���ڴ����������һ��
�Ʋ�����ˮ��,�����綾��������ĺ�â��\n");
		set("value", 1000000);
		set("material", "steel");
		set("unique", 1);
		set("wield_msg", HIB "ֻ�������һ�����죬�������ʷɳ�������Ծ��$N���С�
ֻ�����Һ����,�����ݺᡣ\n" NOR);
		set("unwield_msg", HIY "���轣��$N���з����ڰ����һת����ৡ���Ծ�뽣�ʡ�\n" NOR);
	}
	init_sword(150);
	setup();
}
