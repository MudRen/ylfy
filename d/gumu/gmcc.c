

#include <room.h>
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", HIC"������"NOR);
     set("long", @LONG
��Ĺ����������࣬�����Ҷ���Щ�ճ���Ʒ������������ѷ���ǽ�ǣ���
�������й�Ĺ����ǰ����ɨ������������
LONG  
      );

     set("exits", ([
         "north" : __DIR__"fang",
     ]));    

     set("fire_count", 2);

     setup();
}

void init()
{
       add_action("do_search", ({"search","zhao"}));
}

int do_search(string arg)
{
        object ob,me=this_player();
        if ( arg == "qiangjiao"){
         if ( me->query_temp("fire") < 3 ){
          if(objectp(ob = present("fire", me)))        
           return notify_fail("���Ѿ����˻����ˣ���ô��ô̰�ģ�\n");   
          me->add_temp("fire", 1);
          message_vision(YEL"$N��ǽ�ŵ���Ʒ���﷭����ȥʲôҲû���š�\n"NOR, me);
          return 1;
          }                      
          message_vision(HIY"$N��ǽ�ŵ���Ʒ���﷭����ȥ�ҳ�һ�ѻ��ۡ�\n"NOR, me);
          me->delete_temp("fire");
          new(__DIR__"obj/fire")->move(me);
          return 1;
          }
     return notify_fail("��Ҫ��ʲô��\n");      
}

