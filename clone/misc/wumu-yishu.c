// ��������
#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_read", "fan");
}

void create()
{
set_name("���������顷", ({ "wumu yishu", "yishu","book"}));	
	set("weight", 600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "paper");
set("long", "�ഫ�Ȿ��Ϊ�������������м������������ñ���ս�ľ��飬�Լ���һ��֮�����书������Է���(fan)����\n");
	}
	setup();
}

int do_read(string arg)
{
if (!arg||(arg!="wumu yishu"&&arg!="yishu"))	
        return notify_fail("��û���Ȿ�飬�ҷ��ڴ���ʲô��\n");
    this_player()->start_more(read_file("/d/nanyang/marry"));
    return 1;
}

int query_autoload() { return 1; }
