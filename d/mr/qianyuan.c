#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","ǰԺ");
         set("long",@long
������������ɽׯ��ǰԺ, ֻ��һ����Ѿ��, ��Ů������������Ϣ, ��
�Ҹ�����������, ��Ȼ�书������Ժ�ӵĶ�����һ��Сʯ�ţ�������һ��
���ȡ������߾͵���ׯ�š�
long);
         set("outdoors","mr");
         set("exits",([
             "west" : __DIR__"zhuangmen",
             "north" : __DIR__"hc4",
             "east" : __DIR__"shiqiao1",
             "south" : __DIR__"cl",
]));
          set("objects", ([
	    __DIR__"npc/yahuan" : 2,
        ]));
         setup();
         replace_program(ROOM);
}
