
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
      set("short", HIG"����"NOR);
      set("long", @LONG
�⴦�ǹ�Ĺ�ɵ��Ӳμ�����֮�����˿̹�Ĺ����С��Ů�������������
�����̽�������Ա��˲����书�ѳ�һ����ʦ������ʸ־����֮�����������
��Ľ���ѡ�����ֻһ�ų���������ʯ�Ρ����Ϸ���һ���Ҷ�(bian).
LONG  
      );

      set("exits", ([
           "east" : __DIR__"gmht",
           "west" : __DIR__"gmqt",
           "south" : __DIR__"gmlg1",
           "north" : __DIR__"gmlg2",
      ])); 
//��shi ren���������𵱻�--wpk      set("objects",([
//         __DIR__"npc/shiren" : 2,   
//      ]));

      set("item_desc", ([
          "bian" :  HIR"
             ����������������������������������������
             ����������                      ��������
             ��������    ���鲻�� ��ĵ���   ��������
             ��������                        ��������
             ����������������������������������������\n"NOR,
       ]));

      create_door("south", "ʯ��", "north", DOOR_CLOSED);

      setup();
}

void init()
{ 
        add_action("do_jump","zong");
}

int do_jump(string arg)
{
     object me;
     me=this_player();
     if (arg!="bian") return 0;
if(me->is_busy())
return notify_fail("����һ��������û����ɡ�\n");
    if(me->query_skill("dodge",1) < 100)
       return notify_fail("�㹦���������������Ҷ\n");
     message_vision(HIY"$N�������У�ƽ�հ������ɣ����������Ҷ�֮��\n"NOR,me);
     me->move(__DIR__"bianhou"); 
me->start_busy(1);
     return 1; 
}

