// Room: /d/dali/huanggong15.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "С԰");
	set("long", @LONG
������������ǰ��һ��С԰���ʷ�軨ʢ���ļ��ڣ�԰�еĲ軨
���涷�ޣ����࿪�š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanggong16",
  "northup" : __DIR__"huanggong13",
]));

	setup();
}

