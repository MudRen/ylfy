// tanan.c

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIY"ˮ̶����"NOR);
    set("long", @LONG
��վ��һƬɽ���е�һ��ˮ̶(tan�����ߡ���Ŀ�Ĺˣ�ֻ��������ݣ���
��һ������Ļ�԰��Ȼ����Ӱ�������Ĺ����ˣ�������ʮ�ְ������ݵ���һ��
���ѵ�С·ֱͨ��Զ��һ��é�ݡ�
LONG
        );
    set("item_desc", ([
          "tan":HIC"���Ŀ��̶����ȥ������ˮ̶����ˮ�ݻζ���������֪���İ���������ȥ��\n"NOR,      
          ]));

    set("outdoors", "��Ĺ");

    set("objects", ([
                __DIR__"obj/shi3" : 1,
                __DIR__"obj/shi1" : 2,
        ]));
    set("exits", ([
          "north" : __DIR__"xiaolu",
    ]));        

    setup();

}

void init()
{
      add_action("do_tiao", "tiao");
       
}

int do_tiao(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "tan")
                return notify_fail("��Ҫ��������\n");
        message_vision(HIY"$N��ͨһ����ӿ��������ˮ̶��\n"NOR, me);
        me->set("water", me->max_water_capacity()+200);
        me->move(__DIR__"tanmian");
        tell_room(environment(me), me->name() + "�Ӱ�������������\n", ({ me }));
        return 1;
}

