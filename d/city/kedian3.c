// Room: /city/kedian3.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，
不少客人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，
你蹑手蹑脚地走了过去。
LONG
	);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	setup();
}
void init()
{
	add_action("do_sleep","sleep");
}

int valid_leave(object me, string dir)
{
	return ::valid_leave(me, dir);
}
int do_sleep()
{
	object me,room;
	me=this_player();
	if (room=find_object(__DIR__"kedian"))
	room=load_object(__DIR__"kedian");
	if (room){
		if (present("xiao er",room)){
			if (me->query_temp("rent_paid")){
				me->add_temp("rent_paid",-1);
				return 0;
			}
			tell_object(me,	"店小二从门外对你大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!\n");
			message("vision",me->name()+"被店小二揪了出去！\n",this_object(),({me}) );
			me->move(room);
			message_vision("$P被店小二揪了出来！\n",me);
			return 1;
		}
	}
	return 0;
}
