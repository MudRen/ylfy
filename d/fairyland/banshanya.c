
inherit ROOM;
void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
���������У���ߵ�ɽ��ʮ�����գ�ֱ���˰��ʱ��Ҳ���κ�ȥ·�ˡ�
LONG	);
	set("no_clean_up", 0);

	set("outdoors", "����ɽ");
	setup();
}

void init()
{
	add_action("do_climb", ({"climb", "pa"}));
}

int do_climb(string arg)
{
	object me = this_player();
        if(me->is_busy() || me->is_fighting())
              return notify_fail("����æ���أ�\n");
	if (arg == "east") {
		message_vision("$N�����������ȥ��\n", me);
		me->move(__DIR__"songshu");
                me->start_busy(1);
		message("vision", me->name() + "�Ӱ�ɽ�������˹�����С��������������������\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}