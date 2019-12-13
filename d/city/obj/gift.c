// /d/city/obj/gift.c
// 注意：礼物发放Add的调用格式务必使用 add(string prop, mixed data, 1)

#include <ansi.h>
#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
#define GIFT_NAME "新手礼物包"

inherit ITEM;

void create()
{
    set_name(HIR + GIFT_NAME + NOR, ({"gift","liwu"}));
    set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "件");
        set("long", @LONG
┌──────────────────────┐	
│                                            │ 	
│  夕阳再现，所有巫师。                      │        	
│                                            │ 	
│       向侠客们衷心祝福，WANFU ALL          │                	
│                                            │ 	
│            希望我们的明天更美好!           │        	
│                                            │ 	
│                                            │ 	
│                        sigh, addoil!       │ 	
│                                            │ 	
└──────────────────────┘	
XYZX 巫师的一点小心意，请打开(chai)来看看是什么？	
LONG
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
	mapping my_score;
	string *myscore;
	int max;
	object me = this_player();
	
	if (!id(arg))
		return notify_fail("你要拆什么？\n");
	
	if (me->query(THIS_PAR + "_chai"))
	{
		tell_object(me,HIY "一个漂亮的人影突然在一阵烟雾中出现,一把抓过你手中的礼包,歪歪头看了半天：“呀~你该已经拿过了吧~别想偷懒哦~!!”说完转身跑了.\n"NOR);
		destruct(this_object());
	}
	else
	{
		/*_________________基本状态_______________________*/
		my_score = get_mapping_config(DATA_CONFIG_DIR+"mapping/gift_new.mapp");
		if ( mapp(my_score) && sizeof(my_score) )
		{
			myscore = keys(my_score);
			for ( int i=0; i<sizeof(myscore); i++ )
			{
				if ( me->query(myscore[i], 1) < my_score[myscore[i]] )
					me->set(myscore[i], my_score[myscore[i]]);
			}
		}
		/*____________________end_________________________*/
		/*____________________技能________________________*/
		my_score = get_mapping_config(DATA_CONFIG_DIR+"mapping/gift_new_skill.mapp");
		if ( mapp(my_score) && sizeof(my_score) )
		{
			myscore = keys(my_score);
			for ( int i=0; i<sizeof(myscore); i++ )
			{
				if ( me->query_skill(myscore[i], 1) < my_score[myscore[i]] )
					me->set_skill(myscore[i], my_score[myscore[i]]);
			}
		}
		/*____________________end_________________________*/
		/*___________________恢复精、气___________________*/
		max = me->query("max_jingli") / 4;
		me->set("max_jing", max);
		me->set("eff_jing", max);
		me->set("jing", max);
		max = me->query("max_neili") / 4;
		me->set("max_qi", max);
		me->set("eff_qi", max);
		me->set("qi", max);
		/*____________________end_________________________*/
		tell_object(me,HIC "你小心翼翼的拆开礼物包，只见一阵烟雾过后，你顿时隐隐约约感到自己身体有了一些变化。\n" NOR);
		
		//删除上次派礼物生成的参数，增加本次参数，确保每位玩家只能用一次。
		me->delete(LAST_PAR + "_chai");
		me->set(THIS_PAR + "_chai",1);
		destruct(this_object());
	}
	return 1;
}

void owner_is_killed() { destruct(this_object()); }
