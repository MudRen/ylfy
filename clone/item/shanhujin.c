//shanyu-jin ɺ����
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIM"ɺ����"NOR, ({"shanhu jin", "shanhu","jin" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIM"����һ���ں��׳���ǧ������ɵ�ɺ�����ջ����ۣ���Ӳ�ޱȣ��Ƕ���������Ϻò��ϡ�\n");
                set("no_sell", 1);
                set("value", 10000);
                //set("no_drop", "��ô���ı����ɲ������ⶪ����\n");
                set("can_make", "all");
                set("not_make", ({ "��", "��", "����","ս��", "ָ��", "����","ѥ��" }));
                set("rigidity",200+random(30)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("material_attrib", "gold");
                set("power_point", 190+random(30)); //���ɺ��jiali��С
                set("rate", 3); //���ò��ϵȼ�
        }

        setup();
}
