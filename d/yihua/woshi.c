#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ƻ�����������");
	set("long", @LONG
�������ƻ�����λ���������ҡ����ﵽ���������˻��㣬ʹ���������С�
����Ҳ��װ�ε��񻨴�һ��������ϸ�Ŀ���һ�´�(bed)���ƺ��е㲻�Ծ���
�����ǰȥ����һ�¡�
LONG
	);
        set("sleep_room", 1);   
        set("exits", ([
        "northwest" : __DIR__"yaoyue",
        "northeast" : __DIR__"lianxing",
	]));
	set("item_desc", ([
        "bed": "һ������ͨͨ�Ĵ�����������ϸ�Ŀ���һ�£��ƺ����ƶ�����\n"
	]) );

	setup();
}

void init()
{
	add_action("do_push", "push");
}
void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==8
        &&  (int)query("right_trigger")==5
	&&	!query("exits/down") ) {
        message("vision", "�����Ȼ���������������������������ƶ�����¶��һ�����µĽ��ݡ�\n",
			this_object() );
        set("exits/down", __DIR__"midao");
        if( room = find_object(__DIR__"midao") ) {
			room->set("exits/up", __FILE__);
            message("vision", "��Ȼ���������������������������ƶ�����¶��һ�����ϵĽ��ݡ�\n",
				room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 30);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
    message("vision", "�����Ȼ����������������������£�������µ�ͨ����ס�ˡ�\n",
		this_object() );
    if( room = find_object(__DIR__"midao") ) {
		room->delete("exits/up");
        message("vision", "�����Ȼ����������������������£�������ϵ�ͨ����ס�ˡ�\n"
                        HIY "���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" NOR ,
			room );
	}
	delete("exits/down");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="bed" ) {
		write("�������ƶ�����ʻ��̳ɵĴ��壬���������������ƶ�....\n");
		return 1;
	}
	if( sscanf(arg, "bed %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N������������...����Ȼ���������������ƻ�ԭλ��\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N������������...����Ȼ���������������ƻ�ԭλ��\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("��Ҫ�����������Ǹ�����\n");
			return 1;
		}
	}
}
void reset()
{
	::reset();
	delete("left_trigger");
	delete("right_trigger");
}
