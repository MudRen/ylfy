
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIR"����"NOR, ({"long jin","longjin","jin","dragon"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIR"һ�����Ϲ�������������ȡ���Ľ����ʵ�գ��쳣�ļ��͡�����Ө��͸���������£���Ȼ������⡣\n���ƺ�����������ľ��ò��ϡ�\n\n"NOR);
                set("no_sell", 1);
                //set("no_drop", "��ô�����Ϲ������ɲ������ⶪ����\n");
                set("rate", 4); //���ò��ϵȼ�
                set("rigidity",300+random(50)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("can_make", "all");
                set("not_make", ({ "��","��", "��", "��","��","��", "��","����","ͷ��" }));
                set("material_attrib", "bamboo");
                set("power_point", 300+random(50)); //���ɺ��jiali��С
              }
}
