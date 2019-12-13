
#include <ansi.h>
#include <armor.h>

inherit FINGER;
inherit F_GEMS;

void init_sockets(object me)
{
	//���ÿɿ���Ľӿ�����
	set("max_sockets", 1);
	
	if ( me->query("combat_exp") > 10000000 )
		add("max_sockets", 1);
	
	if ( (int)query("sockets/max")>3 )
		set("sockets/max",3);
	
	if ( me->query("combat_exp") > 100000000 )
		add("max_sockets", 1);
	
	//��鿪��ʱ������ӵ���ز���
	if ( me->query("diablo/" + TYPE_FINGER + "/id") != query("id") 
		|| me->query("diablo/" + TYPE_FINGER + "/file_name") != base_name(this_object()) )
		return;
	
	//����ҿ��������־��������ָ�Ľӿ�ֵ
	set("sockets", me->query("diablo/" + TYPE_FINGER + "/sockets"));
	//���Ӹ���ӵ��ʶ�����
	set("diablo/only_me",me->query("id"));
	//���½�ָ�ĳ�����
	set_ring_desc();
}

void setup()
{
	if ( objectp(this_player()) ) init_sockets(this_player());
	::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
	//�����Ƕ��ʯ�����ͺ͵ȼ��Ƿ���ȷ
	if (!valid_gem(socket, socket_level))
		return;
	
	//�ٴμ�鿪��ʱ������ӵ���ز���
	if ( me->query("diablo/" + TYPE_FINGER + "/id") != query("id") || 
		me->query("diablo/" + TYPE_FINGER + "/file_name") != base_name(this_object()) )
		return;

	if ( query("diablo/only_me") != me->query("id") )
		return;
	
	//������Ƕ��ʯ�������ò�ͬ��Ч��
	switch (socket)
	{
		case "ruby":	
		if ( mode == 1 )
			message_vision(HIR + query("name") + HIR"���һ��ҫ�۵ĺ�⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
		else
			message_vision(HIR"������⽥������ȥ��$N�������ָֻ������ˡ�\n"NOR, me);
		me->add("max_qi", me->query("max_neili") * socket_level * mode / 30);
		me->add("eff_qi", me->query("max_neili") * socket_level * mode / 30);
		me->add("qi", me->query("max_neili") * socket_level * mode / 30);
		break;
		
		case "topaz":
		if (mode == 1)
			message_vision(HIY + query("name") + HIY"���һ����Ŀ�Ļƹ⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
		else
			message_vision(HIY"������⽥������ȥ��$N�ľ����ָֻ������ˡ�\n"NOR, me);
		me->add("max_jing", me->query("max_neili") * socket_level * mode / 30);
		me->add("eff_jing", me->query("max_neili") * socket_level * mode / 30);
		me->add("jing", me->query("max_neili") * socket_level * mode / 30);
		break;
		
		case "sapphire":
		if (mode == 1)
			message_vision(HIB + query("name") + HIB"���һ����͵����⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
		else
			message_vision(HIB"������⽥������ȥ��$N�������ָֻ������ˡ�\n"NOR, me);
		me->add("neili", me->query("max_neili") * socket_level * mode / 10);
		break;
		
		case "emerald":
		if (mode == 1)
			message_vision(HIG"��Ȼ��" + query("name") + HIG"��û���һ��������ɴ������Ů��Χ����$N����ߣ�\n"NOR, me);
		else
			message_vision(HIG"�̹�һ����$N������Ů��Ͳ����ˡ�\n"NOR, me);
		me->add_temp("apply/karma", 10 * socket_level * mode);
		break;
		
		case "amethyst":
		if (mode == 1)
			message_vision(MAG"һƬ��ɫ����Ѹ�ٴ�" + query("name") + MAG"��ӿ����ת�ۼ���Ѿ���$N����������\n"NOR, me);
		else
			message_vision(MAG"��ɫ�����紵ɢ�ˣ�$N�������������˳�����\n"NOR, me);
		me->add_temp("apply/dexerity", 10 * socket_level * mode);
		break;
		
		case "diamond":
		if (mode == 1)
			message_vision(HIW"��������" + query("name") + HIW"����һ������ֱ����ʣ�$Nɲʱ�е����ڳ�����������\n"NOR, me);
		else
			message_vision(HIW"������$N����ɫ�ָֻ���������\n"NOR, me);
		me->add_temp("apply/strength", 10 * socket_level * mode);
		break;
		
		case "skull":
		if (mode == 1)
			message_vision(WHT"$N��Ȼ�е�һ�����������Χ����$P������֮��ֻ���ó����Ī����ħ����\n"NOR, me);
		else
			message_vision(WHT"$N" + query("name") + WHT"�е����･��ʧȥ��Ч�ã�\n"NOR, me);
		me->add_temp("apply/magic", 10 * socket_level * mode);
		break;
	}
	return;
}

//װ����ָʱ�Ĳ����仯��������Ч��
int wear()
{
	int i, sockets, ret;
	object me = environment();
	
	if (!(ret = ::wear()))
		return 0;
	
	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);
	return ret;
}

//���װ��ʱ���������Ч��
int unequip()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::unequip())) return 0;

	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);
	return ret;
}
