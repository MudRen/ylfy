// Wenwu 2003.8.25
#include <ansi.h>	
inherit ITEM;	
void create()	
{	
set_name(HIW "兵器架" NOR, ({ "bingqi jia", "jia" }) );        
set_weight(30000000);	
if( clonep() )	
set_default_object(__FILE__);	
else{	
set("unit", "个");	
set("long", HIY"这是一个专门用来放各种兵器的架子,你可以从里面拿需要的兵器 na <兵器名称> from jia 里面有:\n"NOR+ 	
HIW"风雷剑(fenglei jian)\n"+    	
HIW"风火棍(fenghuo gun)\n"+     	
HIW"风云刀(fengyun dao)	
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
return notify_fail("命令格式: na <兵器名称> from jia。\n");      
if (arg2!="jia")	
return notify_fail("命令格式: na <兵器名称> from jia。\n");      
// if(present(arg1, me) || present(arg1, environment()))       	
// return notify_fail("已经有这样东西了。\n");             	
switch (arg1){	
case "fenglei jian": ob=new("/clone/weapon/expsword"); break;
case "fenghuo gun": ob=new("/clone/weapon/expclub"); break;    	
case "fengyun dao": ob=new("/clone/weapon/expblade"); break;  	
default :	
return notify_fail("没有这种兵器。\n");	
}	
if(ob) ob->move(me);    	
message_vision("$N从兵器架上取下了$n。\n",me, ob);    	
return 1;	
}	
