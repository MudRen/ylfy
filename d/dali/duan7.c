// Room: /d/dali/duan7.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺20ʱ44��11�롣

inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
���������������ĺ�԰��������Ȼ��ģԶ�ϻʹ�������԰
С���������ÿƷ�軨����Ȼ�Ǿ��������������������ϲ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"duan6",
]));

        set("objects", ([
        __DIR__"npc/yahuan" : 1,
        __DIR__"npc/jiading" : 1,
]));

	setup();
}

