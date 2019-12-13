// killerͨ�� by Wenwu

inherit F_DBASE;

nosave mapping killer_ips = ([]);
nosave string killer_list = "";

int clean_up()
{
	return 1;
}
 
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "PKͳ�ƾ���");
	CHANNEL_D->do_channel( this_object(), "sys", "PKͳ��ϵͳ�Ѿ�������\n");
	set_heart_beat(300);
}

private void heart_beat()
{
	object *user, *killer_obs;
	string ip, *killer_ip, name;
	int i, n, m, max;

	if ( !mapp(killer_ips) ) killer_ips = ([]);
	killer_ip = keys(killer_ips);
	if ( !arrayp(killer_ip) ) killer_ip = ({});
	
	user = children(USER_OB);
	max = sizeof(user);
	for ( i=0; i<max; i++ )
	{
		if ( !objectp(user[i]) ) continue;
		if ( !clonep(user[i]) ) continue;
		if ( !environment(user[i]) ) continue;
		
		ip = query_ip_number(user[i]);
		if ( !ip ) ip = user[i]->query_temp("last_ip_number");

		if ( user[i]->query_condition("killer") )
		{
			if ( ip ) 
			{
				if ( !arrayp(killer_ips[ip]) ) killer_ips[ip]=({ user[i] });
				if ( member_array(ip, killer_ip) == -1 ) killer_ip += ({ ip });
			}
			CHANNEL_D->do_channel(this_object(),"rumor","�ݿɿ���Ϣ��ɱ�˷�"+user[i]->query("name")+"["+user[i]->query("id")+"]��"+environment(user[i])->query("short")+"һ�����ܡ�\n");
		}

		if ( ip && member_array(ip, killer_ip) != -1 )
		{
			if ( !arrayp(killer_obs=killer_ips[ip]) ) killer_obs=({});
			if ( !wizardp(user[i]) && member_array(user[i], killer_obs) == -1 ) killer_obs += ({ user[i] });
			killer_obs -= ({ 0 });
			killer_ips[ip] = killer_obs;
		}
	}

	//˫������ʱ���ʱ����ҷ���ͨ��
	if ( atoi(CHINESE_D->chinese_time(9,ctime(time()))) > 19 )
		message("channel:chat", HIG"������ˮ�¡�"+HIM"���ڵ�ʱ��Ϊ "HIG+CHINESE_D->chinese_time(9,ctime(time())) + "�� "HIM"ϵͳ������˫������Ľ�����\n"NOR,users() );

	//______________________________ͨ��ɱ�˷�ȫ��ID______________________________
	killer_list = "";
	for ( n=0; n<sizeof(killer_ip); n++ )
	{
		if ( !arrayp(killer_obs=killer_ips[killer_ip[n]]) )
		{
			map_delete(killer_ips, killer_ip[n]);
			continue;
		}
		killer_obs -= ({ 0 });
		if ( !sizeof(killer_obs) )
		{
			map_delete(killer_ips, killer_ip[n]);
			continue;
		}
		name = "";
		for ( m=0; m<sizeof(killer_obs); m++ )
		{
			if ( !objectp(killer_obs[m]) ) continue;
			if ( wizardp(killer_obs[m]) ) continue;
			name += HIY+killer_obs[m]->query("name")+"("HIR+killer_obs[m]->query("id")+HIY")";
			if ( m < sizeof(killer_obs)-1 ) name += "��";
		}
		killer_list += HIW"ɱ��ͨ����IP("HIR+killer_ip[n]+HIW")���������У�"+name+HIW".\n"NOR;
	}
	//__________________________________End_______________________________________
	set_heart_beat(300+random(600)); // ��������
}

// �����µ�ɱ�˷� IP ����
void add_killer(object ob)
{
	string ip, *killer_ip;

	if ( !objectp(ob) || !playerp(ob) || wizardp(ob) ) return;
	
	ip = query_ip_number(ob);
	
	if ( !ip ) ip = ob->query_temp("last_ip_number");
	if ( !ip ) return;

	if ( !mapp(killer_ips) ) killer_ips = ([]);
	
	killer_ip = keys(killer_ips);
	
	if ( !arrayp(killer_ip) ) killer_ip = ({});
	if ( member_array(ip, killer_ip) != -1 ) return;

	killer_ips[ip] = ({ ob });
}

// ���ɱ�˷��뱻ɱ�� IP �Ƿ���ͬ
int check_killer_ip(object killer, object ob)
{
	if ( query_ip_number(ob) == query_ip_number(killer) ) return 1;

	return 0;
}

// ����killerͳ��
string get_killer_list()
{
	return killer_list;
}