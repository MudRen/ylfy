// Room: /chengdu/chengzhong.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡���������������
����ʯ�ذ塣�����������񣬽ֵ������ϱ��ݺᣬ·�����˲��ϡ�
��������ĺ������̾�������ʿȺ���ڴˣ����Ǹ����̷��ǵĻ�
��ش�������һЩ���ֺ��е��������������
LONG
	);
        set("no_sleep_room",1);

	set("exits", ([
                "east" : __DIR__"dongjie2",
                "south" : __DIR__"nanjie2",
                "west" : __DIR__"xijie2",
                "north" : __DIR__"beijie2",
	]));

	set("objects", ([
                __DIR__"npc/xiaohai" : 1,
                __DIR__"npc/liumang" : 1,
                __DIR__"npc/yiren" : 1,
	]));

	setup();
}

