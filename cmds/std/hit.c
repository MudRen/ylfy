// fight.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object obj;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");
	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");
if(me->query_temp("apply/name")&&userp(obj))                 return notify_fail("�㻹����ȡ����߰�!\n");	
	if( obj->is_fighting(me) && me->is_fighting(obj) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");
	if( me->query_temp("hitting") )
		return notify_fail("���ͣ����ͣ����ͣ�\n");
        if( obj->query("env/no_fight")&&wizardp(obj) )
                return notify_fail("���ܴ򣬴򲻵ð���\n");
if(obj->query_temp("apply/shade_vision"))    return notify_fail("�㿴����"+obj->query("name")+"��\n");        	
	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��������㻹Ҫ�򣬹����˵�ɣ�\n"); 
	if(obj==me)	return notify_fail("���Լ�������ô�벻����\n");
	if((int)obj->query("age") <= 17 && playerp(obj) 
		&& !obj->query_condition("killer") )
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

#ifdef XYZX_SYS_JULI
	if ( !(me->query("xysys_map_xy/x") - obj->query("xysys_map_xy/x") < 2 
		&& me->query("xysys_map_xy/x") - obj->query("xysys_map_xy/x") > -2 
		&& me->query("xysys_map_xy/y") - obj->query("xysys_map_xy/y") < 2 
		&& me->query("xysys_map_xy/y") - obj->query("xysys_map_xy/y") > -2) )
	{
		me->set("env/map_xy_msg","auto");
		return notify_fail(HIY"�����Զ�޷����й����������߽�����˵�ɡ�\n"NOR);
	}
#endif

	if( userp(obj) ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
		me->set_temp("hitting");
// ��������
 		if ( me->query("age")<18 )
			me->att_kill_ob(obj);
                me->fight_ob(obj);
                obj->fight_ob(me);
		remove_call_out("do_hit");
		call_out("do_hit", 1, me, obj);
		return 1;
	}
	if( obj->query("can_speak") ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
		me->fight_ob(obj);
		if (obj->query("shen")<-3000 )
			obj->kill_ob(me);
		else
			obj->fight_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}
	return 1;
}
void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : hit <����>
 
���ָ������ֱ����һ��������С���������ʽ��ս���Ǽ�ʱ�ģ�ֻҪ���һ
��������ս���ͻῪʼ��ֱ��ĳһ������50% ����Ϊֹ�����ָ�����Щ��
ϲ��fight��NPC�����ã���Ϊ�ܶ�ʱ����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: fight, kill
HELP
    );
    return 1;
}
 
