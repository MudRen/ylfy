inherit ITEM;

#include <task.h>
void create()
{
 set_name(HIY "���˭������÷" NOR, ({"luo mei", "mei"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "һ���ˣ��ǻ���Ϊ���߹�������\n");
               set("unit", "��");
               set("owner_name","���߹�");
               set("owner_id","hong qigong");
        }
}


