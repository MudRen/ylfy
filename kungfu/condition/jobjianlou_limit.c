#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        object room;
        object obb;
        int step;
        
        if( duration < 1 ) return 0;  
        me->apply_condition("jobjianlou_limit", duration - 1);  
        room = environment(me);     

        if ( me->query_temp("guo_jianlou/where")) 
        if ( me->query_temp("guo_jianlou/where") != room->query("site")
             && !me->query_temp("guo_jianlou/job_over") ) 
        {
          message_vision(HIY"һ���α��ܹ�����$N˵�������Ȼ�������ӣ�"
                         +"��ȥ��������ˣ�\n"NOR,me);

          me->set("guo_shoucheng/failed",1);
          me->apply_condition("jobjianlou_limit",0);  
        }

        if ( me->query_temp("guo_jianlou/start_job")
             && me->query_temp("guo_jianlou/where") == room->query("site"))
        {
           if( duration % 2 == 0 && duration > 30)     
           {
             step=random(9)+1;
             message_vision(HIY"��Ȼ$N�Ӽ�����ƺ���������"HIW+chinese_number(step) +HIY"������һ��"HIR"�ɹż���"HIY"��̽ͷ̽�ԡ�\n"NOR,me);
             obb=new("/quest/guojob/job2/robber4");
             obb->move("/d/xiangyang/"+room->query("site")+step);
             obb->change_ob(me);
             obb->set("where",room->query("site"));
           } else
                if( duration % 10 == 0 )  
             message_vision(HIY"$Nͨ������ھ����Ѳ���ų���������"+ "���Ǻ���û�з����κε��顣\n"NOR,me);
        }

        if( me->is_ghost() && !me->query_temp("linji/youming") )
        {
         me->delete_temp("guo_jianlou");
         me->apply_condition("jobjianlou_limit",0);
         return 0;
        }

        if( duration == 2
            && me->query_temp("guo_jianlou/where") == room->query("site") )
        {
         message_vision(CYN"\nһ���س��α��ܹ���˵�����ɹ�������ʱ�������ˣ�" +"$N���Ի�ȥ�����ˣ�\n"NOR,me);
         if (me->query_temp("guo_jianlou/start_job")) 
         me->set_temp("guo_jianlou/job_over",1);
         me->delete_temp("guo_jianlou/start_job");
         me->apply_condition("jobjianlou_limit",0);     
        }
       return CND_CONTINUE;      
}

