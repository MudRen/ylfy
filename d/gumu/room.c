
#include <ansi.h>
#include <room.h>
inherit ROOM;
int a = random(2);
int b = random(2);
int c = random(2);

void create()
{    
     
     set("short", "ʯ��");
     set("long", @LONG
����һ���С��ʯ�ң����������Ⱦ޴��ʯ�ţ�����ȴ��������ֻ������
�̵�����ͷ�񣬽�����������������֮��������Ϊ��������Ϊ�׻�����Ϊ��ʨ��
�޿��и��߻��ɣ���������������������֪ʲô���ء�
LONG
        );

     set("exits", ([
         "out" : __DIR__"gmlg2",
         ]));

        while (!a && !b && !c) {
                a = random(2);
                b = random(2);
                c = random(2);
        }
        set_temp("mark/left", 0);
        set_temp("mark/middle", 0);
        set_temp("mark/right", 0);
        setup();
   }

void init()
{
     add_action("do_pull", "pull");
     add_action("do_push", "push");
 }

int do_pull(string arg)
{    
     object me = this_player();
     if ( arg == "left") {
        if (query_temp("mark/left") > 0)
                return notify_fail("��ͷ�еĻ����Ѿ�����ͷ�ˡ�\n");
        message_vision("$N�⶯��ͷ�еĻ��ɣ�������������һ�¡�\n", me);
        message("vision", "ʯ�ź�����¡¡��������\n", me);
        add_temp("mark/left", 1);
        return 1;
     }    
     if ( arg == "middle") {
        if (query_temp("mark/middle") > 0)
                return notify_fail("ʨͷ�еĻ����Ѿ�����ͷ�ˡ�\n");
     message_vision("$N�⶯ʨͷ�еĻ��ɣ�������������һ�¡�\n", me);
     message("vision", "ʯ�ź�����¡¡��������\n", me);
      add_temp("mark/middle", 1);
     return 1;
}
     if (arg == "right") {
        if (query_temp("mark/right") > 0)
                return notify_fail("��ͷ�еĻ����Ѿ�����ͷ�ˡ�\n");
     message_vision("$N�⶯��ͷ�еĻ��ɣ�������������һ�¡�\n", me);
     message("vision", "ʯ�ź�����¡¡��������\n", me); 
    add_temp("mark/right", 1);
     return 1;
}
     if ( arg == "gate")
             return notify_fail("�����ź������Ƶġ�\n");  
      write("��Ҫ��ʲô��\n");
      return 1;
}

int do_push(string arg)
{    object me = this_player();
     if ( arg == "left") {
        if (query_temp("mark/left") < 0)
                return notify_fail("��ͷ�еĻ����Ѿ��Ƶ�ͷ�ˡ�\n");
     message_vision("$N�⶯��ͷ�еĻ��ɣ�������������һ�¡�\n", me);
     message("vision", "ʯ�ź�����¡¡��������\n"NOR, me);
     add_temp("mark/left", -1);
     return 1;
}    
     if ( arg == "middle") {
        if (query_temp("mark/middle") < 0)
                return notify_fail("ʨͷ�еĻ����Ѿ��Ƶ�ͷ�ˡ�\n");
     message_vision("$N�⶯ʨͷ�еĻ��ɣ�������������һ�¡�\n", me);
     message("vision", "ʯ�ź�����¡¡��������\n"NOR, me);
      add_temp("mark/middle", -1);
     return 1;
}
     if (arg == "right") {
        if (query_temp("mark/right") < 0)
                return notify_fail("��ͷ�еĻ����Ѿ��Ƶ�ͷ�ˡ�\n");
     message_vision("$N�⶯��ͷ�еĻ��ɣ�������������һ�¡�\n", me);
     message("vision", "ʯ�ź�����¡¡��������\n", me); 
    add_temp("mark/right", -1);
     return 1;
}
     if ( arg == "gate")
{     
      if (me->query("qi") < 20 || me->query("neili") < 100)
      return notify_fail("�����������������ƶ�ʯ�š�\n");
      if (query_temp("mark/left") == a && query_temp("mark/middle") == b
      && query_temp("mark/right") == -c)
{     message_vision("$N�����ƶ�ʯ�ţ�ʯ��Ӧ�ֶ�����\n", me);
      set("exits/enter", __DIR__"gmlg3");
      remove_call_out("shut_gate");
      call_out("shut_gate", 10);
      me->add("combat_exp", random(10));
      set_temp("mark/left", 0);
      set_temp("mark/middle", 0);
      set_temp("mark/right", 0);
      return 1;    
}
      message_vision("$N��������ʯ�ţ�����ȴ��˿������\n", me);
      me->receive_damage("qi", 20);
      me->add("neili", -100);
      return 1;
}      
      write("��Ҫ��ʲô��\n");
      return 1;
}
                
void shut_gate()
{  
      if ( !query("exits/enter")) return;
      message("vision", "ʯ�Ż����������Լ������¹�������\n", this_object());
      delete("exits/enter");
}



