
#include <ansi.h>;
inherit ROOM;

void create()
{
     set("short", HIR"Ǳ��"NOR);
     set("long", @LONG
��û��ˮ�У�ֻ��ˮ��������������޷����㡣�������쳣��ֻ��������
��Ǳ�У������ǽ���ά�ȡ�
LONG    
    );

     set("exits", ([
         "westup" : __DIR__"gmanhe2",
         "east" : __DIR__"gmql1",
     ]));    

     setup();
}

void init()
{
     object me;
     me = this_player();
add_action("do_qian","qian");	
     me->receive_damage("qi", 50 );
     me->receive_damage("jing", 50 ); 
     message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
     if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
     me->set_temp("last_damage_from","��Ǳ���б���");
     me->unconcious();
     me->die();
     return ;   
     }    
}

int do_qian(string arg)	
{
object me;	
me=this_player();	
if ( !arg || arg != "down" )	
return notify_fail("��Ҫ������Ǳ��\n");	
if ( me->is_busy() || me->is_fighting())	
return notify_fail("����æ���ģ�\n");	
if (arg =="down"){	
if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() <= 50) 	
return notify_fail("�����������������޷�������Ǳ!\n");	
message_vision(HIG"$Nһ�����ԣ�Ǳ����ȥ��\n"NOR, me);	
me->receive_damage("jing", 500);   	
me->receive_damage("qi", 500);   	
me->move(__DIR__"gmql3");	
tell_room(environment(me), me->name() + "������Ǳ��������\n", ({ me }));	
message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);	
return 1;	
}
return 1;	
}
