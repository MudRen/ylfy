// xiangfang1.c �᷿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
��վ��һ�䲻����᷿�У������ɨ�ĺܸɾ�������ǽ��һ����ܣ����Ű�
ʮ��������������䣬������Ŀ�����ǰ����һ���鰸���ķ��ı��ٶ��߱�����
���Ҳ࣬��һ�Ű��������Ϸ���һ������β�ݱ�ɵ����š�
LONG
	);
        
	set("exits", ([
		"east" : __DIR__"neiyuan",
	   ]));
	setup();
	replace_program(ROOM);
}



