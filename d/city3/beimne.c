// Room: /chengdu/northchengmen.c
// oooc: 1998/06/27 

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�ɶ����ţ�����ͷ���²�̫ƽ���ټ��ϳɶ�������������
��������֮Ҫ�壬��Ȼ���̲����ܡ������ש����ĳ�ǽ������
�����٣�Ҳ��֪�����ж��ٸ���ͷ�ˡ��سǵı��²�������ĵ�
���㣬�ڴ��ǻ���Ҳ�׼�����ʲô���£��㲻�ɵüӿ��˲�����
��·�ϱ��ݺᡣ
LONG
	);

	set("exits", ([
                "north" : __DIR__"dadao",
                "south" : __DIR__"beijie",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "chengdu");
	setup();
}

