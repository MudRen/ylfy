// feeblebolt.c

#include <ansi.h>

inherit SSERVER;
int do_execration(object me,object target,int i);
int do_hit(object me,object target,int skill);

int cast(object me, object target)
{


	int  skill;
	string msg;
	skill=me->query_skill("divinemagic",1);
	if(!skill||skill<=100)
		return notify_fail("你还没有学会如何使用天眼通\n");
	if(me->query_temp("execration"))
		return notify_fail("你正在念咒。\n");
	if(me->query_temp("execration"))
		return notify_fail("你正在念咒。\n");
	if((int)me->query("mana") < 50 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -50);
	me->receive_damage("sen", 10);
        if(!target||me==target||!userp(target)) return notify_fail("找不到该生物\n");
	msg = ""+me->name()+"自言自语不知道在说些什麽。\n";
        message("vision",msg, environment(me), ({me}));
	tell_object(me,"你回忆起记忆深处的天眼通,开始低声吟诵咒语......\n");
	me->set_temp("execration",1);
	call_out("do_execration",1,me,target,1);
	return 1;
}


int do_execration(object me,object target,int i)
{
	string msg;
	int skill;
	switch(i)
	{
		case 1:
	   	 	msg=HIC"跟随我的精灵们\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"我以主人的身份命令\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"将远方的信息\n"NOR;
            		break;
		case 4:
		        msg=HIC"带到我的面前\n"NOR;
		default: 
			break;
	}
	tell_object(me,msg);
        i++;
    	if(i<5&&i>=0) call_out("do_execration",1,me,target,i);
	else 
	{
  	    	skill=me->query_skill("divinemagic",1);
        	if(!skill) return 1;
            	call_out("do_hit",1,me,target,skill);
	    	return 1;
    	}
	return 1;
}



int do_hit(object me,object target,int skill)
{

	string msg;
	object room;
	
	me->delete_temp("execration");
	
	if(!target||!objectp(target)||userp(target))
		return notify_fail("随着咒语吟诵完毕,可是你确无法得知该生物确切的地方\n");
	room=environment(target);
	if(!room) return notify_fail("随着咒语吟诵完毕,可是你确无法得知该生物确切的地方\n");
	if(room->query("no_magic"))
               	return notify_fail("随着咒语吟诵完毕,你发现对方所在地有一道魔法屏障当住了你的视线。\n");
	if(random(100)<1)
	{
		msg="$N的天眼通失败了\n";	
		message_vision(msg,me);
		return 1;
	}
	else
	{
		
		msg="随着咒语吟诵完毕,你渐渐看清楚了"+target->name()+"所在的地方......\n";
		tell_object(me,msg);
		"/cmds/std/look"->look_room(me, environment(target));
                tell_object(target,"你感到脖子发凉，黑暗处好像有双眼睛盯着你！\n"
                       "你仔细地看了一下四周，却什么也没有！\n");
		return 1;
	}
	return 1;
}


