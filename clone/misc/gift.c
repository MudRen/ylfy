// /clone/misc/gift.c
// ע�⣺���﷢��Add�ĵ��ø�ʽ���ʹ�� add(string prop, mixed data, 1)

#include <ansi.h>
#define GIFT_NAME "�������"
// ���ε����﷢��
#define THIS_GIFT_USER "2005_����"
// �ϴε����﷢��
#define LAST_GIFT_USER "2005_ʥ��"

inherit ITEM;

void create()
{
	set_name(HIR + GIFT_NAME + NOR, ({"gift","li wu"}));
    set_weight(200);
	if (clonep())
    set_default_object(__FILE__);
	
	else
	{
		set("unit", "��");
		set("long",
"     ������������������������������������������������\n" + 	
"     ��              " + HIR"Happy        Games"NOR + "            ��\n" + 
"     ��                                            ��\n" + 	
"     ��        " + HIM"�� �� �� ��        �� �� ˳ ��"NOR + "      ��\n" +  
"     ������������������������������������������������\n" + 
        HIG"��Ϧ�����֡�" + HIC" ȫ����ʦ��һ��С���⣬���(chai)��������ʲô��\n"NOR	
		);
		set("value", 0);
		set("no_give",1);
		set("no_get",1);
		set("no_put",1);
		set("no_drop",1);
	}
    setup();
}

void init()
{
	add_action("do_chai", "chai");
}

int do_chai(string arg)
{
	object me;
	me = this_player();
	
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->query(THIS_GIFT_USER))                	
	{
		tell_object(me,HIY "һ��Ư������ӰͻȻ��һ�������г���,һ��ץ�������е����,����ͷ���˰��죺��ѽ~����Ѿ��ù��˰�~!!��˵��ת������.\n"NOR);
		destruct(this_object());	
	}
	else
	{
        me->add("potential", 1000000, 1);
		me->add("combat_exp", 5000000, 1);
		
		/*if(me->query("xy_huiyuan"))
		{
			ob=new("/quest/baoshi/baoshi");
			ob->move(me);
			ob=new("/quest/baoshi/baoshi");
			ob->move(me);
			ob=new("/quest/baoshi/baoshi");
			ob->move(me);
			ob=new("/quest/baoshi/baoshi");
			ob->move(me);
			ob=new("/quest/baoshi/baoshi");
			ob->move(me);
			me->add("more_money",3);
			me->add("potential",400000);
			tell_object(me,HIM "�ر��л��ҶԱ�վ��֧��,���ͺ���������ƽ�ת����Ǯׯ�ʻ�.ף�����Ϸ��졢���Ľ���!\n"NOR);
		}*/

        tell_object(me,HIC "��С������Ĳ������������ط����Լ���Ǳ�ܼ�Ȼ����100��ʵս����Ҳ������500��\n" NOR);     	

//ɾ���ϴ����������ɵĲ��������ӱ��β�����ȷ��ÿλ���ֻ����һ�Ρ�
        me->delete(LAST_GIFT_USER);              	
        me->set(THIS_GIFT_USER,1);
		destruct(this_object());
	}
	return 1;
}

void owner_is_killed() { destruct(this_object()); }
