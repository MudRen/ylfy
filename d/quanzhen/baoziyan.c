// baoziyan.c ������ 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ǳ�����,������״����һλ��ĸ���ź��ӣ��ȴ����ɷ�Ĺ�
���������ܶ��������ͱ�,��ǰֻ��һ����խ��ɽ·ͨ��ɽ�ϡ�����
�������ҡ�
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
	    "westup" : __DIR__"laoyuyan",
	    "southdown" : __DIR__"cuihuamiao",
        ]));
	setup();
	replace_program(ROOM);
}


