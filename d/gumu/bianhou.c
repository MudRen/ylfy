// Room: bianhou.c
// csy 1998.12.29
#include <ansi.h>
inherit ROOM;

void create()
{
      set("short",HIB"�Һ�"NOR);
      set("long", @LONG
������ǹ�Ĺ�����Ҷ�֮�󣬺������ʲô�����������
LONG
    );
      
      set("objects",([
         __DIR__"obj/silkey" : 1,   
      ]));

      setup();
}

void init()
{
     add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me,room;
        me=this_player();  
        if (arg!="down") return 0;
if(me->is_busy())
return notify_fail("����һ��������û����ɡ�\n");     	
        message("vision",me->name()+"һ����������ȥ��\n",this_object());
        if(room=find_object(__DIR__"gmzt"))
        message("vision",me->name()+"���Ҷ������˹�����\n",room);
        me->move(__DIR__"gmzt");
me->start_busy(1);
        return 1;
}

