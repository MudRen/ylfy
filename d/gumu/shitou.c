// shitou.c By csy 98/12/29

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIC"ʯ��"NOR);
     set("long", @LONG
�˵ع������Ӵ�������֮�á����Ͻ��м������ţ�������Ĺ�������ڱ�Ŀ
���������ʯǽ( qiang)�Ͽ��Ų�������, ��ϸһ����ԭ������¼��������
���ȹż�����������Ĺ�������������
LONG
        );

      set("exits", ([
            "west" : __DIR__"gmqs",
            "south" : __DIR__"yaofang",
            "north" : __DIR__"lgf",
      ]));

      set("item_desc", ([
            "qiang" : "ǽ��д���˸��ֹż����֡�\n",
      ]));

      create_door("west", "ʯ��", "east", DOOR_CLOSED);

      setup();
}

void init()
{ 
            add_action("do_du","read1");
}

int do_du(string arg)
{
          mapping fam;
          object me;
          me = this_player();                     
          if ( !living(me) ) return 0;
          if (me->is_busy() || me->is_fighting())
           return notify_fail("����æ���ģ�\n");
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if (arg =="qiang"){                 
          if ((int)me->query("jing") < 20 )
           return notify_fail("����ú���,����˯����\n");
          if ( me->query_skill("literate",1) >100)
           return notify_fail("���Ѿ���ȫ������ǽ�ϵ����֡�\n");
          if ( me->query_skill("literate",1) > 10 && me->query_skill("literate",1) > me->query("combat_exp")/1000)
           return notify_fail("��ľ��鲻�������ܶ���ǽ�ϵ����֡�\n");
          if (me->query("potential", 1) < 1)
           return notify_fail("���Ǳ��û�ˣ������ټ�����ϰ�ˡ�\n");
          me->add("potential", -1);
          me->receive_damage("jing", 5 + random(10));
          me->improve_skill("literate",me->query_int());
          write("�����ʯ�ڣ��·���������\n");
          return 1;
          }
       return notify_fail("��Ҫ��ʲô��\n");
}


