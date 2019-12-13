#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        set("short", "����");
        set("long",@LONG
����һƬ�ȵ׵�С·������һ���޼ʣ�ȫ��ʢ�����ʻ���΢�������
�۷䵽���衣�������ˡ�������һƬõ�廨����������һƬ��������
LONG
        );
  
	set("outdoors", "yihua");
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
    message_vision(HIR"ͻȻһ��������$NϮ��,$N���ɵÿ�ʼ���룡\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
       
        int  total_steps ;
        mapping myfam;
        total_steps = ( 100 - (int)this_player()->query_skill("qimen-wuxing",1) ) / 10 ;
        if ( total_steps <= 0 ) total_steps = 1 ;  
        myfam = (mapping) this_player()->query("family");
        if(myfam && myfam["family_name"] == "�ƻ���") total_steps = 1 ; 
	if ( dir == "north")
            me->add_temp("yihua/steps",1);
	if ( dir == "south")
            me->add_temp("yihua/steps",-1);

	if (me->query_temp("yihua/steps") == total_steps)
         {
     	    me->move(__DIR__"xiaojin");
            me->delete_temp("yihua/steps");
             return notify_fail("�����˰��죬�����߳��˻�����\n");
         }  

     if (me->query_temp("yihua/steps") == - total_steps )
	    {  
	     me->move(__DIR__"yihua_out");
             me->delete_temp("yihua/steps");
             return notify_fail("�����˰��죬�����߳��˻�����\n");
     	}

        return ::valid_leave(me,dir);
}
