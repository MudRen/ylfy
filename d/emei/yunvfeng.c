// /d/emei/yunvfeng.c ������ ���
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��ɽ�������˳�����ɽ����ؾ�Ȼ������������һԾ���������أ�����
̤����������ϸ�ݣ������ŵ��������Ļ��㣬���ݼ�أ��ʹ���֦������õ�
���������Ķ�Ѩ֮�󣬾���������һ�����츣�أ����������������������
��ɽ���ƣ��ƺ�ب��������δ���˼�����������ѩ����ƣ��վ��������޷���
Ԯ���롣
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
		"south" : __DIR__"taolin",
		]));
	set("objects", ([ 
	]));

	setup();
	
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{

   object me = this_player();
	
    if ( !arg || (arg != "shandong") )
        return notify_fail("������ʲô��������\n");

    if (me->is_busy())
	return notify_fail("��������æ���ء�\n");

    message_vision("$N�ֽŲ��ã���ʯ���ϣ�������ɽ����\n", me);
    me->move(__DIR__"shandong12");
     return 1;
}
