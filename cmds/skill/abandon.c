// /cmds/skill/abandon.c
// lisa 2003.7.24
// 2.0 ���Ʒ����书ǰ����������ݱ�ʶ

inherit F_CLEAN_UP;
int get_biaoshi(string biaoshi,object me,string arg);
int main(object me, string arg)
{
object ob;
if( me != this_player(1) ) return 0;
ob = me->query_temp("link_ob");
if( !ob ) return 0;
while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
	if( !arg || arg=="" ) return notify_fail("��Ҫ������һ��ܣ�\n");
	if (!(me->query_skill(arg,1) + me->query_skill_learn(arg)))
		return notify_fail("�㲢û��ѧ������ܡ�\n");
write("�����������ݱ�ʶ��");
input_to("get_biaoshi", 1,ob,arg);
return 1;
}
int get_biaoshi(string biaoshi,object ob,string arg)
{
object me=this_player();
string old_biaoshi;
write("\n");
old_biaoshi=ob->query("biaoshiold");
if( crypt(biaoshi, old_biaoshi)!=old_biaoshi) 
{
	write("��ݱ�ʶ����\n");
	return 0;
}
if( !me->delete_skill(arg) )
return notify_fail("��û��ѧ������ܡ�\n");
write("�������������ѧϰ" + to_chinese(arg) + "��\n");
me->reset_action();
return 1;
}
int help()
{
	write(@TEXT
ָ���ʽ��abandon <��������>
����һ������ѧ���ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�������
��������ɾ����������Ժ�Ҫ��������ӣ���ʼ����������ؿ��������
���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������
TEXT
	);
	return 1;
}
