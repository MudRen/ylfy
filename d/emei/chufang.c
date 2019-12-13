// Room: /d/emei/chufang.c ����
// create by host dec,15 1997

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string);
int do_sit(string);
void delete_served(object);

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݵķ���Ͳ�������һ��ɢ����������ζ��������Ƣ��ֻ��
�������������ҵ��׼�Ů��������æ����衢���������ڶ��ҹ��ֻ������
������һ�׶��ص����跽����ÿ�꿪���ɲ輾�ڣ�Ū���ϺõĲ�Ҷ��Ȼ���
԰�в�ժ�ϺõĶž�;ջ��Ļ��굷�������У���˵����������������
�������յ����ã���ʮ�ֵ�������ڰ�����Щ����(table)������(chair)��
�����������ҵ��ӡ�
LONG
	);

	set("exits", ([
                "south" :__DIR__"zoulang3",
	]));
	
    set("item_desc", ([
	    "table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�\n",
	    "chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ������Ү��\n",
	]));
	                                

	set("objects",([
              __DIR__"npc/fangbilin" : 1
	]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}


int do_tap(string arg)
{

	object me;
	object fang;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("��Ҫ��ʲô��\n");	
	}
		
	me = this_player();	
	if( !objectp(fang = present("fang bi lin", environment(me))) )
	 	return notify_fail("�����������ӣ�ȴ����û�����㡣��ͻȻ�о��Լ������ġ�\n");
	 			
	if( !me->query_temp("marks/sit") )  
		return notify_fail("�����������ӣ�ȴû�뵽�ж������˴���������������Ȼ�ؿ����㣬"
	 		+"\n��ͻȻ�о��Լ����޴���\n");
	
    if( me->query_temp("marks/served") )
    {
        message_vision("�����ղ��ͷ��ض�$N˵�����ո����Ϲ�������ž�Ҫ��"+
				"���Ǹ��ң�����ҿɲ��ǰ���\n", me);
        return notify_fail("");
    }

	message_vision("$N��������ǰ��������������棬������ݸ��һЦ�������к���\n", me);
	
	fang->serve_tea(me) ;

    me->set_temp("marks/served", 1);
    call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ����˸���λ�ˡ�\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("�����˸���λ���£������ϲ衣\n");	
}


int valid_leave(object me, string dir)
{

	if (  (dir == "south")
	   && ( present("xiang cha", this_player())
	        || present("mi tao", this_player()) ) 
	   && objectp(present("fang bi lin", environment(me))) )
       switch ( random(2) ) 
	{
	case 0: 
	 return notify_fail
		("�����հ���һƲ���Ա��˺����˻����������߻��ﻹ����һЩ��СŮ��Ҳ���������أ�\n");
	 break;
	case 1:
	 message_vision("�����ն�$N���˸��򸣣�����ʦ���Ը�������ʳ���ô����跿��", me);
	 return notify_fail("\n");
	 break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
