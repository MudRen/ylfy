// gangdao.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("�⵶", ({ "xiu blade","blade" }));
        set_weight(7000);
                set("flag",2);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������˵Ķ̵�������͸��һ�ɱ����ɱ����\n");
                set("value", 5);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
        }
       init_blade(600,2);
        setup();
}

int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
         message("rumor",HIG"���������桿"+ "��˵����ħ����"+
        dest->query("name")+"�õ����ˣ�\n"NOR,users());
        return 1;
}

