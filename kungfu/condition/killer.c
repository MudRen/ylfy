// killer.c

#include <user.h>

int update_condition(object me, int duration)
{
	duration--;

    if (duration < 1) 
    {
        tell_object(me, "官府不再通缉你了！\n");
		me->apply_condition("killer", duration);
		me->reset_heart_beat(0);
		// 退出游戏
		if ( !interactive(me) && me->query_temp("netdead") ) 
			"/cmds/usr/quitfyup"->main(me);
        return 0;
     }

    if(environment(me)->query("no_fight") && !me->query_temp("diable_inputs"))
    {

      int i = random(30);
      me->receive_damage("jing", me->query("max_jing")/10);	
      me->receive_damage("qi", me->query("max_qi")/10);	
      me->receive_wound("jing", me->query("max_jing")/20);	
	  me->receive_wound("qi", me->query("max_qi")/20);	
    	if(i>20) tell_object(me,"一道闪电划过长空，你想起以前为非作歹的事迹，不由得心发虚！\n"  );
    	else if (i>10)  tell_object(me,"天空中响起了滚滚雷声，你怔怔地望着天喃喃自语：我做了这么多坏事，该不会被天遣吧！\n");
    	else tell_object(me,"你觉得背脊一凉，打心底涌起了一股寒意：鬼！！\n");

 
        me->set_temp("die_for","遭天遣而");
        me->delete_temp("last_damage_from");
    }
    me->apply_condition("killer", duration);
	if ( me->query_temp("apply/id") )
		me->command("pretend cancel");
    return 1;
}
