
inherit ROOM;
void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
ֻ����ǰһ����ɽ��ɽ�Ʒǳ���Ҫ��һ��С������ɽ���������ϡ�
������һ����ʯС����ֻͨ���η���
LONG
);
	set("outdoors", "xiaodou");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room16",
  "southwest" : "/d/wudujiao/cun9",
  "westup" : __DIR__"xiaodao",
]));

	setup();
	replace_program(ROOM);
}
