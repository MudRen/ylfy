// tyroad2.c ʯ��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ������ʵ��ʯ��·����ʱ���н���ͺ����˴��������߹���̧ͷ��
������ΰ��������������������֮�У�Ρ��׳�ۡ��ϱ�һ��ʯ��ͨ��ɽ�£�
��Լ�ɼ�Զ���һ�ƬƬ��������Ŀ��
LONG
	);
	set("outdoors", "quanzhen");

	set("exits", ([
		"northup" : __DIR__"guangchang",
		"southdown" : __DIR__"tyroad1",
	]));
	setup();
	replace_program(ROOM);
}