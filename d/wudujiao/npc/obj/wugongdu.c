#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat","eat");
}

void create()
{
	    set_name("��򼶾��", ({"wugong dunang" ,"dunang"}));	
		set("unit", "��");
		set("long", "����һ�����Ķ��ҡ�\n");
		set("value", 100);
        set("no_drop", "�������������뿪�㡣\n");
        set_weight(100);

	    setup();
}

int do_eat(string arg)
{
	object ob;
    object me = this_player();
    if( !this_object()->id(arg) ) return 0;
    if( !objectp(ob = present(arg, me)) )
        return notify_fail("ʲô?\n");	
    tell_object(me,  "������������suicide�ȽϿ�һ�㡣\n" );
    return 1;
}
int query_autoload() { return 1; }
