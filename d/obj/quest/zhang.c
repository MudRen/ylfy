inherit ITEM;
#include <task.h>
void create()
{
        set_name("ߦ����", ({"ganmian zhang", "zhang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����ɩ��Ԫ��ʱ�õ�ߦ���ȡ�\n");
                set("unit", "��");
               set("owner_name","����ɩ");
                 set("owner_id","aqing sao");
        }
}
