// /d/cxwxm/shandong.c
// marry 99.8
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short","ɽ��");
       set("long", @LONG
ԭ����������һ��ɽ���������������һƬ�����䳱ʪ�������������������ƺ�����
��ʯ�ڡ�һ�󺮷紵���������ֱ��ս��
LONG
     );
       
        set("exits", ([
                "northeast" : __FILE__,
                "southeast" : __FILE__,
                "southwest" : __FILE__,
                "northwest" : __FILE__,
                "north" : __FILE__,
                "south" : __FILE__,
                "west" : __FILE__,
                "east" : __FILE__,
        ]));
        setup();
}

void init()
{
        object me;
        int jing, jing_cost, n ,v;

        me = this_player();
        n = (int)me->query("combat_exp");
        v = (int)me->query("dex");
        jing = me->query("jing");
        jing_cost = (me->query("chulu") * 5);

        if(jing < jing_cost)
                me->unconcious();
        me->add("jing", -jing_cost);

        if (me->query("chulu") >= 10)
        {
message_vision(HIC"$Nһ�ߺ�˼���룬һ�����ߣ���Ȼ������ǰһ�����Ѿ�������һ��������Դ��\n"NOR            WHT"����$N������Ϊ������֧�������˹�ȥ��\n"NOR,me);

                me->move("/d/cxwxm/cxwx");
                me->set("chulu",0);
                me->set("jihao",1);
                me->unconcious();
                return;
        }  
        if ((me->query("chulu") <= -10)||(!me->query_temp("jihao")))
        {
                message_vision(WHT"$Nһ��С�ĵ�����һ�����ӡ�\n"NOR,me);
                me->move("/d/cxwxm/anhe");
                me->set("chulu",0);
                if(userp(me))
                me->unconcious();
                return ;
        }

   if (((int)me->query("str") >= 15) && (((int)me->query("kar")) >= 25)&& (n>10000000||random(v)>20))        { 
         me->add("chulu",1); 
         }
        else 
        {
         me->add("chulu",-1); 
        }
}
