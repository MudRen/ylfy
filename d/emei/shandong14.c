// Room: /d/emei/shandong14.c ɽ��14
// create by host dec,20 1997

inherit ROOM;
void init();

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
��Ӻڰ������˳������پ�����Ұʮ�ֵĿ�����������һ������ɽ
�������߸�����һֻ���(fire)���յ���ͬ����һ�㣬��ǰ����һ���޴�
��ʯ�Ž����ر��ţ���ס��ȥ·��
LONG
	);
        set("exits", ([
           "west":  __DIR__"shandong13",
	]));
       set("item_desc", ([
           "fire" : "һֻȼ�������Ļ�ѡ������������(pull)��\n",
          ]));
	setup();
}
void init()
{
    add_action("do_pull", "pull");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"shanpo")) )
        room = load_object(__DIR__"shanpo");

    if(objectp(room))
    {
        delete("exits/east");
        message("vision", "ֻ�����һ�����죬ʯ���ִ��º���������\n",
            this_object());
        room->delete("exits/west");
        if (objectp(room))
           message("vision", "ֻ�����һ�����죬ʯ���ִ��º���������\n", room);
     }
}

int do_pull(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("ʯ���Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "fire"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"shanpo")) )
        room = load_object(__DIR__"shanpo");
    
    if(objectp(room))
    {
        set("exits/east",__DIR__"shanpo");
        message_vision("$N�þ���������һ�»�ѣ�"
            "ֻ��֨֨�������죬ʯ�������Ĵ��ˡ�\n",this_player());
        room->set("exits/west", __FILE__);
        message("vision", "��Զ�������˼������죬��ǰ��ͻȻ������һ�����ڡ�\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}
