// zhongtang.c ���� 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ƽ̴��͵ĵط�����ǽ�����������һ��̫ʦ�Ρ���
��ǽ�Ϲ���һ��������ǽ��һ�������ż���������и��������
�����ˡ����ݴ�������׭�֣������������ڣ��ƺ��Ǹ�����²衣
LONG
	);
        
	set("exits", ([
		"east" : __DIR__"waishi",
		"west" : __DIR__"neishi",
        ]));
	create_door("west", "����", "east", DOOR_CLOSED);
	setup();
}



