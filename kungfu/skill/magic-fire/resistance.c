#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	
    if ( me->is_busy() )
        return notify_fail("��������æ���޷��ٻ���������");
	if((int)me->query("neili")< 300)
	return notify_fail("��ķ���̫���ˣ�\n");
	if((int)me->query_skill("magic-fire",1)< 250)
	return notify_fail("��Ļ�ϵħ��̫���ˣ�\n");
        if ((int)me->query("magicgift")==1)
        return notify_fail("���Ѿ�ʹ�����������ˣ�\n");
	me->add("neili",-250);
	me->start_busy(2);
        me->set("magicgift",1);
	message_vision(HIR "\n$N����� [ΰ��Ļ�֮���飬�������_����Ϊ��֮����!] !!\n" NOR, me);	
	message_vision(HIR "\n$N����Χ���������ε���֮����!\n" NOR, me);
	return 1;
}