inherit ITEM;
#include <task.h>
void create()
{
        set_name("������", ({"qingxin zhou", "zhou"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������飬�е�����Ϣ�����á�\n");
                set("unit", "��");
               set("owner_name","��ӯӯ");
                 set("owner_id","ren yingying");
        }
}

