//tulong.c

#include <weapon.h>

inherit BLADE;

void create()
{
set_name(HIW HIY"������"NOR, ({ "tulong dao", "blade","tulong","dao" }) );	
set_weight(15000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "��");
set("icon", "10037");
set("weapon_prop/strength", 25);
set("weapon_prop/karma", 10);
set("weapon_prop/dodge", 100);
set("weapon_prop/blade", 100);
set("weapon_prop/constitution", 5); 
set("value", 5000000);	
set("material", "iron");
set("long", "��˵�е���������������ʱ͸������ɱ�����˷�����\n" );
set("wield_msg",HIB"һ������������$N�ѽ�$n"+HIB"�������У���Χ��ʱɱ������������Ϣ���㲻��������Ĵ����ս��"NOR+"\n"NOR);	
set("unwield_msg", YEL"$N��$n"+YEL"�ع����ڣ�������������ٸ�ѹ����������������˿�����"NOR+"\n"NOR);
}
init_blade(500,1);	
setup();
}
int query_autoload() { return 1; }	
