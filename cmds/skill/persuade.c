// du.c

#include <ansi.h>

// inherit F_CLEAN_UP;
inherit SKILL;

int main(object me, string arg)
{
	string who;
	object ob, victim;
       
	mapping myfam, vtfam;
	int sp, dp;

	seteuid(getuid());

        if ( (!(myfam = me->query("family")) || myfam["family_name"] != "������") )
                return notify_fail("ֻ�ж��ҵ��Ӳ����ö������ˣ�\n");

        if( (string)me->query("class") != "bonze")
                return notify_fail("�㲻�ǳ��ҵ��Ӳ���ʹ�ö������ˣ�\n");

        if( environment(me)->query("no_fight") )
		return notify_fail("����û���˴򶷣�\n");

	if( me->query_temp("dushi") )
		return notify_fail("���Ѿ���Ȱ�˼Ұն��ˣ�\n");

        if( me->query_skill("yugalism",1) < 20 )
                return notify_fail("��ķ�ѧ������տ�����޷�ʹ�ö������ˣ�\n");

	if( !arg || sscanf(arg, "%s halt", who)!=1 ) return
		notify_fail("ָ���ʽ��quanjia <����> halt\n");

	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("�����ҵĶ��������\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("��ҪȰ˭�ն���\n");

        if( victim->query("race") == "Ұ��" )
                return notify_fail("�㷢ʲôɵ������ô�����Ķ���˵��ʲô����\n");

    if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "������" )
        return notify_fail("�㲻�����ɵ�ʹ�ö������ˣ�\n");
       if( victim->is_fighting())
       {
       	tell_object(me, "��ҡҡ��ͷ����������" + victim->name() + "�߹�ȥ��˫�ֺ�ʮ����ʼ���з�"
			+ "...\n\n");
	tell_object(victim, me->name() + "ҡҡ��ͷ���������߹�����˫�ֺ�ʮ��˵�����ҷ�ȱ��նȶ�����, ����" + RANK_D->query_respect(victim) + "�ն�, ���������� ...��\n\n");

	message("vision", "ֻ��" + me->name() + "ҡҡ��ͷ����������" 
		+ victim->name() + "�߹�ȥ��\n��˫�ֺ�ʮ��˵��: ��"
		+ RANK_D->query_respect(victim) + "��ͣ�ְ� ...\n\n", environment(me), ({ me, victim }) );

     }
       else 
     {
         return notify_fail("�Է�û�д򶷣���Ȱʲô�ܣ�\n");
       }

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("��Ҳ���Ȱ��ʦ�ն���\n");

	if( me->is_fighting() )
                return notify_fail("һ�ߴ��һ��Ȱ���˰ն�����������α�����ˣ�\n");


	sp = (int)me->query_skill("yugalism",1) * 10 + (int)me->query("kar") * 5;
	if( sp < 1 ) sp = 1;
	dp = (int)victim->query("jing");

	me->set_temp("dushi", 1);
	call_out( "compelete_dushi", 3, me, victim, ob, sp, dp);

	return 1;
}

void compelete_dushi(object me, object victim, object ob, int sp, int dp)
{
	int exp;


	me->delete_temp("dushi");

	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ���Ҫ�ҵ����Ѿ����ˡ�\n");
		return;
	}

	if( living(victim) && (random(sp+dp) > (dp*2) ) ) 
	{
                victim ->remove_all_killer();
		tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬ҡҡͷ��̾�˿�����ֹͣ�˴򶷡�\n");
		tell_object(victim, "������֮�����в���һ�����������������ȥ�ˡ�\n");

		me->improve_skill("dushi-jiren", random(me->query("int")));
                if( me->query("combat_exp") > victim->query("combat_exp"))
                return ;
               	if(((int)me->query("learned_points") + 50) > (int)me->query("potential"))
                exp = (int)me->query_int();
                me->add("potential",random(20));
                me->add("combat_exp",random(exp));
		me->start_busy(2);
                return;
	} 

      else if((random(sp+dp)) < dp/2)    
             {          
               message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ����Ҷ������˸������ˣ��ܰն���! \n�������ǲ�����ˣ���������������˵��\n", me);
               victim ->remove_all_killer();
               victim->kill_ob(me);
               return;
             }
      else if( random(sp) < dp*2 )
  	    {
		message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ����Ҷ������˸������ˣ��ܰն���! $N̾�˿���ת���߿��ˡ�\n", me);
		me->start_busy(1);
		return;
		}
      else {
        	tell_object(me, victim->name() + "Ť��ͷȥ������������\n");
		tell_object(victim, "��Ť��ͷȥ����" + me->name() + "������\n");
		message("vision", victim->name() + "Ť��ͷȥ����" + me->name() + "������\n", 
			environment(me), ({ me, victim }) );
                me->start_busy(1);
                return;
            }
}
int help(object me)
{
write(@HELP
ָ���ʽ : quanjia <ĳ��> halt

HELP
    );
    return 1;
}
