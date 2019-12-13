#include <ansi.h>
#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
       string objid,userid;
       object obj,user;
       if (!arg)
           return notify_fail("指令格式 : dest2 <物件> in <玩家>\n" );
       if( sscanf(arg, "%s in %s", objid, userid)!=2 )
           return notify_fail("指令格式 : dest2 <物件> in <玩家>\n" );
       user = find_player(userid);
       if(!user || !playerp(user))
           return notify_fail("找不到这个人。\n");
       obj=present(objid,user);
       if (!obj)
           return notify_fail("没有这样物件....。\n");
           printf("你召唤出一个黑洞，将"HIG"%s(%s)"NOR"身上的"HIW"%s"NOR"吞噬掉\n",
                   user->query("name"),user->query("id"),obj->query("name"));
       destruct(obj);
       if(obj)
           write("你无法将这个物件摧毁。\n");
       else
           write("OK\n");
       return 1;
}
int help(object me)
{
       write(@HELP
指令格式 : dest2 <物件> in <玩家>
清除玩家身上的一个物件。
HELP
    );
    return 1;
}

