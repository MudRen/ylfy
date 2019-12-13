//ROOM damen.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�컨���ܶ����");
        set("long",@LONG
��վ�����Ⱥ������ǰ�����϶�������ڴ�С��ͭ����
�ſڵ�̨���ϲ���վ������������Բ�Ĵ󺺣����￴ȥ����
����һ���������۵�����ͨ�������
LONG
	);
        
	set("outdoors", "honghua");
        
	set("exits", ([
               "up" : __DIR__"zoulang" ,
		"southeast" : __DIR__"caoyuan3",
        ]));
	
	set("objects", ([
		"/d/honghua/npc/dizi" : 2,
            "/d/honghua/npc/wen-tailai" : 1,
	]));	

	setup();
}

void init()
{
	object me;
	me=this_player();
	if ( interactive( this_player())
           && ((string)me->query("family/family_name") != "�컨��")
           && (!present("honghua_ling",me))
	   )
		message_vision(HIG"�������������һ��,���������صĺ���һ����\n"NOR,me);
        else if ( present("honghua_ling",me) && !(present("honghua_ling",me))->query("zizhi")) 
		message_vision(HIG"�����󺺹����������˸���,˵���������ã�\n"NOR,me);
}
int valid_leave(object me, string dir)
{
	me=this_player();
	if (  (dir == "up")
           && ((string)me->query("family/family_name") != "�컨��")
	  && objectp(present("wen tailai", environment(me)))
           && (!present("honghua_ling", me))
           )

	return notify_fail
		("��̩����ס��˵���㲻�Ǳ�����֣����ܽ�ȥ��\n");
	return ::valid_leave(me, dir);
}
