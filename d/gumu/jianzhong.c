// jianzhong.c

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"��ڣ"NOR);
    set("long", @LONG
�Ὺڣ��ʯ�飬¶���������������������ڵ�һ���ڶ����ѽ�֮�䣬����
һ�鳤��ʯƬ����������ʯƬ�����һ�����ʯ֮�ϡ�  
LONG
        );   

    setup();
}

void init()
{
        add_action("do_ti", "ti");
        add_action("do_tui", "tui");               
}

int do_ti(string arg)
{
        object me,sword;
        me = this_player();
//      sword = unew("/clone/weapon/xuantiejian");
        if (!arg ) return 0;         
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( arg == "gangjian" ){
           if (me->query_temp("sword"))
           return notify_fail("���Ѿ�������һ�ѽ��˰���\n"); 
           message_vision(HIY"$N�������׵�һ������ֻ�����µ�ʯ�Ͽ�������С�֣����������ͣ��޼᲻
�ݣ�����ǰ��֮���˷Ⱥ�����档��\n"NOR,me); 
           me->set_temp("sword",1);
           return 1;
           }
         else
        if ( arg == "xuantiejian" ){
           if (!me->query_temp("sword"))
             return notify_fail("ʲô��\n");
           if (me->query_str() < 30 )
             return notify_fail("�����������������������������ġ�\n");                  
if (me->query("max_neili") < 30000 ){                          	
               message_vision(HIY"$N������ȥ��ڶ�������ֻ�������ߣ�Ǻ�һ������Ȼ���ֵ��£���ʯ��һ
�������Ľ�������������һ����\n"NOR,me);
//  48                 me->set_temp("sword1",1);	
               me->add("neili",-300);
return 1;
               }
//  52  if (!me->query_temp("sword1"))          	
//  53                 return notify_fail("��������ʲô��\n");	
               me->add("neili",-300);
               me->delete_temp("sword");
               me->delete_temp("sword1");
               me->set_temp("sword2",1);
               sword= new("/d/gumu/obj/xuantiejian");
               if(!clonep(sword))
//               if (!query_temp("jian_get") && !present("xuantie jian", me)) 
               return notify_fail(HIR"�������ˣ��������Ѿ�����ȡ���ˡ�\n"NOR);            
               sword->move(me);
               me->set_temp("jian_get",1);
               message_vision(HIY"���$N�ٸ�����������˷����������߰�ʮ����������ǲ���һ���¡�����
�����߽��涼�Ƕۿڣ������ԲԲ�����Ǹ����򡣿����µ�ʯ��ʱ��������С
�ֵ������ؽ��޷棬���ɲ�������ʮ��ǰ��֮�������¡���\n"NOR,me);                 
               return 1;
              } else
           if( arg == "mujian") {
             if ( !me->query_temp("sword2"))
                return notify_fail("��������ʲô��\n");
                message_vision(HIY"$N�������ȥȡ������������֪��������ȴ��ƮƮ�Ļ����������һ����ԭ
���Ǳ�ľ���������վã����������Ѹ��࣬�������µ�ʯ�̵�������ʮ���ᣬ
��������ľ��ʯ����Ϊ�����Դ˾��ޣ�������޽�ʤ�н�֮������\n"NOR,me);
                me->delete_temp("sword2");
                return 1;
              }
}

int do_tui(string arg)
{
           object me;
           me = this_player();
           if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
           if ( !arg || arg !="shi" )
                return notify_fail("��Ҫ��ʲô��\n");
           if (arg =="shi")
           message_vision(YEL"$N��������˿����������ƶ���ʯ��\n\n"NOR,me);
           write(HIG"�����ʯ�ƿ���¶���˽�ڣ�ĳ��ڡ�\n"NOR);
           set("exits/out", __DIR__"pingtai");
           remove_call_out("close");
           call_out("close", 5, this_object());
           return 1; 
}      

void close(object room)
{
        message("vision",HIY"��ʯ�����ƻ���ԭλ���ֵ�ס�˳��ڡ�\n"NOR, room);
        room->delete("exits/out");
}

