
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int my_idle, your_idle;
    object obj, ob;
    string callname;
    
	if ( !me )
		return 0;
    
	if( environment(me)->query("no_fight") )
        return notify_fail("���ﲻ׼ս����\n");
    
	if( !arg )
        return notify_fail("����ɱ˭��\n");
    
	if(!objectp(obj = present(arg, environment(me))) || !me->visible(obj))
        return notify_fail("����û������ˡ�\n");
	
	if(me->query_temp("apply/name") && userp(obj))
		return notify_fail("�㻹����ȡ����߰�!\n");
	
	if(obj->query_temp("apply/shade_vision"))
		return notify_fail("�㿴����"+obj->query("name")+"��\n");        	
    
	if( !obj->is_character() || obj->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
    
	if(obj==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
    
	if(me->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");
    
	if (playerp(me))
	{
		your_idle = obj->query_skill("fadai-qigong",1);
		my_idle = me->query_skill("fadai-qigong",1);
		
		if(userp(obj)&&me->query("combat_exp")<500&&obj->query("combat_exp")>10000)
			return notify_fail("�㲻��"+obj->query("name")+"�Ķ��֣���Ҫ�װ�ȥ�����ˡ�\n");
		
		if(userp(obj) && random(your_idle)>30 && random(your_idle) > random(my_idle) && !obj->is_fighting() && !environment(obj)->query("fight_room") )
		{
			write("�����"+obj->query("name")+"��ɱ�֣����ǿ������Ǵ���ľ�������ӣ���ʼ�պݲ���������\n");
			tell_object(obj,"һ�ֲ���ĸо���������ȫ������\n");
			tell_object(obj,me->query("name")+"("+me->query("id")+")"+"������¶��֣����ڿ����У��㻹�ǿ��Ӱɣ�\n");

			if ( !me->is_busy() )
				me->start_busy(5);
		}
		
		if ( wizardp(obj) && !wizardp(me) )
			return notify_fail(obj->query("name")+"������һ�ۣ���ͻȻ�ŵ����ȷ�������������������\n");
		
		if((int)obj->query("age") <= 17 && playerp(obj)
			&& !obj->query_condition("killer") )
			return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
		
		if( !living(obj) && userp(obj) && obj->query_temp("sleeped") )
			return notify_fail("���˼�˯����ʱ�����֣��ٺ٣���Ҳ̫ȱ���ˣ�\n");
	}

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
    
	callname = RANK_D->query_rude(obj);
    message_vision("\n$N����$n�ȵ�����" 
        + callname + "�����ղ������������һ��\n\n", me, obj);
    
	me->kill_ob(obj);
	
	if ( userp(me) && userp(obj) )
	{
		if ( !me->is_busy() )
			me->start_busy(3);
	}
    
	obj->delete_temp("fighting");
    
	if ( userp(obj))
	{
 		if ( me->query("age")<18 )
			me->att_kill_ob(obj);
	}
	
	if( !userp(obj))
        obj->kill_ob(me);
    else {
        obj->fight_ob(me);
        tell_object(obj, HIR "�����Ҫ��" + me->name() 
            + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
    }
      if (!userp(me)) return 1;
    if (stringp(obj->query("marry"))){
    ob=present(obj->query("marry"),environment(me));
    if (ob && userp(ob) && living(ob) && ob!=me ){
        if (ob->query("gender")=="����")
            message_vision(CYN"\n$Nһ��ŭ��"+me->name()+"���㾹���۸������ţ��Ҹ���ƴ�ˣ�\n\n"NOR, ob);
        else
            message_vision(CYN"\n$N����һ����"+me->name()+"�������㲻���۷򸾷���������У�\n\n"NOR, ob);
        ob->kill_ob(me); me->fight_ob(ob);
    }
    }
    if( !stringp(callname=obj->query("family/family_name")))
        if( !stringp(callname=obj->query("friend")))
        return 1;
    ob=first_inventory(environment(me));
    while(ob){
        if( ob!=obj && ob->is_character() && !ob->is_corpse() && living(ob)){
//ͬ�Ż�������ҿɲ����룩
            if ( (string)ob->query("family/family_name")==callname && !ob->is_killing(me) && !userp(ob) ){
                message_vision(CYN"\n$N��ŭ��"+me->name()+"���㾹��ı���ҵ�ͬ�ţ����У�\n\n"NOR, ob);
                ob->kill_ob(me); me->kill_ob(ob);
            }
//�ݰѵ��ֵܻ���
            if ((string)ob->query("friend")==callname  || (string)ob->query("friend")==obj->query("id") ){
                message_vision(CYN"\n$N����һЦ��"+me->name()+"����Ҫɱ�Ұݰѵ��ֵܣ����������ң�\n\n"NOR, ob);
                ob->kill_ob(me); me->fight_ob(ob);
            }
        }
        ob=next_inventory(ob);
    }
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��
�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��
�������ָ��: hit, fight
�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
