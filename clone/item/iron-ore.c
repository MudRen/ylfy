
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(WHT"����ʯ"NOR, ({ "iron ore","ore","iron"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",WHT"����һ���Ұ�ɫ������ʯ�������Ծ����أ����ƺ��ƺ������������������\n"NOR);
                set("value", 0);
                set("rate", 1); //���ò��ϵȼ�
                set("rigidity",40+random(30)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("can_make", "all");
                set("material_attrib", "iron");
                set("power_point", 30+random(30)); //���ɺ��jiali��С
              }
}
