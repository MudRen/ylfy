inherit ITEM;
#include <task.h>
void create()
{
        set_name("������", ({"iron hand"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", " ӥצһ�������ơ�\n");
                set("unit", "��");
               set("owner_name","��ǧ��");
               set("owner_id","qiu qianzhang");
        }
}
