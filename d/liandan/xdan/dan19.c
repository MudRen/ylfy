inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIM"���ܵ�"NOR, ( {"jineng dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�źں�����ҩ�衣\n");
	}
}
int do_eat(string arg)
{
	string *skills;
	mapping all_skills;
	int i;
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	else
	{
    if(this_player()->query("id")==query("value"))
        return notify_fail("��õ�����������,��Ը�ʲô����\n");

		all_skills=this_player()->query_skills();
		if (!sizeof(all_skills))  destruct(this_object());
		skills=keys(all_skills);
		for(i=0; i<sizeof(skills); i++)
			this_player()->set_skill(skills[i],all_skills[skills[i]]+1);

		message_vision(HIB"$N����һ�ż��ܵ�,�о��书����������\n", this_player());

		destruct(this_object());
		return 1;
	}
}


