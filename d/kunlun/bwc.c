// Room: /d/kunlun/bwc.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
string look_men();
void create()
{
        set("short", "练武场");
        set("long", @LONG
你正站在一间宽阔的大房间里, 这里是昆仑派弟子打坐练功的地方, 空气
中弥漫著一股股汗臭味。四周的墙壁上画著一幅幅经脉穴道图。靠近墙壁的地
上则摆著一个个练功用的木人。西边有一扇门(men)，好象是虚掩着。
LONG
        );
    set("objects", ([ 
        CLASS_D("kunlun")+"/xihuazi"  : 1,
        CLASS_D("kunlun")+"/weisiniang"  : 1,
    ]));
        set("exits", ([ 
  "north" : __DIR__"dt",
  "south" : __DIR__"klpsm",
  "east" : __DIR__"pqf",
  "southwest" : __DIR__"wgws",
]));

    set("item_desc",([
        "men"        :    (: look_men :),
]));

        setup();
}
void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
    add_action("do_open", "open");
}
int do_open(string arg)
{
    if (query("exits/west"))
        return notify_fail("门已经是开着了。\n");
    if (!arg || (arg != "door" && arg != "men"))
        return 0;
    this_player()->add_temp("open_men",1);
    if (this_player()->query_temp("open_men")>5){
        this_player()->delete_temp("open_men");
        return notify_fail("这门只能先推(push)开才能进去!猪!!!!\n");
    }
    else    return notify_fail("你试着扭了一下竹门,不过发现方法似乎不对!\n");
}
void close_men()
{
    object room;
    if(!( room = find_object(__DIR__"xis")) )
        room = load_object(__DIR__"xis");
    if(objectp(room))
    {
        delete("exits/west");
        message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
        room->delete("exits/east");
        message("vision", "门吱吱呀呀地自己合上了。\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}
int do_knock(string arg)
{
    object room;
    if (query("exits/west"))
        return notify_fail("大门已经是开着了。\n");
    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要敲什么？\n");
    if(!( room = find_object(__DIR__"xis")) )
        room = load_object(__DIR__"xis");
        
    if(objectp(room))
    {
    if ((int)room->query_temp("sleeping_person") > 0)
    {
        message_vision(
        "$N刚轻轻地敲了一下门，就听见里面传出一阵雷鸣般的鼾声，\n"
    "显然里面的人睡得跟死猪似的，怎么敲都没用了\n",
        this_player());
    } else if ((int)room->query_temp("person_inside") > 0)
    {
        switch( random(2) )
        {
        case 0:
            message_vision(
            "$N轻轻地敲了敲门，只听见里面有人很不耐烦地吼到：\n"
        "刚躺下就来敲门！我睡着了，听不见！！！\n",
            this_player());
            
            break;
        case 1: 
            message_vision(
            "$N轻轻地敲了敲门，只听见里面有些响动，\n"
        "好象有人在踱来踱去，拿不定主意是否开门。\n",
            this_player());
            
            break;
    }           
                
    } else
    {
    room->delete_temp("sleeping_person");
        message_vision("$N轻轻地敲了敲门：咚、咚、咚．．．咚、咚、咚．．．\n",
            this_player());
    }
    }
    if(objectp(room))
        message("vision",
        "外面传来一阵敲门声，你从门缝往外一瞧，是"+this_player()->query("name")+"一脸焦急地站在门外，\n"
        "看样子也想进来休息。\n", room);
        
    return 1;
}
int do_push(string arg)
{
    object room;
    if (query("exits/west"))
        return notify_fail("门已经是开着了。\n");
    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要推什么？\n");
    if(!(room = find_object(__DIR__"xis")))
        room = load_object(__DIR__"xis");
        
    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
        room->delete_temp("person_inside");
        set("exits/west", __DIR__"xis");
        message_vision("$N轻轻地把门推开。\n", this_player());
        room->set("exits/east", __FILE__);
        message("vision", "有人从外面把门推开了。\n", room);
        remove_call_out("close_men");
        call_out("close_men", 10);
    } else 
    {
        message_vision("$N想把门推开，却发觉门被人从里面闩上了。\n",
        this_player());
    }
    }
    return 1;
}
string look_men()
{
    object room;
    if (query("exits/east"))
    return ("门上挂了个牌子：南柯梦处。\n");
    if(!( room = find_object(__DIR__"xis")) )
        room = load_object(__DIR__"xis");
    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
    return ("门上挂了个牌子：请毋打扰\n");
    } 
    
    return ("门上挂了个牌子：休息室\n");
}
int valid_leave(object me, string dir)
{
        object room;
        
    if(!( room = find_object(__DIR__"xis")) )
            room = load_object(__DIR__"xis");
    if(objectp(room) && dir == "west")
    {
        if (room->query_temp("person_inside"))
            return notify_fail("没看到里面已经有人了吗？\n");
        room->add_temp("person_inside", 1);
        // will open the door if ppl inside stay too long 
        remove_call_out("force_open");
        call_out("force_open", 100, room);
    }       
    return ::valid_leave(me, dir);
}
int force_open(object room)
{
    object *env;
    int i;
    if ( !objectp(room) ) return 0;
    if((int)room->query_temp("person_inside")<=0) return 0;
    room->delete_temp("person_inside");
    set("exits/west", __DIR__"xis");
    room->set("exits/east", __FILE__);
    message("vision", "外面突然响起粗重的脚步声，由远而近，到门前停了下来．．．\n"
        "西华子啪地把门打开，伸个头进来，一脸狐疑：呆大半天了还不出去，搞什么鬼？\n", room);
    env=all_inventory(room);
    if (sizeof(env))
        for(i=0;i<sizeof(env);i++)
            if (userp(env[i])){
                env[i]->move(this_object());
                message_vision("西华子一把抓住$N的衣领，提了出来!\n", env[i]);
                message("vision", "西华子一把抓住"+env[i]->name()+"的衣领，提了出去!\n",room);
                }
    remove_call_out("close_men");
    call_out("close_men", 10);
    return 1;
}
