// Room: /d/dali/huanggong7.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������һ�����������ȣ������ƹ����߹��������
һ��С�����������ϣ�����������壬Զ������������ˮ�������
�����������㣬�ͥԺ����Ȼ����ɽ��Ұ���⾳��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanggong5",
  "northeast" : __DIR__"huanggong8",
]));

	setup();
}

