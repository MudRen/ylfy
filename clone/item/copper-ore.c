
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIY"ͭ��ʯ"NOR, ({"copper ore","ore","copper"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIY"����һ���ƺ�ɫ��ͭ��ʯ�������Ծ����أ����ƺ��ƺ������������������\n"NOR);
                set("value", 0);
                set("rate", 1); //���ò��ϵȼ�
                set("rigidity",50+random(30)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("can_make", "all");
                set("material_attrib", "copper");
                set("power_point", 40+random(30)); //���ɺ��jiali��С
              }
}
