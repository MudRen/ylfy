inherit ITEM;

#include <task.h>
void create()
{
        set_name(HIY "���޺�" NOR, ({"tie luohan", "luohan"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�������ֵ����޺����ǹ����͸�������ġ�\n");
                set("unit", "ֻ");
               set("owner_name","������");
               set("owner_id","zhang sanfeng");
        }
}


