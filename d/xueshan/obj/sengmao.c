// sengmao.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit HEAD; 
 
void create() 
{ 
set_name( HIR "ɮñ" NOR, ({ "seng mao", "mao","hat" }) ); 	
        set_weight(500); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ����ɮ����ɮñ��\n"); 
set("value", 100);     	
set("material", "cloth"); 	
set("armor_type", "head");	
set("armor_prop/armor",10);   	
set("wear_msg","$N����һ��$n��\n");	
set("remove_msg","$N��$n����������\n");	
        } 
        setup(); 
} 
int query_autoload() { return 1; }
