inherit ITEM;
#include <task.h>
void create()
{
        set_name("��ȹ��", ({"hua qunzi", "qunzi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ư����ȹ�ӡ�\n");
                set("unit", "��");
               set("owner_name","Τ����");
               set("owner_id","wei chunfang");
        }
}
