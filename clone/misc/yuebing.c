// /clone/misc/gift.c	
// ע�⣺���﷢��Add�ĵ��ø�ʽ���ʹ�� add(string prop, mixed data, 1)

#include <ansi.h>
#define GIFT_NAME "�±�"

inherit ITEM;

void create()
{
	set_name(HIY + GIFT_NAME + NOR, ({"yue bing","bing"}));
	set_weight(200);
	if ( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", HIM"һ���±����������ƺ�����ɿڣ������̲�ס��������ҧһ�ڡ�"NOR);
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
	add_action("do_chai", "eat");
}

int do_chai(string arg)
{
	object me;
	int i;

	me = this_player();
	
	if ( !id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
	if ( me->query("07_����") )                	
	{
		tell_object(me, HIY "�������±�����ҧ�˿ڣ�����üͷһ����ôζ���ֵֹ�....����ϸһ��ԭ���������ģ���ݺݵذ��±����˳�ȥ....\n"NOR);	
		destruct(this_object());
		return 1;
	}
	
	tell_object(me,HIG "�������±������ҧ�˿ڣ�������ζ�������ޱȣ��̲�סһ��ȫ������ȥ��\n" NOR);
	for ( i=0; i<10; i++ )
	{
		me->add("combat_exp", 5000000, 1);
	}
	// ɾ���ϴ����������ɵĲ��������ӱ��β�����ȷ��ÿλ���ֻ����һ�Ρ�
	me->delete("����",1);              	
	me->set("07_����", 1);              	
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{ 
	destruct(this_object());
}