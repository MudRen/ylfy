// Room: /d/songshan/fengchangtai.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
��������̨�ɴ���ʯ������ÿ���ʯ����ü���ƽ����������Ϊ��
��������������ģ�������£��ƿ����ʣ����費������Ŀ��������ң
���ɸ����ţ��ƺ�����һ�ߣ��������������������ڣ����϶��ǵ�����
ɽ��
LONG );
	set("exits", ([
		"eastdown" : __DIR__"shandao8",
	]));
	set("objects", ([
		__DIR__"npc/bo": 1,
		__DIR__"npc/sha": 1,
        __DIR__"master/master" : 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
