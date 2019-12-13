// breakup.c
//���±���

#include <ansi.h>
inherit F_CLEAN_UP;	

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        
        object where;
      
        seteuid(getuid());
        where = environment(me);

		if ( !interactive(me) ) return 0;

		if ( arg == "-stop" )               	
        {
			if ( me->query_temp("breakuping") )
			{
				me->delete_temp("breakuping");
				BIGUAN_D->del_breaking_user(me);
				message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
				message("chat", HIY"������ˮ�¡�"+HIM"��˵"+me->query("name")+HIM"�չ���;ͻȻ����,�ƺ�û��̫��Ľ�չ��\n"NOR,users() );
				return 1;
			}
			else
				return notify_fail("�����ڲ�û���˹���Ѩ��\n");	
        }
        
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (me->query("breakup"))
                return notify_fail("���Ѿ���ͨ���ζ������ˣ��ƺ�û�б�Ҫ����һ�Ρ�\n");

        if (me->query_temp("breakuping", 1))
                return notify_fail("�����������˹���Ѩ����ͼ��ͨ�ζ�����!\n");		

        if (where->query("no_fight"))	
                return notify_fail("�����ﲻ���˹�����,�޷���ͨ�ζ�����!\n");	

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (me->query("potential") < 10000)              	
                return notify_fail("���Ǳ�ܲ�����û���չ������Դ�ͨ�ζ�������\n");

        if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
                return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");

        if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
                return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");

        if ((int)me->query("max_neili") < 150000)   	
                return notify_fail("������������в��㣬����Ŀǰ�����Դ�ͨ�ζ�������\n");

        if ((int)me->query("neili") * 100 / me->query("max_neili") < 90)
                return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");

        if ((int)me->query_skill("force", 1) < 1000)	
                return notify_fail("������Լ����ڹ�������ޣ�������Ҫ�ȶ������ڹ����С�\n");

        message_vision("$N��ϥ���£���ʼڤ���˹����չ����С�\n", me);
        me->start_busy(5);                     	
        message("chat", HIY"������ˮ�¡�"+HIM"��˵"+me->query("name")+HIM"��ʼ�չ�����,��ͼ��ͨ�ζ�������\n"NOR,users() );	
		BIGUAN_D->add_breaking_user(me);
        
		return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : biguan

�չ������Դ�ͨ�ζ���������Ҫ�ǳ������������ڹ����ײ���������
���һ�����Ǳ�ܡ�һ����ͨ���ζ���������ͬʱ��չ��������������
���������ޡ�
�������жϱչ����У�����
biguan -stop
�Ϳ����ˡ�
HELP );
        return 1;
}
