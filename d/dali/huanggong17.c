// Room: /d/dali/huanggong17.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������䳡�������֮���һ�����ȣ��������������ĵ�����
��ʯ�̳ɵ�С�ȸ����徻�����¡���������һ��С�أ��������㾧Ө
��͸��������һ����ɽ��һ����ϸ��ע����У���һ��ɽˮ��԰ͼ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huanggong16",
  "east" : __DIR__"huanggong3",
]));

	setup();
}

