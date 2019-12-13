// zongjue.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_fight(object me);
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
		
        if( target != me ) return
            notify_fail("��ֻ�ܶ��Լ���["+HIB+"�����ܾ�"+NOR+"]\n"NOR,);
        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("���Ѿ���������ˡ�\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("���Ѿ�����̫�����ˡ�\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("���Ѿ����˿����޵й��ˡ�\n");
        if( (int)me->query_temp("liuyun") ) 
            return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");
        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");
        if( (int)me->query_temp("powerup") )
        	return notify_fail("���Ѿ����˱���ڹ����ˡ�\n");
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

	if ((int)me->query_skill("jiuyin-zhenjing", 1) < 200)
		return notify_fail("��ľ����澭̫���ˡ�\n");
        if( (int)me->query("neili") < 700 )
        	return notify_fail("�������������\n");
        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("���Ѿ����˹����ˡ�\n");

	me->set_temp("jiuyin/powerup", 1);
        skill = me->query_skill("force");
		//skill += me->query_skill("jiuyin-zhenjing");
       // if ( skill > 20000 ) skill = 20000;
        me->add("neili", -600);
        //me->receive_damage("qi",0);

        message_vision(HIB"$N�����˾����ܾ���˲�佫����֮����תһ���죬����������Ȼ������\n" NOR, me);
        me->add_temp("apply/armor", skill/2);
        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->add_temp("apply/damage", skill/3);
        me->add_temp("apply/strength",skill/25);
        me->add_temp("apply/dexerity",skill/25);
        me->add_temp("apply/constitution",skill/25);
        me->add_temp("apply/intelligence",skill/25);
	check_fight(me);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

int check_fight(object me)
{
	//if (me->query("qi") < 0) return 0;  //��� ��ѪΪ���� ���β�����bug
	//if (me->query("jing") < 0) return 0;
	if (!me || !(int)me->query_temp("jiuyin/powerup")) return 0;
        if (!me->is_ghost() && living(me)
            && me->is_fighting() && me->query("neili") > 500
            && me->query_skill_mapped("force") == "jiuyin-zhenjing")
        {
                if(me->query("qi") < (int)me->query("max_qi")){
                        message_vision(HIY"$N��ɫһ���ֻظ��������������ڵ�����Ϣ��\n"NOR,me);
                        me->add("neili", -200);
                        me->add("eff_qi",me->query_skill("jiuyin-zhenjing")/2);
			if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
                        me->add("qi",me->query_skill("jiuyin-zhenjing"));
			if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
                        }
				if(me->query("jing") < (int)me->query("max_jing")){
                        message_vision(HIR"$N��ɫһ���ֻظ��������������ڵ�����Ϣ!\n"NOR,me);
                        me->add("neili", -200);
                        me->add("eff_jing",me->query_skill("jiuyin-zhenjing")/2);
			if (me->query("eff_jing") > me->query("max_jing")) me->set("eff_jing", me->query("max_jing"));
                        me->add("jing",me->query_skill("jiuyin-zhenjing"));
			if (me->query("jing") > me->query("eff_jing")) me->set("jing", me->query("eff_jing"));
                        }	
        }
        call_out("check_fight", 2, me);
        return 1;
}       

void remove_effect(object me, int amount)
{
	   if (!me) return;
        me->delete_temp("jiuyin/powerup");
        me->add_temp("apply/armor", -(amount/2));
        me->add_temp("apply/attack", -(amount/3));
        me->add_temp("apply/dodge", -(amount/3));
        me->add_temp("apply/damage", -(amount/3));
        me->add_temp("apply/strength",-(amount/25));
        me->add_temp("apply/dexerity",-(amount/25));
        me->add_temp("apply/constitution",-(amount/25));
        me->add_temp("apply/intelligence",-(amount/25));
        tell_object(me, "���["+HIB+"�����ܾ�"+NOR+"]������ϣ��������ջص��\n");
}

