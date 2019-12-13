//Ǳ������

#define MAX_CUN_QIANNENG 50000000

#include <dbase.h>
#include <ansi.h>

//����Ǳ��
int cun_qn(string arg)
{
	object ob;
	int temp_qn, my_qn, qn;

	ob = this_player();
	my_qn = ob->query("potential");

	if ( ob->query("temp_svqn") )
		temp_qn = ob->query("temp_svqn");
	else temp_qn = 0;

	if ( !ob || !living(this_object()) )
		return 0;

	if( !arg )
        return notify_fail("��Ҫ������ٵ�Ǳ�ܡ�\n");

	if ( sscanf(arg, "%d", qn) != 1 )
		return notify_fail("��Ҫ������ٵ�Ǳ�ܡ�\n");

	if ( !qn )
		return notify_fail("��Ҫ������ٵ�Ǳ�ܡ�\n");

	if ( qn < 1 || qn > MAX_CUN_QIANNENG )
		 return notify_fail("��ÿ��ֻ�ܴ�"HIY" 1��5000�� "NOR"��Ǳ�ܡ�\n");

	if ( qn > my_qn )
		return notify_fail("��û����ô��Ǳ�ܡ�\n");

	if ( qn + temp_qn > MAX_CUN_QIANNENG )
		return notify_fail("���Ѵ��� "HIY + temp_qn + NOR" ��Ǳ�ܣ����ܴ� "HIG + (MAX_CUN_QIANNENG - temp_qn) + NOR"��Ǳ�ܡ�\n");

	ob->add("potential",-qn);
	ob->add("temp_svqn",qn);
	
	if ( temp_qn > MAX_CUN_QIANNENG)
		ob->set("temp_svqn",MAX_CUN_QIANNENG);

	ob->save();
	tell_object(ob, "������ " + qn + " ��Ǳ�ܣ���һ����Ǳ�����д��� " + (temp_qn+qn) + " ��Ǳ�ܡ�\n");
	return 1;
}

//ȡ��Ǳ��
int qu_qn(string arg)
{
	object ob;
	int temp_qn, qn;

	ob = this_player();

	if ( ob->query("temp_svqn") )
		temp_qn = ob->query("temp_svqn");
	else temp_qn = 0;

	if ( !ob || !living(this_object()) )
		return 0;

	if( !arg )
        return notify_fail("��Ҫȡ�����ٵ�Ǳ�ܡ�\n");
	
	if ( sscanf(arg, "%d", qn) != 1 )
		return notify_fail("��Ҫȡ�����ٵ�Ǳ�ܡ�\n");

	if ( !qn )
		 return notify_fail("��Ҫȡ�����ٵ�Ǳ�ܡ�\n");

	if ( qn < 1 || qn > MAX_CUN_QIANNENG )
		return notify_fail("��ÿ��ֻ��ȡ��"HIY" 1��500�� "NOR"��Ǳ�ܡ�\n");

	if ( qn > temp_qn )
		return notify_fail("���Ǳ��������û����ô��Ǳ�ܡ�\n");

	ob->add("temp_svqn",-qn);
	ob->add("potential", qn, 1);
	tell_object(ob, "���Ǳ������ȡ���� " + qn + " ��Ǳ�ܣ�����Ǳ�����л��� " + (temp_qn-qn) + " ��Ǳ�ܡ�\n");
	ob->save();
	return 1;
}

//��ѯ���е�Ǳ��
int cha_qn(string arg)
{
	object *who, ob;
	int temp_qn, i;
	string temp;

	ob = this_player();

	if ( ob->query("temp_svqn") )
		temp_qn = ob->query("temp_svqn");
	else temp_qn = 0;

	if ( !ob || !living(this_object()) )
		return 0;
	
	tell_object(ob, this_object()->name(1)+"����������ĸ����㣺���Ѿ����� " + temp_qn + " ��Ǳ������\n");

	if ( wizardp(ob) )
	{
		temp = HIY"�������Ǳ������״����ѯ:\n" + 
			HIC"�����(ID)                    ����Ǳ��\n";
		who = users();
		for (i=0; i<sizeof(who); i++)
		{
			temp += sprintf(HIW"%-30s"HIY"%-9d\n"NOR, who[i]->name(1)+"("+who[i]->query("id")+")",who[i]->query("temp_svqn"));
		}
		ob->start_more(temp);
	}

	return 1;
}