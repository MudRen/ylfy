inherit ITEM;
#include <task.h>
void create()
{
        set_name("ľ�ҽ�", ({"mutao jian", "jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ҩʦ����ʱ�õ�ľ�ҽ���\n");
                set("unit", "��");
               set("owner_name","��ҩʦ");
               set("owner_id","huang yaoshi");
        }
}
