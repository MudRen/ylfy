// pink_cloth.c
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name( MAG "������" NOR, ({ "kang naiqing", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "��ĸ�ױ�ﰮ��Ŀ����ࡣ\n");
		set("unit", "��");
                set("value", 30);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
		set("female_only", 1);
	}
	setup();
}
int query_autoload() { return 1; }
