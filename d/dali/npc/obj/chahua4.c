//chahua4.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
set_name(HIB"���ɹ���"NOR, ({"cha hua","cha hua 4", "hua"}));	
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��軨���˶���ɫͬ�֦꣬�Ϲ����˶仨��"MAG"����"NOR"��"HIR"����"NOR"�Ļ���һ
�䣬����������ͺ��ɹã������ɫ��ͬ���컨��С��������״��
�䲻ͬ���������\n");
                set("value", 8500);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}
int query_autoload() { return 1; }