inherit ITEM;
#include <task.h>
void create()
{
        set_name("��Ƥ�˱�", ({"renpi zhangben", "zhangben"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ǯ�ۿ��������ʵ�С���ӡ�\n");
                set("unit", "��");
               set("owner_name","Ǯ�ۿ�");
               set("owner_id","qian yankai");
        }
}
