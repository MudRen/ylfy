// Room: /chengdu/ruin1.c
// oooc: 1998/06/26

inherit ROOM;
void create()
{
	set("short", "�ƾɴ�լ");
	set("long", @LONG
������һ���ƾɴ�լ��ǰԺ�������Ѿ�������һ�룬���ڵ���
����ס�����ȥ·��ͥԺ���Ӳݴ����������Ѿ��ܾ�û����ס�ˣ�
��˵���������й����֣����ǵ�Ҳ��û��˵�����˱�������˸�
���ľ�����Ȼ�ճ����
LONG
	);
        set("outdoors", "chengdu");
	set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"cai",
                "east" : __DIR__"ruin2",
        ]));
        set("objects", ([
           __DIR__"npc/qigai" : 3,
        ]));

	setup();
}

