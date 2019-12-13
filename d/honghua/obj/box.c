// box.c ����
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"����"NOR, ({ "gold xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ��װǮ�����ӣ��컨��Ӹ��ؽ����Ĳ���֮��ȫ��������!\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}
int is_container() { return 1; }
void init()
{
	add_action("do_put", "put");
}
int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;
	me = this_player();
	if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");
	if( sscanf(arg, "%s in %s", item, target)!=2 
	||  sscanf(item, "%d %s", amount, item)!=2
	||  !objectp(obj = present(item, me)) )
	return notify_fail("��Ҫ��˭ʲô������\n");
	if( obj->query("money_id") == "silver" 
	&&  obj->query_amount() >= 5 && amount >= 5 ) 
	{
		if( me->query("begger") > 0) {
			message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
				obj->query("unit"), obj->name(), 
				this_object()->name()),me );
			obj->set_amount(obj->query_amount() - amount);
			return 1;
		}
	}
	return 0;
}