// Room: /d/dali/jiulou.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ32��17�롣

inherit ROOM;

void create()
{
	set("short", "���Ӿ�¥");
	set("long", @LONG
����һ������������ľ�¥��������ԭ��¥�ľ��ţ������Ե�
�ֿ���ʵ�ã��ṩһЩ�򵥵�ʳ��;�ˮ�������Ķ���һЩ���Ҵ�æ
æ�������ˣ�żȻҲ�м������������������⣬����һ��ʳ���ˮ
����·�ˡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mantuo" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dbdajie1",
]));

	setup();
}

