inherit ITEM;
#include <task.h>
void create()
{
        set_name("���־�", ({"san zijing", "jing"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�쵤�����鱾��\n");
                set("unit", "��");
                set("owner_name","�쵤��");
                set("owner_id","zhu danchen");
        }
}
