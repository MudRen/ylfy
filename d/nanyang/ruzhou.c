#include "/clone/item/liuxing.h"
inherit ROOM;

void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ����
�����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ�����������
���Ͼ��ǵıؾ�֮�����ٱ��̲�Ҳʮ���ϸ񡣴��������������ţ���
�Ե�����֮�е���ɽ�ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaozheng",
      "north" : "/d/city2/road9",
		"west" : __DIR__"wangxi-lu",
		"east" : __DIR__"hong-damen",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



