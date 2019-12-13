inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
���ܵ���������ˡ����߼�����ʲôҲ�����塣
LONG
        );

        set("exits", ([
                "up" : __DIR__"woshi",
                "north" : __FILE__,
                "south" : __FILE__,
                "west" : __FILE__,
                "east" : __FILE__,
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zou", "zou");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ������ܵ����ƺ���һ��·����(zou)��ȥ��\n"
             );
             this_player()->set_temp("marks/��1", 1);
             return 1;
       }
}

int do_zou(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/��1") ) {
            message("vision", me->name() + "��ʧ��һ��ڰ�֮�С�\n",
                    environment(me), ({me}) );
            me->move(__DIR__"midao_out");
            message("vision", me->name() + "�����������˳�����\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��1");

            return 1;
        }
        else {
            write("�������Ķ���?!\n");
            return 1;
        }
}

