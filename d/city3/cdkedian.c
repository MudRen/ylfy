// Room: /chengdu/cdkedian.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "������ջ");
	set("long", @LONG
������һ�����ֺŵĿ�ջ��ո�µ������ŵ������룬����һ
��������������һ�������������������ǿ�ջ�ĳ��������ϱ�
��ǽ�ڱ�����һ��ͨ����¥��¥�ݣ��ſ�һ���̽�Ĵ�������д
���ĸ����֡�������ջ����
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
                "paizi" : "¥�Ͽͷ���ÿҹ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
                "south" : __DIR__"dongjie1",
                "up" : __DIR__"cdkedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

        if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
