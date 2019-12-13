// Room: /d/dali/kezhan.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺21ʱ42��22�롣

inherit ROOM;

void create()
{
	set("short", "��ջ");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ
��������ţ��������������������صķ������顣��С����
������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ�
LONG
	);
        set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xidajie1",
  "up" : __DIR__"kedian2",
]));

	set("objects", ([
		__DIR__"npc/dingsan" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
        if(objectp(present("ding san", environment(me))))
	return notify_fail("����һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "north" )
        if(objectp(present("ding san", environment(me))))
	return notify_fail("�����ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
