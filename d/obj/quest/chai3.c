inherit ITEM;
#include <task.h>
void create()
{
        set_name("����", ({"changjian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", " ͸�ź���ı�����\n");
                set("unit", "��");
               set("owner_name","�Ŵ�ɽ");
               set("owner_id","zhang cuishan");
        }
}
