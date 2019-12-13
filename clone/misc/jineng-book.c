inherit ITEM;

void init()
{
	add_action("do_yanjiu", "yanjiu");
}

void create()
{
	set_name(HIM"技能书"NOR, ( {"jineng book", "book"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", "这是一本有些发黄的古书，里面有些奇怪的内容，看来可以研究下(yanjiu)。\n");
	}
}
int do_yanjiu(string arg)
{
	string *skills;
	mapping all_skills;
	int i;
	if (!id(arg))
		return notify_fail("你要研究什么？\n");
	else
	{
   // if(this_player()->query("id")==query("value"))
    //    return notify_fail("这棵丹不是你练的,你吃个什么劲。\n");

		all_skills=this_player()->query_skills();
		if (!sizeof(all_skills))  destruct(this_object());
		skills=keys(all_skills);
		for(i=0; i<sizeof(skills); i++)
			this_player()->set_skill(skills[i],all_skills[skills[i]]+5);

		message_vision(HIB"$N你仔细研究了下这本古书,感觉武功有所提升。\n", this_player());

		destruct(this_object());
		return 1;
	}
}


