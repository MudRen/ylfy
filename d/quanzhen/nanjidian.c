// najidian.c �ϼ���

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ϼ���");
	set("long", @LONG
�������ϼ���ϼ���������϶�ʮ������֮�ף������ֳ����ǣ�
�������˼���ز֮�񡣵��з��˺�ľ���㰸���㰸�Ϲ�Ʒ�뱸�����
ʮ����ʢ�� 
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"xilang2",
		"northwest" : __DIR__"xilang4",
       ]));
	setup();
	replace_program(ROOM);
}



