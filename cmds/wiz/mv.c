// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("ָ���ʽ: mv <ԭ����> <Ŀ�굵��> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
	if (file_size(src)<0)
		return notify_fail("û�����������\n");
	if (src==dst)	return notify_fail("Ok��\n");
	if (!(int)SECURITY_D->valid_write(src,me,"write_file") )
		return notify_fail("��û���㹻�Ķ�дȨ����\n");
        if( !rename(src, dst) )
                write("Ok.\n");
        else
                write("��û���㹻�Ķ�дȨ����\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : mv <ԭ����> <Ŀ�굵��>
 
��ָ�������(��)�޸�ĳ��������Ŀ¼���ơ�
HELP
    );
    return 1;
}
 
