// wizlock.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	if( me!=this_player(1) )
		return 0;

	if( wiz_level(me) < wiz_level("(boss)") )
		return 0;

	if( LOGIN_D->get_madlock() == 1 )
		return notify_fail("时空已是关闭的。\n");
	
	if( LOGIN_D->set_madlock(1) )
	{
		message("chat", HIG"【"+HBRED+HIY"游戏精灵"NOR+HIG"】"+HIW"档案更新中.....，时空已被暂时封闭。\n"NOR,users() );
		return 1;
	}
	else
		return notify_fail("时空封闭失败。\n");
}

int help (object me)
{
        write(@HELP
指令格式: madlock
 
限制使用者继续进入游戏。
 
HELP
);
        return 1;
}
 
