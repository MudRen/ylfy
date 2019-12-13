// telnet.c

#include <net/socket.h>
#include <ansi.h>

inherit F_SHADOW;

static string from_user;        // �û�����������Ϣ
static int fd;                  // ����Զ�˻������׽���
static string dest_addr;        // ����Զ�˻����ĵ�ַ
static int port;                // ����Զ�˻����Ķ˿ں�

#define MAX_PENDING_INPUT               16384

// ȡ����������Ļ�������

private void send_to_remote();

void init()
{
}

int is_telneting() { return 1; }

string query_dest_addr() { return sprintf("%s %d", dest_addr, port); }

void telnet_input(string str)
{
	if ( str == "CLOSE" )
	{
		write(HIW"�û��Ͽ������ӡ�\n"NOR);
		destruct(this_object());
		return;
	}

	input_to("telnet_input");

	if ( strlen(str) + strlen(from_user) < MAX_PENDING_INPUT )
	{
		from_user += str + "\n";
		if ( find_call_out("send_to_remote") == -1 )
			send_to_remote();
	} 
	else
		write(HIY"�������̫����...\n"NOR);
}

int clean_up()
{
	if ( query_shadow_now() )
		return 1;

	destruct(this_object());
	return 0;
}

void connect_to(string arg)
{
	if ( sscanf(arg, "%s %d", dest_addr, port) != 2 )
	{
		write("�����ַ����\n");
		return;
	}

	write(HIW"�������ӷ�����("+dest_addr+" "+port+")�����Ժ�...\n"NOR);
	from_user = "";
	resolve(dest_addr, "telnet_resolve_callback");
	input_to("telnet_input");
}

void telnet_resolve_callback(string address, string resolved, int key)
{
	int ret;
	object sob;
	string full_addr;

	if ( !objectp(sob = query_shadow_now()) )
	{
		destruct(this_object());
		return;
	}

	if ( !resolved )
	{ // ��������ʧ��
		// �� IP ���ý���
		if ( sscanf(dest_addr, "%*d.%*d.%*d.%*d") == 4 )
			resolved = dest_addr;
		else
		{
			message("telnet", HIW"��������ʧ��\n"NOR, sob);
			return;
		}
	}
	else if ( resolved != dest_addr ) 
		message("telnet", HIW"����������"+dest_addr+" = "+resolved+"\n"NOR, sob);

	full_addr = sprintf("%s %d", resolved, port);
	fd = socket_create(STREAM, "telnet_read_callback", "telnet_close_callback" );
	
	if ( fd < 0 )
	{
		message("telnet", HIW"���ӳ�ʼ������\n"NOR, sob);
		sob->write_prompt();
        destruct(this_object());
		return;
	}
        
	ret = socket_connect(fd, full_addr, "telnet_read_callback", "telnet_write_callback");
	
	if ( ret != EESUCCESS )
	{
		message("telnet", HIW"�޷����ӷ�����("+full_addr+")"NOR, sob);
		sob->write_prompt();
		destruct(this_object());
		return;
	}

	message("telnet", HIY"��Ҫ�ж����ӣ�������( "HIR"CLOSE"HIY" )\n"NOR, sob);
}

void telnet_read_callback(int fd, string mess)
{
	object sob;

	if ( !objectp(sob = query_shadow_now()) )
	{
		destruct(this_object());
		return;
	}
	// ����������ˣ�sobӦ���������� Add By Wenwu
	if ( !interactive(sob) )
	{
		destruct(this_object());
		return;
	}
	if ( stringp(mess) ) message("telnet", mess, sob);
}

void telnet_write_callback(int fd)
{
	object sob;

	if ( !objectp(sob = query_shadow_now()) )
	{
		destruct(this_object());
		return;
	}

	message("telnet", HIW"���ӳɹ�\n"NOR, sob);

	if ( strlen(from_user) ) send_to_remote();
}

void telnet_close_callback(int fd)
{
	object sob;

	if ( objectp(sob = query_shadow_now()) )
		message("telnet", HIY "�����ѶϿ����밴�س�������...\n" NOR, sob);

	destruct(this_object());
}

void remove()
{
}

void remove_interactive()
{
	destruct(this_object());
}

varargs string short(int raw)
{
	object sob;
	string str;

	if ( objectp(sob = query_shadow_now()) )
	{
		str = sob->short(raw);
		str = replace_string(str, " <����������>", HIY" <Զ�̵�¼��>"NOR);
		return str;
	}

	return 0;
}

// ���û������������ݷ��͵�Զ�˷�������ȥ
private void send_to_remote()
{
	switch ( socket_write(fd, from_user) )
	{
		// ���ͳɹ�
		case EESUCCESS:
		case EECALLBACK:
			from_user = "";
		return;
		// ������������
        case EEWOULDBLOCK:
			call_out("send_to_remote", 2);
			return;
		// ����ʧ��
        default:
			return;
	}
}
