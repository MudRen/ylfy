// Room: /d/tiezhang/dezj.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "[32m�ڶ�ָ��[0;37;0m");
	set("long", @LONG
    �����ѵ�����ָ��İ�ɽ���ˣ���������ɽ���е�����ָһ���� 
ÿ��ɽ���ַ����أ�������ָ��ָ��һ�㣬�����������λ�ڵڶ�ָ�ڵ�
λ�á�������嶥�ѽ���͸�����������������ѿ��Կ���ɽ·�ľ�ͷ�ˡ�
��ǰ����ʮ���ɴ��������������һ����Ѩ(dong)������������ʯ���޽�
�ü���������
LONG	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sslin-5",
  "northup" : __DIR__"shanlu-8",
  "enter" : __DIR__"dong-1",
]));
     set("objects", ([
     __DIR__"npc/mayi" : 2,
    ]));
    set("item_desc", ([ 
  "dong" : "һ���������ɽ�����ڰ���ż���м����׹������������ˣ�����\n",
]));
	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	setup();
      //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	
	
	if (dir == "enter" && objectp(present("mayi zhanglao", environment(me))))
	   return notify_fail("���³��Ϻȵ����������ư���أ��κ��˲������ڣ�����������������\n");
		
        return ::valid_leave(me, dir);
}
