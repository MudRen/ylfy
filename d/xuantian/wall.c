inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "ǽ��");
        set("long", @LONG
������ǽͷ�����ܺ����ɵģ���Ȼһ����Ӱ����������ǰ��
LONG
        );
        set("outdoors", "xuantian");

        set("exits", ([ 
   "east" : __DIR__"work",
]));
        set("objects", ([
        ]));
    

        setup();
}

void init()
  {
       add_action("do_climb","climb");
  }
int do_climb(string arg)
{
       
        object me=this_player();
        object ob; 
        if( (!arg) ||!((arg == "wall") || (arg == "down")))
                return 0;
                message_vision("$N˳�ŷ���������ȥ��\n\n",me);
        ob = load_object(__DIR__"midao");
        ob = find_object(__DIR__"midao");
        message("vision", me->query("name")+"˳�ŷ�������������\n", ob);
        me->move(__DIR__"midao");
        return 1;
}

