#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����ˮ�");
         set("long",@long
��䷿��С������, ��Ϊ���š�С���Ҷ���д��"����ˮ�"�ĸ�����, 
������Ϊ������������һ��С·����֪��ͨ������ġ�����ǰ�ߣ��͵�
��"������"���ϱ���ˮ鿵ĺ�Ժ��
long);
         set("exits",([
             "north" : __DIR__"anbian2",
      "west" : __DIR__"anbian4",
             "south" : __DIR__"houyuan1",
]));
setup();
             replace_program(ROOM);
}
