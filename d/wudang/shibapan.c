// Room: /d/wudang/shibapan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ʮ����");
	set("long", @LONG
������һ����ʵ��ʯ���ϣ���Χ�������ԲԵİ��֣�����������������
����������徲����࣬ż���н�����߹���һ�����ͱڣ�һ�������£�̧
ͷ��Լ�ɼ������������е������壬������ˮ���ȣ������Ŀ�������
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  "/d/mengpai/wddizi" : 3,
]));
	set("outdoors", "wudang");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie5",
  "northup" : __DIR__"zixiaogong",
]));

	setup();
	replace_program(ROOM);
}
