// pishui zhu
inherit ITEM;	
void create()	
{	
set_name(CYN BLINK "��ˮ��" NOR, ({ "pishui zhu" ,"zhu", }) );	
set_weight(210000);     	
if( clonep() )	
set_default_object(__FILE__);	
else {	
set("unit", "��");	
set("long","һ����������ӡ�\n");	
set("value", 0);  	
set("material", "dainomd");	
}	
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
if(arg=="pishui zhu"){                  			
if(ob->move(me))		
message("rumor",HIW"\n���������š�����˵"+me->query("name")+"��"+place+"Ū����һ��"CYN"��ˮ��.\n\n"NOR,users());        		
return 1;		
}		
return 0;		
}		
