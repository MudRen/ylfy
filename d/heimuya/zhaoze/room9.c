// Room: room9.c
inherit ROOM;
int do_climb(string arg);
int do_tiao(string arg);
void create()
{
        set("short", "é��");
        set("long", @LONG
Խǽ���룬ԭ��ǽ���Ǹ�Ժ�ӣ���Ϊ���룬��һ����ʵ������һ
��ȴ��ˮ�������Ժ�ӣ��������ã���ǰ�Ǹ��¶����������顣
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"room10",
]));

    set("item_desc", ([
        "wall" : "ǽ�ܸߣ����ܷ�����ȥ(climb)��\n",
          "ǽ" : "ǽ�ܸߣ����ܷ�����ȥ(climb)��\n",
        "ˮ��" : "һ��ˮ���������������ȥ��\n",
    ]) );

        setup();
}
void init()
{
    object me;
    me = this_player();
    add_action("do_climb", "climb");
    add_action("do_tiao", "tiao");
}
int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge",1);
    if( !arg || arg!="wall" ) {
        write("��Ҫ����������\n");
        return 1;
    }
    message_vision(
    "$N��ǽǰվ��,����һ��������ȻԾ��.\n", this_player());
        
    if (n>=1000) {
        message_vision(
        "ֻ��$N�����ǽ��һ��,����ȻƮ��Χǽ�⡣\n", this_player());
        this_player()->move(__DIR__"room8");
    }
    else if (n>=800) {
        message_vision(
        "ֻ��$N˫����ǽ��һ��,��ǿ����Χǽ,����Χǽ�⡣\n", this_player());
        this_player()->move(__DIR__"room8");
    }
    else {
        message_vision(
        "$N�߸�Ծ��,�ɻ���һ�����,�������Ṧ�����á�\n", this_player());
     }
    return 1;
}

int do_tiao(string arg)
{
        object me,room;
        me = this_player();
        if( !arg || arg!="ˮ") return notify_fail("��Ҫ��������\n");          
        message_vision("$N��ԥ��һ�£��������������߸�Ծ���ڿ��л���������Ļ��ߣ�\n"
                       "����ˮ�С�\n",me);
        if (!room=find_object(__DIR__"shx"))
             room=load_object(__DIR__"shx");
        me->move(room);
        return 1;
}
