
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIW"����ʯ"NOR, ({"silver ore","ore","silver"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIW"����һ����ѵ�һ��������ʯ����������Щ���أ����ƺ��ƺ������������������\n"NOR);
                set("value", 100);
                set("rate", 2); //���ò��ϵȼ�
                set("can_make", "all");
                set("material_attrib", "silver");
                set("rigidity",90+random(30)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("power_point", 90+random(30)); //���ɺ��jiali��С
              }
}
