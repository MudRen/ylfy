// Room: /d/emei/shandong12.c ɽ��12
// create by host dec,20 1997

inherit ROOM;
void init();

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У���ʱ�е�ͷ��һ���ʹ��ֻ���ö���ʮ
����խ�͵Ͱ������Ŷ����ұڻ���ǰ�У���ǽ����ɢ���������䳱ʪ��
Ϣ��ʹ�㲻�������Ĵ��˺��䣬������˵���������ܡ�
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong13",
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
    if ( !arg || (arg != "out") )
        return notify_fail("������ʲô��������\n");
    if (me->is_busy())
	return notify_fail("��������æ���ء�\n");
    message_vision("$N��ɽ�������˳�������ƮƮ�������˲ݵ��ϡ�\n", me);
    me->move(__DIR__"yunvfeng");
     return 1;
}
