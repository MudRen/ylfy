// qiankun baojia.c	
#include <armor.h>
#include <ansi.h>	
inherit ARMOR;	
void create()	
{	
set_name(HIC "Ǭ"YEL"��"HIM"����" NOR,({ "qiankun baojia","baojia","armor", }) ); 	
set_weight(1000);	
if( clonep() )	
set_default_object(__FILE__);	
else	
{	
set("unit", "��");	
set("long", "һ����������,��˵����ؼ������������,��\n");	
set("material", "copper");	
set("value",0);	
set("no_get", "�������������뿪�Ƕ���\n");	
set("no_drop", "�������������뿪�㡣\n");                           	
set("armor_prop/armor", 500);	
set("armor_prop/dodge", 100);	
set("armor_prop/force", 100);	
set("armor_prop/unarmed", 100);	
set("armor_prop/sword", 100);	
set("armor_prop/blade", 100);	
set("armor_prop/parry", 100);	
set("wear_msg", YEL "$N˫��һ����һ������ɫ���ӭ��չ����ƮƮ��������$N�ļ���,"GRN"$N����Ӱ��$n"GRN"����ɫ��������ģ�����塣\n" NOR);	
set("remove_msg", YEL "$N�����������ƾ��һ�ӣ�$n"YEL"����Ʈ������$N����,$N�������𽥱��������\n" NOR);	
}	
setup();	
}	
int query_autoload() { return 1; }	
