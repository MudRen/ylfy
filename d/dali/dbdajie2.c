// Room: /d/dali/dbdajie2.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺19ʱ27��56�롣

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ���ʹ�����ĳ���·�������ڽ��ʹ���Ե�������Ե���
�ֶ�����Ȼ������ɴ����ز��Ĵ���ʯ�̳ɣ���Χ�긨���������ص�
���ˣ��ο����ﲻ����������������䡣��һƬ�����ľ���
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dbdajie3",
  "east" : __DIR__"wuqidian",
  "south" : __DIR__"dbdajie1",
]));

	setup();
}
