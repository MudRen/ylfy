// yinyang.c
// suimeng by 2015.4

#include <ansi.h>
int exert(object me)
{
	int improve; 
	improve = me->query_skill("force");
	improve *= me->query("con");	

	if( (int)me->query_skill("linji-zhuang", 1) < 1020 )
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");
	
	if( me->query("class") != "bonze" && me->query("family/generation") > 3)
		return notify_fail("�㲻�ǳ����ˣ��޷�����ټ�ʮ��ׯ�ġ��������־���\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( (int)me->query("max_neili") < 150000 )
		return notify_fail("�������������\n");

	if( me->query_temp("ljz/yinyang")   )
		return notify_fail("�����������ټ�ʮ��ׯ�ġ��������־���\n");
	
    if( (int)me->query_temp("powerup") )
		return notify_fail("�㡸ս�����������Ѿ����˹����ˡ�\n");
	
	message_vision(HIW"ֻ��$N��ȡ���֮���������������Ȼ����������\n"NOR,me);

	me->add("max_qi", improve);
	me->add("eff_qi", improve);
	me->add("qi", improve);

//	�޸���ǰ��ֱ�ӻָ���Ѫ

	me->add("max_jing", improve);
	me->add("eff_jing", improve);
	me->add("jing", improve);

//	���Ӿ�Ѫ

	me->set_temp("ljz/yinyang", improve);
	me->add("neili", - 500);
	if( me->is_fighting() ) me->start_busy(random(2));
	me->start_exert(1, "�����־�");
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
	me->add("max_jing", - improve);	// �ָ�ԭ���ľ�Ѫ 
	
	if( me->is_ghost() ) return;

	// �޸�ԭ���ָ���������
	if( me->query("eff_qi") > me->query("max_qi") )
		me->set("eff_qi", me->query("max_qi") );
	if( me->query("qi") > me->query("max_qi") )
		me->set("qi", me->query("max_qi") );

	if( me->query("eff_jing") > me->query("max_jing") )
		me->set("eff_jing", me->query("max_jing") );
	if( me->query("jing") > me->query("max_jing") )
		me->set("jing", me->query("max_jing") );

	tell_object(me, HIR"����ټ�ʮ��ׯ���������־��˹���ϣ������ظ���������\n"NOR);
}

string exert_name(){ return HIW"�����־�"NOR; }

int help(object me)
{
        write(HIW"\n�ټ�ʮ��ׯ�������־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 150000 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 1020 ���ϣ�
				���һ��׼��������ӡ�

HELP
        );
        return 1;
}
