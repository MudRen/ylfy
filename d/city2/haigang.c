
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǴӾ��ǳ����ıؾ�֮�أ���������Գ�������������
LONG
	);
	set("exits", ([
                "west" : __DIR__"road10",
	]));
	set("objects", ([
                __DIR__"npc/flowerg":2,
		"/d/shenlong/npc/chuanfu" :1,
"/d/binghuodao/npc/chuanfu" :1,	
	]));
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
