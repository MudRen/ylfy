inherit ITEM;
#include <task.h>
void create()
{
        set_name("���ٱ�", ({"guteng bei", "bei"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ��Ӳ�����Ĺ��ٱ���\n");
                set("unit", "��");
               set("owner_name","��ǧ��");
                 set("owner_id","zu qianqiu");
        }
}

