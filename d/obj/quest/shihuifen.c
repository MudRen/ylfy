inherit ITEM;

#include <task.h>
void create()
{
        set_name(HIW "ʯ�ҷ�" NOR, ({"shihui fen", "fen"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ͨ�������õ�ʯ�ҷۡ�\n");
                set("unit", "��");
               set("owner_name","ΤС��");
               set("owner_id","wei xiaobao");
        }
}


