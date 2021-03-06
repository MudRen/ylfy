// fileserver By Wenwu On 2006年7月2日
// 文件传送服务 v1.0.0.0
// 为了方便更新分站版本随手写的一个简单网络服务

#define FILE_SERVER_DEBUG
#define FILE_SERVER_PASSWD "Ll12345"

#include <ansi.h>
#include <net/socket.h>
#include <runtime_config.h>

inherit F_DBASE;

// 主站通讯 SOCKET
int send_file_socket;
// 连接的远端 IP
string to_addr;
// 连接的远端 端口
int send_file_port;
// 分站通讯 SOCKET
int server_socket;

// 分站通讯端口
#ifdef __SENSIBLE_MODIFIERS__
int server_port = get_config(15);
#else
int server_port = get_config(__MUD_PORT__);
#endif

// 文件内容
string send_file_arg = "";
// 文件路径(初始化为临时文件 /temp.c)
string send_file_name = "/temp.c";
// 文件路径(初始化为临时文件 /temp.c)
string save_file_name = "/temp.c";
// 通讯密码
string server_passwd = "12345";
// 接收到的数据
string all_file_arg = "";

// 内部使用函数
protected void setup();
protected void listen_server();
protected void server_listen_callback(int fd);
protected void server_write_callback(int fd);
protected void server_read_callback(int fd, mixed mess);
protected void server_close_callback(int fd);
void file_resolve_callback(string address, string resolved, int key);
void file_read_callback(int fd, string mess);
void file_write_callback(int fd);
void file_close_callback(int fd);
private void send_to_remote();

// 外部使用函数
void connect_to(string arg, string file);

void create()
{
	seteuid(getuid());

	set("channel_id", "网络服务");
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务已经启动。\n"NOR);

	// 初始化
	setup();
}

protected void setup()
{
	// 开始监听
	call_out("listen_server", 3);
	return;
}

protected void listen_server()
{
	// 建立监听 SOCKET
	server_socket = socket_create(STREAM, "server_read_callback", "server_close_callback");

	if ( server_socket < 0 )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：创建监听 SOCKET 失败。\n"NOR);
		log_file("/net/net_server", sprintf("创建监听 SOCKET 失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	if ( socket_bind(server_socket, server_port) < 0 )
	{
		// 关闭 SOCKET
		if ( server_socket )
			socket_close(server_socket);
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：命名监听 SOCKET 失败。\n"NOR);
		log_file("/net/net_server", sprintf("命名监听 SOCKET 失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 已关闭。\n"NOR);
		log_file("/net/net_server", sprintf("监听 SOCKET 已关闭 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	// 开始监听
	if ( socket_listen(server_socket, "server_listen_callback" ) < 0 )
	{
		// 关闭 SOCKET
		if ( server_socket )
			socket_close(server_socket);
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 失败。\n"NOR);
		log_file("/net/net_server", sprintf("监听 SOCKET 失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 已关闭。\n"NOR);
		log_file("/net/net_server", sprintf("监听 SOCKET 已关闭 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务：开始监听 SOCKET 。\n"NOR);
	log_file("/net/net_server", sprintf("开始监听 SOCKET On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

protected void server_listen_callback(int fd)
{
	int new_fd;

	if ( (new_fd = socket_accept(fd, "server_read_callback", "server_write_callback")) < 0 )
		return;

	server_write_callback(new_fd);
#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 授权远端位址允许传送文件。\n"NOR);
	log_file("/net/net_server", sprintf("监听 SOCKET 授权远端位址允许传送文件 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

protected void server_write_callback(int fd)
{
	switch (socket_write(fd, "成功接受连接"))
	{
		// 发送成功
		case EESUCCESS:
		case EECALLBACK:
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 成功应答信息。\n"NOR);
			log_file("/net/net_server", sprintf("监听 SOCKET 成功应答信息 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		
		// 发送数据阻塞
		case EEWOULDBLOCK:
			call_out("server_write_callback", 3);
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 应答信息阻塞，三秒后重新发送。\n"NOR);
			log_file("/net/net_server", sprintf("监听 SOCKET 应答信息阻塞，三秒后重新发送 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
			
		default:
			// 发送失败
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 应答信息失败。\n"NOR);
			log_file("/net/net_server", sprintf("监听 SOCKET 应答信息失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
	}
}

protected void server_read_callback(int fd, mixed mess)
{
	string file_name, file_arg, pass, *file_dir, file_dir_add;
	int i;

	if ( !stringp(mess) )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 接收文件失败。\n"NOR);
		log_file("/net/net_server", sprintf("监听 SOCKET 接收文件失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	if ( all_file_arg == "" )
	{
		if ( sscanf(mess, "@@@%s#@#%s@@@##%s", file_name, pass, file_arg) != 3 )
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 解析信息包失败。\n"NOR);
			log_file("/net/net_server", sprintf("监听 SOCKET 解析信息包失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		}

		if ( pass != FILE_SERVER_PASSWD )
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：服务密码验证失败，监听 SOCKET 拒绝了文件接收。\n"NOR);
			log_file("/net/net_server", sprintf("服务密码验证失败，监听 SOCKET 拒绝了文件接收 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		}

#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：服务密码验证通过，开始接收文件。\n"NOR);
		log_file("/net/net_server", sprintf("服务密码验证通过，开始接收文件 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif

		save_file_name = file_name;
		// 文件路径不存在，则新建文件路径(注意：文件路径格式必须是 "/***/***" 的格式)
		file_dir = explode(save_file_name, "/");
		file_dir_add = "";
		for ( i =0; i < sizeof(file_dir) - 1; i++ )
		{
			if ( file_dir[i] != "" )
				file_dir_add += ("/" + file_dir[i]);
			if ( file_dir_add != "" && file_dir_add != "/" )
				mkdir(file_dir_add);
		}

		if ( sscanf(file_arg, "%s###END***", file_arg) == 1 )
		{
			all_file_arg = file_arg;
			write_file(save_file_name, all_file_arg, 1);
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 成功接收到文件(" + save_file_name + ")。\n"NOR);
			log_file("/net/net_server", sprintf("监听 SOCKET 成功接收到文件(" + save_file_name + ") On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			save_file_name = "/temp.c";
			all_file_arg = "";
		}
		else
		{
			all_file_arg = file_arg;
			write_file(save_file_name, all_file_arg, 1);
		}
	}
	else
	{
		if ( sscanf(mess, "%s###END***", file_arg) == 1 )
		{
			all_file_arg = file_arg;
			write_file(save_file_name, all_file_arg);
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 成功接收到文件(" + save_file_name + ")。\n"NOR);
			log_file("/net/net_server", sprintf("监听 SOCKET 成功接收到文件(" + save_file_name + ") On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			save_file_name = "/temp.c";
			all_file_arg = "";
		}
		else
		{
			all_file_arg = mess;
			write_file(save_file_name, all_file_arg);
		}
	}

	return;
}

protected void server_close_callback(int fd)
{
	// 关闭 SOCKET
	if ( server_socket )
		socket_close(server_socket);

	// 30秒后重新开始监听
	call_out("listen_server", 30);
	return;

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务：监听 SOCKET 断开连接。\n"NOR);
	log_file("/net/net_server", sprintf("监听 SOCKET 断开连接 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

void connect_to(string arg, string str)
{
	string file, pass;

	if ( sscanf(arg, "%s %d", to_addr, send_file_port) != 2 )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：连接的远端位址错误。\n"NOR);
		log_file("/net/net_server", sprintf("连接的远端位址错误 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

	if ( sscanf(str, "%s#%s", file, pass) != 2 )
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：被拒绝的命令格式。\n"NOR);
		log_file("/net/net_server", sprintf("被拒绝的命令格式 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务：解析远端地址中。\n"NOR);
	log_file("/net/net_server", sprintf("解析远端地址中 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	send_file_name = file;
	send_file_arg = read_file(file);
	server_passwd = pass;
	resolve(to_addr, "file_resolve_callback");
}

void file_resolve_callback(string address, string resolved, int key)
{
	int ret;
	string full_addr;
	
	while (1)
	{
		if ( ! resolved )
		{
			if ( sscanf(to_addr, "%*d.%*d.%*d.%*d") == 4 )
				resolved = to_addr;
			else
			{
#ifdef FILE_SERVER_DEBUG
				CHANNEL_D->do_channel( this_object(), "sys", "文件服务：无法解析远端地址。\n"NOR);
				log_file("/net/net_server", sprintf("无法解析远端地址 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
				break;
			}
		}
		
		full_addr = sprintf("%s %d", resolved, send_file_port);
		send_file_socket = socket_create(STREAM, "file_read_callback", "file_close_callback" );
		
		if ( send_file_socket < 0 )
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：文件发送 SOCKET 初始化失败。\n"NOR);
			log_file("/net/net_server", sprintf("文件发送 SOCKET 初始化失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			break;
		}
		
		ret = socket_connect(send_file_socket, full_addr, "file_read_callback", "file_write_callback");
		
		if (ret != EESUCCESS)
		{
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：网络连接错误。\n"NOR);
			log_file("/net/net_server", sprintf("网络连接错误 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			break;
		}
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：正在连接" + address + "(" + full_addr + ")。。。\n"NOR);
		log_file("/net/net_server", sprintf("正在连接%s(%s) On %s。\n", address, full_addr, CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}
}

void file_read_callback(int fd, string mess)
{
	if (stringp(mess))
	{
#ifdef FILE_SERVER_DEBUG
		CHANNEL_D->do_channel( this_object(), "sys", "文件服务：接收到远端应答信息。\n"NOR);
		log_file("/net/net_server", sprintf("接收到远端应答信息 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
		return;
	}
}

void file_write_callback(int fd)
{
	send_to_remote();
}

void file_close_callback(int fd)
{
	// 关闭 SOCKET
	if ( send_file_socket )
		socket_close(send_file_socket);

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务：文件发送 SOCKET 断开连接。\n"NOR);
	log_file("/net/net_server", sprintf("文件发送 SOCKET 断开连接 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
	return;
}

private void send_to_remote()
{
	string msg;
	msg = "@@@" + send_file_name + "#@#" + server_passwd + "@@@##" + send_file_arg + "###END***";
	
	switch ( socket_write(send_file_socket, msg) )
	{
		// 发送成功了
		case EESUCCESS:
			//call_out("file_close_callback", 0);
		case EECALLBACK:
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：发送文件(" + send_file_name + ")成功。\n"NOR);
			log_file("/net/net_server", sprintf("发送文件(" + send_file_name + ")成功 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
		
		// 发送数据阻塞
		case EEWOULDBLOCK:
#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：发送文件阻塞，三秒后重新发送。\n"NOR);
			log_file("/net/net_server", sprintf("发送文件阻塞，三秒后重新发送 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			call_out("send_to_remote", 3);
			return;
			
		default:
			// 发送失败，关闭 SOCKET
			if ( send_file_socket )
				socket_close(send_file_socket);

#ifdef FILE_SERVER_DEBUG
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：发送文件失败。\n"NOR);
			log_file("/net/net_server", sprintf("发送文件失败 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
			CHANNEL_D->do_channel( this_object(), "sys", "文件服务：文件发送 SOCKET 已关闭。\n"NOR);
			log_file("/net/net_server", sprintf("文件发送 SOCKET 已关闭 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif
			return;
	}
}

// 析构函数
void remove(string euid)
{
	if ( send_file_socket )
		socket_close(send_file_socket);

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务：服务终止，文件传送 SOCKET 关闭。\n"NOR);
	log_file("/net/net_server", sprintf("服务终止，文件传送 SOCKET 关闭 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif

	if ( server_socket )
		socket_close(server_socket);

#ifdef FILE_SERVER_DEBUG
	CHANNEL_D->do_channel( this_object(), "sys", "文件服务：服务终止，监听 SOCKET 关闭。\n"NOR);
	log_file("/net/net_server", sprintf("服务终止，监听 SOCKET 关闭 On %s。\n", CHINESE_D->chinese_time(7,ctime(time()))));
#endif

	return;
}