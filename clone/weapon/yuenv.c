#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
set_name(HIR"ԽŮ"+HIY"����"+HIC"��"NOR, ({ "yuenv chaoyang jian", "yuenv jian","jian", "sword" }) );	
set_weight(8000);
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 15);	
set("weapon_prop/intelligence", 3);	
set("weapon_prop/strength", 5);	
set("weapon_prop/sword", 50);		
set("unit", "��");
set("icon", "10022");
set("value", 10000000);	
set("material", "steel");
set("long", "һ�ѳ��������˵��ս��ʱԽŮ�������彣��������̶Ȳ��¸ɽ� Īа��\n");	
set("wield_msg", HIR"һ������,$N����������Ϣ�Ķ��˰ѳ����.\n"NOR);
set("wield_msg", HIR"����ͻȻ��ó���..,����...\n"            
HIB"��........��........Ǻ................\n"   	
HIY"������Խ��������������...���಻��,$N�����Ѷ��˰�"HIR"�����.\n"NOR);          	
} 

init_sword(500,2);	
setup();
}
int query_autoload() { return 1; }
