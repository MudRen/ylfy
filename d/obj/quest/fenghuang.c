inherit ITEM;
#include <task.h>
void create()
{
        set_name("������", ({"biyu fenghuang", "fenghuang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����̳ɵķ�ˣ���Ԭ�����͸���쳵ġ�\n");
                set("unit", "��");
                set("owner_name","���");
                set("owner_id","hu fei");
        }
}

