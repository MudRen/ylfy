// ȫ�µ����ģʽ By Wenwu on 2005.10.21

// ����ӵ���С�ȼ�
#define MIN_TEAM_LEVEL 1
#include <liebiao.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object *team, ob;
	string name, team_name, msg, id;
	float exp;
	int lvl, i;
	if ( me->is_busy() ) return notify_fail("��������æ�ţ������Ȱ����ϵ�����������˵��\n");
	// �ǻ�Ա������������
//	if ( !stringp(me->query("xy_huiyuan")) || !sscanf(me->query("xy_huiyuan"), "%*s��%*s��%*s��") )
//		return notify_fail(HIY"ֻ�л�Ա����ʹ����ӹ��ܡ�\n"NOR);

	name = me->query_temp("xyzx_team/name");
	
	// ��ѯ������Ϣ
	if ( !arg )
	{
		if ( !stringp(name) ) return notify_fail("��Ŀǰ��û�к�����ӣ��޷���ѯ������Ϣ��\n");
		if ( !stringp(msg = TEAMD->more_team_list(me)) )
			return notify_fail("��Ŀǰ��û�к�����ӣ��޷���ѯ������Ϣ��\n");
		if ( msg == "" ) return notify_fail("��Ŀǰ��û�к�����ӣ��޷���ѯ������Ϣ��\n");
		
		write(msg);
		return 1;
	}

	// ��������
	if ( sscanf(arg, "found %s", team_name) == 1 )
	{
		if ( stringp(name) ) 
			return notify_fail("��Ŀǰ����������У�ֻ���������˲��ܴ����µĶ��顣\n");

		i = strlen(team_name);

		if ( i < 4 ) return notify_fail("������������Ҫ���������ĺ�����ɡ�\n");
		if ( i > 10 ) return notify_fail("�����������ֻ����������ĺ�����ɡ�\n");

		while ( i-- )
		{
			if ( team_name[i]<=' ' ) return notify_fail("�������Ʋ���ʹ�ÿ�����Ԫ��\n");
			if ( i % 2 == 0 && !is_chinese(team_name[i..<0]) ) 
				return notify_fail("�������Ʊ��������ġ�\n");
		}

		exp = to_float(LEVUP_EXP)*me->query("xyzx_sys/level")+me->query("xyzx_sys/levup_exp")+me->query("combat_exp");
		lvl = to_int(exp / LEVUP_EXP);
              
		if ( lvl < MIN_TEAM_LEVEL )      
			return notify_fail("ֻ������ȼ��ﵽһ�����ϣ�����ʵս����ﵽ"+LEVUP_EXP+"���ϣ��ſ��Դ������顣\n");
                 
		if ( !TEAMD->found_team(me, team_name) )
			return notify_fail("������������Ѿ��������ˣ����޷�����������ƴ������顣\n");
	
		message_vision(HIG"$N�ɹ�������һ֧���飺"HIY+team_name+"\n"NOR, me);
		me->start_busy(3);
		return 1;
	}
	else
		if ( arg == "found" ) return notify_fail("��������ָ���ʽ��"HIY"team found ��������\n"NOR);

	// ת�öӳ�
	if ( sscanf(arg, "rang %s", id) == 1 )
	{
		if ( !stringp(name) ) return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		if ( !me->query_temp("xyzx_team/zhang") ) return notify_fail("�����ڲ����Ƕӳ����޷����жӳ�ת�á�\n");
		if ( !objectp(ob = find_player(id)) ) return notify_fail("����Ѷӳ�ת�ø�˭��\n");

		team = TEAMD->get_team_member(me);
		if ( member_array(ob, team) == -1 ) return notify_fail("��Ķ����в�û�������Ա��\n");

		if ( ob == me ) return notify_fail("ת�ø��Լ������ⲻ��û��������Ϲæ����\n");

		me->delete_temp("xyzx_team/zhang");
		ob->set_temp("xyzx_team/zhang", 1);
		//____________________����IP������____________________
		// �������ϵͳ IP ������ز���
		VRM_SERVER->make_check_user(me, 2);
		// ���Ӹ���ϵͳ IP ������ز���
		if ( !VRM_SERVER->valid_place_name(name) )
			VRM_SERVER->make_check_user(ob, 1);
		//________________________ End _________________________
		team = filter_array( users(), "team_listener", this_object(), name );
		message("party", HIY"��"+name+"��"HIW+me->query("name")+"("+me->query("id")+") "HIM"�Ѷӳ�ְ֮ת�ø��� "HIW+ob->query("name")+"("+ob->query("id")+")"+HIM" ��\n"NOR, team);
		return 1;
	}
	
	// ��һ����Ա�߳�����
	if ( sscanf(arg, "out %s", id) == 1 )
	{
		if ( !stringp(name) ) return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		if ( !me->query_temp("xyzx_team/zhang") ) return notify_fail("ֻ�жӳ�����Ȩ�����˳��ӡ�\n");
		if ( !objectp(ob = find_player(id)) ) return notify_fail("�����˭�߳����飿\n");

		team = TEAMD->get_team_member(me);
		if ( member_array(ob, team) == -1 ) return notify_fail("�����в�û�������Ա��\n");

		if ( ob == me )
		{
			message_vision("���ڶӳ�("HIY"$N"NOR")��ӣ�����("HIY+name+NOR")��ɢ�ˡ�\n", me);
			team = filter_array( users(), "team_listener", this_object(), name );
			message("party", HIY"��"+name+"��"HIM+"���ڶӳ� "HIW+me->query("name")+"("+me->query("id")+") "HIM"��ӣ������ɢ�ˡ�\n"NOR, team);
		}
		else
			message_vision("$N��$n�Ӷ���("HIY+name+NOR")�����˳�ȥ��\n", me, ob);

		if ( !TEAMD->del_team_member(ob) ) return notify_fail("�����в�û�������Ա��\n");

		return 1;
	}
	else if ( arg == "out" ) // �뿪����
	{
		if ( me->query_temp("xyzx_team/zhang") )
		{
			 message_vision("$N������("HIY+name+NOR")��ɢ�ˡ�\n", me);
			 team = filter_array( users(), "team_listener", this_object(), name );
			 message("party", HIY"��"+name+"��"HIM+"�ӳ� "HIW+me->query("name")+"("+me->query("id")+") "HIM"�������ɢ�ˡ�\n"NOR, team);
		}
		else if ( stringp(name) )
			message_vision("$N�����˶���("HIY+name+NOR")��\n", me);
		
		if ( !TEAMD->del_team_member(me) ) return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		
		return 1;
	}

	// ���ζ��鹲����佱����Ϣ
	if ( arg == "block" )
	{
		if ( !stringp(name) ) return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		if ( me->query_temp("xyzx_team/block") ) return notify_fail("�����ڲ�û�н������齱������������Ϣ��\n");

		me->set_temp("xyzx_team/block", 1);
		write("�������˶��齱������������Ϣ��\n");
		return 1;
	}

	// �������鹲����佱����Ϣ
	if ( arg == "listen" )
	{
		if ( !stringp(name) ) return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		if ( !me->query_temp("xyzx_team/block") ) return notify_fail("�����ڲ�û�����ζ��齱������������Ϣ��\n");

		me->delete_temp("xyzx_team/block");
		write("�㿪ʼ�������齱������������Ϣ��\n");
		return 1;
	}

	// ����������
	if ( sscanf(arg, "yaoqing %s", id) == 1 )
	{
		if ( !stringp(name) ) return notify_fail("�����������鶼û����Ҫ�����˶���������ն�Ա��\n");
		if ( !me->query_temp("xyzx_team/zhang") ) return notify_fail("ֻ�жӳ�����Ȩ�����ճ�Ա��\n");
		if ( !objectp(ob = present(id, environment(me))) 
			|| !living(ob) 
			|| !ob->is_character() 
			|| ob==me )
			return notify_fail("��������˭������Ķ��飿\n");

		if ( me->is_fighting() || ob->is_fighting() )
			return notify_fail("ս��״̬���޷���ӡ�\n");

		team = TEAMD->get_team_member(me);
		if ( member_array(ob, team) != -1 ) return notify_fail(ob->query("name")+"�Ѿ�����Ķ�Ա�ˡ�\n");
		if ( ob->query_temp("xyzx_team/name") ) return notify_fail(ob->query("name")+"�Ѿ��ж����ˡ�\n");
		if ( sizeof(team) > 9 ) return notify_fail("����������\n");

		if ( ob->query_temp("team_shenqing") == me->query("id") )
		{
			ob->delete_temp("team_shenqing");
			ob->delete_temp("team_yaoqing");

			if ( !TEAMD->add_team_member(me, ob) )
				message_vision("$N����ȼ�����һ����ʵս����Ҳ����"+LEVUP_EXP+"���޷�����$n�Ķ���("HIY+name+NOR")��\n", ob, me);
			else
				message_vision("$N�ɹ��ؼ�����$n�Ķ���("HIY+name+NOR")��\n", ob, me);
		}
		else
		{
			ob->set_temp("team_yaoqing", me->query("id"));
			message_vision("$N����$n�������("HIY+name+NOR")��\n", me, ob);
		}
		return 1;
	}
	else if ( arg == "yaoqing" ) return notify_fail("��������˭������Ķ��飿\n");

	// ����������
	if ( sscanf(arg, "jiaru %s", id) == 1 )
	{
		if ( !objectp(ob = present(id, environment(me))) 
			|| !living(ob) 
			|| !ob->is_character() 
			|| ob==me )
			return notify_fail("�����������˭�Ķ��飿\n");
		if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) 
			return notify_fail("��(��)�������Լ�����û�ж��顣\n");
		if ( !ob->query_temp("xyzx_team/zhang") ) return notify_fail("��(��)�����Ƕӳ����޷���ȡ����ӡ�\n");
		if ( me->is_fighting() || ob->is_fighting() )
			return notify_fail("ս��״̬���޷���ӡ�\n");

		team = TEAMD->get_team_member(ob);
		if ( member_array(me, team) != -1 ) return notify_fail("���Ѿ����������Ķ�Ա�ˡ�\n");
		if ( me->query_temp("xyzx_team/name") ) 
			return notify_fail("���Ѿ��ж����ˣ�������ӱ�Ķ����ȵ�����Ŀǰ�Ķ��顣\n");
		if ( sizeof(team) > 9 ) return notify_fail("����("HIY+ob->query_temp("xyzx_team/name")+NOR")�Ѿ���Ա�ˡ�\n");

		if ( me->query_temp("team_yaoqing") == ob->query("id") )
		{
			me->delete_temp("team_shenqing");
			me->delete_temp("team_yaoqing");

			if ( !TEAMD->add_team_member(ob, me) )
				message_vision("$N����ȼ�����һ����ʵս����Ҳ����"+LEVUP_EXP+"���޷�����$n�Ķ���("HIY+name+NOR")��\n", me, ob);
			else
				message_vision("$N�ɹ��ؼ�����$n�Ķ���("HIY+name+NOR")��\n", me, ob);
		}
		else
		{
			me->set_temp("team_shenqing", ob->query("id"));
			message_vision("$N�������$n�Ķ���("HIY+name+NOR")��\n", me, ob);
		}
		return 1;
	}
	else if ( arg == "jiaru" ) return notify_fail("�����������˭�Ķ��飿\n");

	// ����
	if ( sscanf(arg, "talk %s", msg) == 1 )
	{
		if ( !stringp(name = me->query_temp("xyzx_team/name")) ) 
			return notify_fail("�����ڲ�û�вμ��κζ��顣\n");

		team = filter_array( users(), "team_listener", this_object(), name );
		message("party", HIY"��"+name+"��"+me->query("name")+"("+me->query("id")+")"+HIW"��"+ msg + "\n"NOR, team);
		return 1;
	} else if ( arg == "talk" )
	{
		if ( !stringp(name = me->query_temp("xyzx_team/name")) ) 
			return notify_fail("�����ڲ�û�вμ��κζ��顣\n");

		team = filter_array( users(), "team_listener", this_object(), name );
		message("party", HIY"��"+name+"��"+me->query("name")+"("+me->query("id")+")"+HIW"��...\n"NOR, team);
		return 1;
	}

	// �ı����ģʽ
	if ( sscanf(arg, "change %s", msg) == 1 )
	{
		TEAMD->change_allot_type(me, msg);
		return 1;
	}

	help(me);
	return 1;
}

int team_listener(object ppl, string str)
{
	if ( !objectp(ppl) ) return 0;
	if ( !objectp(environment(ppl)) ) return 0;
	if ( wizardp(ppl) || ppl->query_temp("xyzx_team/name") == str )
		return 1;
	else
		return 0;
}

int help(object me)
{
write( @HELP
����ָ��ʹ�÷���:
------------------------------------------------------------------------
team found   <����>    - ����һ�����飬�������Լ��Ƕӳ���������������ӡ�
team rang    <����>    - ���������ӰѶӳ�ְ֮ת�ø������е�������Ա��
team yaoqing <����>    - �öӳ�����ʹ�ø�ָ������������Ҽ�������顣
team jiaru   <����>    - ���������һ������Ķӳ�������ӡ�
team out     <����>    - ����Ķӳ����԰�һ����Ա�߳����飬����Լ��߳�
                         ���������鱻��ɢ��
team out               - �뿪����. ���´�ָ��������, ������������ɢ��
team talk    <ѶϢ>    - ����������������̸��, ������ tt <ѶϢ> �����
team block             - ������ö��齱������������Ϣ�ȽϷ��ˣ���ô��
                         ���������ָ��������ε���
team listen            - ������Ѿ������˶��齱������������Ϣ��������
                         �������½������齱�����������Ϣ��ô��Ϳ�����
                         ���ָ����ʵ���ˡ�
team change <����ģʽ> - ���ķ���ģʽ����֧�ֵķ���ģʽ�У�ƽ������ģʽ
                         (average) �� ���յȼ����������ģʽ(level)��
ֱ���� team ָ��ʱ�����ʾ��Ŀǰ�Ƿ��м�����鼰��Ա������
 
�����[Ϧ������-������ӡ]��һ����ɫϵͳ:������֮��,���ж�Ա��Ϊһ��,��
��ˢ����(fight)�⣬����������(quest)������ɱnpc�����������еĶ�Ա��õĽ�
�����ȵ������Ҫ�߳���࣬�����ܸ߶����Ǹ��ݶ����ڶ�Ա��Ŀ�������ģ����
��˵�����ԱԽ�����ý����ӳɾ�Խ�ߣ�����������ý��������Ǽ򵥵�ƽ������
�ģ����Ǹ��ݶ�Ա����ߵͰ��վ���ߵĶ�á�����͵���ȡ��ԭ��������ġ�Ŀ
ǰÿ��������������10����Ա������ÿ����һ����Ա�����ӳɾͻ��10%��
------------------------------------------------------------------------
HELP);
	return 1;
}
