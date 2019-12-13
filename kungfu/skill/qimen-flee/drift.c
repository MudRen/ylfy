// drift_sense.c
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

	if ( me->is_fighting() ) return notify_fail("ս������û��ʱ���,�Ǻǣ�\n");
	//if ( me->query_condition("killer") ) return notify_fail("�ٸ����������޵���,�궴������Ѱ��·?\n");
	if  ( !environment(me)->query("outdoors") ) return notify_fail("�ԣ��ԣ��ԣ�����ĵذ壬�ƺ���ӲӴ��\n");
	if ( present("biao yin",me) ) return notify_fail("�����ϴ����������޷�ʹ����ͨ��\n");
	//if ( present("xin",me) ) return notify_fail("�����ϴ����ż����޷�ʹ����ͨ��\n");
	obj = deep_inventory(me);
	for ( i=0; i<sizeof(obj); i++ )
	{
		if (obj[i]->id("illicit salt"))
			return notify_fail("�����ϴ���˽�Σ��޷�ʹ����ͨ��\n");
	}
	ob = first_inventory(me);
	while ( ob )
	{
		if (ob->is_character() && !ob->is_corpse() )
			return notify_fail(ob->name()+"���ܺ���һ���궴��\n");
		ob = next_inventory(ob);
	}
	if ( me->query("jing") < 30 || me->query("jingli") < 75 ) return notify_fail("��ľ���������\n");
	if ( target ) return notify_fail("���Ŷ���ֻ���Լ�ʹ�ã�\n");
	if ( me->query_temp("gamble") ) return notify_fail("�㻹��������������߰�!\n");
	if ( virtualp(environment(me)) ) return notify_fail("�����޷�ʹ����ͨ!\n");
	write("��Ҫ�굽��һ������ߣ�");
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
		write("��ֹʩ����\n");
		return;
	}
	ob = find_player(name);
	if ( !ob || !me->visible(ob) || wizardp(ob) ) ob = find_living(name);
	if ( !ob || !me->visible(ob) || !living(ob) || wizardp(ob) )
	{
		write("���޷����ܵ�����˵ľ��� ....\n");
		return;
	}
	if ( !objectp(env=environment(ob)) )
	{
		write("���޷����ܵ�����˵ľ��� ....\n");
		return;
	}
	if ( random(me->query("jing"))<30 || random(me->query("jingli"))<20 )
	{
		write("���޷��о����Է��Ĵ���\n");
		return;
	}
	if ( me->query("quest/quest_type")=="ɱ"
	        && (string)me->query("quest/quest")==ob->short()
	        && me->query("quest/task_time")<time() )
	{
		write("���޷����ܵ�����˵ľ��� ....\n");
		return;
	}
	if	( ob->query("id")=="salt seller"
	        || virtualp(environment(ob)) )
	{
		write("���޷����ܵ�����˵ľ��� ....\n");
		return;
	}
	if ( me->is_fighting() )
	{
		write("ս������û��ʱ���,�Ǻǣ�\n");
		return;
	}
	else if( me->query("jingli") < 75 )
	{
		write("������ľ���״̬��̫�ã�Ъ��ɣ�\n");
		return;
	}
	me->add("jingli", -75);
	me->receive_damage("jing", 30);
	if ( random(ob->query("jingli")) > (int)me->query("jingli")
	        || time() - me->query_temp("do_flee") < 1 )
	{
		message_vision( HIY "$N�ɿ���ڵ��ϰ��˸��������˽�ȥ ....\n" NOR, me);
		write("���˼��������ڵ������ʯͷ���ۣ�û�ţ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	me->set_temp("do_flee",time());
	if ( !environment(ob) || environment(ob)->query("no_magic")
	        || environment(ob)->query("no_fight")
	        || random(me->query_skill("qimen-flee",1)) < 30 )
	{
		write("����ָ��ĥ���ˣ����ڳ������󶴣�MY GOD����ô��ѽ��\n");
		message( "vision",HIY+me->name()+"ʹ��������������˼��£������ġ�\n" NOR, environment(me),( {me}));
		return;
	}
	exits=environment(ob)->query("exits");
	if (!mapp(exits) || !sizeof(exits) )
	{
		write("���ڵ�һ��ʯǽ�����ò����˻�����\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="shaolin"
	        || domain_file(base_name(environment(ob)))=="new"
	        || domain_file(base_name(environment(ob)))=="mingjiao"
	        || domain_file(base_name(environment(ob)))=="shenlong"
	        || domain_file(base_name(environment(ob)))=="wizard"
	        || domain_file(base_name(environment(ob)))=="death" )
	{
		write("����������أ��ǵ������ܼ���\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="changan" )
	{
		write("���˼��������ڵ������ʯͷ���ۣ�û�ţ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="party" )
	{
		write("���޷����ܵ�����˵ľ���.....��\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="huashan" )
	{
		write("���˼��������ڵ������ʯͷ���ۣ�û�ţ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="wudujiao" )
	{
		write("���ﶾ�����أ���������ȥ�޻أ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
//        message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),({me}));
//        return;
//    }
	if ( domain_file(base_name(environment(ob)))=="player" )
	{
		write("�������˼ҵļ������������\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="kefang%d" )
	{
		write("�������˼ҵ�˯���ĵط�������������\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="migong" )
	{
		write("���˼��������ڵ������ʯͷ���ۣ�û�ţ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="taohua" || domain_file(base_name(environment(ob)))=="miwudao")
	{
		write("��ϲ�㣬���ڵ���Ȫˮ����\n");
		message( "vision",HIY+me->name()+"�ӿ����³�����ˮ��У�����ѽ��\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="yihua" )
	{
		write("��ϲ�㣬���ڵ���é������\n");
		message( "vision",HIY+me->name()+"�ӿ����³����ڴ���У��ó�ѽ���ó�ѽ��\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="flypproom" )
	{
		write("��ϲ�㣬���ڵ���é������\n");
		message( "vision",HIY+me->name()+"�ӿ����³����ڴ���У��ó�ѽ���ó�ѽ��\n" NOR, environment(me),( {me}));
		return;
	}
	if ( domain_file(base_name(environment(ob)))=="xiakedao" )
	{
		write("��ϲ�㣬���ڵ���é������\n");
		message( "vision",HIY+me->name()+"�ӿ����³����ڴ���У��ó�ѽ���ó�ѽ��\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="gaochang" )
	{
		write("����̫ңԶ�ˡ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="city3" )
	{
		write("����̫ңԶ�ˡ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="mingjiao" || domain_file(base_name(environment(ob)))=="automap" )
	{
		write("����̫ңԶ�ˡ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}

	if ( domain_file(base_name(environment(ob)))=="heimuya" || domain_file(base_name(environment(ob)))=="gumu")
	{
		write("����̫ңԶ�ˡ�\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}

	if (!environment(ob) || wizardp(ob))
	{
		message_vision( HIY "$N�ɿ���ڵ��ϰ��˸��������˽�ȥ ....\n" NOR, me);
		write("���ڵص����˰��죬����"+ob->name()+"�ƺ������� ....\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	if(ob->query("id")=="zhang tianshi")
	{
		message_vision( HIY "$N�ɿ���ڵ��ϰ��˸��������˽�ȥ ....\n" NOR, me);
		write("���ڵص����˰��죬����"+ob->name()+"�ƺ������� ....\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}

	if( userp(ob) )
	{
		message_vision( HIY "$N�ɿ���ڵ��ϰ��˸��������˽�ȥ ....\n" NOR, me);
		write("���ڵص����˰��죬�����ƺ����ű߼� ....\n");
		message( "vision",HIY+me->name()+"һ�������ܻ�����ͷ�����شӶ��������˻�����\n" NOR, environment(me),( {me}));
		return;
	}
	message_vision( HIY "$N�ɿ���ڵ��ϰ��˸��������˽�ȥ ....\n" NOR, me);
	message( "vision", HIY "\n�ܿ죬�����ַ���������" + me->name() + "�����ˣ�\n\n" NOR, environment(me), ( { me }) );

	for ( i=0; i<sizeof(stop_maps); i++ )
	{
		if ( domain_file(base_name(environment(ob))) == stop_maps[i] )
		{
			write("���ǣ��ܿ���㷢�������ƺ��޷���������ֻ�ͷ���������˻�����\n");
			return;
		}
	}

	if(file_size(file_name(environment(ob))+".c")<=0 && file_size("/binaries" + file_name(environment(ob))+".b")<=0)
	{
		write(HIY"���ǣ��ܿ���㷢�������ƺ��������ڣ������ֻ�ͷ���������˻�����\n"NOR);
		return;
	}
	else me->move(environment(ob));
	message( "vision", HIY "\nһ����ӰͻȻ�ӵ���ð�˳����������������Ļң�\n\n" NOR,
	         environment(ob), ( { me }) );
	if (me->query_skill("taoism",1)>me->query_skill("qimen-flee",1))
		me->improve_skill("qimen-flee", random(me->query_skill("taoism")),0);
	else me->improve_skill("qimen-flee", random(me->query_skill("taoism")),1);
}

