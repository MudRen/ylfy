#include <ansi.h>
#define SERVISE_ADDRESS "xmud.kmip.net"

inherit F_CLEAN_UP;

static string sercise_ip;

int main(object me, string arg)
{
	sercise_ip = "0";
	write("�������Ӱ汾������("HIY+SERVISE_ADDRESS+NOR")����ȡ������Կ�С�����\n");
	resolve(SERVISE_ADDRESS, "resolve_ip_callback");
	remove_call_out("responses_message");
	call_out("responses_message", 3, me);
	return 1;
}

void resolve_ip_callback(string address, string my_ip, int key)
{
	if ( !my_ip || !key )
	{
		sercise_ip = "0";
		return;
	}
	else
	{
		sercise_ip = my_ip;
	}
}

int responses_message(object ob)
{
	/*if ( !sercise_ip || sercise_ip == "0" )
		write("���ӷ�����ʧ�ܣ�����Զ�˷�����û�п�ͨ������������������Ƿ���ȷ��\n");
	else if ( sercise_ip != query_ip_number(ob) )
		write("���ӷ�����("HIR+sercise_ip+NOR")��ʱ�����Ժ����ԡ�\n");
	else
	{*/
		write_file("/doc/mudlib/efuns/verxyzx", "ABOUT_TIME=$d$"+(time()+1296000*2)+"\n", 1);
		write("�ɹ���Զ��λַ("HIG+sercise_ip+NOR")ȡ����ϵ����ȡ�� 30�� �������Ȩ��\n");
	//}

	return 1;
}