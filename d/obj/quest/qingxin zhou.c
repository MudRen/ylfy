inherit ITEM;
#include <task.h>
void create()
{
        set_name("�廨��", ({"xiuhua zhen", "zhen"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ԧԧƽʱ�������·��õ��롣\n");
                set("unit", "��");
                set("owner_name","��ݺݺ");
                set("owner_id","cui yingying");
        }
}
