// no_equip.c ����װ��
// make by cigarman 2012

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string query_msg_color()   { return YEL;         } 

string query_is_id  ()     { return "no_equip";}   
                      
string query_msg_my()     { return "��˫��˫������Ҫ�����޷�����ʹ���װ����";         }  
string query_msg_round()  { return "����ȥ˫�ֲ�����Ӳ������ʮ����";         }  
                                                                                                  
int update_condition(object me, int duration)
{
       
        tell_object(me, query_msg_color()+query_msg_my()+"\n"NOR);
        tell_room(environment(me), query_msg_color()+me->name()+query_msg_color()+query_msg_round()+"\n" NOR,({ me }));
        if( duration < 1 ) {
                me->clear_condition(query_is_id());
                return 0;
        }
        else {
                me->apply_condition(query_is_id(), duration - 1);
                return CND_CONTINUE; 
        }
        
}

string query_type(object me) { return "busy"; }


