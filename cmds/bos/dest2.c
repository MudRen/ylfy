#include <ansi.h>
#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
       string objid,userid;
       object obj,user;
       if (!arg)
           return notify_fail("ָ���ʽ : dest2 <���> in <���>\n" );
       if( sscanf(arg, "%s in %s", objid, userid)!=2 )
           return notify_fail("ָ���ʽ : dest2 <���> in <���>\n" );
       user = find_player(userid);
       if(!user || !playerp(user))
           return notify_fail("�Ҳ�������ˡ�\n");
       obj=present(objid,user);
       if (!obj)
           return notify_fail("û���������....��\n");
           printf("���ٻ���һ���ڶ�����"HIG"%s(%s)"NOR"���ϵ�"HIW"%s"NOR"���ɵ�\n",
                   user->query("name"),user->query("id"),obj->query("name"));
       destruct(obj);
       if(obj)
           write("���޷����������ݻ١�\n");
       else
           write("OK\n");
       return 1;
}
int help(object me)
{
       write(@HELP
ָ���ʽ : dest2 <���> in <���>
���������ϵ�һ�������
HELP
    );
    return 1;
}

