// houfang.c
// by chenww

inherit ROOM;
#include <ansi.h>
int flag=0;
void create()
{
	set("short", "��");
	set("long", @LONG
�����Ǽ��춴�ĺ�,�ռ�ǳ���,����ڷ�����ั�ײ�(guan cai).
��Щ�ײ��ﶼ�ǵ����˵������ӵܺ�佻�����,����Ϊ佻����ɶ���,ʬ��
Ҳ���ͣ�������ҵ������Ĳ෿��.
LONG
	);
/*        set("objects", ([
                 __DIR__"obj/guancai" :1,
        ]));
*/        
        set("outdoors", "huanhua");

	set("exits", ([
		"west" : __DIR__"jiantiand",
	]));
	
	set("item_desc", ([
	    "guan cai" : "һ��������Ĵ�ײ�,�ײĸ�û���ϣ����������ʲô������\n",
	    
	]));
	setup();
}

void init()
{
	add_action("do_dakai", "dakai");
	add_action("do_dakai", "move");
	add_action("do_dakai", "push");
	add_action("do_dakai", "open");			
}
int do_dakai(string arg)
{
	object me=this_player();
	object ob;
	if(!arg || arg!="guan cai")
		return notify_fail("��Ҫ��ʲô��\n");
	
	else if ( flag==0 )
		{
			flag=1;
			message_vision("��С��������ƿ��˹ײĸ�....�ۣ������Ȼ��һ�����.\n",me);
			message_vision("$N���¿��˿�����æ�ѹ��񴧽��˶���.\n"NOR,me);
		ob = new ( __DIR__"obj/wenyu" );
 		ob->move( this_player() );

		}
	     else message_vision("����һ���յ����Ĵ�ڹײġ�\n",me); 		

	return 1;
}

 