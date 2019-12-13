// /adman/daemons/logind.c
// 2003.7.24 lisa
// ��ֹ������������ 2004.7.29
// �����û�Э��Ķ˿�ʶ�� 2004.8.7
// ����Mysql��֤�����վ��ͬID��Mysql������������
// ����WIZ��½�������� 2004.8.20
// ����webת��
// ����tomudЭ���login����(�������ҡ����who�б�)
// 2.0 ����������ݱ�ʶ
// ��ԭ����MD5ϵͳת���ɳ��棬���������������ʶ��ԭ�������
// ���ӶԿͻ��˰汾ʶ��Tomud����˿�Ĭ�ϣ�5555 9999��WEB����˿�Ϊ2001������Ϊ��2003 8888
// ���ó���ASCII����ձ���֤Tomud�ͻ��˰汾
//2015.10.10ɾ��һЩ�ͱ���Ϸ�޹ص�һЩ����

#define ZMUD_1 get_system_config(DATA_CONFIG_DIR "system.h", "WEB")
#define ZMUD_2 get_system_config(DATA_CONFIG_DIR "system.h", "ZMUD_1")
#define ZMUD_3 get_system_config(DATA_CONFIG_DIR "system.h", "ZMUD_2")
#define TOMUD_1 get_system_config(DATA_CONFIG_DIR "system.h", "TOMUD_1")
#define TOMUD_2 get_system_config(DATA_CONFIG_DIR "system.h", "TOMUD_2")
#define XYZX_PORT_MSG ""+ZMUD_2+"|"+ZMUD_3+"|"+TOMUD_1+"|"+TOMUD_2
#define MAX_USERS_PER_IP 8

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <liebiao.h>
#include <mudlib.h>
#include <net/daemons.h>

inherit F_DBASE;
inherit F_ASCII;

int lock_age = LOCK_AGE;
int wiz_lock_level = WIZ_LOCK_LEVEL;
int mad_lock = 0;

string Rname;

string *banned_name = ({
	"��", "���", "��","�ҵ�","�Լ�","ƨ", "��", "����","��", "����","��", "����",
	"����","����","��å","��","���ŷ���ʹ"," ","��","��","����","����","ү","��",
	"ë��","��Сƽ","������","��","��","���˼","����˹","����","��","����","�ϰ���",
	});

string *start_room = ({
	"/d/city3/kedian",
	"/d/city2/kedian",
	"/d/dali/kezhan",
	"/d/nanyang/kedian1",
	});

string *banned_id = ({
	"mudos","admin","arch","wizard","manager","president","apprentice","immortal",
	"player","genie","fuck","manager","ceo","boss","root","book","staff","sword",
	"noname","blade","silver","coin","look","gold","angel","newer","out","talk",
	"none","corpse","Skeleton","club","hammer",
		});

protected void get_version(string arg, object ob,int ip_cnt);//�ͻ��˰汾ʶ��
protected void get_id(string arg, object ob,int ip_cnt);
protected void confirm_id(string yn, object ob,int ip_cnt);
object make_body(object ob);
protected void init_new_player(object user);
void get_resp(string arg, object ob);
protected void new_biaoshi(string biaoshi,object ob); // �趨��ʶ
protected void confirm_biaoshi(string biaoshi,object ob); //����ʶ
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string random_name();

void random_gift(mapping my, int select)
{
	int i = 10, j;
	int tmpstr, tmpint, tmpcon, tmpdex;

	tmpstr = tmpint = tmpcon = tmpdex = 10;

	switch (select)
	{
		case 1: tmpstr = i = my["str"]; break;
		case 2: tmpint = i = my["int"]; break;
		case 3: tmpcon = i = my["con"]; break;
		case 4: tmpdex = i = my["dex"];
	}

	i = 50 - i;

	while (i--)
	{
		j = random(4);

		if (j == select - 1)
		{
			i++;
			continue;
		}

		switch (j)
		{
			case 0: tmpstr++; break;
			case 1: tmpint++; break;
			case 2: tmpcon++; break;
			case 3: tmpdex++; break;
		}
	}

	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;

	my["kar"] = 10 + random(21);
	my["per"] = 10 + random(21);
}

void create() 
{
    seteuid(getuid());
    set("channel_id", "���߾���");
}

protected void logfile(string str)
{
    mixed *local =localtime(time());

    string file=sprintf("login/login%d%d.log",local[5],local[4]+1);
    log_file(file,str);
}

void logon(object ob) 
{
	object *usr;
	int i, wiz_cnt, ppl_cnt,ip_cnt,ban_cnt,login_cnt,i_user,online_num,a_port,b_port,c_port,d_port;
	string str, user_num, Rasc;
	/*if (uptime() < 60)
	{
	        write(RED"��Ϸ�������������У����Ժ���login��\n"NOR);
	        destruct(ob);
	        return;
	}*/
	str=query_ip_number(ob);

	Rasc = random_all_char();
	write(TMI("connect " + Rasc) + "\n");
	ob->set_temp("tomud_version", Rasc);
	
	if (BAN_D->is_banned(str) == 1)
	{
		write(HIW"    �������� "HIR"��ĵ�ַ�ڱ�"HIG" MUD "HIR"���ܻ�ӭ������������"HIW" ��������"HIY"\n               http://lovexyzx.getbbs.com\n"HIW"               ����������������"HIC"����"HIW"����������������\n"NOR);
		destruct(ob);
		return;
	}
	
	if( mad_lock == 1 )
	{
		write(HBRED+HIY"����������.....��ʱ���ѱ���գ����Ժ��������ߣ����� \n"NOR);
		destruct(ob);
		return;
	}

	if ( !DNS_MASTER->query_doing_end() )
	{
		write(HBRED+HIY+CHINESE_MUD_NAME + "������վͬ���С����������Ժ��������ߣ����� \n"NOR);
		destruct(ob);
		return;
	}
	
	write("\n");
	write(NOR"��ӭ���� "+BBLU+HIM+get_system_config(DATA_CONFIG_DIR "system.h", "XYZX_NAME_1")+BBLU+HIW" ֮ "+BBLU+HIR+get_system_config(DATA_CONFIG_DIR "system.h", "XYZX_NAME_2")+NOR);
	write("\n\n");
	write(CYN"Ϧ������"HIW"��̳"NOR" : " + get_system_config(DATA_CONFIG_DIR "system.h", "XYZX_BBS") + "\n"NOR);
	write(CYN"�������汾��"NOR" : " HIW +  __VERSION__ + "\n"NOR);
	//if ( !"/cmds/bos/mudlist-login"->main() )
	write("\n");
	
	usr = get_all_user();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	ban_cnt = 0;
	ip_cnt=0;
	a_port=0;
	b_port=0;
	c_port=0;
	d_port=0;
	
	for(i=0; i<sizeof(usr); i++)
	{
		if(query_ip_port(usr[i]) == ZMUD_2) a_port++;
		if(query_ip_port(usr[i]) == TOMUD_1) b_port++;
		if(query_ip_port(usr[i]) == ZMUD_3) c_port++;
		if(query_ip_port(usr[i]) == TOMUD_2) d_port++;
		if (str==query_ip_number(usr[i])) ip_cnt++;
		if( str==query_ip_number(usr[i]) && !environment(usr[i]) ) ban_cnt++;
		
		if( !environment(usr[i]) ) 
			login_cnt++;
		else if( wizardp(usr[i]))
		{
			if (!usr[i]->query("env/invisibility"))
				wiz_cnt++;
		}
		else
			ppl_cnt++;
	}
	
	user_num=read_file(__DIR__"users",1);
	i_user=atoi(user_num);
	i_user=i_user+1;
	user_num=sprintf("%d", i_user); 
	write_file(__DIR__"users",user_num,1);
	user_num=read_file(__DIR__"iduser",1);
	i_user=atoi(user_num);
	online_num = atoi(read_file(__DIR__"maxonline",1));
	
	if (ip_cnt-1 > 0)
	{
		printf("�����ڴ�%s���߽��롣",CYN+str+NOR);
		printf("�������ַ�ϣ�����"+YEL+chinese_number(ip_cnt-1)+NOR+"λ������ҡ�\n");
	}
	else
		printf("�����ڴ�%s���߽��롣\n",CYN+str+NOR);
	printf("Ŀǰ����"+ HIY"%s"NOR+ "λ���ɡ�"+HIW"%s"NOR+"λ������ʿ�ڽ����У��Լ�"+HIB"%s"NOR+ "λ�������ڲ���;�С�\n",
	chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
	printf(HIY"��վ֧�ֶ�˿����ӣ���ѡ���������ٵĶ˿����ߣ������������Ϸ�ٶ�\n"NOR);//��Ӷ���˿�
	printf(	HIW"��"+ZMUD_2+" %s��"+"����"+ZMUD_3+" %s��"+"����"+TOMUD_1+" %s��"+ "����"+TOMUD_2+" %s��"+ "��\n"NOR,chinese_number(a_port),chinese_number(b_port),chinese_number(c_port),chinese_number(d_port),);
	
	if(ppl_cnt > online_num)
	{
		user_num = sprintf("%d",ppl_cnt);
		write_file(__DIR__"maxonline",user_num,1);
	}
	
	if (ban_cnt > 10 )
	{
		write(HIY"���IP��ͬʱ�������ߵ����̫���ˣ����Ժ��ٳ��ԣ��� \n"NOR);
		destruct(ob);
		return;
	}
	//��Ӷ���˿�
	write(BRED+HIW"ZMud�˿�["HIY+ZMUD_2+HIW"],ZMud�˿�["HIY+ZMUD_3+HIW"],ToMud�˿�["HIG+TOMUD_1+HIW"],ToMud�˿�["HIG+TOMUD_2+HIW"],��ѡ���ʺϵĶ˿�����\n"NOR+YEL"����������Ӣ�����֣�\n"NOR);
	input_to( (: get_version :), ob,ip_cnt );
}

protected void get_id(string arg, object ob,int ip_cnt)
{
	object ppl;
	object *usr;
	int i, wiz_cnt,usr_cnt;
	arg = lower_case(arg);
    
	if( !check_legal_id(arg))
	{
		write(YEL"����������Ӣ�����֣�\n"NOR);
		input_to("get_id", ob,ip_cnt);
		return;
	}

	// ��������б�
	if ( query_ip_port(ob) == TOMUD_1 || query_ip_port(ob) == TOMUD_2 )
	{
		write(CLEAN2);
		write(CLEAN0);
		write(CLEAN1);
	}
	
	usr = users();
	wiz_cnt = 0;
	
	for(i=0; i<sizeof(usr); i++)
	{
		if( wizardp(usr[i]) )
			wiz_cnt++;
	}
	
	if( (string)SECURITY_D->get_status(arg)=="(player)" && (sizeof(users()) - wiz_cnt) >= 500)
	{
		ppl = find_body(arg);
		
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) )
		{
			write(HIY"�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n"NOR);
			destruct(ob);
			return;
		}
	}
	
	if( wiz_level(arg) < wiz_lock_level )
	{
		write(HIY"�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� "HIG + wiz_lock_level + HIY" ���ϵ��˲������ߡ�\n"NOR);
		destruct(ob);
		return;
	}
	
	if( (string)ob->set("id", arg) != arg ) 
    {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}
	
	for (i=0;i<sizeof(banned_id);i++)
	
	if ( strsrch(arg, banned_id[i])!=-1)
	{
		write(HIY"�Բ�������ʻ���������һ��ʹ�����ڵ�¼���������������Ӣ������\n"NOR);
		write(YEL"����������Ӣ�����֣�\n"NOR);
		input_to("get_id", ob,ip_cnt);
		return;
	}
	
	if( arg=="guest")
	{
		write(HIY"�Բ�����������guest�ʻ���¼���������������Ӣ������\n"NOR);
		write("����"+HIW"Ӣ��"NOR+"���֣�\n");
		input_to("get_id", ob,ip_cnt);
		return;
	}
	ob->set_temp("ip_cnt",ip_cnt);
	/*if (wiz_level(arg)<2)
    {
		if (!BAN_D->is_welcome(arg))
		{
			//if (!BAN_D->is_netclub(query_ip_number(ob)))
			if (ip_cnt > 9)//�����θ���2003��10��18���賿4��,ԭ����ip_cnt>8(��ip��½��Ҹ���)
			{
				write(HIR"���IP���������̫���ˣ����ܽ��룡�� \n"NOR);
				destruct(ob);
				return;
			}
		}
	}*/
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
	{
		if( ob->restore() )
		{
			// �����Աʶ�� 
			/*if (ob->query("quyu/rzjh"))
			{
				write(HBRED+HIW"���ʺŹ����ڡ����ڽ��������޷��ڴ�����ʹ�ã���ʹ�������ʺ����µ�½\n"NOR);
				destruct(ob);
				return;
			}*/

			/*if(wiz_level(arg) > 0)
			{
				write(HIW"��Ŀǰ��Ȩ����"HIY+wizhood(arg)+HIW",Ϊ�˰�ȫ����������뱾վ��ʦ��½Ч���룺\n"NOR);
				input_to("get_wizpass", 1, ob);
			}
			else
			*/{
				write(YEL"�������������룺\n"NOR);
				input_to("get_passwd", 1, ob);
			}
			return;
		}
		else
		{
			write(HIY"\n�������ﵵ�����˵����⣬����ϵ����ԱQQ 41689592 ���д���\n"NOR);
			destruct(ob);
			return;
		}
	}
	
	usr_cnt=0;
	
	for(i=0; i<sizeof(usr); i++)
	{
		if (usr[i]->query("id")==arg)
			usr_cnt++;
		
		if (usr_cnt>1)
		{
			write(HIY"�Բ�������ʻ���������һ��ʹ�����ڵ�¼���������������Ӣ������\n"NOR);
			write("��������������Ӣ�����֣�\n");
			input_to("get_id", ob,ip_cnt);
			return;
		}
	}
	
	write("ʹ�� "HIW + (string)ob->query("id") + NOR" ������ֽ��ᴴ��һ���µ������ȷ����("HIG"y"NOR"/"HIR"n"NOR")��\n");
	input_to("confirm_id", ob,ip_cnt);
}

protected void get_passwd(string pass, object ob)
{
	string my_pass, my_biaoshi;
	int err_num;
	object user;
	
	//write("\n");
	my_pass = ob->query("passwordold");
	my_biaoshi = ob->query("biaoshiold");

	if ( crypt(pass, my_biaoshi) == my_biaoshi && crypt(pass, my_pass) != my_pass )
	{
		write(HIY"�����������ݱ�ʶ��������ע�����������֤�Ի�ȡ��½Ȩ��:\n"NOR);
		input_to("cha_mail", 1, ob);
		return;
	}
   else if( crypt(pass, my_pass) != my_pass )
	{
		err_num=ob->query_temp("error_login");
		err_num++;
		ob->set_temp("error_login",err_num);

		if ( err_num < 3 )
		{
			write("������"HIR+chinese_number(3-err_num)+NOR"�λ��ᣬ��������ȷ���룺\n");
			input_to("get_passwd", 1, ob);
			return;
		}
		else
		{
			write("\n���Ѿ�û�л����ˣ�����ú������ߣ�\n");
			destruct(ob);
		}		
		return;
	}
	
	if (!BAN_D->vaild_allow_address(ob))
	{
		destruct(ob);
		return;
	}
	
	user = find_body(ob->query("id"));
	
	if (user)
	{
		if(time()-(int)user->query("quit_time") < 10)
		{
			if ( !user->query("lixian/biguan") )
				write(HIY"\nϵͳ��æ����ȴ� "HIG"10��"HIY" ���г������ߡ�\n"NOR);
			else
				write(HIY"\n�������߽��бչ�������Ŀǰ���ڴ���ָ���У����Դ�Ƭ���������ߡ�\n"NOR);
			destruct(ob);
			return;
		}
		
		if( user->query_temp("netdead") )
		{
			reconnect(ob, user);
			return;
		}
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��("HIG"y"NOR"/"HIR"n"NOR")\n");
		input_to("confirm_relogin", ob, user);
		return;
	}
	
	if( objectp(user = make_body(ob)) )
	{
		if( user->restore() )
		{
			if(time()-(int)user->query("kickout_time") < 600)
			{
				write(HIR"\n������Υ�������߳���Ϸ����Ϊ�ͷ���ʮ���Ӻ������ߡ�\n"NOR);
				destruct(user);
				destruct(ob);
				return;
			}
			
			if(time()-(int)user->query("quit_time") < 60)
			{
				write(HIY"\n����˳���Ϸ��Ϊ�˼���ϵͳ���������˳���Ϸ60����������룬лл����������\n"NOR);	
				destruct(user);
				destruct(ob);
				return;
			}
			
			if(query_ip_port(ob) != ZMUD_1)
			{
				user->delete("xieyi");
				user->delete("position");
			}

			if(query_ip_port(ob) != ZMUD_2)
				user->delete("xieyi");

			if(query_ip_port(ob) != ZMUD_3)
				user->delete("xieyi");
			
			if(query_ip_port(ob) == ZMUD_1)
			{
				user->set("xieyi/zmud",1);
				user->set("position", "webuser");
			}

			if(query_ip_port(ob) == ZMUD_2)
				user->set("xieyi/zmud",1);

			if(query_ip_port(ob) == ZMUD_3)
				user->set("xieyi/zmud",1);

			if ( ob->query_temp("client_version") )
				user->set("env/myhp_show", 1);
			else
				user->delete("env/myhp_show");
			
			if(wiz_level(user) > 0)
				log_file( "login/wiz/"+user->query("id"),sprintf("%-20s��%20s  ��    ¼(%s)��\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );
			else
				log_file( "login/login",sprintf("%-20s��%20s  ��    ¼(%s)��\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );
			
			enter_world(ob, user);
			return;
		}
		else
		{
			destruct(user);
		}
	}
	//if ( wiz_level(ob->query("id")) > 0 )
	//{
		write("\n�������´���������\n");
		confirm_id("y", ob,1);
		/*return;
	} else {
		write(HIY"\n�������ﵵ�����˵����⣬����ϵ����ԱQQ 86644296 ���д���\n"NOR);
		destruct(ob);
		return;
	}*/
}

protected void confirm_relogin(string yn, object ob, object user)
{
	object old_link;
	
	//������ʱ��user���ߣ������ob��
	if(!user)
	{
		destruct(ob);
		return;
	}

	old_link = user->query_temp("link_ob");

	if (!ob)
		return;
	
	if( yn=="" )
	{
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)\n");
		input_to("confirm_relogin", ob, user);
		return;
	}
	
	if( yn[0]!='y' && yn[0]!='Y' )
	{
		if (wiz_level(user) > 3 )
		{
			if( objectp(user = make_body(ob)) )
			{
				if( user->restore() )
				{
					enter_world(ob, user);
					return;
				}
				else
					destruct(user);
			}
		}
		
		write(GRN"�ðɣ���ӭ�´�������\n"NOR);
		destruct(ob);
		return;
	}
	else
	{
		tell_object(user, "���˴ӱ�( "HIW + query_ip_number(ob) + NOR" )����ȡ���������Ƶ����\n");
		log_file("login/replace", sprintf("%-20s��%20s  ��������(%s)��\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );
	}

    // Kick out tho old player.
    if( old_link )
	{
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);
}

protected void confirm_id(string yn, object ob,int ip_cnt)
{
	if( yn=="" )
	{
		write("ʹ��������ֽ��ᴴ��һ���µ����������ȷ����("HIG"y"NOR"/"HIR"n"NOR")��\n");
		input_to("confirm_id", ob,ip_cnt);
		return;
	}
	
	if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("�ðɣ���ô��������������Ӣ�����֣�\n");
		input_to("get_id", ob,ip_cnt);
		return;
	}

    write("\n");
	write(HIW @TEXT
�����������Լ�ȡһ�������ʣ��и��Ե����֣��õ����ֲ�����ʾ��������
��������Ҳ����������һ���õ�ӡ��, ��������˶�������������ѣ���
������һ�����������Ӱ�졣�����������������������������ִ�������
����Ժ󽫺��Ѹ��ġ�����������������������֣���ֱ���ûس�����
TEXT NOR
	);
	
	write("\n����Լ�ȡһ���������֣�\n");
	input_to("get_name", ob);
}

string display_attr(int gift)
{
	if (gift > 24)
		return HIG + gift + NOR;
	
	if (gift < 16)
		return CYN + gift + NOR;
	
	return "" + gift;
}

void get_resp(string arg, object ob)
{
	if( arg=="" )
	{
		write("���Ƿ����������������("HIG"y"NOR"/"HIR"n"NOR")��\n");
		input_to("get_resp", ob);
		return;
	}
	
	if( arg[0]=='y' || arg[0]=='Y' )
	{
		printf("%O\n", ob);
		ob->set("name", Rname);
		write("���趨�������룺\n");
		input_to("new_password", 1, ob);
		return;
	}
	else if( arg[0]=='n' || arg[0]=='N')
	{
		Rname = random_name();
		write("���Ƿ����������������("HIG"y"NOR"/"HIR"n"NOR")��");
        printf( HIW" ����"NOR YEL"�� "HIR"%s"NOR YEL" ��"NOR"��\n"NOR, Rname);
        input_to("get_resp", ob);
		return;
	}
	else
	{
		write("�Բ�����ֻ��ѡ������("HIG"y"NOR")������("HIR"n"NOR")�� \n");
		input_to("get_resp", ob);
		return;
	}
}

protected void get_name(string arg, object ob)
{
	if( arg =="")
	{
		Rname = random_name();
		write("������Ҫ������������������֣���\n");
		write("�������Ƿ����������������("HIG"y"NOR"/"HIR"n"NOR")��");
		printf( HIW" ����"NOR CYN"�� "HIY"%s"NOR CYN" ��"NOR"��\n"NOR, Rname);
		input_to("get_resp", ob);
	}
	else
	{
		if( !check_legal_name(arg) )
		{
			write("���ٴ����������������֣�\n");
			input_to("get_name", ob);
			return;
		}
		
		printf("%O\n", ob);
		ob->set("name", arg);
		write("���趨�������룺\n");
		input_to("new_password", 1, ob);
	}
}

protected void new_password(string pass, object ob)
{
	//write("\n");
	
	if( strlen(pass)<5 )
	{
		write("����ĳ�������Ҫ����ַ����������������룺\n");
		input_to("new_password", 1, ob);
		return;
	}
	
	if(strsrch(pass,"//")!=-1)
	{
		write(HIR"�Ƿ������룬�������������룺\n");
		input_to("new_password", 1, ob);
		return;
	}
	
	ob->set("passwordold", crypt(pass,0) );
	write("��������һ���������룬��ȷ����û�Ǵ�\n");
	input_to("confirm_password", 1, ob);
}

protected void confirm_password(string pass, object ob)
{
	string old_pass;
	
	//write("\n");
	old_pass = ob->query("passwordold");
	
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("��������������벢��һ�����������趨һ�����룺\n");
		input_to("new_password", 1, ob);
		return;
	}
	
	write("\n");
	write(HIY"���趨������ݱ�ʶ���ñ�ʶ������ɱ���Լ�ȡ������ʱʹ�á������޸ģ����������:\n"NOR);
	input_to("new_biaoshi", 1, ob);
	return;
}

protected void new_biaoshi(string biaoshi,object ob)
{
	//write("\n");
	
	if( strlen(biaoshi)<9 )
	{
		write("��ݱ�ʶ�ĳ�������Ҫ�Ÿ��ַ���������������ݱ�ʶ��\n");
		input_to("new_biaoshi", 1, ob);
		return;
	}
	
	if(strsrch(biaoshi,"//")!=-1)
	{
		write(HIR"�Ƿ������룬������������ݱ�ʶ��\n");
		input_to("new_biaoshi", 1, ob);
		return;
	}
	
	ob->set("biaoshiold", crypt(biaoshi,0) );
	write("��������һ��������ݱ�ʶ����ȷ����û�Ǵ�\n");
	input_to("confirm_biaoshi", 1, ob);
}

protected void confirm_biaoshi(string biaoshi,object ob)
{
	string old_biaoshi;
	
	//write("\n");
	old_biaoshi=ob->query("biaoshiold");
	
	if( crypt(biaoshi, old_biaoshi)!=old_biaoshi )
	{
		write("�������������ݱ�ʶ����һ�����������趨һ�Σ�\n");
		input_to("new_biaoshi", 1, ob);
		return;
	}

	write("\n");
	write(HIC"һ��������츳��������������ϰ������ϢϢ��ء���Ϧ�����֡��е���\n"+
		"����������������츳,���и�Ե����ò���������ԣ�\n"+
		"������\n"+
		"�����塡������Ӱ�칥���������������Ĵ�С��\n"+
		"�����桡���ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ����ʦ����������\n"+
		"�����硡���ǣ�Ӱ�������ָ����ٶȼ������������ӵ�������\n"+
		"�����衡����Ӱ���������ܵ�������\n"+
		"�����顡��Ե��Ӱ����ԡ���������ʦ���������档\n"+
		"������  ��ò��Ӱ����ܣ���ʦ�������Լ���Һ�NPC�����ӡ��\n"NOR);
	write("\n���������� ("HIY"1-4"NOR") ָ�����е�һ��ֵ���������� "+HIR"0"NOR" ��ϵͳ���ѡ��\n");
	write("����ѡ���� ("HIY"0-4"NOR")��\n");
	input_to("select_gift", ob);
}

void get_gift(string yn, object ob, mapping my, int select)
{
	if (yn[0] != 'y' && yn[0] != 'Y')
	{
		random_gift(my, select);

		printf("����[%s]������[%s]������[%s]����[%s]\n",
			display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]));
		
		write("��ͬ����һ���츳��\n");
		input_to("get_gift", ob, my, select);
		return;
	}

	//write("\n");
	
	write("\n���ĵ����ʼ���ַ��\n");
	input_to("get_email", ob, my);
}

void select_gift(string yn, object ob)
{
	int i;
	mapping my = ([]);

	if (!sscanf(yn, "%d", i) || i < 0 || i > 4)
	{
		write("�������������ѡ��\n");
		input_to("select_gift", ob);
		return;
	}

	if (i)
	{
		write("����������Ҫ����ֵ(10-30)��\n");
		input_to("set_gift", ob, my, i);
	}
	else
		get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
	int i;

	if (!sscanf(yn, "%d", i) || i < 10 || i > 30)
	{
		write("��ֵ�������������룺\n");
		input_to("set_gift", ob, my, select);
		return;
	}

	switch (select)
	{
		case 1: my["str"] = i; break;
		case 2: my["int"] = i; break;
		case 3: my["con"] = i; break;
		case 4: my["dex"] = i;
	}
	get_gift(" ", ob, my, select);
}

protected void get_email(string email, object ob, mapping my)
{
	object user;
	string id,address;

	//write("\n");
	if (email == "" || strsrch(email, "@") == -1 || sscanf(email,"%s@%s",id,address)!=2 || strsrch(address,".")==-1)
	{
		write("�����ʼ���ַ��Ҫ�� id@address �ĸ�ʽ��\n");
		write("���ĵ����ʼ���ַ��\n");
		input_to("get_email", ob, my);
		return;
	}

	ob->set("email", email);

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	
	ob->set("body", USER_OB);
	
	if( !objectp(user = make_body(ob)) )
	{
		// �޷�����user��ȥ��ob��
		destruct(ob);
		return;
	}
	
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	user->set("kar", my["kar"]);
	user->set("per", my["per"]);
	
	ob->set("registered", 1);
	user->set("registered", 1);

	write("��Ҫ��������("HIC"m"NOR")�Ľ�ɫ��Ů��("HIR"f"NOR")�Ľ�ɫ��\n");
	input_to("get_gender", ob, user);
}

protected void get_gender(string gender, object ob, object user)
{
	int id_temp; string id_num;
	object gift;
	
	//write("\n");
    
	if( gender=="" )
	{
		write("��Ҫ��������("HIC"m"NOR")�Ľ�ɫ��Ů��("HIR"f"NOR")�Ľ�ɫ��\n");
		input_to("get_gender", ob, user);
		return;
	}
    
	if( gender[0]=='m' || gender[0]=='M' )
        {
		user->set("gender", "����");
                //user->set("icon","50001");      //��������Ĭ��ͷ��
	
        }
	else if( gender[0]=='f' || gender[0]=='F' )
        {
		user->set("gender", "Ů��" );
                //user->set("icon","50002");      //����Ů��Ĭ��ͷ��
        }
	else
	{
		write("�Բ�����ֻ��ѡ������("HIC"m"NOR")��Ů��("HIR"f"NOR")�Ľ�ɫ��\n");
		input_to("get_gender", ob, user);
		return;
	}

	if(query_ip_port(ob) != ZMUD_1)
	{
		user->delete("xieyi");
		user->delete("position");
	}

	if(query_ip_port(ob) != ZMUD_2)
		user->delete("xieyi");

	if(query_ip_port(ob) != ZMUD_3)
		user->delete("xieyi");
			
	if(query_ip_port(ob) == ZMUD_1)
	{
		user->set("xieyi/zmud",1);
		user->set("position", "webuser");
	}

	if(query_ip_port(ob) == ZMUD_2)
		user->set("xieyi/zmud",1);

	if(query_ip_port(ob) == ZMUD_3)
		user->set("xieyi/zmud",1);

	if ( ob->query_temp("client_version") )
		user->set("env/myhp_show", 1);
	else
		user->delete("env/myhp_show");
	
	log_file( "login/newid.log", sprintf("%-12s was created from %-20s (%s)\n", user->query("id"),query_ip_number(ob), ctime(time()) ) );
	CHANNEL_D->do_channel( this_object(), "sys","����һ������ң�"+user->query("name")+"["+user->query("id")+"]��"NOR);
	init_new_player(user);
	enter_world(ob, user);
	gift = new("/d/city/obj/gift");
	gift->move(user);
	id_num=read_file(__DIR__"iduser",1);
	id_temp=atoi(id_num);
	id_temp=id_temp+1;
	id_num=sprintf("%d",id_temp);
	
	write_file(__DIR__"iduser",id_num,1);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;
	
	if (stringp(ob->query("body")))
		user = new(ob->query("body"));
	else
		return 0;
	
	if(!user)
	{
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
		write(err+"\n");
		return 0;
	}
	
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

protected void init_new_player(object user)
{
	user->set("title", "��ͨ����");
	user->set("birthday", time() );
	user->set("max_fashufali",100);
	user->set("fashufali",100);
	//user->set("wuxing/mofa",random(10));
	user->set("potential", 100);
	user->set("channels", ({ "es","chat", "jypm","xyxw","rumor","tell","new","shout","jh","xy"}) );
	user->set("combat_exp", 5);
	user->set("money", 2000);
}

protected void get_wizpas(string wizpas, object ob)
{
	string wizpass;
	
	//write("\n");
	wizpass = ob->query("wizpasswd");
	if(!wizpass||wizpass=="")
	{
	    destruct(ob);
	    return;
	}
  if( crypt(wizpas, wizpass) == wizpass)
	{
		write(HIG"\n��ʦ��½Ч������֤ͨ����Ȩ�޼��سɹ���"HIY"Ϧ������ "HIG"�������������ʣ�����\n"NOR);
		write(YEL"�������������룺\n"NOR);
		input_to("get_passwd", 1, ob);
	}
	else
	{
		write(HIR"\n��ʦ��½Ч������֤ʧ�ܣ����ĵ�ַ�ѱ���¼������������������ʦ������\n"NOR);
		log_file( "login/getwiz.log", sprintf("%-15s ��ͼ�� %-27s ��½ %-15s\n",query_ip_number(ob),CHINESE_D->chinese_time(7,ctime(time())),ob->query("id")) );
		destruct(ob);
	}
}

protected void have_mail()
{
	write( HBBLU + "\n�ſ�(Post officer)�����㣺�������ţ��뵽��վ��һ��...\n\n" + NOR);
}

varargs void enter_world(object ob, object user, int silent)
{
	object cloth, xy_hy;
	string startroom, id, str, send;
	object login_ob;
	int j, max;
	int i=random(4);
	int ip_cnt=0,k;
	string ipnum=query_ip_number(ob);
	object *usr;
	usr = get_all_user();
	for(k=0;k<sizeof(usr);k++)
	{
	    if(ob->query("id")==usr[k]->query("id"))
		continue;
	    if (ipnum==query_ip_number(usr[k])) ip_cnt++;
	}
	if (ip_cnt>MAX_USERS_PER_IP)
	{
	    write(HIR"���IP���������̫���ˣ����ܽ��룡�� \n"NOR);
	    destruct(user);
	    destruct(ob);
	    return;
	}
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered", ob->query("registered"));
	exec(user, ob);
	user->setup();
	
	if (user->query("age") == 14)
	{
		user->set("food", user->max_food_capacity());
		user->set("water", user->max_water_capacity());
	}

	if ( user->query("lixian/biguan") )
		user->delete("lixian/biguan");
	
	user->save();
	ob->save();
	
	if (!user->over_encumbranced())
	{
		if (user->query("age")<18 /*&& !ob->query("last_on")*/)  //�Ժ��½���������·�
		{
			if (user->query("gender")=="Ů��")
				cloth = new("//clone/cloth/pink_cloth");
			else
				cloth = new("/clone/cloth/cloth");
			
			if (!ob->query("last_on"))
			{
				cloth->move(user);
				cloth->wear();
				//��������ϵ���Լ������ֵ�������
				user->set("env/wimpy",50);
                //user->set("env/prompt", "null"); //������
			}
		}

		// ��ʱ�Եģ��������ʱ�Զ���Ϊ��Ա
		/*if ( stringp(xy_hy = user->query("xy_huiyuan")) && sscanf(xy_hy, "%*s��%*s��%*s��") )
		{
			if ( !user->query("temp_huiyuan") )
				user->set("sun_huiyuan", 1);
		}*/
		if ( !user->query("xyhy_type") )
			user->set("xy_huiyuan", get_system_config(DATA_CONFIG_DIR "vip.h", "VIP_TIME"));

		//user->set("temp_huiyuan", 1);
		
		if (stringp(xy_hy = user->query("xy_huiyuan")))
		{
			if ( sscanf(xy_hy, "%*s��%*s��%*s��") )
				"/feature/vip"->del_vip(user, xy_hy);
			else
			{
				user->delete("xy_huiyuan");
				user->delete("xyhy_type");
			}
		}
		else
		{
			user->delete("xy_huiyuan");
			user->delete("xyhy_type");
		}

		//�ͷű��صĵ��ڵ���� 
		if(user->query("block/time") && time() > user->query("block/time"))
		{
			user->delete("startroom");
			user->delete("block/time");
		}
	}
	
	if( !silent )
	{
		// cat(MOTD); ������ʾ����
		//login_ob=new(LOGIN_OB);
		login_ob = ob;
		login_ob->set("id",user->query("id"));
		login_ob->restore();
		
		if(user->query("lixian/biguan"))
			user->delete("lixian/biguan");
		
		if(!user->query("xieyi/zmud"))
		{
			if(user->query("xy_huiyuan"))
			{
				//write(ALERT("���Ļ�Ա�ʸ񣺽�ֹ��"+user->query("xy_huiyuan")+"\n"));
				//write(TMI("statu ��Ա��ֹʱ�䣺" + user->query("xy_huiyuan")+"\n"));
			}
			else
			{
				//write(ALERT("���Ļ�Ա�ʸ��ѹ���\n"));
				//write(TMI("statu ��Ա��ֹʱ�䣺" + "����\n"));
			}
		}
		else
		{
			if(user->query("xy_huiyuan"))
                        {
			       //write(HIG"�� ���Ļ�Ա�ʸ�"HIC"��ֹ��"+user->query("xy_huiyuan")+"\n"NOR);
                        }
			else
			{
				//write(HIG"�� ���Ļ�Ա�ʸ�"HIC"�ѹ���\n"NOR);
			}
		}
		
		write(HIG"�� ��Ŀǰ��Ȩ�ޣ�"HIY + wizhood(user) + "\n"NOR);
		
		if(!login_ob->query("last_from"))
			write(HIG"�� ���ϴι����Ǵӣ�"HIW"�����ǵ�һ�ν���������½\n"NOR);
		else
		{
			write(HIG"�� ���ϴι����Ǵӣ�"HIW+login_ob->query("last_from")  + "\n"NOR);
			//write(HIG"�� ���ϴ����ߵ�ַΪ��"HBBLU+HIW+"/feature/ipsite"->seek_ip_address(login_ob->query("last_from"))  + "\n"NOR);
		}
		
		if(!login_ob->query("last_on"))
			write(HIG"�� ���ϴ����ߵ�ʱ���ǣ�"HIC"��ӭ����Ϊ���ǵ�һԱ\n"NOR);
		else
			write(HIG"�� ���ϴ����ߵ�ʱ���ǣ�"HIR+CHINESE_D->chinese_time(5,ctime(login_ob->query("last_on"))) + "\n"NOR);
		
		id=user->query("id");
		str=DATA_DIR + "mail/" + id[0..0] + "/" + id+".o";
		
		if(file_size(str) && user->query("new_mail")<file_size(str) )
		{
			call_out("have_mail",3);
		}
		
		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else
		{
			if( !stringp(startroom = user->query("startroom")) )
				startroom = start_room[i];
			
			if ( startroom == DEATH_ROOM )
				startroom = start_room[i];

			//���ؽ���Ҽ�����ID
			if(user->query("block/time"))
				startroom = "/clone/misc/block";
		}
		
		if ((file_size(startroom+".c") > 0 || file_size("/binaries" + startroom+".b") > 0) && !catch(load_object(startroom)))
			user->move(startroom);
		else
		{
			user->move(start_room[i]);
			startroom = start_room[i];
			user->set("startroom", start_room[i]);
		}
		
		tell_room(startroom, user->query("name") + "���߽���������硣\n",({user}));
	}
	
	write(HIW"�����߽���������磬��ʼ���Լ���"+HIG"����"+HIW"����\n"NOR);
	
	if(ob->query_temp("no_allow_ip"))
		write(HIY"\n\n���棺��δ�趨�Լ��ĵ�¼��ַ��Χ������"HIR" allowip "NOR"ָ�����á�\n\n"NOR);
	
	if(file_size("/log/login/notice")>0)
	{
		write(HIY"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"HIW);
		write(read_file("/log/login/notice"));
		write(NOR""+HIY"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n\n"NOR);
	}

	//���������ʾ������ȡλ��
	if(!login_ob->query("last_on"))
		write(HBMAG"��ӭ���������ǹ�ͬ��������������磬��Ϊ������һ��С�����Ա����⣡\n" + 
		HIG"������ȡ·����fly yz;w;n;w;pick gift;chai gift                    \n"NOR);
	// ��ʾ����
	NEWSD->prompt_user(user);
	
	if(user->query("gender") == "����"&&user->query("age")<=25)
	{
		switch(random(2))
		{
			case 0 : str = "������ʿ";
			break;
			
			case 1 : str = RANK_D->query_respect(user);
			break;
		}
	}
	else
	if(user->query("gender") == "Ů��"&&user->query("age")<=25)
	{
		switch(random(2))
		{
			case 0 : str = "������Ů";
			break;
			
			case 1 : str = RANK_D->query_respect(user);
			break;
		}
	}
	else
		str = RANK_D->query_respect(user);
	
	
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s)��%s���߽��롣", user->name(),user->query("id"), query_ip_name(user)) );
	UPDATE_D->check_user(user, 3);
	STATUS_D->compare_status(user);
	
	user->set_temp("temp_exp",user->query("combat_exp"));
	user->set_temp("temp_time",time());

	if ( interactive(user) )
	{
		object *temp;

		temp = children(USER_OB);
		max = sizeof(temp);
		send = "";
		for ( j=0; j<max; j++)
		{
			if ( !playerp(temp[j]) ) continue;
			if ( !environment(temp[j]) ) continue;
			if ( user->visible(temp[j]) ) send += ADD2(temp[j]);

			if ( !user->query("xieyi/zmud") && !(j%5) )
			{
				if ( send != "" ) tell_object(user, send);
				send = "";
			}

			if ( !interactive(temp[j]) ) continue;
			if ( !temp[j]->visible(user) ) continue;
			
			if ( !temp[j]->query("xieyi/zmud") )
			{
				tell_object(temp[j], ADD2(user));
			}
		}

		if ( send != "" && !user->query("xieyi/zmud") ) 
			tell_object(user, send);
	}
	//�����Զ�װ��
	user->force_me("wear all");
	
	if(! wizardp(user) && user->query("age") < lock_age)
	{
		write(HIY"�Բ���������Ϸ��ֹ������"+lock_age+"���µ�������룡\n"NOR);
		CHANNEL_D->do_channel(this_object(), "sys",user->query("name") + "(" + ob->query("id") + ")�����뿪��Ϸ�ˡ�");	
		user->save();
		destruct(user);
		destruct(ob);
	}
}

varargs void reconnect(object ob, object user, int silent)
{
	object *inv;
	string send;
	int i, j, max;

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);

	if(query_ip_port(ob) != ZMUD_1)
	{
		user->delete("xieyi");
		user->delete("position");
	}

	if(query_ip_port(ob) != ZMUD_2)
		user->delete("xieyi");

	if(query_ip_port(ob) != ZMUD_3)
		user->delete("xieyi");
			
	if(query_ip_port(ob) == ZMUD_1)
	{
		user->set("xieyi/zmud",1);
		user->set("position", "webuser");
	}

	if(query_ip_port(ob) == ZMUD_2)
		user->set("xieyi/zmud",1);

	if(query_ip_port(ob) == ZMUD_3)
		user->set("xieyi/zmud",1);

	if ( ob->query_temp("client_version") )
		user->set("env/myhp_show", 1);
	else
		user->delete("env/myhp_show");

	exec(user, ob);
	user->reconnect();

	if ( interactive(user) )
	{
		object *temp;

		temp = children(USER_OB);
		max = sizeof(temp);
		send = "";
		for ( j=0; j<max; j++ )
		{
			if ( !playerp(temp[j]) ) continue;
			if ( !environment(temp[j]) ) continue;
			if ( user->visible(temp[j]) ) send += ADD2(temp[j]);

			if ( !user->query("xieyi/zmud") && !(j%5) )
			{
				if ( send != "" ) tell_object(user, send);
				send = "";
			}
		}

		if ( send != "" && !user->query("xieyi/zmud") ) 
			tell_object(user, send);

		if ( !user->query("xieyi/zmud") )
		{
			inv = all_inventory(user);
			if ( sizeof(inv) )
			{
				for (i = 0; i < sizeof(inv); i++)
				{
					tell_object(user, ADD1(inv[i]));
				}
			}
		}
	}
	
	if( !silent )
	{
		if(user->query("lixian/biguan"))
		{
			user->delete("lixian/biguan");
			BIGUAN_D->del_bg_user(user);
			
			tell_room(environment(user), user->query("name") + YEL"�չظ�������̤�뽭����\n"NOR,({user}));
			message("channel:chat", HIY"������ˮ�¡���"+HIW"��˵ "HIC+user->query("name")+HIW" �չ���;ͻȻ����,�ƺ�������ռ��������˽�һ���˽⣡\n"NOR,users() );
		}
		else
			tell_room(environment(user), user->query("name") + YEL"�������߻ص�������硣\n"NOR,({user}));
	}

	user->force_me("look");
	
		CHANNEL_D->do_channel( this_object(), "sys",sprintf("%s(%s)��(%s)�������߽��롣", user->query("name"),user->query("id"), query_ip_number(user)) );
	
	UPDATE_D->check_user(user);
	// ������
	if ( stringp(user->query_temp("xyzx_team/name")) )
		TEAMD->del_team_member(user);
}

int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 15 ) )
	{
		write("�Բ������"+HIW"Ӣ��"NOR+"���ֱ����� 3 �� 15 ��Ӣ����ĸ��\n");
		return 0;
	}
	
	while(i--)
	if( id[i]<'a' || id[i]>'z' )
	{
		write("�Բ������"+HIW"Ӣ��"NOR+"����ֻ����Ӣ����ĸ��\n");
		return 0;
	}
	return 1;
}

string random_name()
{
	string *lname = ({
		"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
		"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
		"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
		"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
		"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
		"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
		"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
		"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
		"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
		"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
		"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
		});
		return (lname[random(200)] + chinese_number(random(20)));
}

int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 10 ) )
	{
		write("�Բ�������������ֱ����� 1 �� 5 �������֡�\n");
		return 0;
	}
	
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	
	if( member_array(name, banned_name)!=-1 )
	{
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}
	
	for (i=0;i<sizeof(banned_name);i++)
	if ( strsrch(name, banned_name[i])!=-1)
	{
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}
	return 1;
}

object find_body(string name)
{
	object ob, *body;
	
	if( objectp(ob = find_player(name)) )
		return ob;
	
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i]) && getuid(body[i]) == name )
		return body[i];
	
	return 0;
}

int set_agelock(int setage)
{
	if(wiz_level(this_player(1))< wiz_level("(admin)") )
		return 0;
	
	if(setage==0)
		lock_age=0;
	else
		lock_age=setage;
	
	return 1;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	
	wiz_lock_level = level;
	
	return 1;
}

int set_madlock(int setmark)
{
	if( wiz_level(this_player(1)) < wiz_level("(arch)") )
		return 0;
	
	if( setmark == 1 )
		mad_lock = 1;
	else
		mad_lock = 0;
	
	return 1;
}

int get_madlock()
{
	return mad_lock;
}

protected void get_version(string arg, object ob,int ip_cnt)
{
	object ppl, *usr;
	string Rasc;
	int i, wiz_cnt,usr_cnt;

	Rasc = ob->query_temp("tomud_version");

	if ( sscanf(arg, "%*s"+ascii_num(Rasc) + "2060%*s") )
	{
		if(query_ip_port(ob) == TOMUD_1 || query_ip_port(ob) == TOMUD_2 )
		{
			if ( get_system_config(DATA_CONFIG_DIR "system.h", "VERSION") == 0 )
			{
				if ( !sscanf(arg, "%*s"+ascii_num(Rasc) + "2060_V_1.00%*s") )
                                {
					/*   write(ALERT("��ʹ�õĵ�½��(�ͻ���)�汾���ͣ��뵽��̳�������°汾�Ŀͻ��ˡ�$$$$"
						"�°汾�ͻ��������Ĺ��ܾ������£�$$"
						"�塢������˫�������Ʒ�����ͼ��ɴ���Ʒ���Կ�(��������Ϸ����Ա����ֱ��ͨ�������޸���Ʒ����)$$"
						"�桢�������������ť������ֱ�Ӵ򿪻����������ÿ������и�����������;����ϸ˵����$$"
						"�硢���Ӿ�����Ѫ��������������ʳ���ˮ����״̬��������������Ҳ���þ���������hp���鿴״̬�ˡ�$$"
						"�衢�����ͼ��ť���Դ򿪵�ͼ�Ի���������ͨ����ť����ֱ��ȥһЩ��ȥ�ĵط�����Ҳ���Բ鿴��ǰ��ͼ��$$"
						"�顢��������걨��ť�����ӷ��Ϳ������ͨ��������㷢�ֵ�������ߺõĽ���ֱ�ӷ��͸���Ϸ����Ա��$$"
						"�ꡢ�޸��˿ͻ�����ע��Ϳ���ʹ��ȫ���Ĺ��ܡ�$$"
						"�롢������ԭ���󴰿����ֹ��໻�е����⣬���ڿ�����ȫ������������������Ϣ��ʽ������ʾ��(���۶��ˣ��Ǻ�)$$"
						"�졢�޸���ԭ����who�б��Լ���ͼ��鿴QQ����û��Ӧ�����⣬���ڵ��Լ���ͼ��鿴QQ���ϻ��QQ�������ÿ�$$"
						"�����������촰�ڲ����Զ����������⡣�޸�who�б��ڿͻ��˴���ˢ�¡�$$"
						"������˵��������ͼ����ʱ�ᵼ�´��ں�ͼ��ͬʱ��ʧ�����⡣(��ʱ����������ֻ����������������������̡���)"));
        				*/
                                 }
				else
					ob->set_temp("client_version", 1);
				input_to( (: get_id :), ob,ip_cnt );
			}
			else 
			{
				if ( sscanf(arg, "%*s"+ascii_num(Rasc) + "2060_V_1.00%*s") )
				{
					ob->set_temp("client_version", 1);
					input_to( (: get_id :), ob,ip_cnt );
				}
				else
				{
                                     /*
					write(ALERT("��ʹ�õĵ�½��(�ͻ���)�汾���ͣ��뵽��̳�������°汾�Ŀͻ��ˡ�$$$$"
						"�°汾�ͻ��������Ĺ��ܾ������£�$$"
						"�塢������˫�������Ʒ�����ͼ��ɴ���Ʒ���Կ�(��������Ϸ����Ա����ֱ��ͨ�������޸���Ʒ����)$$"
						"�桢�������������ť������ֱ�Ӵ򿪻����������ÿ������и�����������;����ϸ˵����$$"
						"�硢���Ӿ�����Ѫ��������������ʳ���ˮ����״̬��������������Ҳ���þ���������hp���鿴״̬�ˡ�$$"
						"�衢�����ͼ��ť���Դ򿪵�ͼ�Ի���������ͨ����ť����ֱ��ȥһЩ��ȥ�ĵط�����Ҳ���Բ鿴��ǰ��ͼ��$$"
						"�顢��������걨��ť�����ӷ��Ϳ������ͨ��������㷢�ֵ�������ߺõĽ���ֱ�ӷ��͸���Ϸ����Ա��$$"
						"�ꡢ�޸��˿ͻ�����ע��Ϳ���ʹ��ȫ���Ĺ��ܡ�$$"
						"�롢������ԭ���󴰿����ֹ��໻�е����⣬���ڿ�����ȫ������������������Ϣ��ʽ������ʾ��(���۶��ˣ��Ǻ�)$$"
						"�졢�޸���ԭ����who�б��Լ���ͼ��鿴QQ����û��Ӧ�����⣬���ڵ��Լ���ͼ��鿴QQ���ϻ��QQ�������ÿ�$$"
						"�����������촰�ڲ����Զ����������⡣�޸�who�б��ڿͻ��˴���ˢ�¡�$$"
						"������˵��������ͼ����ʱ�ᵼ�´��ں�ͼ��ͬʱ��ʧ�����⡣(��ʱ����������ֻ����������������������̡���)"));
				     */
					destruct(ob);
				}
			}
			return;
		}
		else
		{
			write(HBRED+HIY"\n��ʹ�õ���Tomud��WWW�ͻ��ˣ���ʹ��ר�ö˿� "HIG+TOMUD_1+HIW" �� "HIG+TOMUD_2+HIY" �������ߣ�\n"NOR);
			destruct(ob);
			return;
		}
	}
	else
	{	
		if(query_ip_port(ob) == TOMUD_1 || query_ip_port(ob) == TOMUD_2 )
		{
			write(HBRED+HIY"\n��ʹ�õ���Zmud�ͻ��ˣ���ʹ��Zmudר�ö˿� "HIG+ZMUD_2+HIW" �� "HIG+ZMUD_3+HIY" �������ߣ�\n"NOR);
			destruct(ob);
			return;
		}
		else
		{
			arg = lower_case(arg);
			
			if( !check_legal_id(arg))
			{
				write(YEL"����������Ӣ�����֣�\n"NOR);
				input_to("get_id", ob,ip_cnt);
				return;
			}

			usr = users();
			wiz_cnt = 0;
			
			for(i=0; i<sizeof(usr); i++)
			{
				if( wizardp(usr[i]) )
					wiz_cnt++;
			}
			
			if( (string)SECURITY_D->get_status(arg)=="(player)" && (sizeof(users()) - wiz_cnt) >= 500)
			{
				ppl = find_body(arg);
				
				// Only allow reconnect an interactive player when MAX_USERS exceeded.
				if( !ppl || !interactive(ppl) )
				{
					write(HIY"�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n"NOR);
					destruct(ob);
					return;
				}
			}
			
			if( wiz_level(arg) < wiz_lock_level )
			{
				write(HIY"�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� "HIG + wiz_lock_level + HIY" ���ϵ��˲������ߡ�\n"NOR);
				destruct(ob);
				return;
			}
			
			if( (string)ob->set("id", arg) != arg ) 
			{
				write("Failed setting user name.\n");
				destruct(ob);
				return;
			}
			
			for (i=0;i<sizeof(banned_id);i++)
			if ( strsrch(arg, banned_id[i])!=-1)
			{
				write(HIY"�Բ�������ʻ���������һ��ʹ�����ڵ�¼���������������Ӣ������\n"NOR);
				write(YEL"����������Ӣ�����֣�\n"NOR);
				input_to("get_id", ob,ip_cnt);
				return;
			}
			
			if( arg=="guest")
			{
				write(HIY"�Բ�����������guest�ʻ���¼���������������Ӣ������\n"NOR);
				write("����"+HIW"Ӣ��"NOR+"���֣�\n");
				input_to("get_id", ob,ip_cnt);
				return;
			}
			ob->set_temp("ip_cnt",ip_cnt);
			/*if (wiz_level(arg)<2)
			{
				if (!BAN_D->is_welcome(arg))
				{
					//if (!BAN_D->is_netclub(query_ip_number(ob)))
					if (ip_cnt > 9)//�����θ���2003��10��18���賿4��,ԭ����ip_cnt>8(��ip��½��Ҹ���)
					{
						write(HIR"���IP���������̫���ˣ����ܽ��룡�� \n"NOR);
						destruct(ob);
						return;
					}
				}
			}*/
			
			if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
			{
				if( ob->restore() )
				{
					// �����Աʶ��
					/*if (ob->query("quyu/rzjh"))
					{
						write(HBRED+HIW"���ʺŹ����ڡ����ڽ��������޷��ڴ�����ʹ�ã���ʹ�������ʺ����µ�½\n"NOR);
						destruct(ob);
						return;
					}*/

					if(wiz_level(arg) > 0)
					{
						write(HIW"��Ŀǰ��Ȩ����"HIY+wizhood(arg)+HIW",Ϊ�˰�ȫ����������뱾վ��ʦ��½Ч���룺\n"NOR);
						input_to("get_wizpas", 1, ob);
					}
					else
					{
						write(YEL"�������������룺\n"NOR);
						input_to("get_passwd", 1, ob);
					}
					return;
				}
				else
				{
					write(HIY"\n�������ﵵ�����˵����⣬����ϵ����ԱQQ 86644296 ���д���\n"NOR);
					destruct(ob);
					return;
				}
			}
			
			usr_cnt=0;
			
			for(i=0; i<sizeof(usr); i++)
			{
				if (usr[i]->query("id")==arg)
					usr_cnt++;
				
				if (usr_cnt>1)
				{
					write(HIY"�Բ�������ʻ���������һ��ʹ�����ڵ�¼���������������Ӣ������\n"NOR);
					write("��������������Ӣ�����֣�\n");
					input_to("get_id", ob,ip_cnt);
					return;
				}
			}
			
			write("ʹ�� "HIW + (string)ob->query("id") + NOR" ������ֽ��ᴴ��һ���µ������ȷ����("HIG"y"NOR"/"HIR"n"NOR")��\n");
			input_to("confirm_id", ob,ip_cnt);
		}
	}
}

protected void cha_mail(string email, object ob)
{
	object user;

	//write("\n");

	if ( email != ob->query("email") )
	{
		write(HIR"\nע������Ч��ʧ�ܣ���ĵ�ַ�ѱ���¼��������������ѯ������ʦ.\n"NOR);
		log_file( "login/bslogin.log", sprintf("%-15s ��ͼ�� %-27s ʹ������½ %-15s ʱע��������֤ʧ��\n",query_ip_number(ob),CHINESE_D->chinese_time(7,ctime(time())),ob->query("id")) );
		destruct(ob);
		return;
	}

	if (!BAN_D->vaild_allow_address(ob))
	{
		destruct(ob);
		return;
	}
	
	user = find_body(ob->query("id"));
	
	if (user)
	{
		if( user->query_temp("netdead") )
		{
			reconnect(ob, user);
			return;
		}
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��("HIG"y"NOR"/"HIR"n"NOR")\n");
		input_to("confirm_relogin", ob, user);
		return;
	}
	
	if( objectp(user = make_body(ob)) )
	{
		if( user->restore() )
		{
			if(time()-(int)user->query("kickout_time") < 600)
			{
				write(HIR"\n������Υ�������߳���Ϸ����Ϊ�ͷ���ʮ���Ӻ������ߡ�\n"NOR);
				destruct(user);
				destruct(ob);
				return;
			}
			
			if(time()-(int)user->query("quit_time") < 15)
			{
				write(HIY"\n����˳���Ϸ��Ϊ�˼���ϵͳ�������Ժ��������룬лл����������\n"NOR);	
				destruct(user);
				destruct(ob);
				return;
			}

			if(query_ip_port(ob) != ZMUD_1)
			{
				user->delete("xieyi");
				user->delete("position");
			}

			if(query_ip_port(ob) != ZMUD_2)
				user->delete("xieyi");

			if(query_ip_port(ob) != ZMUD_3)
				user->delete("xieyi");
			
			if(query_ip_port(ob) == ZMUD_1)
			{
				user->set("xieyi/zmud",1);
				user->set("position", "webuser");
			}

			if(query_ip_port(ob) == ZMUD_2)
				user->set("xieyi/zmud",1);

			if(query_ip_port(ob) == ZMUD_3)
				user->set("xieyi/zmud",1);

			if ( ob->query_temp("client_version") )
				user->set("env/myhp_show", 1);
			else
				user->delete("env/myhp_show");
			
			if(wiz_level(user) > 0)
				log_file( "login/wiz/"+user->query("id"),sprintf("%-20s��%20s  ��    ¼(%s)��\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );
			else
				log_file( "login/login",sprintf("%-20s��%20s  ��    ¼(%s)��\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );
			
			enter_world(ob, user);
			return;
		}
		else
		{
			destruct(user);
		}
	}
	//if ( wiz_level(ob->query("id")) > 0 )
	//{
		write("\n�������´���������\n");
		confirm_id("y", ob,1);
	/*	return;
	} else {
		write(HIY"\n�������ﵵ�����˵����⣬����ϵ����ԱQQ 41689592 ���д���\n"NOR);
		destruct(ob);
		return;
	}*/
}
