// guanyintai.c ����̨ 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����̨�ֳƴ�̨��λ�ڶ��ɸ�֮�ϣ������������ַ��̨�ӽǿ�������
�������˰����ش��������ؽ�Ϊ֮һ�����Ŀ�������
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
	    "southdown" : __DIR__"dusongge",
	    "eastup" : __DIR__"gaoguanpubu",
      	]));
	setup();
	replace_program(ROOM);
}



