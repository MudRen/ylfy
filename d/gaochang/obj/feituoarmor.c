#include <ansi.h>
inherit EQUIP;
void create()
{
    set_name(YEL "���ս��" NOR, ({ "gold armor","armor","jia", }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
	set("icon", "10089");
        set("value",500000);
	set("long", "����һ���ûƽ������ɵĻ��ף����ϵ����һȺ������������
��˵��ֻ�и߲������ſ���ʹ�÷��ձ�ǡ�\n");
	set("armor_type", "cloth");
        set("armor_prop/dodge", 60);
        set("armor_prop/armor", 500);
    }
}
int query_autoload() { return 1; }