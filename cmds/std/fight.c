// fight.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    object obj, old_target;
    if( environment(me)->query("no_fight") )
        return notify_fail("�����ֹս����\n");
    if(!arg || !objectp(obj = present(arg, environment(me))))
        return notify_fail("���빥��˭��\n");
    if( !obj->is_character() )
        return notify_fail("�����һ�㣬�ǲ��������\n");
    if( obj->is_fighting(me) )
        return notify_fail("���ͣ����ͣ����ͣ�\n");
if(obj->query_temp("apply/shade_vision"))    return notify_fail("�㿴����"+obj->query("name")+"��\n");        	
    if( obj->query("env/no_fight") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");
    if( !living(obj) )
        if( userp(obj) && obj->query_temp("sleeped"))
            return notify_fail("�˼Ҷ�˯���ˣ�����������ô��\n");
        else
            return notify_fail(obj->name() + "�Ѿ��޷�ս���ˡ�\n"); 
    if(obj==me) return notify_fail("�㲻�ܹ����Լ���\n");

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

    if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
        message_vision("\n$N����$n˵����" 
            + RANK_D->query_self(me) 
            + me->name() + "�����"
            + RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);
        if( objectp(old_target = me->query_temp("pending/fight")) )
            tell_object(old_target, YEL + me->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
        me->set_temp("pending/fight", obj);
        tell_object(obj, YEL "�����Ը��ͶԷ����б��ԣ�����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� fight ָ�\n" NOR);
        write(YEL "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
        //��սʦ��
        if ( !obj->is_fighting() && me->query("family/master_id")==(string)obj->query("id")) 
                    obj->set_temp("fighting",me);
        else    obj->delete_temp("fighting",me);
        return 1;
    }
    if( obj->query("can_speak")) {
        if (me->query_temp("pending/fight")!=obj)
        message_vision("\n$N����$n˵����" 
            + RANK_D->query_self(me) 
            + me->name() + "�����"
            + RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);
        obj->set_temp("pending/fight", me);
        me->set_temp("pending/fight", obj);
        notify_fail("������" + obj->name() + "��������������\n");
        if( !userp(obj) && !obj->accept_fight(me) ){
                return 0;
        }
//��սʦ��
        if ( me->query("family/family_name")!="������")
        if ( !obj->is_fighting() && me->query("family/master_id")==(string)obj->query("id")) 
                    obj->set_temp("fighting",me);
        else    obj->delete_temp("fighting",me);
        me->fight_ob(obj);
        obj->fight_ob(me);
    } else {
        message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
        me->fight_ob(obj);
        obj->kill_ob(me);
    }
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : fight <����>
 
���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��������
�㵽Ϊֹ�����ֻ����������������������ˣ����ǲ��������е�  NPC ��ϲ��
��ܣ���������״����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: hit, kill
PS. ����Է���Ը����������ս������Ȼ���������� kill ָ�ʼս������
    �� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
