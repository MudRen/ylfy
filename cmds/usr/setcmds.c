// ���߱չ�ָ� By ������(Wenwu) On 2006��1��21��

#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int set_biguan_cmds(object ob, string cmds);

int main(object me, string arg)
{
	string str, *str_list, msg;
	int i;

	if ( !arg || arg == "" )
	{
		if ( file_size(DATA_DIR + "biguan/" + me->query("id") + __SAVE_EXTENSION__) != -1 )
		{
			write(HIW"���趨����������ָ����£�\n"NOR);
			str = read_file(DATA_DIR + "biguan/" + me->query("id") + __SAVE_EXTENSION__);
			msg = "\n";

			str_list = explode(str,"\n");
			for (i = 0; i < sizeof(str_list); i++)
			{
				msg += (HIW"�� "HIG + (i + 1) + HIW" ��ָ�� - "HIY + str_list[i] + "\n"NOR);
			}

			me->start_more(msg);

			return 1;
		}
		else
			return notify_fail(HIY"��������ָ�����Ϊ�գ�\n"NOR);
	}
	if ( arg == "-r" )
	{
		if ( file_size(DATA_DIR + "biguan/" + me->query("id") + __SAVE_EXTENSION__) != -1 )
		{
			rm(DATA_DIR + "biguan/" + me->query("id") + __SAVE_EXTENSION__);
			write(HIW"�ɹ������������ָ���\n"NOR);
			return 1;
		}
		else
		{
			write(HIW"�㲢û��������������ָ���\n"NOR);
			return 1;
		}
	}

	if ( strlen(arg) > 300 )
		return notify_fail(HIY"���趨����������ָ�̫���ˣ��������300���ֽ����ڣ�\n"NOR);

	if ( file_size(DATA_DIR + "biguan/" + me->query("id") + __SAVE_EXTENSION__) != -1 )
	{
		write(HIW"����ǰ���趨����������ָ���\n"NOR);
		str = read_file(DATA_DIR + "biguan/" + me->query("id") + __SAVE_EXTENSION__);
		msg = "\n";

		str_list = explode(str,"\n");
		for (i = 0; i < sizeof(str_list); i++)
		{
			msg += (HIW"�� "HIG + (i + 1) + HIW" ��ָ�� - "HIY + str_list[i] + "\n"NOR);
		}

		msg += HIC"\n���Ƿ�Ҫ����ԭ��ָ���["HIG"Y"HIW" / "HIR"N"HIY"]��"NOR;
		write(msg);
		input_to("get_biguan_cmds", 1, me, arg);
	}
	else
		set_biguan_cmds(me, arg);

	return 1;
}

int get_biguan_cmds(string arg, object ob, string str)
{
	if ( strsrch(arg,"Y") != -1 || strsrch(arg,"y") != -1 )
	{
		set_biguan_cmds(ob, str);
		return 1;
	}
	else
	{
		write(HIY"\n��ȡ���˸��ǲ���������ʹ��ԭ����������ָ���\n"NOR);
		return 0;
	}
}

int set_biguan_cmds(object ob, string cmds)
{
	string msg, str, *str_list, *args, *arg, msg_list, cmd_msg = "";
	int i = 0, j = 0, cmds_num = 0, list = 0;

	args = explode(cmds, "|");
	cmds_num = sizeof(args);
	for (i = 0; i < cmds_num; i++)
	{
		if ( strsrch(args[i],"#") != -1 )
		{
			msg_list = "";
			arg = explode(args[i], " ");
			list = atoi(replace_string(arg[0], "#", ""));
			if ( list < 0 )
				list = 1;
			else if ( list > 10)
				list = 10;
			cmd_msg = replace_string(args[i], arg[0] + " ", "");
			for (j = 0; j < list; j++)
			{
				msg_list = msg_list + cmd_msg;

				if ( j < list - 1 )
					msg_list += "|";
			}
			cmds = replace_string(cmds, args[i], msg_list);
		}
	}

	msg = replace_string(cmds, "|", "\n");
	
	if ( write_file(DATA_DIR + "biguan/" + ob->query("id") + __SAVE_EXTENSION__, msg, 1) )
	{
		write(HIG"\n��ɹ��趨����������ָ���\n"NOR);
		str = read_file(DATA_DIR + "biguan/" + ob->query("id") + __SAVE_EXTENSION__);
		msg = "\n";

		str_list = explode(str,"\n");
		for (i = 0; i < sizeof(str_list); i++)
		{
			msg += (HIW"�� "HIG + (i + 1) + HIW" ��ָ�� - "HIY + str_list[i] + "\n"NOR);
		}

		ob->start_more(msg);
		return 1;
	}
	else
	{
		write(HIR"\n��������ָ��趨ʧ�ܡ�\n"NOR);
		return 0;
	}
}

int help()
{
	write(@TEXT
ָ���ʽ��setcmds AAA|AAA|AAA|BBB|BBB|CCC
      ��setcmds #3 AAA|#2 BBB|CCC
          [AAA��BBB��CCC������һ��ָ��]
ʹ�����ָ������趨����������ʱ��ϵͳ��ʱ����ִ�е�ָ�
   
���磺
[1]�� ��������������ʱϵͳ���㶨ʱ��������������������趨Ϊ��
      setcmds exercise 100
      ����������������ʱϵͳ�ͻᶨʱ������������ˡ�	
[2]�� �����������������ʱϵͳ����ѭ��ִ������ָ��������
      ����[|] ������ָ�������������磺������ϵͳ�����ȶ���
      �����������ָ�����Ϳ����趨Ϊ��
      setcmds study book|exert regenerate
      ����ϵͳ�ͻ�����ȶ���һ�Σ�Ȼ���������ָ������ˡ�
[3]�� ��Ȼ��������ϵͳ������������ʱ����ѭ��ִ�и���ָ�����
      ����������һ����ÿ��ָ��֮�䶼�� ����[|] ���������
[4]�� ��ȻҲ֧��#10���ָ�ʽ����˼����һ��ָ��ѭ��10�Ρ�
      �磺������ϵͳ����������Σ�Ȼ���������ָ�������ô����
      ��������ô���ã�
      setcmds #3 study book|exert regenerate
      ���㲻����#3�ĸ�ʽ������������Ч��Ҳ��һ����
      setcmds study book|study book|study book|exert regenerate
[5]�� ע�⣺Ҳ����ᷢ�����õ�ָ����Ȼ��ܵ����ƣ��ǵģ�ָ�
      �ĳ���������300���ַ����ڡ��������㹻�����˵ģ�ϵͳ֧��
      ����ͨ�� alias ���õļ�ָ�
      ���磺���ԭ�εĶ���ָ����������
      setcmds #3 study book|exert regenerate
      ��ô���ǿ���ͨ�� alias ��ָ��򻯺��������ã����£�
      alias du study book;
      alias xj exert regenerate;
      setcmds #3 du|xj
      ���ˣ�����������
      setcmds #3 du|xj
      �ǲ��Ǳ�
      setcmds #3 study book|exert regenerate
      �ڳ����϶��˺ܶ��ء�
[6]�� �������ɾ����������ָ�����ʹ������ָ��
      stecmds -r
ע�⣺��������ʱ��ϵͳֻ����ִ��һ������ģʽ��Ҫô�������������õ����
      ��ʱ��ģʽ�ļƻ�������Ҫô������һ�ִ�������ģʽ����������ģʽ
      ��ο� help setchufa
      �ر�ע�⣬��������ģʽ�����ȼ�����Ŀǰ���õ������ʱ���ƻ�����
      ģʽҪ�ߣ�������ʹ�ö�ʱ���ƻ�����ģʽ�����Ҫ�رմ�������ģʽ��
      �رմ������ܵ�ָ�setchufa -stop
TEXT
	);
	return 1;
}