
#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{     
        string msg;
        string str;
        object target,*name;
        int i,cnt;
        
        if(!me->query("party/zhu"))
                        return notify_fail("ֻ�а��İ��������´�׷ɱ�\n");
        if(!me->query("party/id"))
                        return notify_fail("��Ŀǰ��δ�����κΰ�����֯��\n");  
        if(! arg)       {
                msg=HIR"������\n"NOR;
                msg+="��������������������������������������������������������������������������\n";
                name=users();
                cnt=0;
                for(i=0;i<sizeof(name);i++)     {
                        if(name[i]->query("vendetta/"+me->query("party/id"))) {
                        msg+=sprintf("%-18s%s",name[i]->query("name")+"("+name[i]->query("id")+")",
                        (cnt%4==3? "\n":""));
                        cnt++;
                        }
                }
                if(cnt==0||(cnt%4))     msg+="\n";
                msg+="��������������������������������������������������������������������������\n";
                me->start_more(msg);
                return 1;
        }
        if(sscanf(arg,"-a %s",str)==1)  {
                target=find_player(str);
                if(!target)
                        return notify_fail("����׷ɱ����Ҳ�����Ϸ�С�\n");
				if(wizardp(target) && !wizardp(me))
                        return notify_fail("����׷ɱ����Ҳ�����Ϸ�С�\n");
                if(target==me)
                        return notify_fail("׷ɱ�Լ���û����ɡ�\n");
                if(target->query("vendetta/"+me->query("party/id")))
                        return notify_fail("��������ں������С�\n");
				if (file_name(environment(target)) == "/d/shaolin/bagua")
					return notify_fail("����׷ɱ����������ڰ�ȫ�ش���\n");
				if (target->query("age") < 18)
					return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
				if ( me->query_temp("party_zhuisha") > time() )
					return notify_fail("����ָ�����Ƶ�������Ժ�10���ٽ��иò�����\n");
                target->set("vendetta/"+me->query("party/id"),1);
                target->save();
           if(me->query("party/id")==(string)target->query("party/id"))
                message("chat",
               HIB"��"HIR"����׷ɱ��"HIB"����"HIR"��"+me->query("party/name")+"���￪ʼ׷ɱ��ͽ "+
                target->query("name")+"("+target->query("id")+")��\n"NOR,users());
                else
               message("channel:chat",HIB"��"HIR"����׷ɱ��"HIB"����"HIR"��"+me->query("party/name")+"���￪ʼ׷ɱ "+target->query("name")+"("+target->query("id")+")��\n"NOR,users());
				me->set_temp("party_zhuisha", time()+10);
                return 1;
        }
        if(sscanf(arg,"-d %s",str)==1)  {
                target=find_player(str);
                if(! target)    return notify_fail("�˴�û����ô����ҡ�\n");
				if(wizardp(target) && !wizardp(me))
                        return notify_fail("����׷ɱ����Ҳ�����Ϸ�С�\n");
                if(! target->query("vendetta/"+me->query("party/id")))
                        return notify_fail("����Ҳ�����׷ɱ�ĺ������С�\n");
				if ( me->query_temp("party_zhuisha") > time() )
					return notify_fail("����ָ�����Ƶ�������Ժ�10���ٽ��иò�����\n");
                target->delete("vendetta/"+me->query("party/id"));
//              target->remove_all_killer();
                target->save();
                message("channel:chat",
                HIB"��"HIY"����������"HIB"����"HIY"��"+me->query("party/name")+"����ֹͣ׷ɱ "+target->query("name")+"("+target->query("id")+")��\n"NOR,users());
				me->set_temp("party_zhuisha", time()+10);
                return 1;
        }
        return notify_fail("ָ���ʽ��zhuisha [-a][-d]<���ID>\n");
}

int help(object me)
{
        write(@HELP
ָ���ʽ��zhuisha [-a][-d]<����ID>
��ָ��Ϊ����ר�ã����Ӳ�����ʾĿǰ���߱�
׷ɱ����ҡ�-a ׷ɱĳ��ң�-d ȡ��׷ɱĳ
��ҡ�����׷ɱ������������Զ�ֹͣ׷ɱ��
HELP
        );
        return 1;
}

