//Room:/d/lingshedao/migong1.c
inherit ROOM;
#include <ansi.h>
void create()
{ 
set("short", "云路");	
        set("long",@LONG
四周白茫茫一片什么也看不见,你艰辛地往前继续摸索.....	
LONG );
set("outdoors", "city");	
        set("exits", ([
                "east" :  __FILE__,
"north" :  __FILE__,	
"south" :  __FILE__,	
"northwest" :  __FILE__,	
"northeast" :  __FILE__,        	
"southeast" :  __FILE__,        	
"southup" :  __FILE__,                	
"northup" :  __FILE__,                	
"westup" :  __FILE__,                	
"eastup" :  __FILE__,                	
"eastdown" :  __FILE__,                	
"westdown" :  __FILE__,                	
"northdown" :  __FILE__,                	
"southdown" :  __FILE__,                	
"southwest" :  __FILE__,        	
                "west" :  __FILE__,
"down" : __FILE__,	
"up" : __FILE__,	
        ]));             
        set("no_clean_up", 0);
        setup();
}


void init()
{
    object ob=this_player();
    ob->receive_damage("qi", 25);
    ob->receive_wound("qi",  25);
message_vision(HIW"$N越走越感无力、神智渐转模糊，迷糊间似乎被什么东西撞了下，头脑一清似乎有些疼痛...\n"NOR,ob);	
}

int valid_leave(object me, string dir)
{
int tiandao_num;    	
tiandao_num = 35;	
        if ( dir == "northup")
me->add_temp("ctmigong/steps",1); 	
        if ( dir == "southdown")
me->add_temp("ctmigong/steps",-1);	
if ( dir == "down")	
me->add_temp("ctmigong/steps",-1);	
if ( dir == "southdown")	
me->add_temp("ctmigong/steps",1);	
if ( dir == "northdown")	
me->add_temp("ctmigong/steps",-1);	
if ( dir == "westdown")	
me->add_temp("ctmigong/steps",-1);	
if ( dir == "eastdown")	
me->add_temp("ctmigong/steps",-1);	
if ( dir == "up")	
me->add_temp("ctmigong/steps",1);	
if ( dir == "south")	
me->add_temp("ctmigong/steps",1);	
if ( dir == "north")	
me->add_temp("ctmigong/steps",1);	
if (me->query_temp("ctmigong/steps") == tiandao_num )	
        {  
me->move(__DIR__"zisharoom");   	
me->delete_temp("tcmigong/steps");	
return notify_fail("你咬紧牙关艰难前行，终于走到了尽头，原来这里既然是.....。\n");	
             }
        return ::valid_leave(me,dir);
}
