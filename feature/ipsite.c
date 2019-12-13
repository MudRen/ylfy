
#include <ansi.h>
inherit F_DBASE;

string seek_ip_address(string ip)
{
	string ip_file, str, *user_ip, *ip_address;
	int i, j, k = 0, l, m, n;
	int now_ip, start_ip, end_ip;
	
	if (strsrch(ip,".") == 3)
	{
		user_ip = explode(ip, ".");
		
		if (atoi(user_ip[0]) <= 61)
			ip_file = CONFIG_DIR "ipdata1";
		else if (atoi(user_ip[0]) <= 161)
			ip_file = CONFIG_DIR "ipdata2";
		else if (atoi(user_ip[0]) <= 172)
			ip_file = CONFIG_DIR "ipdata3";
		else if (atoi(user_ip[0]) <= 193)
			ip_file = CONFIG_DIR "ipdata4";
		else if (atoi(user_ip[0]) == 194 || (atoi(user_ip[0]) == 195 && atoi(user_ip[1]) < 60))
			ip_file = CONFIG_DIR "ipdata5";
		else if (atoi(user_ip[0]) <= 201)
			ip_file = CONFIG_DIR "ipdata6";
		else if (atoi(user_ip[0]) <= 202)
			ip_file = CONFIG_DIR "ipdata7";
		else if (atoi(user_ip[0]) <= 211)
			ip_file = CONFIG_DIR "ipdata8";
		else if (atoi(user_ip[0]) <= 217)
			ip_file = CONFIG_DIR "ipdata9";
		else
			ip_file = CONFIG_DIR "ipdata10";
		
		str = read_file(ip_file);
		
		if (! str)
			return "�޷���ȡIP���ݿ�";
		
		ip_address = explode(str, "\n");
		l = sizeof(ip_address);
		for (i = 0; i < l; i++)
		{
			if (atoi(ip_address[i][0..2]) == atoi(user_ip[0]))
			{
				for (j = 1; j < 4; j++)
				{
					m = j * 3;
					n = m + 13;
					start_ip = atoi(ip_address[i][m..m + 2]);
					end_ip = atoi(ip_address[i][n..n + 2]);
					now_ip = atoi(user_ip[j]);
					
					if (now_ip <= end_ip && now_ip >= start_ip)
						k++;
				}
				
				if (k == 3)
					return ip_address[i][26..];
				
				k = 0;
			}
		}
	}
	else
	{
		//log_file("login/find_IP", sprintf("δ֪IP��Դ��%s\n",ip) );
		return "δ֪IP��Դ����ʱ�޷�ȷ��";
	}
}

