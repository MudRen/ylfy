// qingsonglin9.c ������

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
������������������ʧ�˷��򣬼��ʾ�������������о��Լ�����
������֮�У�ֻҪ�ߴ�һ��������������Σ�գ����г����˿־塣
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"qingsonglin"+(random(8)+6),
		"north" : __DIR__"qingsonglin"+(random(8)+6),
              "west" :__DIR__"qingsonglin"+(random(8)+6),
		"east" : __DIR__"qingsonglin"+(random(8)+6),
         ]));
	setup();
	
}

void init()
{

	object ob, room;
	mapping fam;

	int i = random(2);
	if( i == 0) return;

	ob = this_player();
	room = this_object();

	if (ob->query("id") == "dao shi" || !living(ob)) return;

	room->delete("exits");

	if ( (fam = ob->query("family"))
	&& fam["family_name"] == "ȫ���" 
	&& ob->query("guilty") != 1 )  
	ob->set("guilty",3);

	ob->set("startroom", "/d/quanzhen/siguotang");

	message_vision(HIR "\n$Nһ��С�ģ��߽��˻�ɽ��ʿ���µ����壡
$Nֻ���ý���һ���ʹ��ԭ���ǲ��������ڵ��µ���ǩ��\n\n" NOR, ob);

	message_vision(HIR "\n$Nʹ�ü���ʧȥ��֪��......\n\n" NOR, ob);

	call_out("trapping", 20, ob, room);

}

void trapping(object ob, object room)
{
	if ( !objectp(ob) || !objectp(room) ) return;
	if ( !living(ob) ) return;

//    message_vision(HIY "\n��ʿ�ǰ�$N���ݾ������˳������ͽ���˼���ã�\n\n\n" NOR, ob);	
message_vision(HIY "\n��ʿ�ǰ�$N���ݾ������˳������������ֽ���Ժ������\n\n\n" NOR, ob);	
ob->move("/d/shaolin/jlyuan"); 	
//        ob->move(__DIR__"siguotang"); 	

	room->set("exits/south", __DIR__"shulin"+(random(8)+6));
	room->set("exits/north", __DIR__"shulin"+(random(8)+6));
	room->set("exits/east", __DIR__"shulin"+(random(8)+6));
	room->set("exits/west", __DIR__"shulin"+(random(8)+6));
}


