// fumo-dao.c ��ħ��
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
    set_name("��ħ��", ({ "fumo dao", "dao" }));
    set_weight(10000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ������ѩ���ķ�ħ�������м�������Ѫ��������������ƥ��
ӳ���������˵�������ǰ�ɴ�Ħ����Я����ԭ��һ·��֮������ħ��
���Ƿ�����Ͻ�ħ������\n");
        set("value", 1000000);
         set("flag",1);
        set("material", "steel");
            set("shaolin",1);
        set("weapon_prop/strength", 15);
        set("wield_msg", HIY "ֻ�������һ������ħ�����ʷɳ�������Ծ��$N���С�
˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n" NOR);
        set("unwield_msg", HIY "��ħ����$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�\n" NOR);
    }
    init_blade(300,1);
    setup();
}
int query_autoload() { return 1; }