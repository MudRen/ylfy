// Room: /d/city/beidajie2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣
�ϱ��Եúܷ�æ��������һ�������¥�󣬹��š�̫���ŷ硱���������Ŷ�����
��һ�����ң�������¥�����ֲ�������������������ѧʿ���ֱʡ�����������
�����㴹�����Ρ�������һ�����ӵ����������ƣ��Ǿ�������ѧ��֮������
ͬ�����������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beimen",
  "west" : __DIR__"wumiao",
  "south" : __DIR__"beidajie1",
  "east" : __DIR__"zuixianlou",
  "northeast" : __DIR__"hongqiao",
]));
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/scavenger" : 1,
  "/d/npc/guojing" : 1,
]));
	setup();
	replace_program(ROOM);
}
