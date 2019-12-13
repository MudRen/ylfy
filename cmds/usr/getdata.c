#include <ansi.h>

inherit F_CLEAN_UP;

int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 15 ) ) return 0;
	while(i--)
	if( id[i]<'a' || id[i]>'z' ) return 0;
	return 1;
}

// �����ļ�·��
int make_dir(string type, string id)
{
	if ( !stringp(type) || !stringp(id) ) return 0;
	mkdir(DATA_DIR+type+"/"+id[0..0]);
	return 1;
}

// ���Ŀ���ļ��Ƿ����
int valid_dest(string id)
{
	if ( !stringp(id) ) return 0;
	if ( file_size(DATA_DIR+"login/"+id[0..0]+"/"+id+".o") == -1 ) return 1;
	return 0;
}

// ���Դ�ļ��Ƿ����
int valid_src(string arg)
{
	string type, id;

	if ( !arg || sscanf(arg, "%s %s", type, id) != 2 ) return 0;
	if ( file_size("/"+type+"/login/"+id[0..0]+"/"+id+".o") > 0 ) return 1;
	return 0;
}

int main(object me, string arg)
{
	string type, id1, id2, src, dest, file;

	if ( !arg || sscanf(arg, "%s %s %s", type, id1, id2) != 3 )
		return notify_fail("ָ���ʽ��getdata ���ݵ������� ԭ��id ת����id\n");
	if ( !check_legal_id(id2) ) 
		return notify_fail("ת����idֻ����Ӣ����ĸ��\n");
	if ( !valid_src(type+" "+id1) )
		return notify_fail("û�����id�ı��ݵ�����\n");
	if ( !valid_dest(id2) )
		return notify_fail("Ŀ��id�����Ѵ��ڡ�����ת����\n");
	if ( find_player(id2) )
		return notify_fail("Ŀ��id�Ѵ��ڡ�����ת����\n");
	make_dir("user", id2);
	src = "/"+type+"/user/"+id1[0..0]+"/"+id1+".o";
	dest = DATA_DIR+"user/"+id2[0..0]+"/"+id2+".o";
	if ( rename(src, dest) )
		return notify_fail("���ﵵ���ļ��ƶ�ʧ�ܡ�\n");
	if ( !(file = read_file(dest)) )
		return notify_fail("���ﵵ���ļ���ȡʧ�ܡ�\n");
	file = replace_string(file, "\""+"id"+"\""+":"+"\""+id1, "\""+"id"+"\""+":"+"\""+id2);
	if ( !write_file(dest, file, 1) )
		return notify_fail("���ﵵ���ļ�д��ʧ�ܡ�\n");
	make_dir("login", id2);
	src = "/"+type+"/login/"+id1[0..0]+"/"+id1+".o";
	dest = DATA_DIR+"login/"+id2[0..0]+"/"+id2+".o";
	if ( rename(src, dest) )
		return notify_fail("��¼����ת��ʧ�ܡ�\n");
	if ( !(file = read_file(dest)) )
		return notify_fail("��¼�����ļ���ȡʧ�ܡ�\n");
	file = replace_string(file, "\""+"id"+"\""+":"+"\""+id1, "\""+"id"+"\""+":"+"\""+id2);
	if ( !write_file(dest, file, 1) )
		return notify_fail("��¼�����ļ�д��ʧ�ܡ�\n");

	write("����ת���ɹ��������ڿ���ʹ��"+id2+"��¼ԭ��"+id1+"�������ˡ�\n");
	log_file("cmds/getdata.log", sprintf("ת�� %s to %s\n", id1, id2));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : ָ���ʽ��getdata ���ݵ������� ԭ��id ת����id

ԭ����ͨ��վ���ݵ������ڣ�2007-12-6
��ͨ��վ���ݵ������ڣ�2007-12-13
HELP);
    return 1;
}