// Room: /d/dali/dbdajie3.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺19ʱ28��9�롣

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
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"beidajie3",
  "south" : __DIR__"dbdajie2",
]));

	setup();
}
