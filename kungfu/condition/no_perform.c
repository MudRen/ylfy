// no_perform.c 不能释放 受阻
// make by cigarman 2012

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string query_msg_color()   { return YEL;         } 

string query_is_id  ()     { return "no_perform";}   
                      
string query_msg_my()     { return "你双手双脚酸麻要命，无法使用出武功的特殊招式！";         }  
string query_msg_round()  { return "看上去四肢十分僵硬，身体时不时的颤抖一下！";         }  
                                                                                                  
int update_condition(object me, int duration)
{
        

        tell_object(me, query_msg_color()+query_msg_my()+"\n"NOR);
        tell_room(environment(me), query_msg_color()+me->name()+query_msg_color()+query_msg_round()+"\n" NOR,({ me }));

	me->add_busy(3);

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


