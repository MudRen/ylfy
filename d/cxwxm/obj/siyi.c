#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
 set_name(HIR "�ɷ�˿��" NOR, ({ "cloth", "siyi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", 1000);
               set("female_only", 1);
             set("no_get",1); 
               set("no_drop",1); 
               set("no_give",1); 
                set("long","���ǳ��������ŵı��£��ǿ�ɽ�����ñ���˿���ɡ�\n");
      }
        setup();
}
