#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
set_name(HIY"��"+HIR"��"+HIC"��"NOR, ({ "huolin jian", "jian","huolin", "sword" }) );	
set_weight(15000);	
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 15);	
set("weapon_prop/intelligence", 5);	
set("weapon_prop/strength", 35);	
set("unit", "��");
set("icon", "10020");
set("value", 30000000); 	
set("material", "steel");
set("long", "��˵�е�а��������ͨ����,���������̵Ľ����Եø���ҫ��,��˵�˽���������,����а��,�����ְ�Ȩ��������\n");	
set("wield_msg", HIR"ֻ��^�^��һ��,$n"+HIR"���ʵ����ջ���һƬ��ϼ��ͷ����,��ؼ��ʱ��ó����쳣.....\n"           	
YEL"�����˸��Լ��һͷȫ������������˶��£�$N����һ������������Ϣ�ض��˰�ͨ�����$n��\n"NOR);      	
set("unwield_msg", HIR "$N�ٽ�����һ��$n"+HIR"���ַɳ�,���������ۺ��,��ʱ������а����ʢ,���������Ȼ��ʧ����,����һ��$n"+HIR"��������.\n"NOR);  	
} 

init_sword(500,2);      	
setup();
}
int hit_ob(object me,object victim,int damage_bonus)
{
victim->apply_condition("fire_poison", 200);
victim->start_busy(1);
return damage_bonus;
}
void init()	
{	
if(this_player()!=environment())	
add_action("do_get","get");	
}	
int do_get(string arg)	
{	
object me=this_player();	
object ob=this_object();	
string place;	
if(environment(ob)->query("short"))	
place = environment(ob)->query("short");	
else place = "һ����Ϊ��֪�ĵط�";	
if(arg=="huolin jian"){                  		
if(ob->move(me))	
message("rumor",HIW"\n���������š�����˵"+me->name()+"��"+place+"Ū����һ��"HIY"��"HIR"��"HIC"��\n\n"NOR,users());        	
me->add("jing",-(me->query("max_jing")/3));
me->set("neili",0);
return 1;	
}	
return 0;	
}	
int query_autoload() { return 1; }
