// Room: /d/dali/huanggong6.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m�еµ�[2;37;0m");
	set("long", @LONG
������Ǵ�����Ľ�𽱦�������еĳ���Ҫ��ȫ��������
�������ڳ��軪���������������֮״����ΰ׳����������ԡ�
���г��ϵ����������Ŵ��������ʵ۱����ۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"huanggong5",
]));

	setup();
}

