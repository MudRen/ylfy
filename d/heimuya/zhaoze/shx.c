// Room: shx.c
inherit ROOM;
int do_press(string arg);
void relay_circs(object me);
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
�����ˮʮ�ֻ��ǣ���������ô��ģ�Ҳʲô����������
LONG
);
        set("exits", ([ 
        "up" : __DIR__"room9",
]));
        setup();
}
void init()
{
    object me;
    me = this_player();
        set("long", @LONG
�����ˮʮ�ֻ��ǣ���������ô��ģ�Ҳʲô����������
LONG
);
     delete("item_desc"); 

    if (userp(me)){
        call_out("relay_circs",5,me);
        }
}
void relay_circs(object me)
{
     if (environment(me)!=this_object()) return;
     if ( !present("ming zhu",me) ) return;  
        write(
"  �㻳���ҹ�����Ȼ����һ����⣬�㷢����ˮ����Լ��ʮ�ɷ�Բ��
������һʯ�壬�Ͽ���һЩ���֣�������԰���(press)��\n"
             );
        set("long", @LONG
ƾ��ҹ����ĺ��⣬����Կ�����ˮ����Լ��ʮ�ɷ�Բ��������һʯ�壬
�Ͽ���һЩ���֣�������԰���(press)��
LONG
        );
        add_action("do_press", "press");
}
int do_press(string arg)
{
    int p;
    if( !arg || arg == "" || (sscanf( arg , "%d", p)!=1) )
    {
        write("��Ϲ����\n");
        return 1;
    }
    if( p == this_player()->query_temp("passwd") )
    {
        message_vision("ֻ����һ��¡¡��������Զ������\n", this_player());
        message_vision("ʯ�建�����˿�����¶��һ������\n", this_player());
        set("exits/enter", __DIR__"mishi");
        remove_call_out("close");
        call_out("close", 5, this_object());
        return 1;
    }
    else
    {
        write("�����룺���챣����������ţ�\n");
        if ( random(10) >5 )
        {
            message_vision("$Nһ���Ұ���ʲô��ӦҲû�С�\n", this_player());
            return 1;
        }
        else
        {
            message_vision("$Nһ���Ұ���ͻȻʯ��ķ�϶�����һ֧��������\n", this_player());
            this_player()->set_temp("die_for","��������");
            this_player()->receive_damage("qi", 1000);
            this_player()->receive_wound("qi", 1000);
            this_player()->unconcious();
            return 1;
        }
    }
}
void close(object room)
{
        message("vision","��¡¡���������֮��ʯ���ֺ����ˡ�\n", room);
        room->delete("exits/enter");
}

