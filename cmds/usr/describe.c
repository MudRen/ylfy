// describe.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string *txt;
	
	if ( !arg || arg=="?" || arg=="/?")	return help(me);
	
	txt = explode(arg, "\n");
	if ( !wizardp(me) )
	{
		if ( sizeof(txt) > 30 )	return notify_fail("请将您对自己的描述控制在三十行以内。\n");
		if ( strlen(arg) > 300 ) return notify_fail("请将您对自己的描述控制在三百个字符以内。\n"); 
	}
	if ( arg=="none" ) me->delete("long");
	else 
	{
		arg = implode(txt, "\n") + "\n";
		arg = trans_color(arg, 2);
		me->set("long", arg + NOR);
	}
	
	write("Ok.\n");
	return 1;
}
int help(object me)
{
	write(@TEXT
指令格式：describe <描述>
这个指令让你设定当别人用 look 指令看你时，对你的描述，通常当你
的描述超过一行时可以用 to describe 的方式来输入。
TEXT
	);
	return 1;
}
