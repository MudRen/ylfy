// xuantian/enter   by:pipip
inherit ROOM;
int do_say(string arg);
void create()
{
        set("short", "����");
        set("long", @LONG
����һ������δ��������������һ����ȥ�����ɵľ��ǻҳ���
��ֵ������е�һ���ֻ�(zihua)��Ȼ�Ǹɾ��쳣�����ĵط�
�γ��������ĶԱȡ�
LONG 
        );
        set("exits", ([
                "north" : "/d/city3/shudao3"
        ]));
        set("item_desc",([
                "zihua" : "�����п������ǣ��������껯���Ρ�\n"
        ]));
        setup();
}
void init()
{
        add_action("do_say", "han");
}
int do_say(string arg)
{
        if( !arg || arg=="" ) return 0;
        if( arg=="�����п�������"
        ||  arg=="�������껯����") 
        {
                write(HIC"��λ���Ѽ�Ȼ�����˴���������������ɡ�\n");
                message("vision", "����ǰ�ĵذ�ͻȻ���ݣ���Ȼ�ǵ����š�\n", this_player());
                set("exits/down", "d/xuantian/room1");
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
        }
}
void close(object room)
{
        message("vision","ֻ���ذ��ֳ����ˣ����Ų����ˡ�\n", room);
        room->delete("exits/down");
}       


