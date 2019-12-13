#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","��ˮͤ");
	set("long",
	    "���Ǻ��е�һ��Сͤ�ӣ�������ȥ�����Կ�����������ľ�ɫ,�����Ŀ�\n"
	    "������ͤ�ӱ��Ͽ̻��Ž���ˮ������˷羰�����˲����������롣ͤ����һ\n"
	    "������liang)��\n"
	   );
	set("exits",([
                 "east" : __DIR__"muqiao",
	             ]));
	set("objects", ([
	                    __DIR__"npc/feng" : 1,
	                ]));
	set("item_desc", ([
                      "liang" : "�������Ϻõ��ľ����,���滹��ʮ�ֹŹֵ��ֻ���\n",
	                  ]));
	setup();

}

void init()
{
	add_action("do_jump", "jump");
}


int do_jump(string arg)
{
	object me;
	me = this_player();
	if (arg !="liang")
		return notify_fail("��Ҫ����ȥ��\n");
	if (me->query_dex()<20)
		write("����ͼ���Ϸ������������������ݣ�ֻ�����ա�\n");
	else
	{
		write("������Ծ���˷�����\n");
		message("vision",me->name() + "һ����Ծ���˷�����\n", environment(me), ( {me}) );
		me->move(__DIR__"liang");
		message("vision", me->name() + "������Ծ��������\n", environment(me), ( {me}) );
		return 1;
	}
}
