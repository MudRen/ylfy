// Room: /d/dali/huanggong8.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����С���ϵ�һ�����������ȣ������ƹ����߹���������ϣ�
����������壬Զ������������ˮ������������������㣬�
ͥԺ����Ȼ����ɽ��Ұ���⾳��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"huanggong7",
  "east" : __DIR__"huanggong9",
]));

	setup();
}

