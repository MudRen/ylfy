// Room: /chengdu/wuchi.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
��������������µ������������������ʱ����һ���ͳ����
���ĵط������ܲ�����������ž޴���Ĺ������ʮ���ľ���ż��
����������������ƽʱ��������������һ��Ӣ���������
LONG
	);
        set("no_fight", 1);

	set("exits", ([
                "east" : __DIR__"beijie",
	]));

	setup();
	replace_program(ROOM);
}

