// passwd.c

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	if( me != this_player(1) ) return 0;
	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
//           write("Ϊ�˰�ȫ���������������ԭ�������룺");	
write("Ϊ�˰�ȫ�������������������ݱ�ʶ��");    	
	input_to("get_old_pass", 1, ob);
	return 1;
}
void get_old_pass(string pass, object ob)
{
	string old_pass;
	write("\n");
//           old_pass = ob->query("password");	
old_pass = ob->query("biaoshiold");	
	//if( crypt(pass, old_pass)!=old_pass && md5crypt(pass, old_pass)!=old_pass ) {
    if( crypt(pass, old_pass)!=old_pass) {
//                   write("�������\n");	
write("��ݱ�ʶ��֤����\n������δ�趨��ݱ�ʶ������ָ��biaoshi���ã�\n");	
		return;
	}
	write("�������µ����룺");
	input_to("get_new_pass", 1, ob );
}
void get_new_pass(string pass, object ob)
{
        if(strsrch(pass,"//")!=-1) {
        write(HIR"\n�Ƿ������룬�����������룺");
        input_to("get_new_pass", 1, ob );
        return;
}
	write("\n��������һ���µ����룺");
	input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}
void confirm_new_pass(string pass, object ob, string new_pass)
{
	write("\n");
	if( crypt(pass, new_pass)!=new_pass ) {
		write("�Բ�������������벢����ͬ������ʹ��ԭ�������롣\n");
		return;
	}
	seteuid(getuid());
	if( !ob->set("passwordold", new_pass) ) {
		write("������ʧ�ܣ�\n");
		return;
	}
	ob->save();
	write("�������ɹ���\n");
}
int help(object me)
{
	write(@HELP
ָ���ʽ : passwd
 
���ָ������޸�����������롣
 
HELP
    );
    return 1;
}
 
