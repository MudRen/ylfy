// File��/adm/daemons/cron.c
// �Լ�ϵͳ

// ϵͳ��� XYZX_REBOOT_TIME Сʱ����
// #define XYZX_REBOOT_TIME 300
// ����ʹ�õ�����ڴ� (Mb)
// #define CAN_USED_MAX_MEM 50

#define DEBUG 1
#define REBOOT_TIME 7

#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;

static int LAST_HARD_DIS;
static int flag = 0;
static int line = 0;
static int reboot_time = 0;

void start_task();
void autosave();
void auto_clear();
void check_dns();
void check_nature();
void check_callouts();
void check_neicun();
void add_top();

int set_last_hard_dis();

void create()
{
	seteuid( ROOT_UID );
	set("channel_id", "�ػ�����");
	CHANNEL_D->do_channel( this_object(), "sys", "�ػ������Ѿ�������\n"NOR);
	set_heart_beat(90);
	set_last_hard_dis();
}

int clean_up()
{
	return 1;
}

int query_last_hard_dis()
{
	return LAST_HARD_DIS;
}

int set_last_hard_dis()
{
	LAST_HARD_DIS = time();
	return flag;
}

private void heart_beat()
{
	object npc;
	int time, m, s;
	
	// ͨ����Ϸ��ҳ��ַ
	//message("system",HIG"��"BRED+HIY"��Ϸ����"NOR+HIG"��"HIW"��"HBBLU"��ҳ:"+get_system_config(DATA_CONFIG_DIR "system.h", "XYZX_WEB")+"\n"NOR,users());
	//message("system",HIG"��"BRED+HIY"��Ϸ����"NOR+HIG"��"HIW"��"HBBLU"��̳:"+get_system_config(DATA_CONFIG_DIR "system.h", "XYZX_BBS")+"\n"NOR,users());

	remove_call_out("start_task");
	call_out("start_task", 60);

	time = get_system_config(DATA_CONFIG_DIR "system.h", "REBOOT_TIME") * 3600 - uptime();
	m = time / 60;
	s = time % 60;

	if ( (int)uptime() / 3600 == get_system_config(DATA_CONFIG_DIR "system.h", "REBOOT_TIME") - 1 )
	{
		message("channel:chat",HIR"��ϵͳ���顿"HIY"Ϧ������ ֮ [һ����ʦ] "HIW"��������ʱ�仹�� "HIY + m + " �� "HIG + s +" �롣\n"NOR, users());
	}

	if ( reboot_time == 0 && (int)uptime() / 3600 == get_system_config(DATA_CONFIG_DIR "system.h", "REBOOT_TIME") )
	{
		npc = new("/clone/npc/demogorgon");
		npc->move("/d/wizard/meeting");
		npc->start_shutdown();
		write_file("/log/static/LASTCRASH", "Ϧ������-��֮���� �Զ������� " + ctime(time()) + "\n");
		reboot_time++;
	}
}

void start_task()
{
	mixed *local;	
	local = localtime(time());
	
	if ( !(local[1] % 7 ))
	{
		auto_clear();
		check_neicun();
	}
	
	if ( !(local[1] % 15 ))
	{
		// ���CALLOUT
		if( LOGIN_D->get_madlock() != 1 )
			check_callouts();
    }
	
	if (local[1]==20 || local[1]==40 )
	{
		TASK_D->init_dynamic_quest();
		message("system",HIY"\n\n��"HIR"������"HIY"��-----"HIG"���·ֲ�����ʹ������������\n\n" NOR,users());
	}
	
	if (flag==1)
	{
		TASK_D->init_dynamic_quest(1);
		flag=0;
		set_last_hard_dis();
		message("system",HIY"\n\n��"HIR"������"HIY"��-----"HIG"���·ֲ�����ʹ������������\n\n" NOR,users());
	}
	
	if (local[1]==59 || ((int)time()-(int)query_last_hard_dis()) > 3720)
	{
		flag=1;
		CHANNEL_D->do_channel( this_object(), "sys", HIR "����ʹ������һ���Ӻ����·ֲ�������\n"NOR);
		//autosave();
	}
	
	if (local[1]==45 || local[1]==15 )
	{
		// check_dns();
		// check_nature();
		add_top();
	}
}

// ����������ҵĵ��������win2000����ػ������µĵ�������
void autosave()
{
	object *users;

	users = users();
	foreach(object ob in users)
	{
		if( !environment(ob) )
			continue;

		//������Ŀ¼
		if ( file_size("/backtemp/") == -1 )
			mkdir("backtemp");

		if ( file_size("/backtemp/login/") == -1 )
			mkdir("/backtemp/login");

		if ( file_size("/backtemp/user/") == -1 )
			mkdir("/backtemp/user");
		
		if ( file_size("/backtemp/login/" + ob->query("id")[0..0] + "/") == -1 )
			mkdir("/backtemp/login/" + ob->query("id")[0..0]);
			
		cp((DATA_DIR+"/login/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"),("/backtemp/login/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"));

		if ( file_size("/backtemp/user/" + ob->query("id")[0..0] + "/") == -1 )
			mkdir("/backtemp/user/" + ob->query("id")[0..0]);
		
		cp((DATA_DIR+"/user/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"),("/backtemp/user/"+ob->query("id")[0..0]+"/"+ob->query("id")+".o"));
	}
	
	message("system",HIG"\n��"HIR"��������"HIG"��"HIW"��"HIY"�������ݱ������\n", users());
}

// �����Զ�����ı���
void auto_clear()
{
	string *msg;
	int i;

	CHANNEL_D->do_channel( this_object(), "sys",sprintf("ϵͳ�Զ���� " + reclaim_objects() + " ��������"NOR));
	
	if(file_size("/data/caipiao/call")!=-1)
	{
		msg = explode(read_file("/data/caipiao/call"),"\n");
		for(i=0;i<sizeof(msg);i++)
		{
			if (msg[i] == "")
				break;

			message("channel:chat",HIW+msg[i]+NOR"\n",users());
		}
	}
}

// ���DNS
void check_dns()
{
	mapping mud_list;
	mixed *muds;
	object dns;
	
	// dns not started, not our problem
	if(!dns = find_object(DNS_MASTER))
		return;
	
	mud_list = (mapping) DNS_MASTER->query_muds();
	muds=keys(mud_list);
	
	if(sizeof(muds)<= 1)
	{
		destruct(dns);
		call_other(DNS_MASTER,"???");
	}
	return;
}

// ���NATURE
void check_nature()
{
	mixed *infos;
	object ob;
	int nature=0;
	
	infos = call_out_info();
	foreach(mixed info in infos)
	{
		if( "/"+sprintf("%O",info[0]) == NATURE_D )
			nature=1;
	}
	
	if(!nature)
	{
		if(ob=find_object(NATURE_D)) destruct(ob);
		call_other(NATURE_D,"???");
	}
	return;
}

// ���CALLOUT��ִ��
void check_callouts()
{
	mixed *info;
	int i,f=0;
	string output;
	object *users, link_ob;
	
	info = call_out_info();
	for(i=0; i<sizeof(info); i++)
	{
		if(info[i][2]<info[f][2])
		{
			f=i;
		}
	}
	
	if(info[f][2] > -100)
	{
		CHANNEL_D->do_channel( this_object(), "sys", HIW"CALLOUT��ⱨ��---"HIG"״̬������\n"NOR);
		return;
	}
	
	users = users();
	
	if( flag!=2 )
	{
		flag = 2;
		message("system",HIB"\n��"HIG"�ػ�����"HIB"��"HIW"��"HIR"��Ϸ���ֹ��ϣ�ϵͳ�Զ����ʱ�ա�\n"NOR,users());
		output = sprintf("%-30O %-20s %d ",info[f][0], info[f][1],info[f][2]);
		log_file("CALLOUTS_ERR",output + ctime(time())+"\n");
		return;
	}
	else
		CHANNEL_D->do_channel( this_object(), "sys", HIW"CALLOUT��ⱨ��---"HIG"״̬������\n"NOR);
	
	message("system",HIR"\n��"HIG"ϵͳ����"HIR"��"HIW"�����ڱ�����������У�����\n"NOR, users());
	foreach(object user in users)
	{
		if( !environment(user) ) continue;
		user->save();
		
		link_ob = user->query_temp("link_ob");
		if( objectp(link_ob) )
			link_ob->save();
	}
	// �������е��ػ����̵�����
	reset_eval_cost();
	// ��ֹ��Ҽ�����½
	LOGIN_D->set_madlock(1);
	// if (find_object(DNS_MASTER)) DNS_MASTER->send_shutdown();
	log_file("static/MADLOCK",sprintf("ϵͳ��Ϊ�����Զ����ʱ����%s\n",ctime(time())) );
	message("system",HIR"\n��"HIG"ϵͳ����"HIR"��"HIW"��"HIY"������������ϣ����Ҿ�����ʦ��������\n\n"NOR, users());
}

// ���ϵͳ�ڴ�ʹ����������������Զ������ͷ��ڴ�
void check_neicun()
{
	object npc;

	if ( memory_info() > get_system_config(DATA_CONFIG_DIR "system.h", "CAN_USED_MAX_MEM") * 1048576 )
	{
		message("system",HIY"\n\n\n\n\n�ػ����飺"HIR"ϵͳ���������滮��Χ��ϵͳ��ά���Ե�������������\n"+
		"��        ��Ϸ����֮ǰ����������֪ͨ��\n"NOR,users());
		/*if( find_object(DNS_MASTER) )
			DNS_MASTER->send_shutdown();
		NATURE_D->auto_shutdown(1);*/
		npc = new("/clone/npc/demogorgon");
		npc->move("/d/wizard/meeting");
		npc->start_shutdown();
		write_file("/log/static/LASTCRASH", "Ϧ������-��֮���� ���ڴ�ά�������� " + ctime(time()) + "\n");
	}
	else
		CHANNEL_D->do_channel( this_object(), "sys", HIY"�ڴ��ⱨ��---"HIG"״̬����\n"NOR);
}

//�Զ����¸���״̬������
void add_top()
{
	"/cmds/bos/topadd-sys"->main();
	CHANNEL_D->do_channel( this_object(), "sys",sprintf(HIC"���а��Զ�������ϡ�\n"NOR));
}
