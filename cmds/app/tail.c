// tail file.

int help(object);

int main(object me,string arg) {
        string file,fileName;
        int line;

        if( !arg || arg == "" )
                return help(me);

        if( sscanf(arg,"%s %d", fileName, line ) != 2 ) {
                fileName = arg;
                line = 20;
        }
        if (file=="here") file=base_name(environment(me))+".c";
          else

        file = resolve_path(me->query("cwd"), fileName);

        if( file_size(file) < 0 )
                return notify_fail("û�����������\n");
        if( !read_file(file) )
//                return notify_fail("�ļ�̫���޷������ڴ档\n");
        {
        me->set("cwf", file);
        write(implode(explode(read_file(file), "\n")[<50..],"\n"));
       return 1;
        }
        me->set("cwf", file);
        write(implode(explode(read_file(file), "\n")[<line..],"\n"));
        write( "\n" );
        return 1;
}

int help(object me) {
        write("ָ���ʽ��tail <�ļ���> | <����>��\n");
        return 1;
}

