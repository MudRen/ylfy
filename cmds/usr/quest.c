// quest.c

inherit F_CLEAN_UP;
int help(object me);
object find_player(string target)
{
	int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
string time_period(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        if(d)
                time = chinese_number(d) + "��";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "Сʱ";
        if(m)
                time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        return time;
}
int main(object me, string arg)
{
	object ob;
	string str;
	mapping quest;
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}
	if( !ob ) ob = me;
	if (!mapp(quest=ob->query("quest"))){
		printf("%sĿǰû���κ�����\n",ob==me?"��":ob->query("name"));
		return 1;
	}
	str=sprintf("%s�������ǣ���%s��%s%s��",ob==me?"��":ob->query("name"),time_period(quest["time"]),quest["quest_type"],quest["quest"]);
	if (quest["task_time"]<time())
		str+=sprintf("%s�Ѿ�û���㹻��ʱ��������ˡ�\n",ob==me?"��":ob->query("name"));
	else
		str+=sprintf("%s����%s��ʱ��ȥ�������\n",ob==me?"��":ob->query("name"),time_period(quest["task_time"]-time()));
	write(str);
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ��quest <ĳ��>
����������ָ���ѯ��Ŀǰ������
HELP
	);
	return 1;
}
