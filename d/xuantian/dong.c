//xuantian/dong
//by pipip
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
������һ����Ȼ��ʯ������������������ʯ(shi)��
�㿴������Ȼ���澰�����ɾ��ô���Ȼ������֮��
��ֱ�������ڣ�����������
LONG
    );
    set("exits", ([
        "south" : "d/xuantian/room6",
        "east" : "d/xuantian/room2",
        "west" : "d/xuantian/room4",
    ]));
    set("item_desc", ([
        "shi": "�ܹ⻬������ʯ��������һ�ƣ���Ȼ�����ƶ���\n"
    ]) );
    setup();
}
void init()
{
    add_action("do_push", "push");
}
void check_trigger()
{
    object room;
    if( (int)query("left_trigger")==16
        &&  (int)query("right_trigger")==24
    &&  !query("exits/north") ) {
        message("vision", "���ߵ�ʯ�ں�Ȼ�����������죬���������Ա��ƶ��ţ�������һ��������Ķ�Ѩ��\n",
            this_object() );
        set("exits/north", "d/xuantian/room10");
        if( room = find_object("d/xuantian/room10") ) {
            room->set("exits/south", "d/xuantian/dong");
            message("vision", "�ϱ߱ߵ�ʯ�ں�Ȼ�����������죬���������Ա��ƶ��ţ�������һ��������Ķ�Ѩ��\n",
                room );
        }
        delete("left_trigger");
        delete("right_trigger");
        call_out("close_passage", 30);
    }
}
void close_passage()
{
    object room;
    if( !query("exits/north") ) return;
    message("vision", "����һ����ʯ���ֹ����ˣ�һ����ڵĺۼ����������ˡ�\n",
        this_object() );
    if( room = find_object(__DIR__"room10") ) {
        room->delete("exits/south");
        message("vision", "����һ����ʯ���ֹ����ˣ�һ����ڵĺۼ����������ˡ�\n"
                        HIR "���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" NOR ,
            room );
    }
    delete("exits/north");
}
int do_push(string arg)
{
    string dir;
    if( !arg || arg=="" ) return 0;
    if( arg=="shi" ) {
        write("�������ƶ�����ʯ�����������������ƶ�....\n");
        return 1;
    }
    if( sscanf(arg, "shi %s", dir)==1 ) {
        if( dir=="right" ) {
            message_vision("$N������ʯ������...����Ȼ������������ʯ���ƻ�ԭλ��\n", this_player());
            add("right_trigger", 1);
            check_trigger();
            return 1;
        } else if( dir=="left" ) {
            message_vision("$N������ʯ������...����Ȼ������������ʯ���ƻ�ԭλ��\n", this_player());
            add("left_trigger", 1);
            check_trigger();
            return 1;
        } else {
            write("��Ҫ������ʯ�����Ǹ�����\n");
            return 1;
        }
    }
}
void reset()
{
    ::reset();
    delete("left_trigger");
    delete("right_trigger");
}

