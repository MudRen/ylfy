// zjb /2002/3/15/
inherit ROOM;
int do_jump(string arg);  
void on_sun();
void create()
{
        set("short", "�������");
        set("long", @LONG 
��һ����һ��ǳ�����ڻ���֮�У������ж��ѹ�
��Ҫ����������ĵ����ƺ����й������ڲ��ϵ�����
����������������߿�Щ�ɡ�
LONG
        );
        set("outdoors", "yihua");
        set("exits", ([
                "enter" : "d/xuantian/room2",
                "east" :  __FILE__,
                "west" :  __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
        ]));             
        setup();

}
void init()
{
        add_action("do_use", "use");
        add_action("do_tiao", "tiao");
    this_player()->receive_damage("qi", 15);
    this_player()->receive_wound("qi",  15);
    message_vision(YEL"$Nһ����һ��ǳ����ǰ���ţ�ֻ���ú���Խ��Խ�ѡ�\n"NOR, this_player());
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ�����·���и�С�ӣ���Ҫ����ȥ��\n"
             );
             this_player()->set_temp("marks/��1", 1);
             return 1;
       }
}

int do_tiao(string arg)
{
        object me;
        me = this_player();
        if( arg != "��" )
                return notify_fail("�������������ݺݵ�ˤ���˵��ϡ�\n");
        if (me->query_temp("marks/��1") ) {
            message("vision", me->name() + "��ʧ��һ��ڰ�֮�С�\n",
                    environment(me), ({me}) );
            me->move("d/xuantian/dongxue");
        me->unconcious();
            message("vision", me->name() + "�ӿ������˳�����\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��1");

            return 1;
        }
        else {
            write("�������������ݺݵ�ˤ���˵��ϡ�\n");
            return 1;
        }
}

