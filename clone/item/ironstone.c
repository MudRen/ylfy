// ironstone.c
inherit ITEM;
#include <ansi.h>
inherit F_UNIQUE;
void owner_is_killed() { destruct(this_object()); }   

void create()
{
	set_name(HIB"��������"NOR, ({ "iron stone","stone"}));
	set_weight(35000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",HIB"����һ�鼫����������ʯ���������أ������յý��ڣ�����ȴ͸��һ������ĺ��⡣\n���ƺ�����������ľ��ò��ϣ�\n");
                //set("item_origin", 1);
                set("material_attrib", "steel");
                set("can_make", "all");
                set("not_make", ({ "��", "ս��", "ѥ��", "����" ,"ָ��"}));
                set("no_sell", 1);
                //set("no_drop", "��ô����ϡ�н�������ɲ������ⶪ����\n");
                set("rate", 4); //���ò��ϵȼ�
                set("rigidity",300+random(50)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("power_point", 300+random(50)); //���ɺ��jiali��С
	}
}

