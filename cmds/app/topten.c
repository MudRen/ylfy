// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;

	seteuid(geteuid(me));
	if (!arg||arg=="")
		str = "/adm/daemons/toptend"->query_type();
	else 
		str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : topten <����> <���ID>
	����:rich|per1|per2|spells|pker|age|exp|force|kill...
HELP
    );
    return 1;
}
