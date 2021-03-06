// more.c
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
int help(object me);
void create()
{
seteuid(getuid());
set("name","查看指令");
set("id", "more");           
set("channel_id", NOR+YEL"查看指令(more)"GRN);
}
int main(object me, string arg)
{
string file;
object ob;
seteuid(geteuid(me));
if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
file = resolve_path(me->query("cwd"), arg);
if( file_size(file) < 0 ) {
ob = present(arg, me);
if( !ob ) ob = present(arg, environment(me));
if (file=="here") ob=environment(me);
if( !ob ) return notify_fail("没有这个档案。\n");
file = base_name(ob) + ".c";
}
   if((int)master()->valid_read(file, me, "more") == 0) {
       printf("More: 权限不允许读%s.\n",
          (file == "" ? "根目录" : file));
       return 1; }
   if((int)master()->valid_write(file, me, "more") == 0) {
        printf("More: 权限不允许读%s.\n",
          (file == "" ? "根目录" : file));
        return 1; 
   }
log_file("edit/mfile", sprintf("%s%s more %s (%s)\n", me->query("name"),
"(" + me->query("id") + ")", file , 
CHINESE_D->chinese_time(5,ctime(time())) ));
CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+"("+me->query("id")+")"+" More "+
file+"。\n"NOR);
if (! (int)SECURITY_D->valid_read(file,me) ) return notify_fail("没有找到这个档案。\n");
me->start_more_file(read_file(file),file);
return 1;
}
int help(object me)
{
write(@HELP
指令格式 : more <档案>|<物件名>
分页显示档案内容。
more 模式下的指令:
q      : 离开 more.
b      : 显示前一页的内容.
[ENTER]: 显示下一页的内容.
HELP
);
return 1;
}
