//wuqing.c ���鵶
#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIW "���鵶" NOR, ({ "wuqing dao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѳ�ƽ���ĵ������������ߴ磬������覣�
		һ����֪��һ�Ѿ���������\n");
		set("value", 1000000);
                  set("unique", 1);

		set("material", "steel");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("wield_msg", HIY "ֻ�������һ����$N�����س�����鵶��ֻ����һ��
��ɱ֮���ӯ����ļ䡣\n" NOR);
		set("unwield_msg", HIY "���鵶��$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�\n" NOR);
	}
            init_blade(550);
	setup();
}
