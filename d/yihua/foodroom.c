inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
�������ƻ������ò��ң��ط���Ȼ���󣬵�������ȴ�����˺ܶ��ò͵�
Ů���ӡ�Ҳ������һ��Ĺ�����Ҷ������ˣ�ֻ��������Է���һ�£�����
Ů�����Ƕ��ڻ�������š������Ҳ��Ե�ʲô,Ҳ���� (order)һ�ݡ�
LONG
	);
	set("exits",([
		"east" : __DIR__"changlang",
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
	 if( present("niang",this_player()) || present("rice",this_player()))
	{
		return notify_fail("��Ů˵�����������Ѿ����ˣ���Ҫ����ô�࣬�Ե���ô��\n");
	}
       if (arg)  return notify_fail("Sorry, ������������û�а���\n");
       message_vision("��Ů��һ���ʻ����һ���ٻ������˸�$N��\n",me);
	food=new(__DIR__"obj/zhou");
	water=new(__DIR__"obj/niang");
	food->move(me);water->move(me);
       return 1; 
}
int valid_leave(object me,string dir)
{
	me=this_player();
        if(dir=="east" && (present("niang",this_player()) || present("rice",this_player()))) 
             return notify_fail("��Ů˵������λʦ��,�㻹�ǳ������߰ɡ�\n");
        return ::valid_leave(me,dir);
}
