// Room: /d/emei/shandong8.c ɽ��8
// create by host dec,20 1997

inherit ROOM;

void init();

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
������һ�����ɽ������Ŷ����ұڻ���ǰ�У���ǽ����ɢ����������
��ʪ��Ϣ��ʹ�㲻�������Ĵ��˺��䣬������˵���������ܡ������У�������
����ȥ����Լ���Կ���һ�ɹ��ߴ��Ҳප��Ͷ�������
LONG
	);
        set("exits", ([
           "west":  __DIR__"shandong"+(random(6)+5),
           "south": __DIR__"shandong"+(random(6)+5),
           "north": __DIR__"shandong"+(random(6)+5), 
	]));
	setup();
}
void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

    object me = this_player();
    object room;
    if ( !arg || (arg != "out") )
        return notify_fail("������ʲô��������\n");
    if (me->is_busy())
	return notify_fail("��������æ���ء�\n");
    room= load_object(__DIR__"yunvfeng");
    if(objectp(room))
        {

                message_vision("$N��ɽ�������˳�ȥ��\n", me);
                message("vision", me->query("name")+"��ɽ�������˳�����\n", room);
        }
    
    if( (int)me->query_kar() < 25 )
      {
         me->move(__DIR__"shanpo");
         write("��ֻ���ý���һ����������ƮƮ�������˵��ϡ�\n");
	 return 1;
       }
         me->move(__DIR__"yunvfeng");
         write("��ֻ���ý���һ����������ƮƮ�������˲ݵ��ϡ�\n");
     return 1;
}