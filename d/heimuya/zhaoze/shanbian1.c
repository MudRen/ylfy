// Room: /d/heimuya/zhaoze/shanbian1.c
inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ֻ��ɽ��һ���ֱ۴�ϸ�ĳ��٣��ط���ϡ���ͷ��������ɽ����ϰ�
����������֮�У���֪�嶥���ж�ߡ�
LONG
);
        set("exits", ([ 
  "south" : __DIR__"shanbian",
]));
        set("outdoors", "shanbian1");

        set("item_desc", ([
        "����" : "�����˳��������ɽȥ��\n",
        ]));
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="����") return notify_fail("��Ҫ��ʲô��\n");
            message("vision", me->name() + "˳�ų���������ȥ��\n",
                    environment(me), ({me}) );
        me->move(__DIR__"fongdian");
            message_vision("$N��������������������\n", me);
        return 1;
}

