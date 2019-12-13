// Room: /d/emei/shierpan3.c ������ ʮ����3

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ʮ����");
	set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡������·���и������أ���������
����л���(clap)���ɴ����Ͽɴﻪ�϶��������������֡�
LONG
	);

	set("exits", ([
                "westdown": __DIR__"shierpan2",
                "eastup":  __DIR__"shierpan4",
	]));

	set("outdoors", "shaolin");
	setup();	
}
void init()
{
       object me = this_player();
       object room;
       room= load_object(__DIR__"xuanya");
       if(random((int)me->query_kar()) <= 10) 
	{
		message_vision(HIR"һ���ȷ�Ϯ����������ͻȻ������һ����������$N����������\n"NOR, me);
		me->move(room);
                return ;
       }
        add_action("do_clap", "clap");
}

int do_clap()
{

        mapping myfam;
	object me = this_player();
	int kar= this_player()->query_kar();

   if (me->is_busy())
	return notify_fail("��������æ���ء�\n");

    message_vision("$N����������������˼��¡�\n", me);

    if ( me->query("jing") < 30)
       return notify_fail("���Ѿ��۵�����������\n");

    if ((!(myfam = me->query("family")) || myfam["family_name"] != "������") )
        write("����һƬ�ž���ֻ���ĳ��м���������\n");

    me->add("jing",-10+random(5)); 

    if (( random(kar) <= 5 ) && (random(3)<2) )  
    {
         write("����һƬ�ž���ֻ���ĳ��м���������\n");
     } else if (random(kar) <= 18 )
    {

        write("�Ӱ������д����������֮����������������ͬʱ��͡�\n");  
        me->improve_skill("strike", random(me->query_int()));
        write(HIR"���ƺ����Ʒ�����һЩ�µ�������Ļ����Ʒ������ˡ�\n"NOR);
    
    } else if (me->query("qi") < me->query("max_qi"))
    {
    	write("��紵�����еĺ�Ҷ��Ȼ���죬ʹ��پ�������ˬ��\n"); 
        me->add("qi",30);
    }
     return 1;
}
