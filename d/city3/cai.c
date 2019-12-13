// Room: /chengdu/cai.c
// oooc: 1998/06/24 

inherit ROOM;

void create()
{
        set("short", "�˳�");
	set("long", @LONG
�����Ǹ�С�˳���һ��ɶ��ľ��񶼵�������ˡ���Ȼ���ز�
�Ǻܴ󣬵�Ʒ�ֻ��ǱȽ���ȫ�ġ����ԣ���Χ��Ҳû�еڶ��ҡ���
�˳������ϴ��ƽ��ϲ�����������ҳ���ֻ��ǽ�Ǵ��ƺ��и�����
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"nanjie",
	]));

        set("objects", ([
             __DIR__"npc/oldwomen" : 1,
        ]));

	set("item_desc", ([
        "��" : "����һ���ڲ����еĶ������治֪����Щʲô�Ź֡�\n",
	]));
	setup();
}

void init()
{
        add_action("do_enter", "enter");
//      UPDATE_D->check_user(this_player());	
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="��" )
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move(__DIR__"ruin1");
                message("vision",
			me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	

