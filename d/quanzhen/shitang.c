// shitang.c

inherit ROOM;

void create()
{
        set("short", "ʳ��");
        set("long", @LONG
�������ȫ������ò͵ĵط����ط��������������ǧ��ͬʱ���͡���
������һ���Ű����˳����Ĳ����ĳ��ʣ���λС��ͯ������æµ�Ų�����ի��
���ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ����Ҳ����(order)һ�ݡ�
LONG
        );
        set("exits",([
                "east" : __DIR__"houyuan",
//                "north" : __DIR__"chufang",
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
	   if( present("bowl",this_player()) || present("rice",this_player()))
	{
		return notify_fail("��ͯ˵�����������Ѿ����ˣ���Ҫ����ô�࣬�Ե���ô��\n");
	}
       if (arg)  return notify_fail("Sorry, ������������û�а���\n");
       message_vision("��ͯ�е������Ե�Ƭ�̣��������Ͼ�������\n"
                      "һ�Ṧ�򣬵�ͯ��һ���׷���һ��ˮ���˸�$N��\n",me);
        food=new(__DIR__"obj/rice");
        water=new(__DIR__"obj/bowl");
        food->move(me);water->move(me);
       return 1; 
}
int valid_leave(object me,string dir)
{
        me=this_player();
        if(dir=="east" && (present("bowl",this_player()) || present("rice",this_player()))) 
             return notify_fail("��ͯ˵�����Բ����ƽ����˷Ը����ܴ�ʳ���뿪���\n");
        return ::valid_leave(me,dir);
}


