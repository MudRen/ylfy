// expblade.c ��������
// Wenwu 2003.8.25
#include <weapon.h>	
inherit BLADE;   	
void create()	
{	
set_name("���Ƶ�", ({ "fengyun dao","blade","fengyun", "dao" }));	
set_weight(5000);	
if (clonep())	
set_default_object(__FILE__);	
else {	
set("unit", "��");     
set("icon", "10040");           	
set("long", "����һ��������Ϊ�����ĵ���������ʿͨ������������ˢ���顣\n");                      	
set("value", 0);	
set("material", "steel");	
}	
init_blade(-30000,2);                      	
setup();	
}	
