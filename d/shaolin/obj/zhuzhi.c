// zhuzhi.c ��֦
#include <weapon.h>
inherit BLADE;
void create()
{
    set_name("��֦", ({ "zhuzhi","zhi" }) );
    set_weight(350);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ����ɫ����֦������ո��������������ż�Ƭ��Ҷ��\n");
        set("unit", "��");
        set("value", 0);
         set("flag",2);
        set("wield_msg", "$Nץ��һ��$n��ժ�������Ҷ�ӣ��������е�������\n");
    }
    init_blade(1);
    setup();
}
int query_autoload() { return 1; }