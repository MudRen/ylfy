inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����ʯ·��һ·�����������������ˡ����ϱ��Ƕ��š�
�������������ߡ�
LONG
	);
        set("outdoors", "city2");
	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"southeast" : __DIR__"dongmen",
	]));
	setup();
	replace_program(ROOM);
}
