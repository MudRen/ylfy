//wuchangdan.c
#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"�ݾ�ħ��"NOR, ({"cuijing dan", "dan"}));
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "����һ�ž�Ө���Ĵݾ�ħ�������Ǻ���֮��!\n");
		set("value", 500000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	
	if ( !id(arg) )
		return notify_fail("��Ҫ��ʲô��\n");
	/*if (me->query("age") > 14)
		return notify_fail("��ô���˻����������ðɣ�\n");*/
	if ( me->query("max_jingli") < 1000 )
		message_vision(HIR"$N����һ�Ŵݾ�ħ������û�з�Ӧ���ƺ�û�����κ����á�\n"NOR,me);
	else 
	{
		me->add("max_jingli", -1000);
		message_vision(HIR"$N����һ�Ŵݾ�ħ������ʱȫ��������\n"NOR,me);
	}
	destruct(this_object());
	return 1;
}

