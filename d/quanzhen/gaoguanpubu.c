// gaoguanpubu.c �߹��ٲ� 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�߹��ٲ�");
	set("long", @LONG
ӭ��һ�ٲ�������ʮ�ף������ɽ���ֱ����̶���������ס���᯲�
��ʫ�ƣ������������٣���հװ����������ʱ�꣬���������ס������Ƕ�
��ǰ�߹��ٲ���ʵ�������д�ա������ǳ���̶��
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"northup" : __DIR__"chexiangtan",
		"westdown" : __DIR__"guanyintai",
        ]));
	setup();
	replace_program(ROOM);
}



