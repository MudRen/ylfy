#include <ansi.h>

inherit F_CLEAN_UP;

int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 15 ) ) return 0;
	while(i--)
	if( id[i]<'a' || id[i]>'z' ) return 0;
	return 1;
}

// 创建文件路径
int make_dir(string type, string id)
{
	if ( !stringp(type) || !stringp(id) ) return 0;
	mkdir(DATA_DIR+type+"/"+id[0..0]);
	return 1;
}

// 检查目标文件是否存在
int valid_dest(string id)
{
	if ( !stringp(id) ) return 0;
	if ( file_size(DATA_DIR+"login/"+id[0..0]+"/"+id+".o") == -1 ) return 1;
	return 0;
}

// 检查源文件是否存在
int valid_src(string arg)
{
	string type, id;

	if ( !arg || sscanf(arg, "%s %s", type, id) != 2 ) return 0;
	if ( file_size("/"+type+"/login/"+id[0..0]+"/"+id+".o") > 0 ) return 1;
	return 0;
}

int main(object me, string arg)
{
	string type, id1, id2, src, dest, file;

	if ( !arg || sscanf(arg, "%s %s %s", type, id1, id2) != 3 )
		return notify_fail("指令格式：getdata 备份档案日期 原来id 转换后id\n");
	if ( !check_legal_id(id2) ) 
		return notify_fail("转换的id只能是英文字母。\n");
	if ( !valid_src(type+" "+id1) )
		return notify_fail("没有这个id的备份档案。\n");
	if ( !valid_dest(id2) )
		return notify_fail("目标id档案已存在。不能转换。\n");
	if ( find_player(id2) )
		return notify_fail("目标id已存在。不能转换。\n");
	make_dir("user", id2);
	src = "/"+type+"/user/"+id1[0..0]+"/"+id1+".o";
	dest = DATA_DIR+"user/"+id2[0..0]+"/"+id2+".o";
	if ( rename(src, dest) )
		return notify_fail("人物档案文件移动失败。\n");
	if ( !(file = read_file(dest)) )
		return notify_fail("人物档案文件读取失败。\n");
	file = replace_string(file, "\""+"id"+"\""+":"+"\""+id1, "\""+"id"+"\""+":"+"\""+id2);
	if ( !write_file(dest, file, 1) )
		return notify_fail("人物档案文件写入失败。\n");
	make_dir("login", id2);
	src = "/"+type+"/login/"+id1[0..0]+"/"+id1+".o";
	dest = DATA_DIR+"login/"+id2[0..0]+"/"+id2+".o";
	if ( rename(src, dest) )
		return notify_fail("登录档案转换失败。\n");
	if ( !(file = read_file(dest)) )
		return notify_fail("登录档案文件读取失败。\n");
	file = replace_string(file, "\""+"id"+"\""+":"+"\""+id1, "\""+"id"+"\""+":"+"\""+id2);
	if ( !write_file(dest, file, 1) )
		return notify_fail("登录档案文件写入失败。\n");

	write("档案转换成功，您现在可以使用"+id2+"登录原来"+id1+"的人物了。\n");
	log_file("cmds/getdata.log", sprintf("转档 %s to %s\n", id1, id2));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : 指令格式：getdata 备份档案日期 原来id 转换后id

原来铁通老站备份档案日期：2007-12-6
铁通新站备份档案日期：2007-12-13
HELP);
    return 1;
}