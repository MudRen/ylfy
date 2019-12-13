// ----/cmds/skill/practice.c ----

// practice.c   	

int help(object me);

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object where = environment(me);
	string skillname, skill_name;
	int skill, skill_basic, skill_add, addtime, is_int;
	
	seteuid(getuid());
	
	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
	
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	
	if( environment(me)->query("no_fight") )
		return notify_fail("�������Ƿ�֮�أ����ɾ������������ˣ����߰ɣ�\n");

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
    
	if (me->query("potential") < 1000)
        return notify_fail("���Ǳ�ܲ����ˡ�\n");
	
	if ( me->query("neili") < 0 )
	{
		me->set("neili", 0);
		return notify_fail("����������㡣\n");
	}

	if( !arg ) 
		return help(me);
	
	if( !stringp(skillname = me->query_skill_mapped(arg)) || arg == "parry" )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	skill_add = (skill_basic+skill)/2;
	is_int = me->query("int");
	is_int *= 100;
	skill_add += is_int;
	
	if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
	
	if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	
	if( skill_basic <= skill )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
	
	notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
	
	if( SKILL_D(skillname)->practice_skill(me) )
	{
		if ( me->query_exp_times() > 1 ) addtime = 2;
		else addtime = 1;

		/*if (skill >= SKILL_D(skillname)->practice_level())
			me->improve_skill(skillname, (skill_add/5 +1)*addtime, skill_basic > skill? 0: 1);
		else*/
			me->improve_skill(skillname, (skill_add/5 +1)*addtime, 1);//ԭ�ǳ�5 

		if(!me->query("env/block_lian_msg") && skill_name = SKILL_D(skillname)->query_skill_name(skill))
			printf(HIW"��������ϰ" + to_chinese(skillname) + "���ԡ�%s����һ���ƺ���Щ�ĵá�\n"NOR, skill_name);
		else
			printf(HIW"��������ϰ" + to_chinese(skillname) + "���ƺ���Щ�ĵá�\n"NOR);
		me->add("potential", -5);
		//write( HIY "���" + to_chinese(skillname) + "�����ˣ�\n" NOR);
		return 1;
	}
	else 
		return 0;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��practice <��������>
���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�
�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
        );
        return 1;
}

