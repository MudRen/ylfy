// xuantie.c ����ʯ

#include <ansi.h>

inherit ITEM;
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIW"������ʯ" NOR, ({"xuan tie", "xuantie"}));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", HIW"һ�鷺��ʯͷ���������ие���Ϊ���أ���ӲԶʤͭ�����Ƕ���������Ϻò��ϡ�\n\n"NOR);
		set("unit", "��");
		set("value", 30000);
                //set("item_origin", 1);
                set("material_attrib", "steel");
                set("can_make", "all");
                set("not_make", ({"ս��", "ָ��", "����","��"}));
                set("no_sell", 1);
                set("value", 10000);
                set("rigidity",250+random(30)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                //set("no_drop", "��ô����ϡ�н�������ɲ������ⶪ����\n");
                set("rate", 3); //���ò��ϵȼ�
                set("power_point", 200+random(50)); //���ɺ��jiali��С
	}
}
