// cangjingge.c �ؾ���

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ؾ���");
	set("long", @LONG
��ǰһ��С¥��ɽ����,¥�����������滨��ݣ�������ʿ�ֽ�����
�߶����������������Ҫ��֮һ�Ĳؾ���
LONG
	);

	set("exits", ([
		"west" : __DIR__"houyuan",
             "enter" :__DIR__"cangjingge1",	
          ]));

	setup();
	replace_program(ROOM);
}
