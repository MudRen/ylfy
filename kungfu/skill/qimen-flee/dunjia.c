// dunjia_sense.c
#include <ansi.h>
//inherit SSERVER;

nosave string *stop_maps = (
{
	"shushan",
	"xuehepai",
	"xuantian",
	"tongchi",
	"cxwxm",
	"hainan",
	"longmen",
	"wudie",
	"liandan",
});

int conjure(object me, object target)
{
	object ob,*obj;
	int i;

	if ( me->is_fighting() ) return notify_fail(HIM "ս������û��ʱ��ʩ����ͨ��\n" NOR);
	//if ( me->query_condition("killer") ) return notify_fail("�ٸ����������޵���,ʹ�÷���������������Ѱ��·?\n");
	if  (environment(me)->query("no_fly")) return notify_fail("�����ڿ����ڼ�����Ү��Ҳ����ʹ����ͨ��\n");
	if ( present("biao yin",me) ) return notify_fail(HIM "�����ϴ����������޷�ʹ����ͨ��\n" NOR);
	//if ( present("xin",me) ) return notify_fail(HIM "�����ϴ����ż����޷�ʹ����ͨ��\n" NOR);
	obj = deep_inventory(me);
	for ( i=0; i<sizeof(obj); i++ )
	{
		if ( obj[i]->id("illicit salt") )
			return notify_fail(HIM "�����ϴ���˽�Σ��޷�ʹ����ͨ��\n" NOR);
	}
	ob = first_inventory(me);
	while ( ob )
	{
		if ( ob->is_character() && !ob->is_corpse() )
			return notify_fail(HIM ""+ob->name()+"���ܺ���һ���������У�\n");
		ob = next_inventory(ob);
	}
	if ( me->query("jing") < 30 || me->query("jingli") < 75 )
		return notify_fail(HIM "��ľ�������,�޷�����������\n" NOR);
	if ( target ) return notify_fail(HIM "���Ŷݼ�ֻ���Լ�ʹ�ã�\n" NOR);
	if ( me->query_temp("gamble") ) return notify_fail("�㻹��������������߰�!\n");
	write(HIM "��Ҫ�ɶݵ���һ������ߣ�" NOR);
	if ( virtualp(environment(me)) ) return notify_fail("�����޷�ʹ����ͨ!\n");
    input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob, env;
	mapping exits;
	int i;

	if ( !name || name=="" )
	{
		write(HIM "��ֹʩ����\n" NOR);
		return;
	}
	ob = find_player(name);
	if ( !ob || !me->visible(ob) || wizardp(ob) ) ob = find_living(name);
	if ( !ob || !me->visible(ob) || !living(ob) || wizardp(ob) )
	{
		write(HIM "�㼯���������ĸ�Ӧ���ƺ��о���������˵Ĵ��ڡ�\n" NOR);
		return;
	}
	if ( !objectp(env=environment(ob)) )
	{
		write(HIM "�㼯���������ĸ�Ӧ���ƺ��о���������˵Ĵ��ڡ�\n" NOR);
		return;
	}
	if ( random(me->query("jing"))<30 || random(me->query("jingli"))<20 )
	{
		write(HIM "�㼯���������ĸ�Ӧ���ƺ�������������һƬ�հס�\n" NOR);
		return;
	}
	if ( me->query("quest/quest_type")=="ɱ"
	        && (string)me->query("quest/quest")==ob->short()
	        && me->query("quest/task_time") < time() )
	{
		write(HIM "�㼯���������ĸ�Ӧ����Լ��Ӧ����ʲô��ͻȻ��������ֻ���ն�������������\n" NOR);
		return;
	}
	if ( ob->query("id")=="salt seller" || virtualp(environment(ob)) )
	{
		write(HIM "�㼯���������ĸ�Ӧ��ֻ������һƬ�հ� ....\n" NOR);
		return;
	}
	if ( me->is_fighting() )
	{
		write(HIM "ս������û��ʱ��ʩ����ͨ,�Ǻǣ�\n" NOR);
		return;
	}
	else if ( me->query("jingli") < 75 )
	{
		write(HIM "������ľ���״̬��̫�ã��޷��ۼ�������\n" NOR);
		return;
	}
	me->add("jingli", -75);
	me->receive_damage("jing", 30);

	if ( /*random(ob->query("jingli")) > (int)me->query("jingli") || */time() - me->query_temp("do_flee") < 1 )
	{
		message_vision( HIM "$N���󽣾�������Ʈ���߲ʻ���һ���������ն�ȥ ....\n" NOR, me);
		write(HIM "��������գ�һ��ǿ�����������ǿ���ص��棬��ֻ������һƬãȻ��\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	me->set_temp("do_flee",time());
	if( !environment(ob) ||
	        environment(ob)->query("no_magic") || me->query_skill("taoism",1) < 800 || me->query_skill("buddhism",1) < 650 || me->query_skill("qimen-flee",1) < 300 )
	{
		write(HIM "�����󽣾�����һ�ݣ����ð���������Ȼ�ѳֲ�סһ��ˤ������������һƬãȻ��\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	exits=environment(ob)->query("exits");
	if (!mapp(exits) || !sizeof(exits) )
	{
		write(HIM "���������һ���ƺ���Ӧ����ʲô������һƬãȻ��\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="shaolin"
	        || domain_file(base_name(environment(ob)))=="new"
	        || domain_file(base_name(environment(ob)))=="mingjiao"
	        || domain_file(base_name(environment(ob)))=="shenlong"
	        || domain_file(base_name(environment(ob)))=="wizard"
	        || domain_file(base_name(environment(ob)))=="death" )
	{
		write(HIM "����������أ��Ƕ���΢ĩ�������ܼ���\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="party" )
	{
		write(HIM "�������˼ҵİ��ɣ���㴳��ȥ������Ź�?\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if(ob->query("id")=="zhang tianshi")
	{
		write(HIM "����ʦ��ǰʩչ���������ǰ���Ū��?\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="taohuacun" )
	{
		write(HIM "�������˼ҵ�˽լ�����ȥ͵������?\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="huashan" )
	{
		write(HIM"һ��ǿ���ɷ�����㵲�˻���.......��\n"NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="migong" )
	{
		write(HIM "һ��ǿ���ɷ������ǿ�г��ص��棬û��.....��\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="wudujiao" )
	{
		write(HIM "���ﶾ�����أ���������ȥ�޻أ�\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
//        message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),({me}));
//        return;
//    }
	if ( domain_file(base_name(environment(ob)))=="player" )
	{
		write(HIM "�������˼ҵļ������������\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="kefang%d" )
	{
		write(HIM "�������˼ҵ�˯���ĵط�������������\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�ռ�׹���£�ģ���Ǳ�֮����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="changan" )
	{
		write(HIM "�㱻һ��ǿ���ɷ�����˻�����\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ��������,��ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="flypproom" )
	{
		write(HIM "�㱻һ��ǿ���ɷ�����˻�����\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ��������,��ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="yihua" )
	{
		write(HIM "����������ͨ�쳹��֮�ܣ�\n" NOR);
		message( "vision",HIY+me->name()+"�Ӱ��������,��ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="xiakedao" || domain_file(base_name(environment(ob)))=="miwudao")
	{
		write(HIM "���������޷���ɺ�֮�ܣ�\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ��������,��ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="gaochang" || domain_file(base_name(environment(ob)))=="automap")
	{
		write(HIM "�����������δ�ﵽ����Ǭ���ľ��硣\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�������£���ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="city3" )
	{
		write(HIM "�����������δ�ﵽ����Ǭ���ľ��硣\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�������£���ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="mingjiao" )
	{
		write(HIM "�����������δ�ﵽ����Ǭ���ľ��硣\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�������£���ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="heimuya" || domain_file(base_name(environment(ob)))=="gumu")
	{
		write(HIM "�����������δ�ﵽ����Ǭ���ľ��硣\n" NOR);
		message( "vision",HIM+me->name()+"�Ӱ�������£���ɫ�ƺ���̫�ÿ���\n" NOR, environment(me),( {me}));
		return;
	}

	if (!environment(ob) || wizardp(ob))
	{
		message_vision( HIM "$N���󽣾����� ��=��=�ӣ�����Ʈ���߲ʻ���һ���������ն�ȥ ....\n" NOR, me);
		write(HIM "���������а��죬����"+ob->name()+"�ƺ�ң������,���Լ��������ܼ� ....\n" NOR);
		message( "vision",HIM+me->name()+"���ɽ��ڰ��ת�˼�ת����ص��棬һ����ͷ���Ե����ӡ�\n" NOR, environment(me),( {me}));
		return;
	}

	if ( userp(ob) )
	{
		message_vision( HIM "$N���󽣾����� ��=��=�ӣ�����Ʈ���߲ʻ���һ���������ն�ȥ ....\n" NOR, me);
		write(HIM "���������а��죬����ӫӫ��ռ�Ȼ���ޱ߼� ....\n" NOR);
		message( "vision",HIM+me->name()+"���ɽ��ڰ��ת�˼�ת����ص��棬һ����ͷ���Ե����ӡ�\n" NOR, environment(me),( {me}));
		return;
	}

	message_vision( HIM "$N���󽣾����� ��=��=�ӣ�����Ʈ���߲ʻ���һ���������ն�ȥ ....\n" NOR, me);
	message( "vision", HIM "\n��ɫ�������Ž���Զȥ��Ʈɢ��ʧ��" + me->name() + "��Զ���������һ���ڵ㣡\n\n" NOR, environment(me), ( { me }) );

	for ( i=0; i<sizeof(stop_maps); i++ )
	{
		if ( domain_file(base_name(environment(ob))) == stop_maps[i] )
		{
			write(HIM "���ǣ��ܿ���㷢�������ƺ��޷�����������㬵�����������\n" NOR);
			return;
		}
	}

	if(file_size(file_name(environment(ob))+".c")<=0 && file_size("/binaries" + file_name(environment(ob))+".b")<=0)
	{
		write(HIM "���ǣ��ܿ���㷢�������ƺ��������ڣ��������㬵�����������\n" NOR);
		return;
	}
	else me->move(environment(ob));
	write(HIM "����Ʈ���߲ʻ��꣬�����зɽ�����ӿս���������\n" NOR);
	message( "vision", HIM "\n����Ʈ���߲ʻ��꣬һ������������������\n\n" NOR,
	         environment(ob), ( { me }) );
	if (me->query_skill("taoism",1)>me->query_skill("qimen-flee",1))
		me->improve_skill("qimen-flee", random(me->query_skill("taoism")),0);
	else me->improve_skill("qimen-flee", random(me->query_skill("taoism")),1);
}

