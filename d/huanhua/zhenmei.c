//zhenmei.c

inherit ROOM;
int flag=0;
#include <ansi.h>
void init();

void create()
{
        set("short", "��ü��");
        set("long", @LONG
��ü��������¥����,����,�����ͳﻮ��������֮��.�������,�ı�
���ֻ�,�������Ÿ������(shelf),��������,�豸���ª,��ȴ��һ
�ִ�����.��������,���ż����ľ����,��ƽʱ�����õ�.
LONG
        );
        set("valid_startroom",1);

        set("no_beg",1);
        set("no_steal",1);
        set("exits", ([
                "east" :  __DIR__"changlang3",
                "west" :  __DIR__"jianshi",
                ]));
        set("objects", ([
                  __DIR__"npc/xiaoxilou" :1,
                  __DIR__"npc/xiaoren" :1,
                       ]));

        set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        	
	set("item_desc", ([
	    "shelf" : "һ����ª�����,������Դ�(dakai).\n",
	    
	]));
}
void init()
{
 add_action("do_dakai", "dakai");
}
int do_dakai(string arg)
{

	object me=this_player();
	object ob;
	if(!arg || arg!="shelf")
		return notify_fail("��Ҫ��ʲô��\n");
	else if ( flag==0 )
		{
			flag=1;
			message_vision("ֻ����֨ѽ��һ�죬��ܴ���.\n",me);
			message_vision(HIC"һ������˳���.\n"NOR,me);
		ob = new (__DIR__"obj/sishuwujing");
 		ob->move( __DIR__"zhenmei");

		}
	     else message_vision("����Ѿ����˴���!\n",me); 		

	return 1;
}


