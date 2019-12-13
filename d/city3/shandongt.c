//shandongt.c
//by mei
inherit ROOM;
string *names=({
        __DIR__"shandong7",
        __DIR__"shandong5",
        __DIR__"shandong1",
        __DIR__"shandong6",
} );

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��׳���ӣ��߽���ɽ���У����ﰵ�����գ�ͻȻ�䣬��
ֻ����������ǰ�ɹ����㱻������һ���亹��Խ�����߾�Խ��
Խ�ڣ��������ʧ�����ˡ�
LONG
        );

        setup();
}
void reset()
{
        int i,j;
        string temp;
        ::reset();
        for (i=0;i<=3;i++)
        {
                j=random(4);
                temp=names[j];
                names[j]=names[i];
                names[i]=names[j];
                names[i]=temp;
        }
        set("exits", ([
                "north" : names[0],
                "south" : names[1],
                "east" : names[2],
                "west" : names[3],
        ]));
}
void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}
int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ�����ɽ���ұ���һ���ѷ죬�ƺ�������(zuan)��ȥ��\n"
             );
             me->set_temp("marks/��1", 1);
             return 1;
       }
    return 0;
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/��1") ) {
            message("vision", me->name() + "ͻȻһ�Ųȿգ�����ֱ����׹��\n",
                    environment(me), ({me}) );
            me->move(__DIR__"midao");
            me->unconcious();
            message("vision", me->name() + "��ɽ�������������\n",
                    environment(me), ({me}) );
            me->delete_temp("marks/��1");

            return 1;
        }
        else {
            write("�������Ķ���?!\n");
            return 1;
        }
}

