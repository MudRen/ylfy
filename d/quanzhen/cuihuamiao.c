// cuihuamiao.c �仪��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�仪��");
	set("long", @LONG
������Ⱥɽ�����е�һ��С���е����˼��ʶ��������й����ų���
ү��������ܶ���һƬƬ�������֡���ǰ��һ��ʯ�̳ɵĹ㳡�����Ƿֲ�
�ż���ʯ���ӣ����ο�Ъ�š������Ǳ����ҡ�
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"west" : __DIR__"songlin3",
		"northup" : __DIR__"baoziyan",
                "east": __DIR__"songlin2", 
                "north": __DIR__"songlin1",
                "south": __DIR__"taiyihu",
	]));
	setup();
	replace_program(ROOM);
}


