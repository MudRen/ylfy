// donglang5.c ��������
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������ϣ��������������֡�����һ��֧�������������ϣ�
��һ�����붫�������ٵ���ݶ����������ȶ��ߵ�ǽ�Ͽ��ŵ��Ƕ�ʮ��Т��
ͼ�Σ�ÿһ��ͼ������һ�������Ĺ��¡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"leizudian",
		"northeast" : __DIR__"sanguandian",
	]));
	
       setup();
       replace_program(ROOM);

}

     
	