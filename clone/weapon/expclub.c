// expclub.c ��������	
// Wenwu 2003.8.25
#include <weapon.h>	
inherit CLUB;  	
void create()	
{	
set_name("����", ({ "fenghuo gun","club","fenghuo", "gun" }));
set_weight(5000);	
if (clonep())	
set_default_object(__FILE__);	
else {	
set("unit", "��");   
set("icon", "10041");   	
set("long", "����һ��������Ϊ�����Ĺ���������ʿͨ������������ˢ���顣\n");              	
set("value", 0);	
set("material", "steel");	
}	
init_club(-30000,2);                     	
setup();	
}	
