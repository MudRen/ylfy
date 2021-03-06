#include "/doc/help.h"

#define GET_VERSION_CMD "/cmds/bos/get_version"

inherit F_CLEAN_UP;

string update_time;
int move_file;
string *findfiles = ({});

int updatefile(object me,string file, string str);
//void make_dir(string dir, string err);

int main(object me, string arg)
{
	int i, j;
	string dir, str;
	mixed *file;

	seteuid( geteuid(me) );
	
	/*if ( playerp(previous_object()) || base_name(previous_object()) == GET_VERSION_CMD )
	{
		if ( sscanf(arg, "%s -debug", arg) ) move_file = 1;
		else move_file = 0;
		update_time = CHINESE_D->chinese_time(10, ctime(time()));
	}*/

	if ( sscanf(arg, "%s,%s", dir, str) != 2 ) return 0;
	
	if ( file_size(dir) == -2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	
	file = get_dir(dir, -1);
	
	if ( playerp(previous_object()) )
	{
		if ( !sizeof(file) )
		{
			if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
			else return notify_fail("没有这个目录。\n");
		}
		findfiles = ({});
	}

	i = sizeof(file);
	while(i--) 
	{
		if ( file[i][1]==-2 ) file[i][0] += "/";
	}
	
	//write(HIY"目录：" + dir + "\n"NOR);

	if ( sizeof(file) )
	{
		for ( i=0, j = sizeof(file); i<j; i++ )
		{
			if ( file[i][1] > 0 )
				updatefile(me,dir+file[i][0],str);
			else 
			{
				if ( file[i][1] == -2 ) 
					call_other(__FILE__, "main", me, dir+file[i][0]+","+str);
			}
		}
	}
	else
		write("      没有任何档案。\n");
	
	//write("\n");
	return 1;
}

int updatefile(object me, string file, string str)
{
	/*object obj, *inv;
	int i, is_load;
	string err;*/
	string src;

	/*me->set("cwf", file);
	is_load = 0;

	if ( obj = find_object(file) ) 
	{
		if ( obj == environment(me) ) 
		{
			if ( file_name(obj) == VOID_OB || file_name(obj) == VOID_USER )
			{
				write("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
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
		write(HIR"无法清除旧程式码："+file+"\n"NOR);
		return 0;
	}

    write("重新编译 " + file + "：");
	err = catch( call_other(file, "???") );

	if ( err ) 
	{
		printf(HIR"发生错误：%s\n"NOR, err);
		if ( move_file ) make_dir(file, err);
	}
	else 
	{
		write(HIG"成功！\n"NOR);
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
	}*/

	src = read_file(file);
	if ( sscanf(src, "%*s"+str+"%*s") )
	{
		findfiles += ({ file });
		write(file+"\n");
	}

	return 1;
}

/*void make_dir(string dir, string err)
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
		file+"发生错误：\n"+err+"\n---------------------------------------------------\n");
	rename(file, dir);
}*/

int help(object me)
{
write(@HELP
指令格式: upddir [<路径名>]

将目录下所有的子目录及档案, 如果没有指定目录, 则使用当前目录


范例:
'upddir /adm' 会将所有位於根/adm目录下的档案编译更新.

HELP
);
return 1;
}

