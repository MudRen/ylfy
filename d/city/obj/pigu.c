#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"�ٹ��ɵ�"NOR, ({"xian dan", "dan"}));
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "����һ�ž�Ө�����ɵ��������ɼ��������˼�ı���!\n");
		set("value", 10000000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if ( !id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
	me->set("food", 8*me->max_food_capacity());
	me->set("water",8*me->max_water_capacity());
	message_vision(HIR"$N����һ���ɵ�����ʱȫ�����������\n"NOR,me);
	destruct(this_object());
	return 1;
}

