// hudi2.c ����

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������С�����ף����ܺں����ģ�ͷ����ֻ�ܿ���һ�����⣬��ߵ�ˮ��
�ƺ������ļ��ˡ������ƺ���һ�����⣬Ҳ��֪��Щʲô����ΧһƬ���ţ���
�������Ų��ɱ����
LONG
	);
        
	set("exits", ([
		"down" : __DIR__"hudi3",
        ]));
	setup();
	replace_program(ROOM);
}
