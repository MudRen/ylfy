
inherit ROOM;
#include <ansi.h>
int flag=0;
void create()
{
	set("short", "���춴");
	set("long", @LONG
���춴�ڴ�ɨ��һ����Ⱦ,�����.���ڸ����а���ȥ�˵ĵط�,
������һ����������������.����ǰ�����ǵƻ�,�����ż����õ�����
���,̳ǰ��һ���û�籰������ľ���(jing juan).
LONG
	);

	set("valid_startroom", 1);	

	set("exits", ([
//                 "east" : __DIR__"houfang",
		"west" : __DIR__"jiashan",
	]));

	set("objects", ([
		  __DIR__"npc/dizi" : 2,
	]));
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",140);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	
	set("item_desc", ([
	    "jing juan" : "һ���û����ϸ�������ľ���,������������Դ�(dakai).\n",
	    
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
	if(!arg || arg!="jing juan")
		return notify_fail("��Ҫ��ʲô��\n");
//	if (me->query_kar() < 28) {
//	message_vision("����˻��,ȴ��������ֻ�Ǹ��պ���.\n");
//       return 1;}
		
	else if ( flag==0 )
		{
			flag=1;
			message_vision("����ϸ�ؽ⿪�˻��.\n",me);
			message_vision(HIY"һ�����ƵĹ�����˳���.\n"NOR,me);
		ob = new ( __DIR__"obj/jian-book" );
 		ob->move( __DIR__"jiantiand");

		}
	     else message_vision("����Ѿ����⿪����!\n",me); 		

	return 1;
}

 
