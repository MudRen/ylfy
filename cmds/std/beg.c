// beg.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;
        
	seteuid(getuid());
	
	if ( (!(myfam = me->query("family")) || myfam["family_name"] != "ؤ��") )
		return notify_fail("ֻ����ؤ�������֣�\n");
	if ( environment(me)->query("no_beg") || environment(me)->query("no_fight"))
		return notify_fail("���ﲻ����л��������ַ��ĵط���\n");
	if ( me->query_temp("begging") )
		return notify_fail("���Ѿ������˼������ˣ�\n");
	if ( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) 
		return notify_fail("ָ���ʽ��beg <��Ʒ> from <����>\n");
	
	victim = present(who, environment(me));
	
	if ( !victim || victim == me) return notify_fail("�������ֵĶ��������\n");
	if ( !living(victim) || !objectp(victim)) return notify_fail("��Ҫ��˭���֣�\n");
	if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "ؤ��" )
		return notify_fail("�㲻������ؤ���֣�\n");
	if ( !wizardp(me) && wizardp(victim) ) return notify_fail("��Ҳ�������ʦ���֡�\n");
	if ( me->is_fighting() ) return notify_fail("һ�ߴ��һ��Ҫ���������ǻ����ˣ�\n");
	if ( victim->is_fighting() ) return notify_fail(victim->name() + "���ڴ�ܣ�û�����㣡\n");
	if ( !ob = present(what, victim) ) 
	{
		object *inv;
		inv = all_inventory(victim);
		if ( !sizeof(inv) ) return notify_fail( victim->name() + "���Ͽ�����û��ʲ���������Ȥ�Ķ�����\n");
		ob = inv[random(sizeof(inv))];
	}
	if ( ob->query("equipped") || ob->query("no_drop") )
		return notify_fail("�������˵�����һ�϶�������㡣\n");
	
	sp = (int)me->query_skill("begging") * 15 
		+ (int)me->query_kar() 
		- (int)me->query("begger") 
		+ me->query("combat_exp") / 1000 
		+ me->query("xyzx_sys/level") * 1000;
	
	if ( sp < 1 ) sp = 1;
	
	dp = (int)victim->query("jing") 
		+ victim->query("combat_exp") / 1000 
		+ victim->query("xyzx_sys/level") * 1000 
		+ (int)victim->query_per();
	
	tell_object(me, "��װ�������Ͱ͵����ӣ���������" + victim->name() + "�߹�ȥ�����˫�֣���Ҫ"
		+ ob->query("unit") + ob->name() +"...\n\n");
	tell_object(victim, me->name() + "�����Ͱ͵����������߹���������֣�˵����" + RANK_D->query_respect(victim) + "���кã�����" 
		+ ob->query("unit") + ob->name() + "�� ...��\n\n");
	message("vision", "ֻ��" + me->name() + "װ�������Ͱ͵����ӣ���������" 
		+ victim->name() + "�߹�ȥ��\n���˫�֣�˵����"
		+ RANK_D->query_respect(victim) + "�����кð� ...\n\n", environment(me), ({ me, victim }) );
	me->set_temp("begging", 1);
	call_out( "compelete_beg", 3, me, victim, ob, sp, dp);
	return 1;
}

protected void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;
	object where;
	
	if ( !me ) return;
	
	me->delete_temp("begging");
	where = environment(me);
	
	if ( !victim )
	{
		tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
		return;
	}
	if ( !where 
		|| (!wizardp(me) && where->query("no_fly")) )
	{
		tell_object(me, "���ﲻ����л��������ַ��ĵط���\n");
		return;
	}
	if ( environment(victim) != environment(me) ) 
	{
		tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
		return;
	}
	if ( !ob || (playerp(me) && !playerp(victim)) )
	{
		tell_object(me, "�Է����������Ү!\n");
		return;
	}
	if ( !living(victim) )
	{
		tell_object(me, "����Ȼ��"+victim->name()+"�����ţ��������㡣\n");
		return;
	}
	if ( playerp(me) && me->query_temp("apply/name") )
	{
		tell_object(me, victim->name()+"�������ۣ�ҡ��ҡͷ�ֹ�����������˭ѽ����\n");
		return;
	}
	if ( victim->query("shen") < -5000 )
	{
		message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ��������������ӣ���ȻҪ��Ҫ��" 
			+ RANK_D->query_self_rude(victim) 
			+ "ͷ�����ˡ���\n", me);
		me->fight_ob(victim);
		victim->kill_ob(me);
		return;
	}
	if ( random(sp) > dp ) 
	{
		if ( ob->query("money_id") )
		{
			amount = ob->query_amount();
			if ( amount < 5 )
			{
				tell_object(me, "���������߰ɣ���һ������Ѿ�û�ж�����ˮ��ե�ˡ�\n");
				return;
			}
			ob->set_amount(amount - amount/5);
			ob1=new("/clone/money/" + ob->query("money_id"));
			ob1->set_amount(amount/5);
			ob1->move(me);
		}
		else if ( !ob->move(me) ) 
		{
			ob->move(where);
			tell_object(me, "���ֵ�һ" + ob->query("unit") + ob->name() 
			+ "�����Ƕ������̫���ˣ����ö��ڵ��¡�\n");
			return;
		}
		tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬ҡҡͷ��̾�˿�����������һ" 
			+ ob->query("unit") + ob->name() + "��\n");
		tell_object(victim, "�㿴��" +  me->name() +"�Ŀ�������̾�˿�����������һ" 
			+ ob->query("unit") + ob->name() + "��\n");
		me->improve_skill("begging", random(me->query("int")));
		me->add("potential", 1, 1);
		me->add("combat_exp", 1, 1);
		if ( random(sp) < dp/2 )
			message("vision", "�㿴��" + victim->name() + "����" + me->name() + "������м��ҡҡͷ��"
				+ "������һ" + ob->query("unit")
				+ ob->name() + "��\n", environment(me), ({ me, victim }) );
		me->start_busy(6);
	} 
	else 
	{
		if ( random(sp) > dp/2 ) 
		{
			message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ������� $N����һ������æŤͷ��������߿��ˡ�\n", me);
			me->add("begger", 1);
			return;
		}
		tell_object(me, victim->name() + "Ť��ͷȥ������������\n");
		tell_object(victim, "��Ť��ͷȥ����" + me->name() + "������\n");
		message("vision", victim->name() + "Ť��ͷȥ����" + me->name() + "������\n", 
			environment(me), ({ me, victim }) );
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : beg <ĳ��> from <ĳ��>
HELP
    );
    return 1;
}

