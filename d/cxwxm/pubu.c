// pubu.c 
// marry 99 .8
inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
�㴩�����׵�������ˮ�����������¡¡��̧ͷһ����ֻ��һ�����ٲ����Ӹ�����ֱк
���������㲻�ɵ����𡰷���ֱ����ǧ�ߣ�������������족��ʫ������
LONG );
       set("exits", ([
               "east" : __DIR__"yumi1",
       ]));
        set("outdoors", "cxwxm" );
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       int n;
        object me = this_player();

    if(arg)  
   {
    write("��������ѽ����ôϲ��������\n");
         return 1;
}

    message_vision(
    "$N˫��һ�գ�Ĭ���̫���Ͼ�����������������͵�������ȥ��\n", this_player());
    n = (int)me->query("combat_exp");
    if (n >=400000)
        {
          me->move(__DIR__"shandong");
          me->set_temp("jihao",1);
        }
    else
        {
         message_vision(
         "���$N�������޵���Ԩ����û���������ˣ�\n", this_player());
         this_player()->unconcious();
    }

    return 1;
}

