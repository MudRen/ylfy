// epi.c
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
    set_name("����Ƥ", ({ "eyu pi", "pi" }));
    set_weight(100000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "����һ�ž�����Ƥ���ƺ�ʮ�ּ��͡�\n");
        set("material", "cloth");
        set("unit", "��");
        set("value", 1000000);
        set("armor_prop/armor", 1500);
    }
    setup();
}

int query_autoload() { return 1; }