// more.c
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
int help(object me);
void create()
{
seteuid(getuid());
set("name","�鿴ָ��");
set("id", "more");           
set("channel_id", NOR+YEL"�鿴ָ��(more)"GRN);
}
int main(object me, string arg)
{
string file;
object ob;
seteuid(geteuid(me));
if (!arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
file = resolve_path(me->query("cwd"), arg);
if( file_size(file) < 0 ) {
ob = present(arg, me);
if( !ob ) ob = present(arg, environment(me));
if (file=="here") ob=environment(me);
if( !ob ) return notify_fail("û�����������\n");
file = base_name(ob) + ".c";
}
   if((int)master()->valid_read(file, me, "more") == 0) {
       printf("More: Ȩ�޲������%s.\n",
          (file == "" ? "��Ŀ¼" : file));
       return 1; }
   if((int)master()->valid_write(file, me, "more") == 0) {
        printf("More: Ȩ�޲������%s.\n",
          (file == "" ? "��Ŀ¼" : file));
        return 1; 
   }
if (! (int)SECURITY_D->valid_read(file,me) ) return notify_fail("û���ҵ����������\n");
me->start_more_file(read_file(file),file);
return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : more <����>|<�����>
��ҳ��ʾ�������ݡ�
more ģʽ�µ�ָ��:
q      : �뿪 more.
b      : ��ʾǰһҳ������.
[ENTER]: ��ʾ��һҳ������.
HELP
);
return 1;
}

