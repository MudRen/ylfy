// pao1.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"��˿����"NOR, ({ "baisi changpao","pao","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ���ʵ�����İ�˿���ۡ�\n");
                set("unit", "��");
                set("material", "cloth");                
                set("armor_prop/armor", 50);
        }
        setup();
}
int query_autoload() { return 1; } 
