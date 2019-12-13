// ���߱չ�ָ� By ������(Wenwu) On 2006��1��21��

#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str, *str_list, msg, chufa_msg, chufa_cmds;
	int i, line;

	if ( !arg || arg == "" )
	{
		if ( file_size(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__) > 0 )
		{
			write(HIC"��Ŀǰ���趨�еĴ������£�\n"NOR);
			str = read_file(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__);
			msg = HIW"";

			str_list = explode(str,"\n");
			for (i = 0; i < sizeof(str_list); i++)
			{
				if ( sscanf(str_list[i], "%s:%s", chufa_msg, chufa_cmds) )
				{
					chufa_cmds = replace_string(chufa_cmds, "-", ";");
					msg += "-----------------------------------------------\n";
					msg += "(" + chinese_number(i+1) + ")\n";
					msg += HIY"�����ַ���"HIW + chufa_msg + "\n";
					msg += HIY"����ָ�"HIW + chufa_cmds + "\n";
					msg += "-----------------------------------------------\n";
				}
			}

			msg += "\n"NOR;
			me->start_more(msg);

			return 1;
		}
		else
			return notify_fail(HIW"ָ���ʽ��setchufa �����ַ�:ִ��ָ��\n"HIY"[��ʾ���������ö��ָ�ÿ��ָ��֮����һ��[-]�����]\n"NOR);
	}
	
	if ( arg == "-r" )
	{
		if ( file_size(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__) >= 0 )
		{
			rm(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__);
			write(HIW"�ɹ�����������á�\n"NOR);
			return 1;
		}
		else
		{
			write(HIW"�㲢û�����ô�����\n"NOR);
			return 1;
		}
	}

	if ( sscanf(arg, "-r %d", line) )
	{
		if ( file_size(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__) > 0 )
		{
			str = read_file(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__);
			str_list = explode(str,"\n");
			
			if ( line > sizeof(str_list) )
				return notify_fail(HIY"�� " + chinese_number(line) +" ���������ò����ڡ�\n"NOR);

			msg = "";

			for (i = 0; i < sizeof(str_list); i++)
			{
				if ( i + 1 == line )
				{
					if ( sscanf(str_list[i], "%s:%s", chufa_msg, chufa_cmds) )
					{
						chufa_cmds = replace_string(chufa_cmds, "-", ";");
						write(HIR"��ɹ�ɾ����" + chinese_number(line) + "���������£�\n");
						write("-----------------------------------------------\n");
						write(HIY"�����ַ���"HIW + chufa_msg + "\n");
						write(HIY"����ָ�"HIW + chufa_cmds + "\n");
						write("-----------------------------------------------\n");
					}

					continue;
				}

				msg += str_list[i] + "\n";
			}

			write_file(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__, msg, 1);
			return 1;
		}
		else
			return notify_fail(HIY"��Ŀǰ��û�д������á�\n"NOR);
	}

	if ( arg == "-stop" )
	{
		if ( me->query("xyzx_chufa_stop") )
			return notify_fail(HIY"�㲢û�п����������ܣ�����Ҫ�ٹرա�\n"NOR);

		me->set("xyzx_chufa_stop", 1);
		write(HIR"��ر��˴������ܡ�\n"NOR);
		return 1;
	}

	if ( arg == "-run" )
	{
		if ( !me->query("xyzx_chufa_stop") )
			return notify_fail(HIY"�㲢û�йرմ������ܣ�����Ҫ�ٿ�����\n"NOR);

		me->delete("xyzx_chufa_stop");
		write(HIG"�㿪���˴������ܡ�\n"NOR);
		return 1;
	}

	if ( strlen(arg) > 300 )
		return notify_fail(HIY"��Ĵ����趨̫���ˣ��������300���ֽ����ڣ�\n"NOR);

	if ( file_size(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__) > 0 )
	{
		str = read_file(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__);
		str_list = explode(str,"\n");

		if ( sizeof(str_list) >= CHUFA_CMD_SIZE )
			return notify_fail(HIY"��ֻ������" + chinese_number(CHUFA_CMD_SIZE) + "����������Ҫɾ��һЩ�������ܼ������á�\n"NOR);
	}

	if ( sscanf(arg, "%s:%s", chufa_msg, chufa_cmds) )
	{
		if ( write_file(DATA_DIR + "chufa/" + me->query("id") + __SAVE_EXTENSION__, chufa_msg + ":" + chufa_cmds + "\n") )
		{
			chufa_cmds = replace_string(chufa_cmds, "-", ";");
			write(HIG"��ɹ�������һ���������£�\n");
			write("-----------------------------------------------\n");
			write(HIY"�����ַ���"HIW + chufa_msg + "\n");
			write(HIY"����ָ�"HIW + chufa_cmds + "\n");
			write("-----------------------------------------------\n");
		}
		else
			write(HIW"���Ӵ���ʧ�ܡ�\n");
	}
	else
		return notify_fail(HIW"ָ���ʽ��setchufa �����ַ�:ִ��ָ��\n"HIY"[��ʾ���������ö��ָ�ÿ��ָ��֮����һ��[-]�����]\n"NOR);

	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��
[һ]������һ��������setchufa �����ַ�:ִ��ָ��
      ���磺���봥�����˹���ϡ���Ҳ������Ļ�ϳ��֡��˹���ϡ����Ҿ�
      �����������ڣ���ô���ǿ�����������ô���ã�
      setchufa �˹����:dazuo 100
      ִ�п�������ᷢ��ֻҪ��Ļ��һ���֡��˹���ϡ���Щ�֣�ϵͳ�ͻ�
      �Զ�������100������������
      Ҳ������ʣ����������Ļ�ϳ��֡��˹���ϡ����ȶ���һ���ٴ�����
      Ҳ������Ļ�ϳ��֡��˹���ϡ�ʱͬʱִ������ָ�����ô�����أ�
      �ܼ򵥣���ֻ��Ҫ�Ѹ���ָ��֮����һ��[-]������Ϳ����ˡ����£�
      setchufa �˹����:study book-dazuo 100
      ϵͳ�ͻ�����Ļ�ϳ��֡��˹���ϡ�ʱ���Ȱ���������һ���ٴ����ˡ�
      ��ȻҲͬ���߼ƻ�����һ��Ҳ��֧�� alias ��ָ��ġ�
[��]���鿴���õ����д�����setchufa
[��]��ɾ��һ��������setchufa -r ����
      ˵����������־�����Ҫɾ��������������λ�ã�����ͨ��setchufa
      �鿴��Ҫɾ��������������λ�á�
[��]��ɾ�����д�����setchufa -r
[��]���رմ�����setchufa -stop
[��]������������setchufa -run
ע�⣺��������ʱ��ϵͳֻ�ܰ���ִ��һ������ģʽ��Ҫô���Ǵ���������Ҫ��
      ���Ǽƻ���ʱ��ģʽ�������ƻ���ʱ��ģʽ������ο�help setcmds
      ����ÿ������ִ�е�ָ�����ֻ��5�������������ó���5��ϵͳִ��ʱ
      Ҳ���׵����ر�ע�⣬����Ĭ���ǿ����ģ�ֻҪ�������˴�����������
      �����еġ�
TEXT
	);
	return 1;
}