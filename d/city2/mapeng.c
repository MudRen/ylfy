
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǿ���������������к�����������һ���ţ�
����ͳ��㡰�ֻ֡�ֱ�С�
LONG
	);
	set("exits", ([
		"west" : __DIR__"kang3",
	]));
/* Deleted by Hop, 97.06.13
	set("objects", ([
		"/d/city2/npc/yucongma" : 1,
	]));
*/
	setup();
	replace_program(ROOM);
}
