//yuzhu.c
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(MAG"�������"NOR, ({"jinban zizhu","zizhu","jinban"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",MAG"���Ǹ������ޱȵĽ������ǳ��ɫ����������һЩ��ɫ�İߵ㣬ʮ�ֺÿ�����������Ӳ���ƺ�������������Ϻò��ϡ�\n"NOR);
                set("can_make", "all");
                set("not_make", ({"��", "��"}));
                set("no_sell", 1);
                set("value", 10000);
                //set("no_drop", "��ô����ϡ�н�������ɲ������ⶪ����\n");
                set("rate", 3); //���ò��ϵȼ�
                set("power_point", 150+random(30)); //���ɺ��jiali��С
                set("material_attrib", "bamboo");
              }
}
