inherit ITEM;
#include <task.h>
void create()
{
        set_name("������", ({"yanyu qin", "qin"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long", "һ�߶��٣�����¾ɣ����ǹ����β��������׭�����\n");
                set("unit", "��");
               set("owner_name","�����");
                 set("owner_id","ling huchong");
        }
}
