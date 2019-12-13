// killer.c

#include <user.h>

int update_condition(object me, int duration)
{
	duration--;

    if (duration < 1) 
    {
        tell_object(me, "�ٸ�����ͨ�����ˣ�\n");
		me->apply_condition("killer", duration);
		me->reset_heart_beat(0);
		// �˳���Ϸ
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
    	if(i>20) tell_object(me,"һ�����绮�����գ���������ǰΪ���������¼������ɵ��ķ��飡\n"  );
    	else if (i>10)  tell_object(me,"����������˹������������������������������������ô�໵�£��ò��ᱻ��ǲ�ɣ�\n");
    	else tell_object(me,"����ñ���һ�������ĵ�ӿ����һ�ɺ��⣺����\n");

 
        me->set_temp("die_for","����ǲ��");
        me->delete_temp("last_damage_from");
    }
    me->apply_condition("killer", duration);
	if ( me->query_temp("apply/id") )
		me->command("pretend cancel");
    return 1;
}
