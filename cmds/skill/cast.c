// perform.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object weapon;
    mapping smap;
    string martial, skill, str;
    
    seteuid(getuid());
    
    smap = me->query_skill_map();
    if((int)me->query_temp("no_cast")==1)	
return notify_fail("�����ڲ�����ħ����\n");	
    if( me->is_busy() )
       return notify_fail("( ����һ��������û����ɣ����������ġ�)\n");
if ((int)me->query_temp("in_qingwang")==1)	
return notify_fail(MAG"����ǰ�����Ǹ���Ϥ����Ӱ���������ķ���������飬�����ϣ����ҡ�\n"NOR);
if( !wizardp(me) && environment(me)->query("no_fight") )	
return notify_fail("���ﲻ׼�����ġ�\n");		
    if( !arg ) return notify_fail("��Ҫ��������ʲ�᣿\n");
    if( sscanf(arg, "%s.%s", martial, str)!=2 ) {
        str=arg;
        if( weapon = me->query_temp("weapon") )
            martial = weapon->query("skill_type");
        else martial = "unarmed";
    }
    if( stringp(skill = me->query_skill_mapped(martial)) ) {
	if (file_size(SKILL_D(skill)->cast_action_file(str)+".c")>0){
        notify_fail("����ѧ�ķ�����û�����ֹ��ܡ�\n");	
        if( SKILL_D(skill)->perform_action(me, str) ) {
            if( random(120) < (int)me->query_skill(skill) )
                me->improve_skill(skill, 1, 1);
            return 1;
        } else if( SKILL_D(martial)->cast_action(me, str) ) {
            if( random(120) < (int)me->query_skill(martial, 1) )
                me->improve_skill(martial, 1, 1);
            return 1;
        }
        return 0;
	}
    }
    if( sscanf(arg, "%s.%s", martial, str)!=2 ) {
        str=arg;
        if( weapon = me->query_temp("secondary_weapon") )
            martial = weapon->query("skill_type");
        else martial = "unarmed";
    }
    if( stringp(skill = me->query_skill_mapped(martial)) ) {
       notify_fail("����ѧ�ķ�����û�����ֹ��ܡ�\n");	
        if( SKILL_D(skill)->cast_action(me, str) ) {
            if( random(120) < (int)me->query_skill(skill) )
                me->improve_skill(skill, 1, 1);
            return 1;
        } else if( SKILL_D(martial)->cast_action(me, str) ) {
            if( random(120) < (int)me->query_skill(martial, 1) )
                me->improve_skill(martial, 1, 1);
            return 1;
        }
        return 0;
    }
    return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ�����ϵ��\n");	
}
int help (object me)
{
        write(@HELP
ָ���ʽ��cast <��������> [<ʩ�ö���>]
ʩ���������Ҫָ��<��������>��<ʩ�����>����п��ޡ�	
����ʹ��ĳһ������֮ǰ����������� enable ָ����ָ����Ҫʹ�õ�����ϵ��
HELP
        );
        return 1;
}
