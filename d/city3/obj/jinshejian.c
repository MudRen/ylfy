//bye enter

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIY"���߽�"NOR, ({ "jinshe jian", "jian" }));
        set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������ɾ���ѩ����֮�����Ľ��߽���\n"+
                            "ֻ���ǽ���״��Ϊ�Ź֣�������������һ����\n"+
                            "�������ɣ���β���ɽ��⣬��������ֲ棬��\n"+
                            "�Խ��⾹�����档�⽣�����ã�����������\n"+
                            "���أ��������ǻƽ��������������������\n"+
                            "����һ��Ѫ�ۣ����������͵İ��⣬���ǹ��졣\n");
		set("value", 1000000);
		set("material", "steel");
		set("icon", "10029");
		set("weapon_prop/strength", 10);
		set("wield_msg", HIR "ֻ�������һ����"HIY"���߽�"NOR""HIR"���ʷɳ�������Ծ��$N���С�
����΢΢ҡ�Σ����ϱ��̵�Ѫ��ӳ�ŵƹ⣬��һ�����߲�סŤ�����ӡ�\n" NOR);
		set("unwield_msg", HIR ""HIY"���߽�"NOR""HIR"��$N���з����ڿ��л��˸�����Ļ��ߣ���ৡ���Ծ�뽣�ʡ�\n" NOR);
	}
        init_sword(400,2);
	setup();
}
int query_autoload() { return 1; }