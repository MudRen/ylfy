
// ÿ��ִ��ָ����
#define XYZX_XIULIAN_CISHU 5
// ÿ�δ������ִ�е�ָ����
#define MAX_CHUFA_CMDS 5

string xiulian_cmds_jiexi(string str);

int do_xyzx_xiulian()
{
	string file, *file_list, hy;
	int i, m, year, mon, day;

	// ÿ��ִ�г�ʽ�����Ի�Ϊ0���Ա��¼
	m = 0;

	if ( !this_object()->query("lixian/biguan") || interactive(this_object()) )
		return 0;
	
	// ��ע���ԱǱ�ܲ�������ʽ��ֹ
	if ( stringp(hy = this_object()->query("xy_huiyuan")) )
	{
		if ( !sscanf(hy, "%d��%d��%d��", year, mon, day) )
		{
			if ( !this_object()->query("potential") || this_object()->query("potential") < 1 )
				return 0;
		}
	}
	else
	{
		// �ǻ�ԱǱ�ܲ�������ʽ��ֹ
		if ( !this_object()->query("potential") || this_object()->query("potential") < 1 )
			return 0;
	}

	// ���ָ��ļ��Ƿ����
	if ( file_size(DATA_DIR + "biguan/" + this_object()->query("id") + __SAVE_EXTENSION__) == -1 )
		return 0;
	
	// ��ȡ�ļ�����
	file = read_file(DATA_DIR + "biguan/" + this_object()->query("id") + __SAVE_EXTENSION__);
	// �����ļ�����Ϊָ�
	file_list = explode(file,"\n");

	if ( this_object()->query_temp("do_xiulian_num") )
	{
		if ( i >= sizeof(file_list) )
			i = 0;
		else
			i = this_object()->query_temp("do_xiulian_num");
	}
	else
		i = 0;

	for (i = 0; i < sizeof(file_list); i++)
	{
		// �� Busy ����ָ��ִ��
		if ( this_object()->is_busy() )
			break;

		// ����״��̫�����ָ��ִ��
		if ( this_object()->query("jing") * 100 / this_object()->query("max_jing") < 5 || this_object()->query("qi") * 100 / this_object()->query("max_qi") < 5 )
			break;

		// ˯�Ρ��������ж�ָ��ִ��
		if ( this_object()->query_temp("block_msg") )
			break;

		// ִ�� XYZX_XIULIAN_CISHU ��ʱ��ֹ�ô�����
		if ( m >= XYZX_XIULIAN_CISHU )
			break;

		// ��ע���ԱǱ�ܲ����ж�ָ��ִ��
		if ( stringp(hy) )
		{
			if ( !sscanf(hy, "%d��%d��%d��", year, mon, day) )
			{
				if ( !this_object()->query("potential") || this_object()->query("potential") < 1 )
					break;
			}
		}
		else
		{
			// �ǻ�ԱǱ�ܲ����ж�ָ��ִ��
			if ( !this_object()->query("potential") || this_object()->query("potential") < 1 )
				break;
		}

		this_object()->command(this_object()->xiulian_cmds_jiexi(file_list[i]));
		// ��¼ָ�ִ�е�λ��
		this_object()->add_temp("do_xiulian_num", 1);
		m++;
		
		// �ǻ�Ա��Ҫ����Ǳ��
		if ( stringp(hy) )
		{
			if ( !sscanf(hy, "%d��%d��%d��", year, mon, day) )
				this_object()->add("potential",-1);
		}
		else
			this_object()->add("potential",-1);

		if ( this_object()->query_temp("do_xiulian_num") == sizeof(file_list) )
		{
			this_object()->delete_temp("do_xiulian_num");
			break;
		}
	}

	return 1;
}

// ���ߴ�������
int do_xyzx_chufa(string cmds)
{
	string *cmd, cmd_buffer, *cmded;
	int i, v;

	if ( !stringp(cmds) ) 
	{ // ֻ�����ַ���
		this_object()->delete_temp("chufa_buffer");
		return 0;
	}
	if ( !sscanf(cmds, "%*s-%*s") )
	{ // ֻ��һ������
		this_object()->command(this_object()->xiulian_cmds_jiexi(cmds));
		this_object()->delete_temp("chufa_buffer");
		return 1;
	}

	cmd = explode(cmds, "-");
	v = sizeof(cmd);
	cmded = ({ });

	for ( i=0; i<v; i++ )
	{
		if ( i >= MAX_CHUFA_CMDS ) break; // ÿ�����ִֻ�� MAX_CHUFA_CMDS ��ָ��
		if ( this_object()->is_busy() ) break; // �� Busy ����ָ��ִ��
		if ( this_object()->query("jing") * 100 / this_object()->query("max_jing") < 5 
			|| this_object()->query("qi") * 100 / this_object()->query("max_qi") < 5 )
			break; // ����״��̫�����ָ��ִ��
		if ( this_object()->query_temp("block_msg") ) break; // ˯�Ρ��������ж�ָ��ִ��
		this_object()->command(this_object()->xiulian_cmds_jiexi(cmd[i])); // ִ��ָ��
		cmded += ({ cmd[i] });
	}
	
	cmd -= cmded;

	if ( !arrayp(cmd) || !sizeof(cmd) ) // ����ָ��ɹ�ִ�����
		this_object()->delete_temp("chufa_buffer");
	else
	{ // ��δִ�����ָ����뻺����
		cmd_buffer = implode(cmd, "-");
		this_object()->set_temp("chufa_buffer", cmd_buffer);
	}

	return 1;
}

// ָ�����
string xiulian_cmds_jiexi(string str)
{
	mapping alias = this_object()->query_all_alias();
	string cmd, argstr, *args;
	int i, j;

	if( mapp(alias) ) 
	{
        if( !undefinedp(alias[str]) )
            return replace_string( alias[str], "$*", "" );
        
		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) 
		{
			if ( sscanf(alias[cmd], "%*s$%*s") )
			{
				cmd = replace_string( alias[cmd], "$*", argstr );
				if ( sscanf(argstr, "%*s %*s") )
				{
					args = explode(argstr, " ");
					if( (j = sizeof(args)) )
					{
						for(i=0; i<j; i++)
						{
							cmd = replace_string( cmd, "$" + (i+1), args[i] );
						}
					}
				}
			}
			else
				cmd = alias[cmd] + " " + argstr;
			return cmd;
        }
    }

	cmd = (string)ALIAS_D->process_global_alias(str);
	if ( this_object()->query_temp("big5") ) cmd = LANGUAGE_D->Big52GB(cmd);
	return cmd;
}