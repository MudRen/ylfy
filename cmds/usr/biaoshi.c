// /cmds/usr/biaoshi.c
// 2003.7.24 lisa
// 1.00 设定人物标识

inherit F_CLEAN_UP;
int main(object me)	
{
	object ob;
	if( me != this_player(1) ) return 0;
	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() )
        ob = ob->query_temp("link_ob");
	if(ob->query("biaoshiold"))
	{
		write("你已经设定了身份标识了，不用再次设定了。\n");
		return 1;
	}
	write("请输入你的身份标识：");
	input_to("get_biaoshi", 1, ob);
	return 1;
}
void get_biaoshi(string biaoshi, object ob)
{
	write("\n");
        if(strsrch(biaoshi,"//")!=-1) {
        write(HIR"\n非法的输入，请重设您的身份标识："NOR);
        input_to("get_biaoshi", 1, ob);
        return;
}
        ob->set("biaoshiold", crypt(biaoshi,0) );
	write("请再输入一次您的身份标识，以确认您没记错：");
	input_to("confirm_biaoshi", 1, ob);
}
void confirm_biaoshi(string biaoshi,object ob)
{
	string old_biaoshi;
	write("\n");
	old_biaoshi=ob->query("biaoshiold");
	if( crypt(biaoshi, old_biaoshi)!=old_biaoshi )
	{
		write("您两次输入的身份标识并不一样，设定失败。\n");
		ob->delete("biaoshiold");
		return;
	}
	write("人物身份标识设定成功！\n");
	ob->save();
	return;
}

int help(object me)
{
	write(@HELP
指令格式 : biaoshi
 
这个指令可以设定你的人物的身份标识。
 
HELP
    );
    return 1;
}
 
