// 守护精灵.该精灵会一直保护玩家,直到玩家死亡或者离线.

#include <ansi.h>

inherit SSERVER;
int do_execration(object me,object target,int i);
int do_hit(object me,object target,int skill);
int set_elf_skill(object me,object elf,int skill);

int cast(object me, object target)
{


	int  skill;
	string msg;
	skill=me->query_skill("divinemagic",1);
	if(skill>=200)
		return notify_fail("你强大的魔法力量足以保护自己的生命,不再需要精灵们守护了.\n");
	if(me->query_temp("execration"))
		return notify_fail("你正在念咒。\n");
	if(me->query_temp("execration"))
		return notify_fail("你正在念咒。\n");
	if((int)me->query("mana") < 100 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("你的精神没有办法有效集中！\n");

	if(objectp(me->query_temp("cast_elf"))) return notify_fail("迷雾岛的精灵已经被你召唤出来了\n");
	me->add("mana", -100);
	me->receive_damage("sen", 50);

	msg = ""+me->name()+"自言自语不知道在说些什麽。\n";
        message("vision",msg, environment(me), ({me}));
	tell_object(me,"你在脑海回忆起守护圣灵的魔法咒语,低声吟诵着......\n");
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
	   	 	msg=HIC"迷雾岛的精灵\n"NOR;
	    		break;
		case 2:
	    		msg=HIC"聆听我的请求\n"NOR;
	    		break;
        	case 3:
            		msg=HIC"请您遵守远古的的盟约\n"NOR;
            		break;
		case 4:
			msg=HIC"守护你的主人\n"NOR;
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
	object elf,room;
	if(!objectp(me)) return 1;
	me->delete_temp("execration");
	
	if(random(100)<1)
	{
		msg="$N的守护圣灵失败了\n";	
		message_vision(msg,me);
		return 1;
	}
	else
	{
		msg="$N将守护圣灵咒语吟诵完毕,一只生物出现在$N身边\n";
		message_vision(msg,me);
		if(me->is_fighting())
			me->start_busy(me->query_busy()+3);
		elf=new("/daemon/class/divine/elf");
		if(!elf)
		{
			tell_object(me,"精灵文件不存在,请通知巫师\n");
			return 1;
		}
		elf->set("owner",me);
		me->set_temp("cast_elf",elf);
		room=environment(me);
		elf->move(room);
		elf->set_leader(me);
		elf->invocation(me);
		set_elf_skill(me,elf,skill);
		
	}
	return 1;
}

int set_elf_skill(object me,object elf,int skill)
{
	elf->set_skill("unarmed",skill);
	elf->set_skill("parry",skill);
	elf->set_skill("dodge",skill);
	elf->set_temp("apply/armor",10+random(40));
	elf->set_temp("apply/damage",10+random(70));
	elf->set("combat_exp",skill*10000>1000000?skill*10000:1000000);
}

