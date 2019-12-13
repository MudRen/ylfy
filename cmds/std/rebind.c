// rebind.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string equip, topic;
        object ob, target;
        seteuid(getuid());
        if( !arg || sscanf(arg, "%s to %s", equip, topic)!=2 )
                return notify_fail("��Ҫ�������ʲô������\n");
        if( !objectp(target = present(topic, environment(me))) )
                return notify_fail("����û������ˡ�\n");
        if( !objectp(ob = present(equip, me)) )
                return notify_fail("������û������������\n");
        if ( me->is_busy() ) 
                return notify_fail("����һ��������û����ɡ�\n");
        if (!playerp(target) )
                return notify_fail("�Է������ˡ�\n");
        if (target==me) 
                return notify_fail("������͸��Լ�û�����塣\n");
        if (sizeof(all_inventory(target)) > 50) 
                return notify_fail("�Է����ϵĶ����Ѿ�̫���ˡ�\n");
        if ( !ob->query("xyzx_sys/bind_type") )
                return notify_fail("������������Ҫ������͡�\n");
        //if ( ob->query("xyzx_item/pinji") == 3)
                //return notify_fail("��Ա�������ܽ��\n");
		if ( !ob->query("armor_prop/armor") && !ob->query("weapon_prop/damage") )
		    return notify_fail(HIR"��ֻ�ܽ�������������߷���!����!!��\n");		
        if ( ob->query("equipped") )
                return notify_fail("�������ϻ����������ϵ�װ���޷�������͡�\n");
        if( (int)target->query_encumbrance() + (int)ob->weight() > (int)target->query_max_encumbrance() )
                return notify_fail("�Է��ò�����ô�صĶ�����\n");
        if (me->query("more_money") < 1)  
                return notify_fail("���������Ҫһ�����ƽ���û��ô���\n");

        me->add("more_money", -1);

        ob->delete("bind_master_level");
        ob->move(target);
        
        message("channel:chat", HIY"\n�������챦��"+HIM"��"+me->query("name")+"�������챦"+ob->query("name")+HIM"���͸�"+target->query("name")+"��\n"NOR,users());


        return 1;
}
int help(object me)
{
   write( @HELP
ָ���ʽ: rebind װ�� to ���
����װ�����͸�������ң�ÿ������һ�����ƽ��
HELP
   );
   return 1;
}

