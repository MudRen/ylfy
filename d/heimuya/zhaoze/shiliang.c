// Room: /d/heimuya/zhaoze/shiliang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
˳��ɽ·��ǰ��ȥ���в���ʱ��ɽ·�͵��˾�ͷ��ǰ��������Լ����    
��ʯ�������������ɽ��֮�䣬�������֣�������������������ƽ��֮��
����С�����������ô��������ʯ��������ȣ���˵���ߣ�ֻ��һ��Ҳ��
�⵨ս�ľ���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fongdian",
  "north" : __DIR__"shiliang1",
]));
	set("outdoors", "shiliang");

	setup();
	replace_program(ROOM);
}
