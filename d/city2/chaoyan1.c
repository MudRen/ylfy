inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����������Ĵ���������������У�ʮ�����֡����߾��ǳ����š�
LONG
	);
        set("outdoors", "city2");
	set("exits", ([
		"west" : __DIR__"wangfu2",
		"east" : __DIR__"chaoyang",
		"south" : __DIR__"zhubaodian",
	]));
	setup();
	replace_program(ROOM);
}
