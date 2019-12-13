// Room: /d/shaolin/hanshui1.c
// Date: YZC 96/01/19
inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();
void create()
{
    set("short", "��ˮ�ϰ�");
    set("long", @LONG
��ǰ��һ�����η����Ĵ�(river)���������������۾�����
�����ɴ���������������һ�����������̯����Ҿͽ������ڰ�
�ߣ���������֧һ��ľ�壬���ϰ����˻�������ĺ������㡣��
ȥ��Զ�����������Ϻӿڣ����ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG
    );
    set("exits", ([
        "south" : __DIR__"yidao2",
        "east"  : __DIR__"matou1",
    ]));
    set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
    ]));
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
/*if((string)environment(this_player())!="�ɴ�")
{
 notify_fail("���ǿ���,;�оͱ��ɵ���!\n");
 return ;
}
*/
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", __DIR__"hanshui2");
    room->set("yell",1);
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    if( !room = find_object(__DIR__"hanshui2") )
    room = load_object(__DIR__"hanshui2.c");
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
    if( room = find_object(__DIR__"hanshui2") )
    room->on_board();
}
int do_yell(string arg)
{
    if( !arg || arg=="" ) return 0;
    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("neili") < 300 )
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
