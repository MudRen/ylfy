// sanhuangdian.c ���ʵ�

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ʵ�");
	set("long", @LONG
���������ʵ�����Ǵ�˵�е�Զ�ŵ�����������ָ�ж���˵����
�˵�������ʣ����ˣ����ػʣ���ũ�����˻ʣ���ԯ�������з�
�˺�ľ���㰸���㰸�Ϲ�Ʒ�뱸�����ʮ����ʢ�� 
LONG
	);
       
	set("exits", ([
		"south" : __DIR__"donglang2",
		"north" : __DIR__"donglang4",
       ]));
	setup();
	replace_program(ROOM);
}



