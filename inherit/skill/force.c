// force.c

inherit SKILL;
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    int damage;
    me->add("neili", - factor );
    damage = (int)me->query("neili")/100 + factor - (int)victim->query("neili")/100;
    if( damage < 0 )
	{  //���Ϳ��ֱ�����ĸ��ʣ����͵�������ĵز�
		if ( !me->query_temp("weapon") && me->query_skill("force") + random(me->query_skill("force")*2) < victim->query_skill("force") ) 
		{
			damage = - damage;
			me->receive_damage( "qi", damage * 2,victim );
			me->receive_wound( "qi", damage ,victim);
			if( damage < 20 ) return "$N�ܵ�$p�����������ƺ�һ����\n";
			else if( damage < 80 ) return "$N��$p���������𣬡��١���һ������������\n";
			else if( damage < 200 ) return "$N��$p������һ���ؿ������ܵ�һ���ش�����������������\n";
			else return "$N��$p������һ����ǰһ�ڣ��������ɳ�������\n";
		}
		else
			return damage_bonus + factor;
	}
	else
		return damage;
}

int valid_learn_ob(object ob) {return 1;} //����1,�ڹ����ܺ����ѧ

varargs mixed armor_ob(object me, object victim, int damage_bonus,int force_armor, int combat_msg)
{
    if ( !living(victim) || damage_bonus < 1 ) 
		return damage_bonus;
	if ( force_armor < 0 ) force_armor = 0;
    if ( victim->query("neili") >= force_armor+damage_bonus )
	{
        if ( force_armor > damage_bonus)
		{
            victim->add("neili",-damage_bonus*2);
            return BOLD "$p��"+to_chinese(victim->query_skill_mapped("force"))+"�Ļ�������������$N���˺���\n" NOR;
        }
		else
		{
			if ( combat_msg < 4 )
				message_vision( BOLD "$p�߶�"+to_chinese(victim->query_skill_mapped("force"))+"�Ļ���������ͼ����$N���˺���\n" NOR,me,victim);
            victim->add("neili",-(force_armor/3)*2);
            return damage_bonus-force_armor;
        }
	}
	return damage_bonus;
}
