#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
	set("short", "�һ�����");
	set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С������в�������
��������������ȥ�ĺá�
LONG);
	set("outdoors", "taohua");
	set("exits", ([
		"east" :  __FILE__,
		"west" :  __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));             
	setup();
}

void init()
{
	this_player()->receive_damage("qi", 15);
	this_player()->receive_wound("qi",  15);
	this_player()->set_temp("die_for","���һ�����");
	message_vision(HIR"ͻȻһ���һ��������㼲��$N��\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
	int  total_steps;
	mapping myfam;
	
	total_steps = (100-(int)me->query_skill("qimen-wuxing",1))/10;
	
	if ( total_steps <= 0 ) total_steps = 1 ;
	
	myfam = (mapping) this_player()->query("family");

	if ( myfam && myfam["family_name"] == "�һ���" ) total_steps = 1 ; 
	if ( dir == "north" ) me->add_temp("taohua/steps", 1);
    if ( dir == "south" ) me->add_temp("taohua/steps", -1);
	if ( me->query_temp("taohua/steps") == total_steps )
	{
		//me->move(__DIR__"tao_in");
		this_object()->set("exits/north", __DIR__"tao_in");
		me->delete_temp("taohua/steps");
		//return notify_fail("�����˰��죬�����߳����һ�����\n");
		tell_object(me, "�����˰��죬�����߳����һ�����\n");
	}
	else
		this_object()->set("exits/north", __FILE__);
	if ( me->query_temp("taohua/steps") == - total_steps )
	{  
		//me->move(__DIR__"tao_out");
		this_object()->set("exits/south", __DIR__"tao_out");
		me->delete_temp("taohua/steps");
		//return notify_fail("�����˰��죬�����߳����һ�����\n");
		tell_object(me, "�����˰��죬�����߳����һ�����\n");
	}
	else
		this_object()->set("exits/south", __FILE__);

	return 1;
}
