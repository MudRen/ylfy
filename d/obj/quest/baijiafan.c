inherit ITEM;

#include <task.h>
void create()
{
        set_name(BLK "�ټҷ�" NOR, ({"baijia fan", "fan"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ѱ���˼ҳ�ʣ�µķ��ˡ�\n");
                set("unit", "��");
               set("owner_name","��ȫ");
               set("owner_id","zuo quan");
        }
}


