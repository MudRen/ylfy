inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIR "ԧ�쵶" NOR, ({"yuanyang dao", "dao"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Խ��������������طɵ���\n");
                set("unit", "��");
               set("owner_name","���");
                 set("owner_id","luo bing");
        }
}

