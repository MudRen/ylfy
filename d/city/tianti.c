//Room:/d/lingshedao/migong1.c
inherit ROOM;
#include <ansi.h>
void create()
{ 
set("short", "��·");	
        set("long",@LONG
���ܰ�ããһƬʲôҲ������,���������ǰ��������.....	
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
message_vision(HIW"$NԽ��Խ�����������ǽ�תģ�����Ժ����ƺ���ʲô����ײ���£�ͷ��һ���ƺ���Щ��ʹ...\n"NOR,ob);	
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
return notify_fail("��ҧ�����ؼ���ǰ�У������ߵ��˾�ͷ��ԭ�������Ȼ��.....��\n");	
             }
        return ::valid_leave(me,dir);
}
