// Room: /d/shaolin/hanshui2.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "汉水北岸");
    set("long", @LONG
汉水北岸也是相当热闹，自北岸渡口往北，一条笔直的官道
直通南阳。此地民风淳朴，路旁夹柳成阴，酒厮林立，且都有一
面大大的「酒」旗迎风飘扬，蔚为壮观。也有不少小贩沿路叫买，
语多难辨，却也令人盛情难却。
LONG
    );
    set("exits", ([
        "north" : __DIR__"nanyang",
// "west" : "/d/quanzhen/guangdao1",
        "east"  : __DIR__"matou2",
    ]));
    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
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
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "只听得江面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}
void on_board()
{
    object room;
    if( !query("exits/enter") ) return;
    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n",
        this_object() );
    delete("exits/enter");
    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
    room->delete("yell");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向江心驶去。\n", room );
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
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    if( !room = find_object(__DIR__"hanshui1") )
    room = load_object(__DIR__"hanshui1.c");
    room->set("exits/enter", __DIR__"duchuan");
    message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
       "板搭上堤岸，以便乘客上下。\n", room );
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
    if( arg=="boat" ) arg = "船家";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("neili") > 600 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="船家")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}
