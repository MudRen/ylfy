// bangong.c
	
inherit ITEM;
#include <ansi.h>
#define LAST_PAR "xin"
#define THIS_PAR "xinsf"
void create()
{
set_name("�칫��", ({ "bangong zhuo","zhuo","table"}));
set_weight(5000000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "��");
set("no_get",1);
set("long","һ������ͨͨ�����ӣ�����������һ���š��Ƿ�(pick xin)������������?");	
set("value", 0);
set("material", "stone");
}       	
}	
void init()
{
add_action("do_pick", "pick");
}
int do_pick(string arg)
{
	object me,obj;
	me = this_player();
	if( !arg || arg!="xin" ) return notify_fail("��Ҫ��ʲô��\n");
	if (me->query("id")!="lisa")
       {	
		tell_object(me,CYN "�Բ���,������㲻���á�\n" NOR)	;
		return 1;	
       }	
	if (me->query(THIS_PAR + "_pick")) 
	{
	tell_object(me,CYN "��Ӱ칫��������һ���š�\n"NOR)	;
	return 1;
	}
	message_vision("$N�Ӱ칫��������һ���š�\n",me );
	obj = new ("/clone/misc/xin");
	obj->move(me);
	return 1;
}
