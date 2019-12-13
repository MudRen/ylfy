// agelock.c	
inherit F_CLEAN_UP;
int main(object me, string arg)
{
int age;
	if( me!=this_player(1) ) return 0;
	if( !arg || arg=="" )
return notify_fail("指令格式：agelock 进入的最低年龄\n");       	
if( sscanf(arg, "%d", age)!=1 ) age = 0;
write("你取消了上线的年龄限制\n");
	seteuid(getuid());
if( LOGIN_D->set_agelock(age) ) {	
write("目前进入游戏的最低年龄为"+age+"\n");
		write("Ok.\n");
		return 1;
	} else
return notify_fail("上线年龄设定失败。\n");	
}
int help (object me)
{
        write(@HELP
指令格式: agelock 年龄  	
 
限制某个年龄以下的使用者进入游戏。	
 
HELP
);
        return 1;
}
 
