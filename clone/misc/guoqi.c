// /clone/misc/gift.c	
// ע�⣺���﷢��Add�ĵ��ø�ʽ���ʹ�� add(string prop, mixed data, 1)

#include <ansi.h>
#define GIFT_NAME "���Ǻ���"

inherit ITEM;

void create()
{
	set_name(HIR + GIFT_NAME + NOR, ({"wuxing hongqi", "hongqi"}));
	set_weight(200);
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "һ�����Ǻ��죬��������ҡһҡ(yao)��\n");
		set("value", 0);
		set("no_give", 1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
		set("no_sell", 1);
	}
	setup();
}

void init()
{
	add_action("do_yao", "yao");
}

int do_yao(string arg)
{
	object me;
	int i;

	me = this_player();
	
	if ( !id(arg) ) return notify_fail("��Ҫҡʲô��\n");
	if ( me->query("07_����") )                	
	{
		tell_object(me, HIY "���������Ǻ���ҡ��ҡ���ƺ���û�з����κ��¡�\n"NOR);	
		destruct(this_object());
		return 1;
	}
	
	tell_object(me,HIG "���������Ǻ���ҡ��ҡ��ͻȻ�����Ϸ���һ����������������ϣ���о���ø�ǿ���ˡ�\n" NOR);
	for ( i=0; i<20; i++ )
	{
		me->add("combat_exp", 5000000, 1);
	}
	// ɾ���ϴ����������ɵĲ��������ӱ��β�����ȷ��ÿλ���ֻ����һ�Ρ�
	me->delete("07_����");              	
	me->set("07_����", 1);              	
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{ 
	destruct(this_object());
}