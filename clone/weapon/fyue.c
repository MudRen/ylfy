#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
set_name(HIW"��"+HIC"��"NOR, ({ "yue hen","yue hen jian","jian", "sword" }) );
set_weight(8000);
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 15);   
set("weapon_prop/intelligence", 3);     
set("weapon_prop/strength", 5); 
set("weapon_prop/sword", 50);           
 set("badao", 1);
 set("icon", "10019");
set("unit", "��");
set("value", 10000000); 
set("material", "steel");
set("long", "һ������������˵�Ǳ��Ʋ�Ů����Ȼ�������彣����˵��ѽ����и������Ĵ�˵�������̲������ص�������\n");   
set("wield_msg", HIR"$N����һ��,�϶�Ӧ��͵��ҩ �̺�����ҹҹ��.һ������,$N����������Ϣ�Ķ��˰�������.\n"NOR);
set("wield_msg", HIR"$N����һ��...\n"            
HIM"�϶�Ӧ��͵��ҩ �̺�����ҹҹ��\n"           
HIC"һ�����¹ⲻ����$N���оۼ�...����Խ��Խǿ,���˲���ֱ��,����������ͬ������Ҳ����ǿ�ҵĹ�â\n"              
HIY"$N�����Ϻ��ط���ѣĿ�Ĺ�â...,$N�����Ѷ��˰���ҫ���¹��"HIC"��.\n"NOR);              
} 
init_sword(1000,2);
setup();
}
void init()	
{
add_action("do_wield", "wield");	
}
mixed hit_ob(object me, object victim)
{
int damage_bonus = 0;

damage_bonus = (damage_bonus+random(damage_bonus))/2;

victim->receive_wound("qi",damage_bonus);
return HIC"�������·���ǿ�ҵĹ�â����"+HIW"��"+HIC"��"+HIM"�Ľ�����,"+HIW"��"+HIC"��"+HIY"����������Ŀ�Ĺ�â��\n" NOR;

}
int do_wield(string arg)
{
object me;	
me=this_player();
if ( !wizardp(me) ) 	
{
write(HIW"�������������������������ô��ʹ��!\n"NOR);
return 1;	
}
//   return 1;	
}
int query_autoload() { return 1; }                      	
