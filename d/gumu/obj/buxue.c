// buxue.c   ��ѥ
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( HIC "�಼ѥ" NOR, ({ "qing buxue", "xue", "shoe" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "һ˫�಼�����Ƴɵ�ѥ�ӡ�\n");
                set("value", 0);
                set("material", "boots");
                set("armor_prop/dodge", 1);             
        }
        setup();
}
int query_autoload() { return 1; }
