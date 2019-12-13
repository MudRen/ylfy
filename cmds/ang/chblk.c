// channel block command..

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        
    if (!arg)
        return  notify_fail("命令格式: chblk <玩家id>\n");
    
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("这个人不在！\n");
//if (wizardp(ob)) return notify_fail("不能关闭巫师的频道。\n");
        if (time()- ob->query("chblk_channel")<3600)
                tell_object(me,(string)ob->query("name")+"的聊天频道是关闭的。\n");
        else{
                ob->set("chblk_channel",time());
                tell_object(me, (string)ob->query("name")+"的所有频道被关闭了。\n");
        }
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : chblk <某人>

       此命令将关闭某人的频道。
HELP
    );
    return 1;
}

