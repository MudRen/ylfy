// checksb.c
// 2003.7.24 lisa
// 1.00 ����������
inherit F_CLEAN_UP;
int main(object me, string arg)
{
object ob;
if (!arg)   return notify_fail("��Ҫ���˭����ݱ�ʶ?\n");
ob=FINGER_D->acquire_login_ob(arg);
if(!objectp(ob))   return notify_fail("û����λ��ҡ�\n");	
//   if( me!=this_player(1) )        	
write("����������֤����ݱ�ʶ��");
input_to("get_biaoshi", 1, ob );
return 1;
}
private void get_biaoshi(string biaoshi, object ob)
{
string old_biaoshi;
write("\n");
old_biaoshi=ob->query("biaoshiold");
if( crypt(biaoshi, old_biaoshi)!=old_biaoshi ) {
write("��ݱ�ʶ����\n");
return;
}
write("��ݱ�ʶ��ȷ��\n");
}
int help(object me)
{
write(@HELP
ָ���ʽ : checksb <���id>

���ָ����Լ����ҵ���ݱ�ʶ��

HELP
);
return 1;
}
