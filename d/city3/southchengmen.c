// Room: /chengdu/southchengmen.c
// oooc: 1998/06/20 

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
��·�ϱ����졣
LONG
	);

	set("exits", ([
                "north" : __DIR__"nanjie",
                "south" : __DIR__"yidao",
		//"east" : __DIR__"work7",
		//"west" : __DIR__"work3",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "chengdu");
	setup();
}

