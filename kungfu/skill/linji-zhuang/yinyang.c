// yinyang.c
// suimeng by 2015.4

#include <ansi.h>
int exert(object me)
{
	int improve; 
	improve = me->query_skill("force");
	improve *= me->query("con");	

	if( (int)me->query_skill("linji-zhuang", 1) < 1020 )
		return notify_fail("你的临济十二庄修为还不够。\n");
	
	if( me->query("class") != "bonze" && me->query("family/generation") > 3)
		return notify_fail("你不是出家人，无法领会临济十二庄的「阴阳」字决！\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("max_neili") < 150000 )
		return notify_fail("你的真气不够。\n");

	if( me->query_temp("ljz/yinyang")   )
		return notify_fail("你正在运用临济十二庄的「阴阳」字诀！\n");
	
    if( (int)me->query_temp("powerup") )
		return notify_fail("你「战斗力提升」已经在运功中了。\n");
	
	message_vision(HIW"只见$N吸取天地之间的阴阳两气，顿然气力大增！\n"NOR,me);

	me->add("max_qi", improve);
	me->add("eff_qi", improve);
	me->add("qi", improve);

//	修改以前的直接恢复气血

	me->add("max_jing", improve);
	me->add("eff_jing", improve);
	me->add("jing", improve);

//	增加精血

	me->set_temp("ljz/yinyang", improve);
	me->add("neili", - 500);
	if( me->is_fighting() ) me->start_busy(random(2));
	me->start_exert(1, "阴阳字决");
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), improve );
	return 1;
}

void remove_effect(object me)
{      
	int improve;
	if( !me || !me->query_temp("ljz/yinyang") ) return;
	improve = me->query_temp("ljz/yinyang");
	me->delete_temp("ljz/yinyang");
	me->add("max_qi", - improve);
	me->add("max_jing", - improve);	// 恢复原来的精血 
	
	if( me->is_ghost() ) return;

	// 修改原来恢复上限问题
	if( me->query("eff_qi") > me->query("max_qi") )
		me->set("eff_qi", me->query("max_qi") );
	if( me->query("qi") > me->query("max_qi") )
		me->set("qi", me->query("max_qi") );

	if( me->query("eff_jing") > me->query("max_jing") )
		me->set("eff_jing", me->query("max_jing") );
	if( me->query("jing") > me->query("max_jing") )
		me->set("jing", me->query("max_jing") );

	tell_object(me, HIR"你的临济十二庄「阴阳」字诀运功完毕，气力回复了正常。\n"NOR);
}

string exert_name(){ return HIW"阴阳字决"NOR; }

int help(object me)
{
        write(HIW"\n临济十二庄「阴阳字诀」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                最大内力 150000 以上；
                临济十二庄等级 1020 以上；
				出家或俗家三代弟子。

HELP
        );
        return 1;
}
