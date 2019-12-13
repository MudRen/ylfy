
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        seteuid(geteuid(me));
        if (!arg)
           return notify_fail("指令格式: addchglog 日志信息 \n");
 
       if (file_size("/log/chglog.txt")<0)
               return notify_fail("/log/chglog.txt不存在。\n");
       if (!(int)SECURITY_D->valid_write("/log/chglog.txt",me,"write_file") )
               return notify_fail("你没有足够的读写权利。\n");
        if( !log_file("/chglog.txt",arg+"\n") )
                write("Ok.\n");
        else
                write("你没有足够的读写权利。\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : addchglog 日志内容
 
此指令可以往/log/chglog.txt追加一行内容。
HELP
    );
    return 1;
}
 

