// Room: /d/emei/gudelin2.c ������ �ŵ���2


#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ŵ���");
	set("long", @LONG
һ������е��������������������ͦ���Σ�֦Ҷ����������������ӵ��
��ʵ��֦Ҷ������գ��������ڵ�˿��Ҳ�ޡ�������Ҷ������һ�أ�����ȥ
ʮ�ֵ�����
LONG
	);

	set("exits", ([
		"east" : __DIR__"gudelin",
                "west" : __DIR__"gudelin3",
	]));

	set("outdoors", "emei");
        setup();
}

