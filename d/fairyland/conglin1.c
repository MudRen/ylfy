
inherit ROOM;
void create()
{
	set("short", "ѩɽ����");
	set("long", @LONG
����һ���ܴ�Ĵ��֣���ľ��֦Ҷ�Ϲ����˱�ѩ��ѩ�׵�һ��Ƭ��������
�ȡ�������ɽ�����죬ֱ��ɽ�����ڴ�����΢¶��һ��С������ϡ���ϣ�����
��С���ϣ�ѩ��������һ�г�������ӡ��
LONG	);
	set("exits", ([
		"northup" : __DIR__"conglin2",
		"eastdown" : __DIR__"shanxi",
	]));
	set("outdoors", "����ɽ");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
