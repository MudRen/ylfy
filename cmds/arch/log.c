// log.c

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string msg)
{
        string *lines;
        string arg,file=me->query("cwd")+".ChangeLog";
        if( !msg || msg=="" ){
        if (file_size(file)<0) return help(me);
        arg=read_file(file);
        if (strlen(arg)>8190)
           me->start_more(arg);
        else
           write(arg);
        return 1;
        }

        lines = explode(msg, "\n");
        for(int i=0; i<sizeof(lines); i++)
                lines[i] = "    " + lines[i];
        msg = implode(lines, "\n") + "\n";

        seteuid(geteuid(this_player(1)));
        write_file(file,"\n" + ctime(time()) + " By " + capitalize(getuid(me)) + "\n\n" + msg);
        write("Ok.\n");
        return 1;
}

int help(object me)
{
        write(@Help
ָ���ʽ: log <msg>

���������ĸı��¼�ڸ�Ŀ¼�µ� .ChangeLog ��
�����Ҫ������һ��, ���� to log ����¼��
Help
        );
        return 1;
}

