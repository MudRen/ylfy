// gmws1.c By csy 98/12/30
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",HIC"����"NOR);
          set("long", @LONG
������С��Ů��ǰ��ס�����ң����пտն���������������ǰ��ģ����һ
�鳤����ʯ������bed)�����������Ų�ϯ��һ���ײ������������������һ��
�˸ߵ�����������У��������
LONG        );
          
          set("item_desc", ([
               "bed" : HIC"һ������ͨ��ʯ�̳ɵĴ��������䴦����һ��ͻ���ʯ�塣\n"NOR, 
          ]));

          set("exits", ([
               "south" : __DIR__"gmht",
          ]));
                    
          setup();
}

void init()
{
          add_action("do_tang", "tang");
          add_action("do_ban", "ban");
          add_action("do_ban","ddd");
}

int do_tang(string arg)
{
          object me=this_player();
          if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ���ģ�\n");
          if ( arg == "bed"){
             message_vision(HIC"$N����������ʯ�Ƴɵ�ʯ�����档\n"NOR,me);
             me->set_temp("marks/��", 1);
             return 1;
            }
         return notify_fail("��Ҫ���ڵ��ϣ�С������Ŷ��\n");
}  

int do_ban(string arg)
{  
          object me=this_player();
          if (!me->query_temp("marks/��"))
             return 0;
          if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ���أ�\n");          
if (me->is_busy())
return notify_fail("����һ��������û����ɣ�\n");
          if ( arg == "shiban" ){
             if (me->query("neili") < 500)
             return notify_fail("��ʹ�����̵ľ�������ʯ��ȴ��˿������\n");
             message_vision(HIY"$N�����⶯ͻ���ʯ�壬ֻ�����������죬ʯ���������²�ʯ�ҡ�\n"NOR,me);
             me->add("neili",-200);
             me->delete_temp("marks/��");
             me->move(__DIR__"ss0");
             write(HIY"�Ҷ�ʯ�����������������ˡ�\n"NOR);
             return 1;
             }
     return notify_fail("��Ҫ��ʲô��\n");
}

