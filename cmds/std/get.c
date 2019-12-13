// get.c

#include <ansi.h>
inherit F_CLEAN_UP;
int do_get(object me, object ob,object env,int amount);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        string from, item;
        object obj, *inv, env, obj2;
        int i, amount;
        if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n");
        // Check if a container is specified.
        if( sscanf(arg, "%s from %s", arg, from)==2 ) {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return notify_fail("���Ҳ��� " + from + " ����������\n");
if (userp(env) && !wizardp(me))	
return notify_fail("�㲻�ܴ�"+env->query("name")+"�������κζ�����\n");	
                if (env->query("no_get_from") && !wizardp(me))
                        return notify_fail("�㲻�ܴ�"+env->query("name")+"�������κζ�����\n");
if( ( living(env) || env->query_temp("sleeped") ) && (wiz_level(me) <= wiz_level(env)) )
                        return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
			if ( env->bind_get(me) ) 
				return notify_fail("���Ǳ��˵ģ�Ŀǰ�������䶳״̬��ʱ�޷����������κζ�����\n");
        } else env = environment(me);
        // Check if a certain amount is specified.
        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("����û������������\n");
                if( amount < 1 )
                        return notify_fail("�����ĸ���������һ����\n");
                if(obj->query_amount() ){
                        if( amount > obj->query_amount() )
                                return notify_fail("����û��������" + obj->name() + "��\n");
                        else if( amount == (int)obj->query_amount() ) {
                                return do_get(me, obj,env,1);
                        } else {
                                i= (int)obj->query_amount();
                                obj->set_amount( amount );
                                obj2 = new(base_name(obj));
                                // Counting precise amount costs more time.
                                do_get(me, obj,env,1);
                                obj2->set_amount( i-amount );
                                obj2->move(env);                        // For containers.
                                return 1;
                        }
                }else   if( amount>1 && me->is_fighting() )
                                return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
                        else    return do_get(me,obj,env,amount);
        }
        // Check if we are makeing a quick get.
        if(arg=="all") {
                if( me->is_fighting() ) return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
                if( !env->query_max_encumbrance() )     return notify_fail("�ǲ���������\n");
                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("������û���κζ�����\n");
           
                for(i=0; i<sizeof(inv); i++) {
                	
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        if (i>7)  break;
                        do_get(me, inv[i],env,1);
                }
                write("Ok��\n");
                return 1;
        }
        if( !objectp(obj = present(arg, env)) )
                return notify_fail("�㸽��û������������\n");
        return do_get(me, obj,env,1);
}
        
int do_get(object me, object obj,object env,int amount)
{
        int i,equipped;
        string str,arg1,arg2;
        if( !obj ) return 0;
//   if( obj->query("money_id",1) && obj->query("money_id",1) != "coin"  && obj->query("money_id",1) != "gold"  && obj->query("money_id",1) != "silver" && !wizardp(me))                     	
//   return notify_fail("��������ò�������\n");   	
        if( obj->query("no_get") && !wizardp(me))
                return notify_fail("��������ò�������\n");
        if( obj->query("board_id") && !wizardp(me))
                return notify_fail("��������ò�������\n");
		if(obj->is_corpse() && obj->is_skeleton())
			return notify_fail("ʬ����ʱ�޷�ʰȡ�������½⣿\n");
        if( obj->is_character() ){
if( living(obj) && wizhood(me)!="(admin)" && wizhood(me)!="(boss)")  return notify_fail(obj->query("name")+"�����㱳��\n");     	
        }
if(obj->query_temp("sleeped") && wizhood(me)!="(boss)")  	
return notify_fail(obj->query("name")+"�����㱳��\n");
		if ( obj->bind_get(me) ) return notify_fail("���Ǳ��˵ģ�Ŀǰ�������䶳״̬��ʱ�޷�����\n");
        if( me->is_fighting() ) me->start_busy(2);
        str=obj->short(1);
        foreach (object ob in all_inventory(env)){
                if (ob->short(1)!=str)  continue;
                if( ob->query("no_get") && !wizardp(me)){
                      write(ob->name(1)+"�ò�������\n");
                      continue;
                }
if(obj->query_temp("sleeped") && wizhood(me)!="(boss)") {
write(ob->name(1)+"�����㱳��\n");	
continue;	
}
if( ob->is_character() && living(ob) && wizhood(me)!="(admin)" && wizhood(me)!="(boss)"){	
                      write(ob->name(1)+"�����㱳��\n");
                      continue;
                }
                if( ob->move(me) ) {
                        if( ob->is_character() ){
                                message_vision( "$N��$n�����������ڱ��ϡ�\n", me, ob );
                                if (userp(ob))  tell_object(ob,BOLD+"�����Ժ����ظе��ƺ����˰��㱳��������\n"+NOR);
                                return 1;
                        }
                        else{
                        if( ob->query("equipped") ) equipped = 1;
                        arg1= env==environment(me)? "����":(env->is_character() ?"��"+env->name()+"����" + (equipped? "����" : "�ѳ�"):"��" + env->name() + "���ó�");
                        arg2=ob->query("unit")+ob->name();
                        }
                }       else{   tell_object(me,ob->name()+"�������̫���ˡ�\n");return 1;}
                i++;
                if(i >= amount)      break;
        }
    if (!i) return 1;
   if ( !me->query("env/invisibility") )
        message_vision( sprintf("$N%s%s%s��\n", arg1,CHINESE_D->chinese_number(i),arg2), me);
        if (! env->is_character() && !sizeof(all_inventory(env)))
        env->set("no_clean_up",0);
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]
           get <����> <��Ʒ����> [from <������>]
���ָ��������������ϻ������ڵ�ĳ����Ʒ.
 
HELP
    );
    return 1;
}

