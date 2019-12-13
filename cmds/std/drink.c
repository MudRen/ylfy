// drink.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object obj;

    if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");

    if(!arg) return notify_fail("��Ҫ��ʲô������\n");
    if (!environment(me)) return notify_fail("Ŀǰ�����⡣\n");
    if (!me) return notify_fail("������ˡ�\n");
if (!present(arg, me)) return notify_fail("������û������������\n");	
if(objectp(obj != present(arg, me)) )
return notify_fail("������û������������\n");	
if( me->query("water") >= me->max_water_capacity() )	
return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");	
//   if(!objectp(obj = present(arg, me)) ){	
if( obj != present(arg, me) )  	
return notify_fail("������û������������\n");		
if(obj = present(arg, environment(me)) && obj->is_character() )
//       tell_room(environment(me), me->name() + "���ŵ��ϵ�"+obj->name() + "������һ����ĭ��\n",({ me }));	
             return notify_fail("������û������������\n");
//            }	
    if(!obj->query("water_supply") )
             return notify_fail("������㣬�ⶫ���ܳ���\n");
    if(!obj->query("water_remaining") )
	     return notify_fail( obj->name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");
/*
    if( me->query("water") >= me->max_food_capacity() )
	     return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
*/
		
    me->add("water", obj->query("water_supply"));
    if( obj->query("drink_func") ) return 1;
    if( !obj ) return 1;
    
    obj->set("value", 0);
    obj->add("water_remaining", -1);
//    if((int)obj->query("food_busy"))
//             me->start_busy(obj->query("food_busy"));
            
    if( !obj->query("water_remaining") ) {
	     obj->delete_temp("apply/long");
	     if((string)obj->query("finish_msg"))
	           message_vision(obj->query("finish_msg"), me, obj);
	     else message_vision("$N��ʣ�µ�$n�ȵøɸɾ�����\n", me, obj);
	     if( !obj->finish_drink() )
		   destruct(obj);
	     } 
    else{
             if((string)obj->query("drink_msg"))
                   message_vision(obj->query("drink_msg"), me, obj);
             else message_vision("$N����$n���˼��ڡ�\n", me, obj);
             }
    return 1;
}



int help(object me)
{
    write(@HELP
ָ���ʽ : drink <��Ʒ����>
 
���ָ����������ˮ��
 
HELP
    );
    return 1;
}
 
