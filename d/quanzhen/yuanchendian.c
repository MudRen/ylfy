// yuanchendian.c Ԫ����

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Ԫ����");
	set("long", @LONG
������Ԫ������й����ű�����ۣ�����������Ϊ����֮һ��Э����
��ִ���쾭��γ�������ǳ�����ʱ���򡣵��������ఴ��ɵ�֧��ʮ���ӹ�
������ÿ���˶��������Լ������������ҵ��Լ��ı�����
LONG
	);
       
	set("exits", ([
//		"northeast" : __DIR__"xilang5",
		"south" : __DIR__"xilang4",
       ]));

	set("objects", ([
"/d/quanzhen/npc/wangchuyi" : 1]));

	setup();
	replace_program(ROOM);
}



