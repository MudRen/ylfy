// taiyihu.c ̫�Һ�

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "̫�Һ�");
	set("long", @LONG
�������̫�Һ���̫�Һ�Ϊɽ���������Ϊ���챦��������ɣ�����
�߷廷�У�����̲�������ɽ��ˮӰ���羰ʮ���������緺�ۺ��ϣ���
�����ڷ��֮�䣬����������Ŵ���Ȼ����Ȥ��������������Ƿ綴��
�����Ǵ仪��
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"southdown" : __DIR__"shijie2",
		"west" : __DIR__"fengdong",
             "north": __DIR__"cuihuamiao" 
	]));
	setup();
	replace_program(ROOM);
}

