// shantang.c
// shilling 97.2
inherit ROOM;
void create()
{
    set("short", "�Ƽ�");
    set("long", @LONG
�����������е�һ��СС�ľƼң��ط���Ȼ���󣬵���Ҳ�в�����ң��
�ĵ��ӹ������������ҵ���ζ����Դ�ˣ����ſɿڵķ��ˣ����̲�סҲ
��� (order)һ���ˡ�
LONG
    );
    set("exits",([
        "north" : __DIR__"xiaodao2",
]));
    set("no_clean_up", 0);
    setup();
}
void init()
{
        add_action("do_order","order");
}
int do_order(string arg)
{
       object me;
    object food;
    object water;
       me=this_player();
       if (arg)  return notify_fail("Sorry, ������������û�а���\n");
	   if( present("bowl",this_player()) || present("rice",this_player()))
	{
		return notify_fail("С��˵�����������Ѿ����ˣ���Ҫ����ô�࣬�Ե���ô��\n");
	}
       message_vision("С������æ��һ���׷���һ��ˮ���˸�$N\n",me);
    food=new(__DIR__"obj/rice");
    water=new(__DIR__"obj/bowl");
    food->move(me);
	water->move(me);
       return 1; 
}
int valid_leave(object me,string dir)
{
    me=this_player();
        if(dir=="north" && (present("bowl",this_player()) || present("rice",this_player()))) 
             return notify_fail("С��˵����Sorry ����������û�д������\n");
        return ::valid_leave(me,dir);
}
