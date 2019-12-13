//Room: /d/honghua/zongduo.c
//Date: 1998.10
inherit ROOM;
#include <ansi.h>
int flag=0;
int get=1;
void create()
{
	set("short", "�컨���ܶ�");
	set("long", @LONG
�����Ǻ컨����ܶ棬������վ���˺컨��ĵ��ӡ����ǵ���
�ϱ������£�ÿ���˵����ֶ��������Լ��ı��У��м�����ӿ���
�������ܶ����¼��岻�ڣ����Ե���¯(xiang lu)ɢ�������Ե���
�̣����ǳ��г�һ����ʥ�ķ�Χ.
LONG
	);

	set("valid_startroom", 1);	

	set("exits", ([
		"southdown" : __DIR__"zoulang2",
		"west" : __DIR__"goldroom",
	]));

	set("objects", ([
		"/d/honghua/npc/wuchen" : 1,
		"/d/honghua/npc/dizi" : 2,
	]));
	
	setup();

	"/clone/board/honghua_b"->foo();

	set("item_desc", ([
	    "xiang lu" : "һ����ɫ�������ͭ��¯��һ�ɵ��������������治ʱ��ð����.\n",
	    
	]));
}
void init()
{
 add_action("do_tui", "tui");
 add_action("do_wedge", "wedge");
}
int do_tui(string arg)
{

	object me=this_player();

	if(!arg || arg!="xiang lu")
		return notify_fail("��Ҫ��ʲô��\n");
        if( me->query("combat_exp") < 200000 )
                return notify_fail("��Ĺ���̫��޷��ƶ���¯����ȥ������ɡ�\n");
	else if ( flag==0 )
		{
			flag=1;
			message_vision("ֻ�������ꡱһ�죬��¯���ֳ�һ��С��\n",me);
        		set("item_desc", ([
	               "xiang lu" : "һ����ɫ�������ͭ��¯��һ�ɵ��������������治ʱ��ð����,������һ��С��,������Բ���ʲô������\n",
	    		]));
		}
	     else message_vision("��¯�Ѿ��Ʋ�����!\n",me); 		

	return 1;
}

int do_wedge(string arg)
{
 	object me=this_player();
        if ( !arg || arg!="honghua_ling" )
		return notify_fail("��Ҫ��ʲô����������¯��\n");

        if ( me->is_busy() )
                return notify_fail("����æ���ء�\n");
	else if ( get==1 && flag==1 && present("honghua_ling",me) && !(present("honghua_ling",me))->query("zizhi") )
		{
                         message_vision( "$N���ŰѺ컨���������¯..\n",me);
			message_vision( HIR"ֻ����¯�����������죬�����Ǵ�����ʲô����...\n"NOR,me);
                        me->start_busy(2);
                        call_out("hit", 0 , me);
		}
	     else 
		{
			if ( flag==0 ) return notify_fail("��¯��������û�У�ʲô����Ҳ�岻��ȥ��\n");
			if ( !present("honghua_ling",me) || (present("honghua_ling",me))->query("zizhi") ) return notify_fail("�㲢û�д��컨�\n");
			if ( get==0 ) return notify_fail("ѩ�����Ѿ�����������!\n");
		}		
	return 1;
}

void hit()
{
	object me;
	object ob;
	me = this_player();
                ob = present ("honghua_ling", me);
                destruct (ob);

	message_vision( HIR"ͻȻֻ����ಡ���һ��������¯�������֧������\n",me);
        if ( random( (int)me->query("kar") ) < 20 )     {
		message_vision( HIR"$N��ǰһ������������������������Ķ���$N���ؿ�\n"NOR,me);
		me->unconcious();
	}
	else {
		message_vision( HIG"$N��æһ���������յıܿ���\n"NOR,me );
		message_vision( HIG"��¯����ת����¶��һ��"NOR,me);
		message_vision( HIW"ѩ����"NOR,me);
                 message_vision( HIG",$N��æ��������\n"NOR,me);
		ob = new ( "/d/honghua/obj/xuelian" );
                        me->start_busy(2);
 		ob->move( this_player() );
		get=0;
	     }	
        return;
} 
         	
 
