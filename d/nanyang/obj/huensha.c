// ruanwei jia
#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
    set_name(HIW "��ɴ" NOR,({ "huen sha","sha", }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else
    {
        set("unit", "��");
            set("long", "һ��������ʦ���õġ���ƮƮ�ġ�ѩ�׵Ļ�ɴ��\n");
        set("material", "copper");
            set("value",20000);
            set("armor_prop/armor", 5);
                set("female_only", 1);
    }
    setup();
}

int query_autoload() { return 1; }