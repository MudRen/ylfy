#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
set_name(GRN"�����Ž�"NOR, ({ "longyin jian", "jian","longyin", "sword" }) );
set_weight(8000);
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 5);
set("weapon_prop/intelligence", 5);
set("weapon_prop/strength", 10);
set("unit", "��");
set("icon", "10021");
set("value", 10000000);	
set("material", "steel");
set("long", "����һ�����α�������������һ�����׳�������������ע�����������֣���˵��һ����������\n");
set("wield_msg", HIC"��ʺ�Ȼ����������Խ��������............\n"
HIG"������ֳ�һ��������ɵľ������������ѻ���һ���Ž�����$N�����С�\n"NOR);
set("unwield_msg", HIC "һ����ɫ�����ڿ�Ծ��$N���е�$n" HIC"��Ȼ��ʧ������\n"NOR);
} 

init_sword(500,2);	
setup();
}
int query_autoload() { return 1; }