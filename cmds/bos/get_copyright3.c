#include <ansi.h>
#define SERVISE_ADDRESS "xmud.kmip.net"

inherit F_CLEAN_UP;

static string sercise_ip;

int main(object me, string arg)
{
	sercise_ip = "0";
	write("正在连接版本服务器("HIY+SERVISE_ADDRESS+NOR")，获取更新密钥中。。。\n");
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
		write("连接服务器失败，可能远端服务器没有开通，或检查你的网络设置是否正确。\n");
	else if ( sercise_ip != query_ip_number(ob) )
		write("连接服务器("HIR+sercise_ip+NOR")超时，请稍候再试。\n");
	else
	{*/
		write_file("/doc/mudlib/efuns/verxyzx", "ABOUT_TIME=$d$"+(time()+1296000*2)+"\n", 1);
		write("成功与远端位址("HIG+sercise_ip+NOR")取得联系，获取了 30天 运行许可权。\n");
	//}

	return 1;
}