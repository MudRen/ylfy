// Room: /d/emei/gudelin3.c ������ �ŵ���3


#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ŵ���");
	set("long", @LONG
��������һ������е��ϣ�·�������������������ͦ���Σ���ʵ��֦Ҷ
������գ��������ڵ�˿��Ҳ�ޡ�������Ҷ������һ�أ�����ȥʮ�ֵ�����
��Զ����ʱ��������������
LONG
	);

	set("exits", ([
		"east" : __DIR__"gudelin2",
                "west" : __DIR__"dabeita",
	]));

	set("outdoors", "emei");
        setup();
}

