// yaofang.c by csy 99/02/24
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIG"ҩ��"NOR);
       set("long", @LONG
������һ��ʯ�ң���Χ�Ļ�ѽ�ʯ���յĵƻ�ͨ����ʯ����������˺ܶ�
ƿƿ�޹ޣ����涼�����˱�ǩ��һƿƿ��佬����Ĺ�����Ƴɺ���ڴ˴�����
�ܿ���������Ĺ��������æµ�ĸɻ
LONG        );

          set("exits", ([
               "west" : __DIR__"fang",
               "north" : __DIR__"shitou",
          ]));             

          setup();
}

void init()
{
       add_action("do_make","make");
       add_action("do_make","huo");
}

int do_make(string arg)
{
        object me,ob,name1;
        int exp,pot,score;
        me= this_player();
        ob= present("feng mi", me);
        name1= me->query("id");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");        
        if ( arg =="jiang"){
           if ( ! me->query_temp("gm_job1"))
                return notify_fail("�㻹ûȥ�����أ���ô������佬��\n");
           if (!objectp(present("feng mi", me)))
                return notify_fail("����ʲô���Ƴ���佬��\n");
           if ( ob->query_temp("gm/make") != name1 )
                return notify_fail("����ۺ�����������İɣ�\n");         
           message_vision(HIY"$N��ϸ�ؽ����۵��;��ȣ��Ƴ���佬�����ڼ��ϡ�\n"NOR,me);
           me->delete_temp("gm_job1");
           exp=40+random(20);
           me->add("combat_exp",exp);
           pot= 10+random(10);
//           if(( (int)me->query("potential", 1) + pot) > (int)me->query("max_pot", 1)){
//           me->set("potential", (int)me->query("max_pot", 1));
//           }
//           if(( (int)me->query("potential", 1) + pot) <= (int)me->query("max_pot", 1)){
           me->add("potential",pot); 
           score=2+random(5);
           me->add("score",score);//           }
           call_out("destroying", 1, ob);
           tell_object(me,HIW"�㱻�����ˣ�\n" + 
           chinese_number(exp) + "��ʵս����\n" +
           chinese_number(pot) + "��Ǳ��\n" +
           chinese_number(score) + "��ʦ���ҳ϶�\n"NOR); 
           return 1;
           }
        return notify_fail("����ѷ����Ƴ�ʲô����\n");
}

void destroying(object ob)
{
        destruct(ob);
        return;
}
