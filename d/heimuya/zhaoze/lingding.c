// Room: /d/heimuya/zhaoze/lingding.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�붥");
	set("long", @LONG
��ɽ�żţ���ˮ����ɽ�ȼ伤�����죬������ڣ�����ˮ�����󣬴�
�������붥��ֻ��һ�������ƵĴ��ٲ��Ӷ���˫��֮�䱼�ڶ��£�������
�Ǿ��ˡ�����������ȥ���ٲ�����һ����ݡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"pubupang",
  "southdown" : __DIR__"pubu",
]));
	set("outdoors", "lingding");

	setup();
	replace_program(ROOM);
}
