// baihong-jian.c
// by ronger

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIC"�׺罣"NOR, ({ "baihong", "jian" }));
	set_weight(8000);
        set("unique", 1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		  set("icon", "10024");
                set("long", HIC"һ����֪��������һ��������ﭰ������Ľ������˲������塣\n"NOR);
                set("value", 500000);
                set("material", "steel");
                set("wield_msg", HIG"ͻȻ�䣬����֮��һ����ɫ������������$N������Ȼ����\n"
                        "һ����˸��ҫ�۰׹�Ĺ����"HIC"�׺罣"HIG"��\n"NOR);
                set("unwield_msg", HIC"�׺罣"HIW"�ڻ���һ�󺮷������Ȼ�ع����С�\n" NOR);
        }
        init_sword(120);
        set("no_drop", "�����ı�������ô����㶪���أ� \n");
        set("no_give", "�����ı�������ô����������أ� \n");
        set("no_put", "�����ı�������ô����㶪���أ� \n");
        set("no_sell", "�����ı�������˭�������Ҫ�ģ� \n");
        setup();
}


