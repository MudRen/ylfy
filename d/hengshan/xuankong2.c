// xuankong2.c

inherit ROOM;

void create()
{
	set("short", "��������¥");
	set("long", @LONG
�����������µ�����¥��Ҳ���ϱ�ͤ���������ڶ�������ʯѨ����
��Ϊ����¥���ջ��������ȫ���涫�������ϱ�Σ¥���������·ֶϣ�
���Ǽ��ա�
LONG
	);
	set("exits", ([
		"north"   : __DIR__"zhanqiao",
		"southup" : __DIR__"zhandao",
			"enter"   : __DIR__"xuankong3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
