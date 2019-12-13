// Room: /d/shaolin/hanshui2.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "��ˮ����");
    set("long", @LONG
��ˮ����Ҳ���൱���֣��Ա����ɿ�������һ����ֱ�Ĺٵ�
ֱͨ�������˵���紾�ӣ�·�Լ��������������������Ҷ���һ
����ġ��ơ���ӭ��Ʈ�εΪ׳�ۡ�Ҳ�в���С����·����
����ѱ棬ȴҲ����ʢ����ȴ��
LONG
    );
    set("exits", ([
        "north" : __DIR__"nanyang",
// "west" : "/d/quanzhen/guangdao1",
        "east"  : __DIR__"matou2",
    ]));
    set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
    ]));
    set("outdoors", "shaolin");
    set("outdoors", "shaolin");
    setup();
}
void init()
{
    add_action("do_yell", "yell");
}
void check_trigger()
{
    object room;
    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan.c");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->do_check() && !room->query("yell") ) {
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
        room->set("yell",1);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿����¡�\n", this_object() );
                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ý��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",
            this_object() );
}
void on_board()
{
    object room;
    if( !query("exits/enter") ) return;
    message("vision", "������̤�Ű��������������һ�㣬��������ʻȥ��\n",
        this_object() );
    delete("exits/enter");
    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
    room->delete("yell");
        message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬��������ʻȥ��\n", room );
    if (!(int)room->do_check()){
        remove_call_out("arrive");
        call_out("arrive", 20);
    }
    }
}
void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", __DIR__"hanshui1");
    room->set("yell",1);
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    if( !room = find_object(__DIR__"hanshui1") )
    room = load_object(__DIR__"hanshui1.c");
    room->set("exits/enter", __DIR__"duchuan");
    message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
       "����ϵ̰����Ա�˿����¡�\n", room );
    remove_call_out("close_passage");
    call_out("close_passage", 10);
   }
}
void close_passage()
{
    object room;
    if( room = find_object(__DIR__"hanshui1") )
    room->on_board();
}
int do_yell(string arg)
{
    if( !arg || arg=="" ) return 0;
    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 600 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}
