// cangjingge2.c �ؾ���

#include <room.h>
inherit ROOM;

string* books = ({
	"force_book",
	"unarmed_book",
	"sword_book",
	"unarmed_book",
	"sword_book",
	"force_book",
	"sword_book",
	"force_book",
	"unarmed_book",
	"sword_book"
	});

void create()
{
	set("short", "�ؾ����¥");
	set("long", @LONG
�����ǲؾ����¥����ǽ�Ǽ�����ܣ�ȫ����������ء����������ߵ���
���������Լ����л����ľ���������������һ�������ʮ�ɵ�Ϫ����
LONG
	);

	set("exits", ([
	    "down" : __DIR__"cangjingge1",
	]));

	
	set("objects", ([
"/d/quanzhen/npc/qiuchuji" : 1,
		__DIR__"obj/bookshelf" : 1,
	]));
          
	setup();
	
}
int valid_leave(object me, string dir)
{
	object ob;

	if ( present("master qiu", environment(me)) )
	if ( present("book", me)
	||   objectp(ob = present("corpse", me)) && present("book", ob) )
	{
		if (dir == "down" )
		{
			return notify_fail("�𴦻�˵��: ���书�ؼ�ֻ���ڲؾ�������ϰ������Я����� !��\n");
		}
	}
	return ::valid_leave(me, dir);
}


