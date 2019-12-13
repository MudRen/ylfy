// Room: /city/kedian3.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ����
���ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ�
��������ŵ����˹�ȥ��
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
			tell_object(me,	"��С�������������: �����ﵱ��������! �ȵ�һ¥��Ǯ������˯!\n");
			message("vision",me->name()+"����С�����˳�ȥ��\n",this_object(),({me}) );
			me->move(room);
			message_vision("$P����С�����˳�����\n",me);
			return 1;
		}
	}
	return 0;
}
