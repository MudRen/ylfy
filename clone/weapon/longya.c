#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
set_name(HIR"����"NOR, ({ "long ya", "blade" }) );	
set_weight(8000);
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 15);	
set("weapon_prop/intelligence", 3);	
set("weapon_prop/strength", 5);	
set("weapon_prop/blade", 50);		
set("unit", "��");
set("icon", "10022");
set("value", 10000000);	
set("material", "steel");
set("long", "��˵�е��Ϲ�����а��֮һ���쵶�߲������ഫ����ԭ����ʹ��������֮����ж������������\n");	
set("wield_msg", HIR"һ������,$N����������Ϣ�Ķ��˰Ѻ������Ƶĵ�.\n"NOR);
set("wield_msg", HIR"����ͻȻ��ó���..,����...\n"            
HIB"ɱ........��........��...........��.....\n"   	
HIY"���Եظ�������...���಻��,$N�����Ѷ��˰�"HIR"�������Ƶĵ�.\n"NOR);          	
} 

init_blade(500,2);	
setup();
}
int query_autoload() { return 1; }