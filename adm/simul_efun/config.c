// 读取属性文件中配置 by Wenwu
/* 目前只支持传回 int 和 string ,当带有前缀 $d$ 时则传回 int */
mixed get_system_config(string file, string need_key)
{
	string file_gut, *gut_list, need_values;
	int i;

	if ( file_size(file) < 0 ) return 0;
	
	file_gut = read_file(file);

	if ( !sscanf(file_gut, "%*s\n%*s") ) return 0;

	gut_list = explode(file_gut, "\n");
	for ( i = 0; i < sizeof(gut_list); i++ )
	{
		if ( sscanf(gut_list[i], need_key+"=%s", need_values) )
		{
			if ( need_values[0..2] == "$d$" ) 
				return atoi(need_values[3..(sizeof(need_values)-1)]);
			else
				return need_values;
		}
	}
}

// 从文件获取mapping
mapping get_mapping_config(string file)
{
	mapping get_map;
	string file_gut, *gut_list, need_key, need_values;
	int i;

	if ( file_size(file) < 0 ) return 0;
	
	file_gut = read_file(file);

	if ( !sscanf(file_gut, "%*s\n%*s") ) return 0;
	
	get_map = ([]);
	gut_list = explode(file_gut, "\n");
	for ( i = 0; i < sizeof(gut_list); i++ )
	{
		if ( sscanf(gut_list[i], "%s=$d$%s", need_key, need_values) )
			get_map[need_key]=atoi(need_values);
		else if ( sscanf(gut_list[i], "%s=%s", need_key, need_values) )
			get_map[need_key]=need_values;
	}

	return get_map;
}

/* 加密方式 by Wenwu*/
string crypt(string str, string seed)
{
#ifdef OLD_CRYPT
	return efun::oldcrypt(str, seed);
#endif

#ifdef MD5_CRYPT
	return efun::md5crypt(str, seed);
#else
	return efun::crypt(str, seed);
#endif
}