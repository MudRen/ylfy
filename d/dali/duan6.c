// Room: /d/dali/duan6.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺20ʱ44��10�롣

inherit ROOM;

void create()
{
	set("short", "Сͤ");
	set("long", @LONG
����������һ�ǵ�һ��Сͤ����������Կ���Զ����Ⱥɽ��
���۵���ɽ��ˮ�̣������Ʋԣ�Ϧ���Ȼƣ���ϼ�Һ죬����һ��
�����;��ĺõط���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"duan8",
  "northwest" : __DIR__"duan5",
  "east" : __DIR__"duan7",
]));

        set("objects", ([
        __DIR__"npc/jiading" : 2,
]));

	setup();
}

