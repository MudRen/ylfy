inherit ITEM;
#include <task.h>
void create()
{
        set_name("ñ��", ({"mao zi", "mao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ǯ�ϱ�ϲ������ñ�ӡ�\n");
                set("unit", "��");
               set("owner_name","Ǯ�ϱ�");
               set("owner_id","qian laoben");
        }
}
