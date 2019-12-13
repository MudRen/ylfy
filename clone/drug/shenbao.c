inherit ITEM;
void create()
{
	set_name(HIR"肾宝"NOR, ( { "shen bao"}));
	set_weight(100);
	set("long", "男人要肾好，就要喝(he)老张牌肾宝，喝了以后，比刘翔快，比姚明高，一瓶提神醒脑，两瓶永不疲劳三瓶长生不老，哦，耶。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "瓶");
		set("no_get",1);
		set("no_s",1);
		set("no_put",1);
		set("no_give",1);
	}
	setup();
}
void init()
{
	if (environment()==this_player())
		add_action("do_he", "he");
}
int do_he(string arg)
{
	object me = this_player();
	int maxneili,neili;
	neili = me->query("neili");
	maxneili = me->query("max_neili");

	if(!id(arg)) return 0;
	if(me->is_busy()) return notify_fail("你上一个动作还没有完成。\n");

	me->add("combat_exp",random(50000000));
	me->add("max_jingli",5000+random(10000));
	me->add("max_neili",3000+random(10000));
	if ( me->query("gender") == "男性"){
	message_vision(HIB"$N拿起肾宝喝了下去,感觉自己恢复了男人本色!!!\n"NOR,me);
	}
	else message_vision(HIB"$N拿起肾宝喝了下去,感觉自己又年轻了几岁!!!\n"NOR,me);
	destruct(this_object());
	return 1;
}

