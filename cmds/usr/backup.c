
inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object link_ob;
   int cur_time;

   seteuid(getuid());

   if( !objectp(link_ob = me->query_temp("link_ob")) )
     return notify_fail("�㲻�Ǿ����������߽��룬���ܴ��档\n");
     
    cur_time = time();
if( me->query("combat_exp") < 50000 )               	
return notify_fail("Ϊ�˼���ϵͳ������ֻ�о���ﵽ21��ſ��Ա��ݡ�\n");
if( !wizardp(me) && (cur_time-me->query("last_backup")) < 3600 )        	
return notify_fail(HIW"Ϊ����ϵͳ����"HIG"1Сʱ"HIW"ֻ�ܱ���һ�Σ��㻹��ȴ�"HIY+(3600-(cur_time-me->query("last_backup")))/60+"����"+(3600-(cur_time-me->query("last_backup")))%60+"��"HIW"�����ٴα���"NOR);	
   
    me->set("last_backup", cur_time);
    
   if( (int)link_ob->save() && (int)me->save() && (int)me->backup()) {

         write("�������沢������ϡ�\n");
        
     return 1;
   } else {
       write("��������ʧ�ܣ�����ϵ��ʦ��\n");
     return 1;
   }
}

int help(object me)
{
   write(@HELP
ָ���ʽ��backup

���ݵ���������ĵ�������Ī��������˺��󣬿�Ҫ����ʦ�ָ���
HELP
   );
   return 1;
}

