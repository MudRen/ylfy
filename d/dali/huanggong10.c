// Room: /d/dali/huanggong10.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
���������鷿ǰ��һ��Ƭ�㳡���ʵ�ɢ���󾭳�Ҫ���鷿��
�飬�������������䱸���ϣ�һ��Ҳ���Ҵ��⡣
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huanggong5",
  "eastup" : __DIR__"huanggong12",
]));

	setup();
}

