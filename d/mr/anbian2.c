#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",
"ԶԶ��ȥ��ֻ��һ��С���ϰ˾ż䷿�䣬����������¥������������Լ¶\n"
"��һ���Ʒ���"HIY"����ˮ�"NOR"����\n"
);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"shuixie",
]));
         setup();
         replace_program(ROOM);
}
