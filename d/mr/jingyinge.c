#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","������");
         set("long",@long
�������������Եĺó��������ﾲ���ĵģ�û�����˵ķԸ���˭Ҳ����
�������������ǽ�Ϲ���һ��ͼ��
long);
       
       set("valid_startroom", "1");
         set("exits",([
             "east" : __DIR__"neitang",
             "west" : __DIR__"c16-2",
             "south" : __DIR__"c16-5",
	]));
          set("objects", ([
	__DIR__"npc/murong-fu" : 1,
        ]));
         setup();
}