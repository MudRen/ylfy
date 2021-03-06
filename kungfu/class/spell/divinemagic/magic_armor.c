// magic_armor 魔法盾

#include <ansi.h>
inherit SSERVER;
int do_hit(object me,int skill);
int do_execration(object me,int i);

int cast(object me,object target)
{
	string msg;
	int  skill;
    	
	if(me->query_temp("execration"))
		return notify_fail("你正在念咒。\n");
        skill=me->query_skill("magic");
        if(!skill||skill<60)
	    return notify_fail("你没有领悟这项魔法！\n");

	if(me->query_temp("magic_armor"))
		return notify_fail("你已经呼唤出魔法盾了......\n");
	if(me->query("mana")<=50)
		return notify_fail("魔法盾需要50点法力才能呼唤出来！\n");
	me->add("mana",-50);

	msg = ""+me->name()+"自言自语不知道在说些什麽。\n";
    	message("vision",msg, environment(me), ({me}));
	tell_object(me,"你开始吟诵魔法盾地咒语......\n");
	me->set_temp("execration",1);
	call_out("do_execration",1,me,1);
	return 1;
}


int do_execration(object me,int i)
{
	string msg;
	int skill;
	switch(i)
	{
		case 1:
	    		msg=HIC"神圣的力量啊.\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"化作为光之盾\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"守护你忠贞的信徒\n"NOR;
			break;
		default: 
			break;
	}
	tell_object(me,msg);
        i++;
        if(i<4&&i>=0)  call_out("do_execration",1,me,i);
	else 
	{
  		skill=me->query_skill("magic",1);
        	if(!skill) return 1;
        	call_out("do_hit",1,me,skill);
	    	return 1;
    	}
	return 1;
}



int do_hit(object me,int skill)
{
	string msg;
	me->delete_temp("execration");
	me->set_temp("magic_armor",2);// 必须是2和系统文件/feature/damage.c有关}
    	msg="$N打开了魔法盾......\n";
    	message_vision(msg,me);
    	if(me->is_fighting()&&userp(me))
    	me->start_busy(me->query_busy()+2);

}

