// Room: room8.c
inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "Χǽ");
        set("long", @LONG
ֻ����ǰ��һ�¸߸ߵ�Χǽ(wall)����Χ��ûһ���Ż���Χǽ��
������é�ݣ�һԲһ����
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"room7",
  "west" : __DIR__"room11",
]));

    set("item_desc", ([
        "wall" : "ǽ�ܸߣ����ܷ�����ȥ(climb)��\n",
    ]) );

        setup();
}
void init()
{
    object me;
    me = this_player();
    add_action("do_climb", "climb");
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
        "ֻ��$N�����ǽ��һ��,����ȻƮ��Ժ��.\n", this_player());
        this_player()->move(__DIR__"room9");
    }
    else if (n>=800) {
        message_vision(
        "ֻ��$N˫����ǽ��һ��,��ǿ����Χǽ,����Ժ��.\n", this_player());
        this_player()->move(__DIR__"room9");
    }
    else {
        message_vision(
        "$N�߸�Ծ��,�ɻ���һ�����,�������Ṧ�����á�\n", this_player());
     }
    return 1;
}
