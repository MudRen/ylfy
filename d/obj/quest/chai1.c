inherit ITEM;
#include <task.h>
void create()
{
        set_name("���ȹ�ͷ", ({"bone"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", " �еþ���ļ��ȹ�ͷ��\n");
                set("unit", "��");
               set("owner_name","Ұ��");
               set("owner_id","dog");
        }
}
