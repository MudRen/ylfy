
#include <ansi.h>;
inherit ROOM;

void create()
{
set("short", HIR"�����ӵ�"NOR);	
     set("long", @LONG
��û��ˮ�У��о��ƺ��ǵ���ˮ��,ˮ���Ѳ��Ƹղ���ôѸ����ˮѹȴ�Ǹ�����ǰ��������Ҫ͸���������ˣ����鼱	
�¼�����������Ѱ�ҳ�·,�����Ϸ�(southup)����͸������,����
����һϲ,����ϸ��������ϸ�ȥ.
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
add_action("do_swim","swim");   	
me->receive_damage("qi", 500 );	
me->receive_damage("jing", 500 ); 	
     message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
     if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
     me->set_temp("last_damage_from","��Ǳ���б���");
     me->unconcious();
     me->die();
     return ;   
     }    
}

int do_swim(string arg) 	
{
object me;	
me=this_player();	
if ( !arg || arg != "southup" )    	
return notify_fail("��Ҫ�������\n"); 	
if ( me->is_busy() || me->is_fighting())	
return notify_fail("����æ���ģ�\n");	
if (arg =="southup"){      	
if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 	
return notify_fail("�����ӳ��أ��þ�ȫ��Ҳ�޷�����ȥ!\n");	
message_vision(YEL"$N��������һ�ţ������渡ȥ��\n"NOR, me);	
me->receive_damage("jing", 500);   	
me->receive_damage("qi", 500);   	
me->move(__DIR__"mishi");       	
tell_room(environment(me), me->name() + "�����渡��������\n", ({ me }));	
message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);	
return 1;	
}
return 1;	
}
