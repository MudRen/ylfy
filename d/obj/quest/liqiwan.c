inherit ITEM;
#include <task.h>
void create()
{
        set_name("����������", ({"liqi wan", "wan"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ƽһָ�����������������Ĺ�Ч��\n");
                set("unit", "��");
                set("owner_name","ƽһָ");
                 set("owner_id","ping yizhi");
        }
}

