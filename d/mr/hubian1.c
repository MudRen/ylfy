#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @LONG
�׻�˵ : ��������, �����պ����������Ǵ��������̫���� �����̲���Ư
��һҶҶ��С��, һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ��С�
LONG
      );
       set("outdoors","mr");
       set("exits", ([
           "west" : __DIR__"hubian",
	   "southeast" : __DIR__"shiqiao",
]));
       setup();
       replace_program(ROOM);
}
