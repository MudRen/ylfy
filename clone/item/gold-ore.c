
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(YEL"���ʯ"NOR, ({"golden ore","ore","golden"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",YEL"����һ����ֵ���ƵĽ��ʯ����������Щ���أ����ƺ��ƺ������������������\n"NOR);
                set("value", 100);
                set("rate", 2); //���ò��ϵȼ�
                set("rigidity",100+random(30)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("can_make", "all");
                set("material_attrib", "gold");
                set("power_point", 100+random(30)); //���ɺ��jiali��С
              }
}
