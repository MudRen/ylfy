#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","������");
         set("long",@long
����һƬ���̵������֣��ݵ��м������ô���(tree)������ȥ֦Ҷïʢ�����ϼ�
ֻС�����������Ľи���ͣ��
long);
         set("exits",([
             "south" : __DIR__"liulin1",
]));
         set("item_desc", ([
	"tree" : "��֦����治�ߣ���֪�ܲ���Ծ(jump)��ȥ��\n",
]));
	set("objects",([
		__DIR__"obj/xiao-shuzhi" : 2,
]));
setup();
}

void init()
{
        add_action("do_yue", "yue");
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me=this_player();
        write(RED"������һ��...\n"
                       "����㷢������Ṧ����Ծ����֦��\n"NOR,
        );
        me->unconcious();
        return 1;
}

int do_yue(string arg)
{
	object me;
	me = this_player();
	if (arg !="tree") 
		return notify_fail("��Ҫ����ȥ��\n");
	else
	{
		write("��������������֦��\n");
		message("vision",
		me->name() + "һ������������֦��\n",
			environment(me), ({me}) );
		me->move(__DIR__"shuzhi");
		message("vision",
		me->name() + "����������������\n",
			environment(me), ({me}) );
	}
	return 1;
}
