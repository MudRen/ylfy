// donglang4.c ��������
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������ϣ��������������֡�����һ��֧����������ʵ��ϣ�
��һ�������������������ݶ����������ȶ��ߵ�ǽ�Ͽ��ŵ��Ƕ�ʮ��Т
��ͼ�Σ�ÿһ��ͼ������һ�������Ĺ��¡��������������������ʵ
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanhuangdian",
		"northwest" : __DIR__"leizudian",
	]));
	
	setup();
       replace_program(ROOM);

}


