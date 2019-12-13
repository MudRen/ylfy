
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
          set("short", HIG"����"NOR);
          set("long", @LONG
����Ҳ�ǿյ�����ûʲô���裬��ǰ��д��һ�д��֣�zi�����������ڶ�
����һ���������� (westpic)�Ļ���������Ů�ɣ����ǹ�Ĺ�ɵ�ʦ���ֳ�Ӣ��
ʦ�����ŵ�Ф�񣬶��ࣨeastpic��������ȴ��һ����ʿ�� 
LONG        );

          set("exits", ([
                        "east" : __DIR__"gmqs",
                        "west" : __DIR__"gmzt",
                        "north" : __DIR__"gmws1",
                        "south" : __DIR__"gmws",
          ]));

         set("objects",([
                 __DIR__"npc/xln" : 1,
                 __DIR__"npc/yang" : 1,
         ]));
          set("item_desc", ([
               "westpic" : HIM"�����������һ����ʮ�����꣬���ڶԾ���ױ�����о���ӳ��Ů����ò������
��ü���ޣ��۽�ȴ��������һ��ɱ�������ǹ�Ĺ��ʦ���ֳ�Ӣ����һ����ʮ��
�����Ѿ�ߣ��ֳ����裬�����ź򣬺�̬���䣬�������������������С��Ů
��ʦ����\n"NOR,
               "eastpic" : HIC"���е���������ߣ���������������ʳָָ�Ŷ����ǣ�ֻ�Ǳ������⣬��òȴ
��������\n"NOR,
               "zi" : HIR"\t���ҹ�Ĺ�����������������񹦣�������ʦ��\n"NOR,
          ]));

          create_door("south", "ʯ��","north", DOOR_CLOSED);
          setup();
}

void init()
{ 
         add_action("do_ketou", "ketou"); 
         add_action("do_tuo", "tuo");
}
 
int do_ketou(string arg)
{
          mapping fam;
          object me = this_player();

        if ((!arg) || (arg != "westpic")) return 0;
          message_vision("$N�����򵹣�˫ϥ���أ�������������ʦ���ŵĻ������һ����ͷ. \n", me);
          me->add_temp("marks/ketou", 1);
if (me->query_temp("marks/tuo") == 2 && me->query_temp("marks/ketou") == 4	&& !me->query("family")
&& (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��") ){	
          me->set("family_name", "��Ĺ��");
          me->set("title", HIW"��Ĺ����"NOR);
          me->create_family("��Ĺ��", 5, "����");
          me->set("class","swordsman");
          write(HIR"��ϲ����Ը��Ϊһ����Ĺ���ӡ�\n"NOR);
          me->delete_temp("marks/tuo");
          me->delete_temp("marks/ketou");
          return 1;
          }
        if (me->query_temp("marks/ketou") == 15 ){
          me->delete_temp("marks/ketou");
         if (me->query_temp("marks/goldkey"))
            return notify_fail("����¶��һ��С��,������տ���Ҳ,�����������������. \n");
          message_vision(HIY"$N��ǰ��ʯ��ͻȻ�³�,¶��һ�ѽ�Կ��,$N�õ�һ�ѽ�Կ��. \n"NOR, me);
          me->set_temp("marks/goldkey");
          new(__DIR__"obj/goldkey")->move(me);
          }
     return 1;
}

int do_tuo(string arg)
{
           object me = this_player();
           if (me->query_temp("marks/tuo") == 2)
             return notify_fail("���ٹ���û�У�\n");
           if ( arg=="eastpic"){
           message_vision("$N���������Ļ���ݺ�����һ��. \n", me);
           me->add_temp("marks/tuo", 1);
           return 1;
           }
          return notify_fail("�㲻Ҫ������ٿ�ˮ����\n");
}


