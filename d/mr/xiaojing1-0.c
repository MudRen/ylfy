#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","С��");
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������С������
�졣
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"zhuangmen",
	     "south" : __DIR__"xiaojing1-1",
]));
        setup();
        replace_program(ROOM);
}
