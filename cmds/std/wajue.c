// By zjb@ty д�� 2002.5.18
// update by Wenwu

int main(object me)
{
	object caoyao;
	object ob;
	
	me = this_player();

	if ( !environment(me)->query("outdoors")
		|| environment(me)->query("no_fight") )
		return notify_fail("���ڷ������ڸ�ƨ,Ҫ��ȥ������!\n");

	if ( !sscanf(base_name(environment(me)),"/d/guanwai/%*s")
		&& !sscanf(base_name(environment(me)),"/d/quanzhen/%*s")
		&& !sscanf(base_name(environment(me)),"/d/gumu/%*s") )
		return notify_fail("��ʱֻ��ͨ�����ȫ��,��Ĺ�����ھ��ҩ!\n");

	if ( me->is_busy() ) return notify_fail("��������æ,��һ�����ڰ�!\n");

	if ( !(ob = present("chu tou", this_player())) ) 
		return notify_fail("û��ͷ���ڸ�ʲô����\n");

	if ( environment(me)->query("wajue")>time() )
		return notify_fail("����ոձ����ھ��,���һ��������!\n");

	if ( me->query_temp("wajuedi") ) 
	{
		if ( me->query_temp("wajuedi") == environment(me) )
			return notify_fail(HIG"��ող��������ھ���,������������ʲô����?\n"NOR);
	}

	me->set_temp("wajuedi", environment(me));

	if ( random(5)>2 ) 
	{
		me->start_busy(5);
		return notify_fail(HIW"��е������ڵ�ʲô������,��ϸһ��ԭ����ʯ��!\n"NOR);
	}
  
	if ( random(20)<5 ) 
	{
		message_vision(HIG"$NͻȻ����������һ����,��ͷ�ڶ���!\n"NOR, this_player());
		destruct(ob);
		return 1;
	}
	// ��ҩ
	if ( sscanf(base_name(environment(me)),"/d/guanwai/%*s") ) 
	{
		caoyao = new("/d/liandan/zyao/yao"+random(10));
		me->start_busy(10);
	}
	// ��ҩ
	if ( sscanf(base_name(environment(me)),"/d/quanzhen/%*s") 
		|| sscanf(base_name(environment(me)),"/d/gumu/%*s")) 
	{
		switch(random(2))
		{
			case 0:
				caoyao = new("/d/liandan/fyao/yao");
				break;
			case 1:
				caoyao = new("/d/liandan/fyao/yao2");
				break;
		}
		me->start_busy(7);
	}
   
	if ( !me->query("env/no_msg") ) me->set("env/no_msg",1); 
	
	me->add("neili", -(me->query("neili")/10));
	me->add("qi", -(me->query("qi")/10));
	me->add("jing",-(me->query("jing")/10));
	environment(me)->set("wajue", time()+300+random(300));
	caoyao->set("zhuren",""+me->query("id")+"");
	caoyao->move(me);
	message_vision(HIR"$N���ų�ͷ�������ѽ��ѽ,�����ڵ���ʲô,�ó���\n"
		"һ��ԭ����"+caoyao->name()+HIR",�㲻�ɸе��Լ�û������!...��\n"NOR, this_player());
	return 1;
}