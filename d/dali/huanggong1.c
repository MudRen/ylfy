// Room: /d/dali/huanggong1.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ39��13�롣

inherit ROOM;

void create()
{
	set("short", "[1;33mʥ�ȹ�[2;37;0m");
	set("long", @LONG
ʥ�ȹ��Ǵ���ʹ���ǰ������������������̷��裬����������
�ɶ��칤������Ϲ���һ�������������ġ���Ȫ��ˮ���������
��ȥ�����н����������̻Ի͡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"paifang",
  "north" : __DIR__"huanggong2",
]));

	setup();
}

