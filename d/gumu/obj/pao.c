// pao.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"��˿����"NOR, ({ "qingsi changpao","pao","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ���ʵ��������˿���ۡ�\n");
                set("unit", "��");
                set("material", "cloth");                
                set("armor_prop/armor", 20);
        }
        setup();
}

int query_autoload() { return 1; }