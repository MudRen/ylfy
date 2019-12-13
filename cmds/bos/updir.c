#include "/doc/help.h"

#define GET_VERSION_CMD "/cmds/bos/get_version"

inherit F_CLEAN_UP;

string update_time;
int move_file;

int updatefile(object me,string file);
void make_dir(string dir, string err);

int main(object me, string arg)
{
	int i, j;
	string dir;
	mixed *file;

	seteuid( geteuid(me) );
	
	if ( playerp(previous_object()) || base_name(previous_object()) == GET_VERSION_CMD )
	{
		if ( sscanf(arg, "%s -debug", arg) ) move_file = 1;
		else move_file = 0;
		update_time = CHINESE_D->chinese_time(10, ctime(time()));
	}

	dir = resolve_path(me->query("cwd"), arg);
	
	if ( file_size(dir) == -2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	
	file = get_dir(dir, -1);
	
	if ( playerp(previous_object()) )
	{
		if ( !sizeof(file) )
		{
			if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
			else return notify_fail("û�����Ŀ¼��\n");
		}
	}

	i = sizeof(file);
	while(i--) 
	{
		if ( file[i][1]==-2 ) file[i][0] += "/";
	}
	
	write(HIY"Ŀ¼��" + dir + "\n"NOR);

	if ( sizeof(file) )
	{
		for ( i=0, j = sizeof(file); i<j; i++ )
		{
			if ( file[i][1]!=-2 && sscanf(file[i][0], "%*s.c") 
				&& file[i][0][strlen(file[i][0])-1]=="c"[0] 
				&& file[i][0][strlen(file[i][0])-2]=="."[0] )
				updatefile(me,dir+file[i][0]);
			else 
			{
				if ( file[i][1] == -2 ) 
					call_other(__FILE__, "main", me, dir+file[i][0]);
			}
		}
	}
	else
		write("      û���κε�����\n");
	
	write("\n");
	return 1;
}

int updatefile(object me, string file)
{
	object obj, *inv;
	int i, is_load;
	string err;

	me->set("cwf", file);
	is_load = 0;

	if ( obj = find_object(file) ) 
	{
		if ( obj == environment(me) ) 
		{
			if ( file_name(obj) == VOID_OB || file_name(obj) == VOID_USER )
			{
				write("�㲻���� VOID_OB �����±��� VOID_OB��\n");
				return 0;
			}
		}
		inv = all_inventory(obj);
		i = sizeof(inv);
		while (i--)
		{
			if ( userp(inv[i]) ) 
				inv[i]->move(VOID_USER, 1);
			else inv -= ({ inv[i] });
		}
		is_load = 1;
		
		if ( !sscanf(file, "/cmds/bos/get_version%*s") 
			&& obj != this_object() )
			destruct(obj);
	}

	if ( obj ) 
	{
		write(HIR"�޷�����ɳ�ʽ�룺"+file+"\n"NOR);
		return 0;
	}

    write("���±��� " + file + "��");
	err = catch( call_other(file, "???") );

	if ( err ) 
	{
		printf(HIR"��������%s\n"NOR, err);
		if ( move_file ) make_dir(file, err);
	}
	else 
	{
		write(HIG"�ɹ���\n"NOR);
		if ( obj = find_object(file) )
		{
			if ( i = sizeof(inv) ) 
			{
				while (i--)
				{
					if ( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
				}
			}
			if ( !is_load )
				destruct(obj);
		}
	}

	return 1;
}

void make_dir(string dir, string err)
{
	string *dir_name, dir_name_link, file;
	int i;
	
	if ( !sscanf(dir, "%*s/%*s") ) return;
	if ( sscanf(dir, DEBUG_DIR "%*s") ) return;
	
	file = dir;
	dir = DEBUG_DIR + update_time + dir;
	dir_name = explode(dir, "/");
	dir_name_link = "";
	for ( i=0; i<sizeof(dir_name)-1; i++ )
	{
		if ( dir_name[i] && dir_name[i] != "" ) dir_name_link += ("/" + dir_name[i]);
		if ( dir_name_link && dir_name_link != "/" && dir_name_link != "" ) 
			mkdir(dir_name_link);
	}
	write_file(DEBUG_DIR+update_time+"/err", 
		file+"��������\n"+err+"\n---------------------------------------------------\n");
	rename(file, dir);
}

int help(object me)
{
write(@HELP
ָ���ʽ: upddir [<·����>]

��Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ��ʹ�õ�ǰĿ¼


����:
'upddir /adm' �Ὣ����λ춸�/admĿ¼�µĵ����������.

HELP
);
return 1;
}

