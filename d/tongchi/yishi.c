inherit ROOM;
int do_jump(string arg);
void create()
{
          set("short", "������");
        set("long", @LONG
�������ͨ�԰����������ƽ����ʲô�£���Ҷ����������
���ۣ����ҳ�����ķ��������аڷ���һ�Ŵ��Σ��������Ǹ���
�����ӡ��������Ϸ�����һ���(bian),������������ݡ�
LONG
        );
        set("exits", ([
                  "north" : __DIR__"tianjin",
                  "south" : __DIR__"road2",
                    "west" : __DIR__"jiujv",
                     "east" : __DIR__"dujv",
        ]));
        set("item_desc", ([
          "bian" : "���������jump��\n",
        ]));
        set("objects", ([
        __DIR__"npc/ouyang" : 1,
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
    if( !arg || arg!="bian") return notify_fail("��Ҫ��ʲô��\n");
            message("vision", me->name() + "˳�ű�������ȥ��\n",
                    environment(me), ({me}) );
        me->move(__DIR__"mishi");
            message_vision("$N��������������������\n", me);
        return 1;
}
