
#include <ansi.h>;
inherit ROOM;

void create()
{
     set("short", HIR"Ǳ��"NOR);
     set("long", @LONG
��û��ˮ�У�ֻ��ˮ��������������޷����㡣�������쳣��ֻ��������
��Ǳ�У������ǽ���ά�ȡ�ͻ���������й�ǿ���������������³�,�㲻�����������³�ȥ.
LONG    
    );
/*
     set("exits", ([
         "westup" : __DIR__"gmanhe2",
         "east" : __DIR__"gmql1",
     ]));    
*/
     setup();
}

void init()
{
     object me;
     me = this_player();
me->receive_damage("qi", 500 );	
me->receive_damage("jing", 500 ); 	
     message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
call_out("down", 5, me);	
     if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
     me->set_temp("last_damage_from","��Ǳ���б���");
     me->unconcious();
     me->die();
     return ;   
     }    
}

void down(object me)	
{
tell_object(me, "ֻ���ŵ�ˮ��������һ��ǿ�����������������ȥ...\n");	
me->move(__DIR__"hedi");	
}
