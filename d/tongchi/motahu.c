inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "Ī����");
        set("long", @LONG
��Ī����������ɲ⣬���䳺�ǣ����Ϸ������³壬�������Ǻ���
��������ӿ�ǳ�����֮������Ͽˮ�ƣ��й�֮���޲�����
LONG
);
        set("exits", ([ 
  "south" : __DIR__"?",
]));

        set("item_desc", ([
        "����" : "�������������ȥ��\n",
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
    if( !arg || arg!="����") return notify_fail("��Ҫ��ʲô��\n");
            message("vision", me->name() + "˳�ŷ������˹�ȥ��\n",
                    environment(me), ({me}) );
        me->move(__DIR__"damen");
            message_vision("$N�������������˹�����\n", me);
        return 1;
}
