#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;  
int update_condition(object me,int duration)
{
   if ( duration < 1 ) return 0;

   if ( duration == 9 )
     message_vision(HIM"$N��Ȼ��΢΢һЦ��������Ϊ���أ�"
             +"�ƺ��е㲻�����⡣\n"NOR,me);
   else if (duration == 6 )
     message_vision(HIM"$NͻȻ��΢΢һЦ����ɫ�Ź֣���֪"
            +"���ڴ�ʲô�����⡣\n"NOR,me);    
   else if (duration <= 3 )
   {
     message_vision(HIM"$N��Ȼ�ſڹ���һЦ��������Ц����"
            +"�������Ͻ�Ӳ��Ц�ݹ���֮����\n" NOR,me);

     me->apply_condition("xys_poison",0);
     message("rumor", HIM"���������š���˵"+me->query("name")
            +"��������Ц��ңɢ�����ˡ�\n"NOR,users());
     me->die();
     return 0;
   }
   me->apply_condition("xys_poison", duration - 1);
   return CND_CONTINUE;      
}



