// TIE@FY3
#include <ansi.h>
inherit F_SSERVER;
 int main(object me, object target)
{
        int wimpy;
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("�㲻��ս���У�����Ҫ��װ����\n");
if(me->query("shen") < 0)       	
return notify_fail("��Ұ�Ĳ�����������Ȼ������װ����������\n");	
target = offensive_target(me);	
if(me->query("shen") > 0)	
   return notify_fail("��һƬ���ǵ��ģ���Ӧ����ɱ�У������������\n");
   target = offensive_target(me);
   if (target->query("combat_exp") > me->query("combat_exp"))
     {
if(random(20)>1) { write("����ͼװ���������"+target->query("nname")+"������ͼ��\n"); 	
me->start_busy(45);                     	
      return 1;
}
     }
else if (random(20)>2) {write("����ͼװ���������"+target->query("name")+"������ͼ��\n"); 	
me->start_busy(45);                     	
      return 1; }
        wimpy = (int)me->query("env/wimpy");
        message_vision("$N�ҽ�һ����һͷ�Ե��ڵ��¡�\n$N���ˡ�\n",me);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set("disable_type",HIG "<������>" NOR);
        me->set("no_get",1);
        me->remove_all_killer();
        me->remove_all_enemy();
        me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me, wimpy :), 
30+random(50 - (int) me->query_con()));
        return 1;
}

void remove_dazuo(object me, int wimpy)
{
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
 me->set("no_get",0);
   me->delete_temp("block_msg/all");
        me->set("env/wimpy",wimpy);
        message_vision("$N�ڵ������ĵط��˸���С��������������ۡ�\n",me);
        me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
ָ���ʽ : jiasi
������ս����װ�������������Ļ��ᡣ
������߲�����װ����

HELP
        );
        return 1;
}

