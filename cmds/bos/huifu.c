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
       

        if(!arg) return notify_fail("��Ҫ�ָ�˭������?\n");
        obj = present(arg, environment(me));
        if(!obj) obj = present(arg, me);
        if(!obj) obj = find_player(arg);
        if(!obj) return notify_fail("�Ҳ���ָ�����ˡ�\n");
        if(file_size(DATA_DIR+"/user/"+arg[0..0]+"/"+arg+".oo.o")==-1)
             return notify_fail(obj->query("name")+"("+obj->query("id")+")û�б��ݵ�����\n");
        cp((DATA_DIR+"/user/"+arg[0..0]+"/"+arg+".oo.o"),(DATA_DIR+"/user/"+arg[0..0]+"/"+arg+".o"));
        write_file("/log/cmds/huifu",sprintf("%s(%s) �ָ� %s(%s) �ĵ���on %s\n",
                me->name(1), me->query("id"),
                obj->name(1),obj->query("id"),ctime(time()) ));
 write(HIW"\n"+obj->query("name")+"("+obj->query("id")+")"HIG"�ĵ����ָ���ϡ�\n"NOR);
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : restoredata username 
 
���ڻָ�������ݡ����ã�
 
HELP
    );
    return 1;
}
