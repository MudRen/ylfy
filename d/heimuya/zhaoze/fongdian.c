// Room: /d/heimuya/zhaoze/fongdian.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ɽ�嶥���ǿ�ƽ�أ����ѳɶ�ʮ��Ķɽ����ź̵���һ����ͷ��
����ߡ�һ�����پͰ����±ߵ�һ���ʯ�ϡ�
LONG
);
        set("exits", ([ 
  "north" : __DIR__"shiliang",
]));
        set("item_desc", ([
        "����" : "�����˳��������ɽȥ��\n",
]));
    set("objects", ([
        __DIR__"npc/nongfu" : 1,
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
        me->move(__DIR__"shanbian1");
            message_vision("$N�ľ���ս������������\n", me);
        return 1;
}
int valid_leave(object me, string dir)
{
        object ob=present("nong fu", environment(me));
        if (ob && living(ob) ){
            if ( ( present("hong juan",me) ) && dir == "north" ) {
                    say("ũ���"+me->name()+"�ȵ�����������\n");
                    return notify_fail("ũ��ȵ�����λ" + RANK_D->query_respect(me) + "��ֹ����\n");
            }
        }
        return ::valid_leave(me, dir);
}

