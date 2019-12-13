#include <ansi.h>
#include <dbase.h>

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object obj;
       

        if(!arg) return notify_fail("你要恢复谁的数据?\n");
        obj = present(arg, environment(me));
        if(!obj) obj = present(arg, me);
        if(!obj) obj = find_player(arg);
        if(!obj) return notify_fail("找不到指定的人。\n");
        if(file_size(DATA_DIR+"/user/"+arg[0..0]+"/"+arg+".oo.o")==-1)
             return notify_fail(obj->query("name")+"("+obj->query("id")+")没有备份档案。\n");
        cp((DATA_DIR+"/user/"+arg[0..0]+"/"+arg+".oo.o"),(DATA_DIR+"/user/"+arg[0..0]+"/"+arg+".o"));
        write_file("/log/cmds/huifu",sprintf("%s(%s) 恢复 %s(%s) 的档案on %s\n",
                me->name(1), me->query("id"),
                obj->name(1),obj->query("id"),ctime(time()) ));
 write(HIW"\n"+obj->query("name")+"("+obj->query("id")+")"HIG"的档案恢复完毕。\n"NOR);
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : restoredata username 
 
用于恢复玩家数据。慎用！
 
HELP
    );
    return 1;
}
