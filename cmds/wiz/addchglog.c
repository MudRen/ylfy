
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        seteuid(geteuid(me));
        if (!arg)
           return notify_fail("ָ���ʽ: addchglog ��־��Ϣ \n");
 
       if (file_size("/log/chglog.txt")<0)
               return notify_fail("/log/chglog.txt�����ڡ�\n");
       if (!(int)SECURITY_D->valid_write("/log/chglog.txt",me,"write_file") )
               return notify_fail("��û���㹻�Ķ�дȨ����\n");
        if( !log_file("/chglog.txt",arg+"\n") )
                write("Ok.\n");
        else
                write("��û���㹻�Ķ�дȨ����\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : addchglog ��־����
 
��ָ�������/log/chglog.txt׷��һ�����ݡ�
HELP
    );
    return 1;
}
 

