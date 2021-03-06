// /clone/misc/gift.c
// 注意：礼物发放Add的调用格式务必使用 add(string prop, mixed data, 1)

#include <ansi.h>
#define GIFT_NAME "春节礼包"
// 本次的礼物发放
#define THIS_GIFT_USER "2005_春节"
// 上次的礼物发放
#define LAST_GIFT_USER "2005_圣诞"

inherit ITEM;

void create()
{
	set_name(HIR + GIFT_NAME + NOR, ({"gift","li wu"}));
    set_weight(200);
	if (clonep())
    set_default_object(__FILE__);
	
	else
	{
		set("unit", "件");
		set("long",
"     ┌──────────────────────┐\n" + 	
"     │              " + HIR"Happy        Games"NOR + "            │\n" + 
"     │                                            │\n" + 	
"     │        " + HIM"春 节 愉 快        万 事 顺 达"NOR + "      │\n" +  
"     └──────────────────────┘\n" + 
        HIG"※夕阳再现※" + HIC" 全体巫师的一点小心意，请打开(chai)来看看是什么？\n"NOR	
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
		return notify_fail("你要拆什么？\n");

	if (me->query(THIS_GIFT_USER))                	
	{
		tell_object(me,HIY "一个漂亮的人影突然在一阵烟雾中出现,一把抓过你手中的礼包,歪歪头看了半天：“呀~你该已经拿过了吧~!!”说完转身跑了.\n"NOR);
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
			tell_object(me,HIM "特别感谢大家对本站的支持,赠送红包三万两黄金转存您钱庄帐户.祝大家游戏愉快、身心健康!\n"NOR);
		}*/

        tell_object(me,HIC "你小心翼翼的拆开礼物包，惊奇地发现自己的潜能既然多了100万，实战经验也增长了500万。\n" NOR);     	

//删除上次派礼物生成的参数，增加本次参数，确保每位玩家只能用一次。
        me->delete(LAST_GIFT_USER);              	
        me->set(THIS_GIFT_USER,1);
		destruct(this_object());
	}
	return 1;
}

void owner_is_killed() { destruct(this_object()); }
