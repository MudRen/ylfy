// �Ŷ�ϵͳ By Wenwu

// Ԥ�����ڴ��ӳ��
// #define FORE_MAPPING_MEM 15
// ����ӵ���С�ȼ�
#define MIN_TEAM_LEVEL 1
// �Ŷӽ����ӳ�ʮ��֮TEAM_LIST_ADD
#define TEAM_LIST_ADD 1
// ÿ���������������Ա��
#define MAX_TEAM_MEMBER 10

#include <ansi.h>

inherit F_DBASE;

// �Ŷ�ӳ��
static mapping user_team = ([]);
// �����������
static mapping team_allot_type = ([]);
// �ɹ������Ľ�����Ŀ
static string *team_share = ({"combat_exp", "potential"});
// �ɹ�����佱����Ŀ�Ķ�Ӧ����
static mapping team_share_chinese = ([
	"combat_exp" : "ʵս����",
	"potential"  : "Ǳ��"
	]);
// �ɸ��ĵķ���ģʽ����
static mapping team_allot_type_chinese = ([ 
	"average" : "ƽ������",
	"level"   : "�ȼ�����"
	]);
// ���ӳٵ���ʱ�˳���������Ҷ���
nosave object *exit_duplicate_user = ({});

// �ڲ�ʹ�ú���
int team_listener(object ppl, string str); // ���ն�����Ϣ�Ķ��󼯺�
void remove(); // ��������
int is_change_allot_type(string type); // �Ƿ�֧�ָ��Ķ������ģʽ
// �ⲿʹ�ú���
int found_team(object ob, string name); // ��������
int add_team_member(object me, object ob); //���ӳ�Ա
int del_team_member(object ob); // ɾ����Ա
string more_team_list(object ob); // �鿴������Ϣ
int team_add(object ob, string prop, mixed data); // �Ŷӹ�����䡢�ӳ�
int change_allot_type(object ob, string type); // ���Ķ������ģʽ
// ���ú���
int query_team_share(object ob, string prop); // �Ƿ����������
object *get_team_member(mixed ob); // ��ȡһ���������г�Ա
string get_allot_type(string name); // ȡ�ö������ģʽ����ת����������ʾ
int check_team_vip(mixed ob); // ���������Ƿ�ȫ�ǻ�Ա��
object get_team_leader(mixed ob); // ȡ�ö����еĶӳ�

void create()
{
	seteuid( ROOT_UID );
	set("channel_id","�Ŷ�ϵͳ");
	CHANNEL_D->do_channel( this_object(), "sys", HIM"�Ŷ�ϵͳ�Ѿ�������\n"NOR);
	set_heart_beat(150);
}

// ����һ������
int found_team(object ob, string name)
{
	//float exp;
	int lvl;

	if ( !name ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !interactive(ob) ) return 0;
	if ( !mapp(user_team) ) return 0;
	if ( user_team[name] ) return 0;
	if ( ob->query_temp("xyzx_team/name") ) return 0;
	
	/*exp = to_float(LEVUP_EXP) * ob->query("xyzx_sys/level") + 
		ob->query("xyzx_sys/levup_exp") + ob->query("combat_exp");
	lvl = to_int(exp / LEVUP_EXP);*/
	lvl = ob->query("xyzx_sys/level");

	if ( lvl < MIN_TEAM_LEVEL ) return 0;

	// ����ʽ��������ʱ����Ԥ������һ���ڴ�
	// ����Ч�ʻ�Ƚϸߣ����������Ƕ�̬����ռ��Cpu
	// if ( !sizeof(user_team) )
		// user_team = allocate_mapping( FORE_MAPPING_MEM );
	// ����һ������ӳ��
	user_team[name] = ({ ob });
	// �����������״̬����
	/////////////////////////////////////////////////////////
	ob->set_temp("xyzx_team/name", name); // ��������
	ob->set_temp("xyzx_team/zhang", 1); // �ӳ���־
	ob->set_temp("xyzx_team/lvl", lvl); // �ܵĵȼ�
	ob->set_temp("xyzx_team/max_lvl", lvl); // ���г�Ա�ȼ���
	/////////////////////////////////////////////////////////
	//message("party", HIY"������ˮ�¡�"HIW+ob->query("name")+"("+ob->query("id")+")"HIM" ������һ֧����: "HIG+name+HIM" ��\n"NOR, users());
	tell_room(environment(ob), HIY"������ˮ�¡�"HIW+ob->query("name")+"("+ob->query("id")+")"HIM" ������һ֧����: "HIG+name+HIM" ��\n"NOR);
	change_allot_type(ob, "average"); // Ĭ�Ϸ���ģʽΪ��ƽ������
	return 1;
}

// ����һ�������Ա
int add_team_member(object me, object ob)
{
	string name, type;
	object *team_user;
	//float exp;
	int i, lvl, team_size;

	if ( !objectp(me) || !objectp(ob) ) return 0;
	if ( !interactive(me) || !interactive(ob) ) return 0;
	if ( !mapp(user_team) ) return 0;
	if ( !sizeof(user_team) ) return 0;
	if ( ob->query_temp("xyzx_team/name") ) return 0;
	if ( !me->query_temp("xyzx_team/zhang") ) return 0;

	// ȡ�ö�������
	name = me->query_temp("xyzx_team/name");
	
	if ( !arrayp(user_team[name]) ) return 0;

	/*exp = to_float(LEVUP_EXP) * ob->query("xyzx_sys/level") + 
		ob->query("xyzx_sys/levup_exp") + ob->query("combat_exp");
	lvl = to_int(exp / LEVUP_EXP);*/
	lvl = ob->query("xyzx_sys/level");

	if ( lvl < MIN_TEAM_LEVEL ) return 0;

	// ���ӳ�Ա���
	/////////////////////////////////////////////////////////
	team_user = user_team[name];
	team_size = sizeof(team_user);

	if ( team_size >= MAX_TEAM_MEMBER ) return 0;

	team_user += ({ ob });
	user_team[name] = team_user;
	/////////////////////////////////////////////////////////
	// ���¸���Ա����״̬����
	/////////////////////////////////////////////////////////
	ob->set_temp("xyzx_team/name", name); // ��������
	ob->set_temp("xyzx_team/lvl", lvl); // �ܵĵȼ�
	team_size = sizeof(team_user);
	for ( i = 0, lvl = 0; i < team_size; i++ )
	{
		if ( objectp(team_user[i]) )
			lvl += team_user[i]->query_temp("xyzx_team/lvl"); // ȡ�����г�Ա�ȼ���
	}
	for ( i = 0; i < team_size; i++ )
	{
		if ( objectp(team_user[i]) )
			team_user[i]->set_temp("xyzx_team/max_lvl", lvl); // ���г�Ա�ȼ���
	}
	/////////////////////////////////////////////////////////
	team_user = filter_array( users(), "team_listener", this_object(), name );
	if ( !check_team_vip(me) ) 
	{ // ������ȫ����ѻ�Ա���������ģʽΪ��ƽ��
		change_allot_type(me, "average");
		type = get_allot_type(name);
		message("party", HIY"��"+name+"��"HIW"���ڶ����ж�����ͨ��ң�����ģʽǿ�Ƹ���Ϊ��"HIC+type+HIW""NOR, team_user);
	}
	type = get_allot_type(name);
	message("party", HIY"��"+name+"��"HIM"�³�Ա "HIW+ob->query("name")+"("+ob->query("id")+")"+HIM" �����˶��飬Ŀǰ�������ģʽΪ��"HIC+type+HIM"��\n"NOR, team_user);
	return 1;
}

// ɾ��һ�������Ա
int del_team_member(object ob)
{
	string name, type;
	object *team_user, room, leader, *show_user;
	int i, lvl, team_size, duizhang, flag, del_ip;

	if ( !objectp(ob) ) return 0;
	if ( !mapp(user_team) ) return 0;
	if ( !sizeof(user_team) ) return 0;
	if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) return 0;
	if ( !arrayp(user_team[name]) ) return 0;

	team_user = user_team[name];

	if ( member_array(ob, team_user) == -1 ) return 0;

	name = ob->query_temp("xyzx_team/name");
	duizhang = ob->query_temp("xyzx_team/zhang");

	switch ( duizhang )
	{
		// ����Ƕӳ��뿪�������������鱻��ɢ
		/////////////////////////////////////////////////////////////////////
		case 1:
				map_delete(user_team, name);
				map_delete(team_allot_type, name);
				team_size = sizeof(team_user);
				flag = 0;
				del_ip = 0;
				for ( i = 0; i < team_size; i++ )
				{
					if ( objectp(team_user[i]) )
					{
						// ������ĳ�Ա�ƶ���������Сʱ�ڽ�ֹ�ٽ��븱��
						if ( !VRM_SERVER->valid_place_name(name) )
						{
							// �������ϵͳ IP ������ز���
							if ( !del_ip )
							{
								VRM_SERVER->make_check_user(ob, 2);
								del_ip = 1;
							}
							// ���ж�Ա�˳�����
							if ( virtualp(environment(team_user[i])) )
							{
								if ( !flag )
								{
									show_user = filter_array(users(), "team_listener", this_object(), name);
									message("party", HIM"��"HIG"��������"HIM"��"HIW"���� "HIC+name+HIW" ��ʼ�˳�������\n"NOR, show_user);
									flag = 1;
								}
								if ( !wizardp(team_user[i]) && virtualp(environment(ob)) )
									team_user[i]->set("vrm_in_busy", time() + 900);
								room = find_object("/d/city/wumiao");
								if ( !room ) room = load_object("/d/city/wumiao");
								// ս����busy���޷������˳�����
								//_____________________________________________________________________
								if ( !team_user[i]->is_fighting() && !team_user[i]->is_busy() )
								{
									tell_object(team_user[i], "�㿪ʼ�뿪������\n");
									team_user[i]->move(room);
								}
								else
								{ // ������У��ӳٴ���
									if ( !arrayp(exit_duplicate_user) ) exit_duplicate_user = ({ });
									if ( member_array(team_user[i], exit_duplicate_user) == -1 )
										exit_duplicate_user += ({ team_user[i] });
								}
							}
							//______________________________________________________________________
						}
						team_user[i]->delete_temp("xyzx_team");
					}
				}
				// ɾ��������ͼ
				VRM_SERVER->delete_team_place(name);
				break;
		/////////////////////////////////////////////////////////////////////
		default:
				ob->delete_temp("xyzx_team"); // ����������״̬����
				// ���Ŷ���ɾ��һ����Ա�������¸������г�Ա���״̬����
				/////////////////////////////////////////////////////////////////////////////////
				team_user -= ({ ob });
				user_team[name] = team_user;
				team_size = sizeof(team_user);
				for ( i = 0, lvl = 0; i < team_size; i++ )
				{
					if ( objectp(team_user[i]) )
						lvl += team_user[i]->query_temp("xyzx_team/lvl"); // ȡ�����г�Ա�ȼ���
				}
				for ( i = 0; i < team_size; i++ )
				{
					if ( objectp(team_user[i]) )
						team_user[i]->set_temp("xyzx_team/max_lvl", lvl); // ���г�Ա�ȼ���
				}
				// �˳�����
				if ( !VRM_SERVER->valid_place_name(name) && virtualp(environment(ob)) )
				{
					show_user = filter_array(users(), "team_listener", this_object(), name);
					message("party", HIM"��"HIG"��������"HIM"��"HIW"���� "HIC+name+HIW" ��Ա "HIY+ob->name(1)+HIW" ��ʼ�˳�������\n"NOR, show_user);
					if ( !wizardp(ob) )
						ob->set("vrm_in_busy", time()+1800);
					room = find_object("/d/city/wumiao");
					if ( !room ) room = load_object("/d/city/wumiao");
					// ս����busy���޷������˳�����
					//_____________________________________________________________________
					if ( !ob->is_fighting() && !ob->is_busy() ) 
					{
						tell_object(ob, "�㿪ʼ�뿪������\n");
						ob->move(room);
					}
					else
					{ // ������У��ӳٴ���
						if ( !arrayp(exit_duplicate_user) ) exit_duplicate_user = ({ });
						if ( member_array(ob, exit_duplicate_user) == -1 )
							exit_duplicate_user += ({ ob });
					}
					//______________________________________________________________________
				}
				/////////////////////////////////////////////////////////////////////////////////
	}
	
	team_user = filter_array( users(), "team_listener", this_object(), name );
	message("party", HIY"��"+name+"��"HIM"��Ա "HIW+ob->query("name")+"("+ob->query("id")+")"+HIM" �˳��˶��顣\n"NOR, team_user);
	if ( !duizhang )
	{ // ��Ա�뿪���飬������ģʽ
		if ( !check_team_vip(name) ) 
		{ // ������ȫ����ѻ�Ա���������ģʽΪ��ƽ��
			if ( leader = get_team_leader(name) )
			{ // ��öӳ�
				change_allot_type(leader, "average"); // �ı����ģʽΪ��ƽ��
				type = get_allot_type(name);
				message("party", HIY"��"+name+"��"HIW"���ڶ����ж�����ѻ�Ա������ģʽǿ�Ƹ���Ϊ��"HIC+type+HIW""NOR, team_user);
			}
		}
	}
	return 1;
}

// �鿴�����Ա
string more_team_list(object ob)
{
	string msg, str, name, arg, type;
	object *team_user, room;
	int i, lvl, max_lvl, team_size;

	msg = "";

	if ( !objectp(ob) ) return msg;
	if ( !interactive(ob) ) return msg;
	if ( !objectp(environment(ob)) ) return msg;
	if ( !mapp(user_team) ) return msg;
	if ( !sizeof(user_team) ) return msg;
	if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) return msg;
	if ( !arrayp(user_team[name]) ) return msg;
	
	type = get_allot_type(name);
	team_user = user_team[name];
	team_size = sizeof(team_user);

	msg = sprintf(HIY"��%s��"NOR"������Ϣ����Ա "HIG"%s"NOR" �ˣ��Ŷӹ�����Դ��ȡ���� "HIY"%s"NOR" ��\n"NOR, 
		name, sprintf(HIG"%d"NOR" / "HIY"%d"NOR, team_size, MAX_TEAM_MEMBER), sprintf("%d %s", check_team_vip(ob)?((team_size-1)*10+100):100, "%") );
	msg += "------------------------------------------------------------------------------\n";
	msg += sprintf("%-8s%-30s %-12s %-4s %-8s %-12s\n", " ", "��Ա����", "��ȡ�ֳ�", "��Ϣ", "����ģʽ", "����λ��");
	msg += "------------------------------------------------------------------------------\n";

	for ( i = 0; i < team_size; i++ )
	{
		lvl = team_user[i]->query_temp("xyzx_team/lvl");
		max_lvl = team_user[i]->query_temp("xyzx_team/max_lvl");
		name = team_user[i]->query("name")+"("+team_user[i]->query("id")+")";
		if ( type == team_allot_type_chinese["average"] )
			str = sprintf(GRN"%-5d"NOR"/"YEL"%-6d"NOR, 1, team_size);
		else
			str = sprintf(GRN"%-5d"NOR"/"YEL"%-6d"NOR, lvl, max_lvl);
		if ( !objectp(room = environment(team_user[i])) ) continue;
		if ( team_user[i]->query_temp("xyzx_team/block") )
			arg = HIR"�ܾ�"NOR;
		else
			arg = HIG"����"NOR;
		if ( team_user[i]->query_temp("xyzx_team/zhang") )
			msg += sprintf("%-8s%-30s %-12s %-4s %-8s %-12s\n", HIY"���ӳ���"NOR, name, str, arg, HIC+type+NOR, room->query("short"));
		else
			msg += sprintf("%-8s%-30s %-12s %-4s %-8s %-12s\n", HIG"����Ա��"NOR, name, str, arg, HIC+type+NOR, room->query("short"));
	}

	msg += "------------------------------------------------------------------------------\n";
	return msg;
}

// �Ŷӽ����ӳɣ������Ŷ������ӳɽ�����
int team_add(object ob, string prop, mixed data)
{
	object *team_user, room, env;
	string name;
	int i, lvl, max_lvl, team_size, v, vv;

	if ( !stringp(prop) || !intp(data) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !objectp(ob) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( data < 1 )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !objectp(room = environment(ob)) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( room->query("no_fight") )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !mapp(user_team) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !sizeof(user_team) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !stringp(name = ob->query_temp("xyzx_team/name")) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	if ( !arrayp(team_user=user_team[name]) )
	{
		ob->add(prop, data, 1);
		return 1;
	}
	
	team_size = sizeof(team_user);
	if ( check_team_vip(ob) ) // �������л�Ա���мӳ�
		v = (10 + TEAM_LIST_ADD * (team_size - 1)) * data / 10;
	else // �����޼ӳ�
		v = data;

	for ( i = 0; i < team_size; i++ )
	{
		if ( mapp(team_allot_type) && team_allot_type[name]=="average" )
		{
			// ƽ������ģʽ
			vv = v/team_size;
		}
		else
		{
			lvl = team_user[i]->query_temp("xyzx_team/lvl");
			max_lvl = team_user[i]->query_temp("xyzx_team/max_lvl");
		//	vv = atoi(count(count(v,"*",lvl), "/", max_lvl));
			vv = v * lvl / max_lvl;

		}
		
		if ( vv < 1 ) continue;
		if ( !objectp(env = environment(team_user[i])) ) continue;
		if ( (virtualp(room) && !virtualp(env))
			|| (!virtualp(room) && virtualp(env)) )
			continue;
		if ( (domain_file(base_name(room))=="party" && domain_file(base_name(env))!="party") 
			|| (domain_file(base_name(env))=="party" && domain_file(base_name(room))!="party") )
			continue;
		if ( domain_file(base_name(room)) != domain_file(base_name(env)) )
			continue;
		// ������ս���ĵط����־���
		if ( env->query("no_fight") ) continue;
		// ɱ�˷����־���
		if ( team_user[i]->query_condition("killer") ) continue;
		// ��ѻ�Ա���־���
		// if ( !team_user[i]->query("xyhy_type") ) continue;
		//����ͬһ�����䲻�־���
	    if(environment(ob) != env) continue;
		//������ս�����־���
	    if(ob->is_fighting() && !team_user[i]->is_fighting()) continue;
		//��Ա��ˢ���־���
	     if(ob->is_fighting(team_user[i]) || team_user[i]->is_fighting(ob)) continue;

		team_user[i]->add(prop, vv, 1);
		// ����ս����������Ϣ
	//	if ( !team_user[i]->is_fighting() )
	//	{
			// ��û�������θ���Ϣ������֮
			if ( !team_user[i]->query_temp("xyzx_team/block") )
			{
				if ( prop == "combat_exp" ) vv *= team_user[i]->query_exp_times();
				tell_object(team_user[i], "�����须�������� "+vv+" ��"+team_share_chinese[prop]+"��\n");
			}
	//	}
	}

	return 1;
}

// �Ƿ����������
int query_team_share(object ob, string prop)
{
	if ( !objectp(ob) ) return 0;
	if ( !ob->query_temp("xyzx_team/name") ) return 0;
	if ( !stringp(prop) ) return 0;
	if ( !arrayp(team_share) ) return 0;
	if ( member_array(prop, team_share) == -1 ) return 0;

	return 1;
}

// ��ȡһ���Ŷ����г�Ա
object *get_team_member(mixed ob)
{
	object *team_member;
	string name;

	team_member = ({});

	if ( objectp(ob) )
	{ // ���������object
		if ( !interactive(ob) ) return team_member;
		if ( !stringp(name = ob->query_temp("xyzx_team/name")) ) return team_member;
		if ( !objectp(environment(ob)) ) return team_member;
	} 
	else if ( stringp(ob) ) // ���������string
		name = ob;
	else 
		return team_member;
	if ( !mapp(user_team) ) return team_member;
	if ( !sizeof(user_team) ) return team_member;
	if ( !arrayp(team_member = user_team[name]) ) return ({});

	return team_member;
}

// ɸѡ����
int team_listener(object ppl, string str)
{
	if ( !objectp(ppl) ) return 0;
	if ( !objectp(environment(ppl)) ) return 0;
	if ( wizardp(ppl) || ppl->query_temp("xyzx_team/name") == str )
		return 1;
	else
		return 0;
}

// ��������
void remove()
{
	string *teams;
	object *team_objs;
	int i, j;

	if ( mapp(user_team) && sizeof(user_team) )
	{
		teams = keys(user_team);
		for ( i=0; i<sizeof(teams); i++ )
		{
			if ( arrayp(team_objs = user_team[teams[i]]) && sizeof(team_objs) )
			{
				for ( j=0; j<sizeof(team_objs); j++ )
				{
					del_team_member(team_objs[j]);
				}
			}
			//message("party", HIR"��"HIM"���龫��"HIR"����"HIW"�Ŷӽ��̸������ã�����("HIY+teams[i]+HIW")�ѱ��Զ���ɢ��\n"NOR, users());
			message("party", HIR"��"HIM"���龫��"HIR"����"HIW"�Ŷӽ��̸������ã�����("HIY+teams[i]+HIW")�ѱ��Զ���ɢ��\n"NOR, teams);
		}
	}

	team_allot_type = ([]);
}

// �ı�������ģʽ
int change_allot_type(object ob, string type)
{
	object *team_user;
	string team_name, *is_type, get_type;
	int i;

	if ( !mapp(team_allot_type) ) team_allot_type=([]);
	if ( !objectp(ob) || !objectp(environment(ob)) ) return 0;
	if ( !stringp(team_name=ob->query_temp("xyzx_team/name")) )
	{
		tell_object(ob, "�㻹û�ж��顣\n");
		return 0;
	}
	if ( !ob->query_temp("xyzx_team/zhang") )
	{
		tell_object(ob, "ֻ�жӳ����ܸı�������ģʽ��\n");
		return 0;
	}

	is_type = keys(team_allot_type_chinese);

	if ( !arrayp(is_type) || !sizeof(is_type) )
	{
		tell_object(ob, "Ŀǰ��Ϸ��֧�ָı�������ģʽ��\n");
		return 0;
	}
	if ( member_array(type, is_type) == -1 ) 
	{
		get_type = "";
		for ( i=0; i<sizeof(is_type); i++ )
		{
			get_type += HIY+team_allot_type_chinese[is_type[i]];
			get_type += "("HIG+is_type[i]+HIY")";
			if ( i < sizeof(is_type)-1 ) get_type += "��";
		}
		tell_object(ob, "Ŀǰ��Ϸ֧�ֵĶ������ģʽֻ�У�"+get_type+"��\n"NOR);
		return 0;
	}
	if ( team_allot_type[team_name] == type )
	{
		tell_object(ob, "�����Ŀǰ�ķ���ģʽ��Ϊ("HIY+team_allot_type_chinese[type]+NOR")������Ҫ�������趨��\n");
		return 0;
	}
	if ( !check_team_vip(ob) && type=="level" )
	{
		tell_object(ob, "��Ķ�����Ŀǰ������ѻ�Ա������ģʽֻ��Ϊ��"+team_allot_type_chinese["average"]+"��\n"NOR);
		return 0;
	}
	
	team_allot_type[team_name] = type;
	team_user = filter_array( users(), "team_listener", this_object(), team_name );
	message("party", HIY"��"+team_name+"��"HIM"�ӳ� "HIC+ob->query("name")+"("+ob->query("id")+")"+HIM" ���Ķ������ģʽΪ��"HIG
		+team_allot_type_chinese[type]+HIM"��\n"NOR, team_user);
	return 1;
}

// �Ƿ�֧�ָ��Ķ���ģʽ
int is_change_allot_type(string type)
{
	string *is_type;

	is_type = keys(team_allot_type_chinese);

	if ( !arrayp(is_type) || !sizeof(is_type) ) return 0;
	if ( member_array(type, is_type) == -1 ) return 0;

	return 1;
}

// ȡ�ö������ģʽ����ת����������ʾ
string get_allot_type(string name)
{
	string type;

	if ( !mapp(team_allot_type) ) team_allot_type=([]);
	if ( !stringp(type=team_allot_type[name]) ) 
	{
		team_allot_type[name]="level";
		type="level";
	}

	if ( !is_change_allot_type(type) ) type = "�ȼ�����";
	else type = team_allot_type_chinese[type];

	return type;
}

// ���������Ƿ��л�Ա���Ƿ��� 1�����򷵻� 0��
int check_team_vip(mixed ob)
{
	object *team_user;
	int i, max;

	if ( !arrayp(team_user=get_team_member(ob)) ) return 0;
	if ( !(max=sizeof(team_user)) ) return 0;
	for ( i=0; i<max; i++ )
	{
		if ( !objectp(team_user[i]) ) continue;
		if ( team_user[i]->query("xy_huiyuan") ) return 1; //xyhy_type
	}

	return 0;
}

// ��ȡ�����еĶӳ�
object get_team_leader(mixed ob)
{
	object *team_user;
	int i, max;

	if ( !arrayp(team_user=get_team_member(ob)) ) return 0;
	if ( !(max=sizeof(team_user)) ) return 0;
	for ( i=0; i<max; i++ )
	{
		if ( !objectp(team_user[i]) ) continue;
		if ( team_user[i]->query_temp("xyzx_team/zhang") ) return team_user[i];
	}

	return 0;
}

private void heart_beat()
{
	object env;
	int i, max;

	if ( !arrayp(exit_duplicate_user) ) exit_duplicate_user = ({ });
	if ( !(max = sizeof(exit_duplicate_user)) ) return;

	for ( i=0; i<max; i++ )
	{
		if ( !objectp(exit_duplicate_user[i]) ) continue;
		if ( !objectp(env = environment(exit_duplicate_user[i])) ) continue;
		if ( !virtualp(env) ) continue;
		if ( exit_duplicate_user[i]->is_fighting() ) continue;
		if ( exit_duplicate_user[i]->is_busy() ) continue;

		tell_object(exit_duplicate_user[i], "�㿪ʼ�뿪������\n");
		exit_duplicate_user[i]->move("/d/city/wumiao");
		exit_duplicate_user[i] = 0;
	}

	exit_duplicate_user -= ({ 0 });
}

mapping check_team_all()
{
	return user_team;
}

mapping check_team_type()
{
	return team_allot_type;
}
