// Room: /d/dali/huanggong12.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m���鷿[2;37;0m");
	set("long", @LONG
�����ǻʹ������鷿������������ŷ��̣��鷿��Ҳ����
��Ҿ��䡣���ڴ����������ϰ�䣬����Ҳ�ղ��˴�����ϵĲ�
���书��Ҫ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"huanggong10",
]));

	setup();
}

