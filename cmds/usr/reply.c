// reply.c

#include <net/dns.h>
inherit F_CLEAN_UP;
int help(object me);


#define DEBUG "wenwu"
#ifdef DEBUG
void debug(string x)
{
    object monitor;
    if (!stringp(x) || !stringp(DEBUG))     return;
    monitor=find_player(DEBUG);
    if(monitor && monitor->query("env/debug"))     tell_object(monitor,x+"\n");
}
#else
#define debug(x)
#endif

object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int main(object me, string arg)
{
        string target, mud;
        object obj,wiz;
        if( !arg || arg=="" )
                return notify_fail("��Ҫ�ش�ʲ�᣿\n");
        if( !stringp(target = me->query_temp("reply")) )
                return notify_fail("�ղ�û���˺���˵������\n");
    if( userp(me) && !wizardp(me)) {
        if (me->query("chblk_tell")+300>time())
            return notify_fail("�����ں���˻��,��仰Ҳ˵�����ˡ�\n");
       me->add_temp("tell_msg_cnt", 1);
       if (me->query_temp("tell_msg_cnt")>5)
            if (time()-me->query_temp("tell_time")<2)
                me->set("chblk_tell",time());
            else
                me->delete_temp("tell_msg_cnt");
    }

        if( sscanf(target, "%s@%s", target, mud)==2 ) {
                GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
                write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
                return 1;
        }
        obj = find_player(target);
        if( !obj ||!interactive(obj) || !environment(obj) )
                return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
		if(wizardp(obj) && obj->query("env/invisibility") == 10)
			return notify_fail("û�������...\n");
    debug(sprintf( YEL "%s(%s)�ش�%s(%s)��%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), arg));
write(HIG "�㸹�����" + obj->name(1) + "��" + arg + "\n" NOR);	
        if (me->id(obj->query("env/no_tell")) )
                return notify_fail("����Ȼ��"+obj->name(1)+"��������������������˵��....��\n");
tell_object(obj, sprintf(HIG"%s��������㣺%s\n"NOR,me->name(1), arg ));	
wiz=filter_array( users() , "party_listener", this_object(), (wizardp(me)) );
	message("channel:rumor",HIW"��REPLY��������"HIG+me->query("name")+NOR"("HIY+me->query("id")+NOR")"HIW"��"HIG+obj->query("name")+NOR"("HIY+obj->query("id")+NOR")"HIW"��"HIB+arg+NOR"\n",wiz);
        if (query_idle(obj)>120) write(YEL+"����"+obj->name(1)+"�Ѿ�����"+query_idle(obj)/60+"���ӣ������������ϻش���Ӵ��\n"+NOR);
        obj->set_temp("reply", me->query("id"));
        return 1;
}

int party_listener(object ppl)
{
	if( !environment(ppl))
		return 0;
	if(wizardp(ppl))
		return 1;
	else
		return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��reply <ѶϢ>
����������ָ��͸ղ��� tell ����˵����ʹ����˵����
see also : tell
HELP
        );
        return 1;
}

