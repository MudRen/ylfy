// callouts.c
inherit F_CLEAN_UP;
int main(object me, string arg )
{
	mixed *info;
	int i;
	string output;
        output = sprintf("%-40s %-20s %5s\n", "物件", "函数", "延迟时间"); 
        if( arg && arg!="" )
		info = filter_array(call_out_info(), (: $1[1]==$2 :), arg);
	else
		info = call_out_info();
      if (!sizeof(info)) return 1;
	for(i=0; i<sizeof(info); i++)
                output += sprintf("%-40O %-20s %5d\n",
                         info[i][0],  info[i][1],   info[i][2]);
        if (strlen(output)>8000) me->start_more(output);
        else write(output);
        return 1;
}
int help()
{
	write(@LONG
指令格式：callouts [<函数名称>]
List all the system callouts, or, a particular callouts 
specified as a parameter.
LONG
	);
	return 1;
}
