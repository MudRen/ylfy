// donglang1.c ��������

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ�������ϣ��������������֡�����һ��֧�ڱ������ٵ��ϣ�
��һ�����������������ݶ����������ȶ��ߵ�ǽ�Ͽ��ŵ��Ƕ�ʮ��Т��
ͼ�Σ�ÿһ��ͼ������һ�������Ĺ��¡�������������������ٵ
LONG
	);

	set("exits", ([
		"north" : __DIR__"lingguandian",
		"west" : __DIR__"sanqingdian",
	]));
	
	setup();
       replace_program(ROOM);

}

