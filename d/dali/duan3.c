// Room: /d/dali/duan3.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺20ʱ44��2�롣

inherit ROOM;

void create()
{
	set("short", "������������");
	set("long", @LONG
�߹������İ���ף���������������ֻ������һ�����ң�д��
�������ʯ���ĸ����֣��������š���î���ʡ��ĸ�С�֡������
�ù������ֻ���һʱҲ��������ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"duan4",
  "westdown" : __DIR__"duan2",
]));

        set("objects", ([
        __DIR__"npc/yahuan" : 1,
        __DIR__"npc/jiading" : 1,
]));

	setup();
}

