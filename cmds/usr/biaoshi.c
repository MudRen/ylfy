// /cmds/usr/biaoshi.c
// 2003.7.24 lisa
// 1.00 �趨�����ʶ

inherit F_CLEAN_UP;
int main(object me)	
{
	object ob;
	if( me != this_player(1) ) return 0;
	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() )
        ob = ob->query_temp("link_ob");
	if(ob->query("biaoshiold"))
	{
		write("���Ѿ��趨����ݱ�ʶ�ˣ������ٴ��趨�ˡ�\n");
		return 1;
	}
	write("�����������ݱ�ʶ��");
	input_to("get_biaoshi", 1, ob);
	return 1;
}
void get_biaoshi(string biaoshi, object ob)
{
	write("\n");
        if(strsrch(biaoshi,"//")!=-1) {
        write(HIR"\n�Ƿ������룬������������ݱ�ʶ��"NOR);
        input_to("get_biaoshi", 1, ob);
        return;
}
        ob->set("biaoshiold", crypt(biaoshi,0) );
	write("��������һ��������ݱ�ʶ����ȷ����û�Ǵ�");
	input_to("confirm_biaoshi", 1, ob);
}
void confirm_biaoshi(string biaoshi,object ob)
{
	string old_biaoshi;
	write("\n");
	old_biaoshi=ob->query("biaoshiold");
	if( crypt(biaoshi, old_biaoshi)!=old_biaoshi )
	{
		write("�������������ݱ�ʶ����һ�����趨ʧ�ܡ�\n");
		ob->delete("biaoshiold");
		return;
	}
	write("������ݱ�ʶ�趨�ɹ���\n");
	ob->save();
	return;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : biaoshi
 
���ָ������趨����������ݱ�ʶ��
 
HELP
    );
    return 1;
}
 
