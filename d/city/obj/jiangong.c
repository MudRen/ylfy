//wuchangdan.c
#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"�������鵤"NOR, ({"xiaogong dan", "dan"}));
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "����һ�Ž��ɫ��ҩ���ƺ�����������������С��ʹ��Ŷ��\n");
		set("value", 10000000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if ( !objectp(me) ) return 0;
	if ( !id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
	if ( me->query_temp("apply/damage") < -500000 )
		message_vision(HIY"$N����һ���������鵤����û�з�Ӧ���ƺ�û�����κ����á�\n"NOR,me);
	else 
	{
		me->add_temp("apply/damage", -50000);
		message_vision(HIG"$N����һ���������鵤���ƺ����ù����������½���\n"NOR,me);
	}
	destruct(this_object());
	return 1;
}

