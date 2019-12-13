inherit F_CLEAN_UP;
#include <liebiao.h>
int main(object me, string arg)
{
	object weapon;
	mapping smap;
	string martial, skill;
	
	seteuid(getuid());
	smap = me->query_skill_map();
	if( !arg )
		return notify_fail("��Ҫ���⹦��ʲ�᣿\n");

	if ( me->query("neili") < 0 )
	{
		me->set("neili", 0);
		return notify_fail("����������㡣\n");
	}

	if ( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ�ü��ܾ��С�)\n");
	
	if ( playerp(me) && !me->query("xy_huiyuan") && me->query("age") > 17 )
		return notify_fail(HIY"ֻ�л�Ա����ʩ�ü��ܾ��С�\n"NOR);

	if ( me->query_use_skill_busy() )
		return notify_fail("���������δ��ת����ʱ����ʩ�ü��ܾ��С�\n");
	
	if( me->query_condition("no_perform") )
		return notify_fail("( ����Ϣ���ȣ���ʱ����ʩ���⹦��)\n");
	
	if (sscanf(arg, "%s.%s", martial, arg) != 2)
        {
		if (weapon = me->query_temp("weapon"))
			martial = weapon->query("skill_type");
		else
			martial = "unarmed";
	}
	
	if( stringp(skill = me->query_skill_mapped(martial)) )
	{
		if (file_size(SKILL_D(skill)->perform_action_file(arg)+".c") > 0 || file_size("/binaries" + SKILL_D(skill)->perform_action_file(arg)+".b") > 0)
		{
			notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
			
			if( SKILL_D(skill)->perform_action(me, arg) )
			{
				if( random(120) < (int)me->query_skill(skill) )
					me->improve_skill(skill, 1, 1);
				if ( playerp(me) )
				{
					// ���ü��ܾ���ʹ���䶳�ӳ�ʱ��
					if ( me->is_busy() && !me->query_use_skill_busy() )
						me->set_use_skill_busy(random(3));
					// �����⹦ûbusyʱ����busy�������BUG
					if ( !me->is_busy() && skill != "shedao-qigong" )
						me->start_busy(1+random(3));
				}
				
				return 1;
			}
			else if( SKILL_D(martial)->perform_action(me, arg) )
			{
				if( random(120) < (int)me->query_skill(martial, 1) )
					me->improve_skill(martial, 1, 1);
				if ( playerp(me) )
				{
					// ���ü��ܾ���ʹ���䶳�ӳ�ʱ��
					if ( me->is_busy() && !me->query_use_skill_busy() )
						me->set_use_skill_busy(random(3));
					// �����⹦ûbusyʱ����busy�������BUG
					if ( !me->is_busy() && martial != "shedao-qigong" )
						me->start_busy(1+random(3));
				}
				
				return 1;
			}
			
			return 0;
		}
	}

	if( sscanf(arg, "%s.%s", martial, arg)!=2 )
	{
		
		if( weapon = me->query_temp("secondary_weapon") )
			martial = weapon->query("skill_type");
		else
			martial = "unarmed";
	}
	
	if( stringp(skill = me->query_skill_mapped(martial)) )
	{
		notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
		
		if( SKILL_D(skill)->perform_action(me, arg) )
		{
			if( random(120) < (int)me->query_skill(skill) )
				me->improve_skill(skill, 1, 1);
			if ( playerp(me) )
			{
				// ���ü��ܾ���ʹ���䶳�ӳ�ʱ��
				if ( me->is_busy() && !me->query_use_skill_busy() )
					me->set_use_skill_busy(random(3));
				// �����⹦ûbusyʱ����busy�������BUG
				if ( !me->is_busy() && skill != "shedao-qigong" )
					me->start_busy(1+random(3));
			}
			
			return 1;
		}
		else if( SKILL_D(martial)->perform_action(me, arg) )
		{
			if( random(120) < (int)me->query_skill(martial, 1) )
				me->improve_skill(martial, 1, 1);
			if ( playerp(me) )
			{
				// ���ü��ܾ���ʹ���䶳�ӳ�ʱ��
				if ( me->is_busy() && !me->query_use_skill_busy() )
					me->set_use_skill_busy(random(3));
				// �����⹦ûbusyʱ����busy�������BUG
				if ( !me->is_busy() && martial != "shedao-qigong" )
					me->start_busy(1+random(3));
			}
			
			return 1;
		}
		
		return 0;
	}
	
	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]
�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��
��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺
perform taiji-jian.chan
or
perform chan
���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}
