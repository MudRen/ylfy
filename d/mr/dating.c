#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set ("long",@long
�����г������, ��ʲ����, �����Ϲ�����������ֻ�, ��������
���ȵ��ż�, ������ʾ�����˵��𾴡������Ķ������鷿,�����Ǿ�
�ң������Ǻ�����
long);
         set("exits",([
             "north" : __DIR__"xiaojing1-2",
             "west" : __DIR__"jushi",
             "south" : __DIR__"houting",
             "east" : __DIR__"shufang",
]));
         set("objects",([
                __DIR__"npc/gongye" : 1,
                __DIR__"obj/xiangcha" : 2,
]));
         setup();
         replace_program(ROOM);
}
