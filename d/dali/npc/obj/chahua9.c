//chahua9.c
#include <ansi.h>
#include <armor.h>;
inherit HEAD;

void create()
{
set_name(HIW"����"NOR, ({"cha hua","cha hua 9", "hua"}));	
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��軨����׻���΢�������ڰߵģ���Щ�ڰߣ��������еĹ�֦��\n");
                set("value", 5000);
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
