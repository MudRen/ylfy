
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIW"��������"NOR, ({"wannian xuanbing", "xuanbing"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW"���ǿ��ں��ױ�ɽ�л����ϡ�н������������������������Ӳ��ѹ���Ƕ���������Ϻò��ϡ�\n");
                set("no_sell", 1);
                set("value", 10000);
                //set("no_drop", "��ô���ı����ɲ������ⶪ����\n");
                set("rate", 3); //���ò��ϵȼ�
                set("rigidity",200+random(30)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("can_make", "all");
                set("not_make", ({ "��", "��", "ս��", "ָ��", "����","ѥ��" }));
                set("material_attrib", "silver");
                set("power_point", 200+random(30)); //���ɺ��jiali��С
        }

        setup();
}
