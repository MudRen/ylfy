// �Ż����� By ������(Wenwu) On 2004��9��21��
// �����������������ʾ����
// ����IP����ѯ
// ��������ͬIP�������У�

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>

int query_only_ip(object *ob);
int sort_user(object ob1, object ob2);

void create()
{
	seteuid( getuid() );
}

string age_string(int time)
{
	int year, month, day, hour, min, sec;
	
	sec = time % 60;
	time /= 60;
	min = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	time /= 30;
	month = time % 12;
	year = time / 12;
	
	return (year?year + "��":"") + (month?month + "��":"") + (day?day + "��":"") +  (hour?hour + "ʱ":"") + (min?min + "��":"") + sec + "��";	
}

string finger_all()
{
	object *ob;
	string msg;
	int i,ips;
	string tomud_version;
	
	ob = sort_array(users(), (: sort_user :));
	msg = "";
	
	if ( !wizardp(this_player()) )
	{
		for(i=0; i<sizeof(ob); i++)
		{
			if( this_player() && !this_player()->visible(ob[i]) )
				continue;
			
			msg = sprintf("%s%-14s%-14s%-14s\n",msg, ob[i]->query("name"), ob[i]->query("id"),query_idle(ob[i]) + "s");
		}
		
		return "�� "+CHINESE_MUD_NAME+" ��\n" + 
		"������������������������������������\n"
		+ "����          �ʺ�          ����\n" +
		"������������������������������������\n"
		+ msg +
		"������������������������������������\n";
	}
	else
	{
		for(i=0; i<sizeof(ob); i++)
		{
			if( this_player() && !this_player()->visible(ob[i]) )
				continue;
			if ( ob[i]->query("xieyi/zmud") ) 
				tomud_version = "Zmud";
			else
			{
				if ( ob[i]->query("env/myhp_show") )
					tomud_version = "Tomud_New";
				else
					tomud_version = "Tomud";
			}

			msg = sprintf( "%s%-14s%-14s%-21s%-9s%-15s"HIG" %s\n"NOR, 
				msg, ob[i]->query("name"), ob[i]->query("id"), 
				age_string( (int)ob[i]->query("mud_age") ), 
				age_string(query_idle(ob[i]))/* + "s"*/, wizardp(ob[i])?(query_ip_name(ob[i]) + HIR"(��)"NOR):query_ip_name(ob[i]),tomud_version );
		}

		ips = query_only_ip(ob);
		
		//���������±�д���Ż��������msg�����޷�������ʾ������
		this_player()->start_more(BBLU + HIW"�� " + CHINESE_MUD_NAME + " ��\n"NOR + 
			HIW"������������������������������������������������������������������������������������\n" + 
			BRED"����          �ʺ�          ����                 ����     ����            �ͻ���    \n"NOR + 
			HIW"������������������������������������������������������������������������������������\n"NOR + 
			msg + 
			HIW"������������������������������������������������������������������������������������"NOR);
		return HIW"Ŀǰ���(Player)���߶�̬��ѯ��"HIG+ips+HIW"/"HIY +sizeof(ob)+HIW" ("HIG"Ip"HIW"/"HIY"Id"HIW")��\n"NOR;
	}
}

string finger_user(string name, int dns)
{
	object ob, body, *users;
	string msg, mud, tomud_version;
	string wiz_status;
	int public_flag, online, i;
	
	//���±�д�Ż�
	if( sscanf(name, "%s@%s", name, mud)==2 )
	{
		GFINGER_Q->send_finger_q(mud, name, this_player(1));
		return "��·ָ��͹��̿�����ҪһЩʱ�䣬���Ժ�\n";
	}
	
	ob = new(LOGIN_OB);
	ob->set("id", name);

	if( !objectp(ob) ) 
			return "û�������ҡ�\n";
	
	if( !ob->restore() )
	{
		destruct( ob );
		return "û�������ҡ�\n";
	}
	
	if( objectp(body = find_player(name)) && geteuid(body)==name )
	{
		if( !dns && wizardp(this_player()))
			public_flag = 1;
		else
			public_flag = 0;

		// ����
		online = 1;
	}
	else 
	{
		body = LOGIN_D->make_body(ob);
		
		if( !body) 
			return "û�������ҡ�\n";
		
		if( !body->restore() ) 
		{
			destruct( body );
			return "û�������ҡ�\n";
		}
		
		if(!dns && wizardp(this_player()))
			public_flag = 1;
		else
			public_flag = 0;
		
		// ������
		online = 0;
	}
	
	msg =  sprintf("\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n""�����ʼ���ַ��\t%s\n�ϴ�����ʱ�䣺\t%s\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		public_flag?ob->query("email"):"��������",
		HIY + CHINESE_D->chinese_time(7,ctime(ob->query("last_on"))) + NOR + 
		(!dns && wizardp(this_player(1))?"\n�ϴ����ߵ�ַ��\t"HIY + ob->query("last_from") + NOR:""));
	
	if( online )
	{
		if ( !dns )
		{
			if ( this_player()->visible(body) )
			{
				wiz_status = SECURITY_D->get_status(this_player(1));
		
				if( wiz_status == "(admin)" || wiz_status == "(boss)" )
					msg += sprintf("%sĿǰ����"HIG"%s"NOR"�����С�\n", body->name(1),query_ip_number(body)?query_ip_number(body):(body->query("lixian/biguan")?HIY:HIR)+body->query_temp("last_ip_number"));
				else
				{
					if ( body->query_temp("netdead") )
						msg += sprintf("%sĿǰ��"HIR"����"NOR"�С�\n", body->name(1));
					else if ( body->query("lixian/biguan") )
						msg += sprintf("%sĿǰ��"HIY"����"NOR"�С�\n", body->name(1));
					else
						msg += sprintf("%sĿǰ��"HIG"����"NOR"�С�\n", body->name(1));
				}
			}
			if ( wizardp(this_player()) )
			{
				msg += HIW"������������������������������������������������������������������������������������\n"
					+ HBBLU"Ŀǰ��IP�ϻ��У�                                                                    \n"NOR
					+ HIW"������������������������������������������������������������������������������������\n"NOR;
				users = users();
				for ( i = 0; i < sizeof(users); i++ )
				{
					if ( users[i] == body ) continue;
					if ( users[i] == ob ) continue;
					if ( query_ip_number(users[i]) != query_ip_number(body) ) continue;
					if ( users[i]->query("xieyi/zmud") ) 
						tomud_version = "Zmud";
					else
					{
						if ( users[i]->query("env/myhp_show") )
							tomud_version = "Tomud_New";
						else
							tomud_version = "Tomud";
					}
					msg += sprintf( "%-14s%-14s%-21s%-9s%-15s"HIG" %s\n"NOR, users[i]->query("name"), users[i]->query("id"), 
						age_string( (int)users[i]->query("mud_age") ), 
						age_string(query_idle(users[i])), wizardp(users[i])?(query_ip_name(users[i]) + HIR"(��)"NOR):query_ip_name(users[i]), tomud_version );
				}
			}
		}
		else if ( !wizardp(body) || !body->query("env/invisibility") )
			msg += sprintf("Ŀǰ����������״̬�С�\n", body->name(1));
	}

	if ( !dns && wizardp(this_player()) )
	{
		msg += HIW"������������������������������������������������������������������������������������\n"
			+ HBRED"Ŀǰ�Ӹ�ID�ϴε�½��IP���ߵ��У�                                                    \n"NOR
			+ HIW"������������������������������������������������������������������������������������\n"NOR;
		users = users();
		for ( i = 0; i < sizeof(users); i++ )
		{
			if ( users[i] == body ) continue;
			if ( users[i] == ob ) continue;
			if ( query_ip_name(users[i]) != ob->query("last_from") ) continue;
			if ( users[i]->query("xieyi/zmud") ) 
				tomud_version = "Zmud";
			else
			{
				if ( users[i]->query("env/myhp_show") )
					tomud_version = "Tomud_New";
				else
					tomud_version = "Tomud";
			}
			msg += sprintf( "%-14s%-14s%-21s%-9s%-15s"HIG" %s\n"NOR, users[i]->query("name"), users[i]->query("id"), 
				age_string( (int)users[i]->query("mud_age") ), 
				age_string(query_idle(users[i])), wizardp(users[i])?(query_ip_name(users[i]) + HIR"(��)"NOR):query_ip_name(users[i]), tomud_version );
		}
	}
	
	destruct(ob);
	
	if ( online == 0 ) destruct(body);
	
	if ( !dns ) return this_player()->start_more(msg);
	else return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) )
	{
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	
	ob = new(LOGIN_OB);
	ob->set("id", id);
	return ob->restore() ? ob : 0;
}

//ͨ�����
string get_killer()
{
	int i;
	string msg;
	object *ob = children(USER_OB);
	
	msg = "";

	for (i = 0; i < sizeof(ob); i++)
	{
		if ((int)ob[i]->query_condition("killer"))
			msg += (HIY"" + ob[i]->query("title") + HIR" " + ob[i]->query("name") + HIW"(" + ob[i]->query("id") + ")\n"NOR);
	}

	if ( msg == "" ) msg = "�����ΰ����á�\n\n";
	else msg = "���ڱ������ڼ��������˷���\n\n" + msg +"\n";
	
	msg += HBRED+HIY"ɱ�˷�ͨ��ͳ���\n"NOR;
	msg += AUTOSAVED->get_killer_list();
	return msg;
}

//����IP��
int query_only_ip(object *ob)
{	
	int i, j;
	
	for ( i=0; i < sizeof(ob); i++ )
	{
		for ( j=sizeof(ob)-1; j >= 0; j-- )
		{
			if ( ob[j] != ob[i] && query_ip_name(ob[j]) == query_ip_name(ob[i]) )
				ob = ob - ({ob[j]});
		}
	}

	return sizeof(ob);
}

//����
int sort_user(object ob1, object ob2)
{
	return strcmp(query_ip_name(ob1), query_ip_name(ob2));
}