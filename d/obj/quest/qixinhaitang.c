inherit ITEM;
#include <task.h>
void create()
{
        set_name("���ĺ���", ({"qixin haitang", "haitang"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����������صĶ�ҩ����ɫ���ᡣ\n");
                set("unit", "��");
               set("owner_name","Ԭ����");
                 set("owner_id","yuan ziyi");
        }
}

