// Wenwu 2003.8.25
#include <ansi.h>	
inherit ITEM;	
void create()	
{	
set_name(HIW "������" NOR, ({ "bingqi jia", "jia" }) );        
set_weight(30000000);	
if( clonep() )	
set_default_object(__FILE__);	
else{	
set("unit", "��");	
set("long", HIY"����һ��ר�������Ÿ��ֱ����ļ���,����Դ���������Ҫ�ı��� na <��������> from jia ������:\n"NOR+ 	
HIW"���׽�(fenglei jian)\n"+    	
HIW"����(fenghuo gun)\n"+     	
HIW"���Ƶ�(fengyun dao)	
\n"NOR);	
set("material","wood");	
set("no_get",1);	
}
}
void init()
{	
add_action("do_get",({"na"}));    	
}	
int do_get(string arg)	
{	
object me,ob;	
string arg1,arg2;	
me=this_player();	
if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)	
return notify_fail("�����ʽ: na <��������> from jia��\n");      
if (arg2!="jia")	
return notify_fail("�����ʽ: na <��������> from jia��\n");      
// if(present(arg1, me) || present(arg1, environment()))       	
// return notify_fail("�Ѿ������������ˡ�\n");             	
switch (arg1){	
case "fenglei jian": ob=new("/clone/weapon/expsword"); break;
case "fenghuo gun": ob=new("/clone/weapon/expclub"); break;    	
case "fengyun dao": ob=new("/clone/weapon/expblade"); break;  	
default :	
return notify_fail("û�����ֱ�����\n");	
}	
if(ob) ob->move(me);    	
message_vision("$N�ӱ�������ȡ����$n��\n",me, ob);    	
return 1;	
}	
