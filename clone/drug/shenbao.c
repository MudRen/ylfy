inherit ITEM;
void create()
{
	set_name(HIR"����"NOR, ( { "shen bao"}));
	set_weight(100);
	set("long", "����Ҫ���ã���Ҫ��(he)�����������������Ժ󣬱�����죬��Ҧ���ߣ�һƿ�������ԣ���ƿ����ƣ����ƿ�������ϣ�Ŷ��Ү��\n");
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "ƿ");
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
	if(me->is_busy()) return notify_fail("����һ��������û����ɡ�\n");

	me->add("combat_exp",random(50000000));
	me->add("max_jingli",5000+random(10000));
	me->add("max_neili",3000+random(10000));
	if ( me->query("gender") == "����"){
	message_vision(HIB"$N��������������ȥ,�о��Լ��ָ������˱�ɫ!!!\n"NOR,me);
	}
	else message_vision(HIB"$N��������������ȥ,�о��Լ��������˼���!!!\n"NOR,me);
	destruct(this_object());
	return 1;
}

