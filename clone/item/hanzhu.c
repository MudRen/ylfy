//yuzhu.c
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIG"��˿����"NOR, ({ "hansi yuzhu","yuzhu","hansi"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIG"���Ǹ������ޱȵĺ�˿����ͨ�徧Ө��΢΢�����̹⣬����������������ƺ������������������ϡ�\n"NOR);
                set("can_make", "all");
                set("not_make", ({"ս��", "����","��", "ͷ��","����","ѥ��","��"}));
                set("no_sell", 1);
                //set("no_drop", "��ô����ϡ�н�������ɲ������ⶪ����\n");
                set("rate", 5); //���ò��ϵȼ�
                set("power_point", 0); //���ɺ��jiali��С
                set("material_attrib", "bamboo");
              }
}
