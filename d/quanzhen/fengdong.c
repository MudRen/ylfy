// fengdong.c �綴 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�綴");
	set("long", @LONG
�����Ƿ綴������һʮ���ף�����ʮ�ף����ж��󻨸ڼ��Ŷ��ɡ��������ϰϰ������
�쬣���һ������ĺõط��������Ǳ�����
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"east" : __DIR__"taiyihu",
		"north" : __DIR__"bingdong",
	]));
	setup();
	replace_program(ROOM);
}

