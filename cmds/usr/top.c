
#include <ansi.h>
#include <liebiao.h>
inherit F_CLEAN_UP;

int top_list(object ob1,object ob2);
int get_score(object ob);

int main(object me, string arg)
{	
	object *list, *ob;
	string msg;
	int i, num, my_n;
	if ( arg == "no" )
	{
		if ( !me->query("no_xyzx_top") )
		{
			me->set("no_xyzx_top", 1);
			write(HIY"��������ٲμ��ۺ����У��Ժ����ۺ��������а��Ͻ����ٳ���������֡�"NOR);
			return 1;
		}
		else
		{
			write(HIY"�㲻������˳��ۺ����������˵ģ�"NOR);
			return 1;
		}
	}

	if ( arg == "yes" )
	{
		if ( me->query("no_xyzx_top") )
		{
			me->delete("no_xyzx_top");
			write(HIY"��������²μ��ۺ������ˡ�"NOR);
			return 1;
		}
		else
		{
			write(HIY"�㲢û���˳��ۺ��������С�"NOR);
			return 1;
		}
	}
	
	if ( wizardp(me) )
		ob = filter_array(children(USER_OB), (: environment($1) :));
	else
		ob = filter_array(children(USER_OB), (: environment($1) && !wizardp($1) && !$1->query("no_xyzx_top") :));
	list = sort_array(ob, (: top_list :));
	my_n = 0;

	if ( sizeof(ob) < 10 )
		num = 10;
	else
		num = sizeof(ob);

	msg =  "\n "HBRED"                     "+HIG"��"HIY"Ϧ������-һ����ʦ"HIG"��"HIC"���߸������а�";
	msg += "                  \n"NOR+HIW;
	msg += "�����������������ө������������������������������ө����������ө�������������\n";
	msg += "��     ����     ��         ��        ��         ��  ��  ��  ��  �ۺ�����  ��\n";
	msg += "�ĩ��������������ة������������������������������ة����������ة�������������\n";
	
	for ( i = 0; i < num; i++ )
	{
		if ( i >= sizeof(list)) 
			msg += HIW"����ʱ��ȱ��                                                              ��\n";
		else
		{
			if ( list[i] == me )
			{
				msg +=HIY;
				my_n = i;
			}
			else
				msg +=HIW;
		
			msg += sprintf("��  %-13s %-26s      %-10s   %10d ��\n"NOR,
				chinese_number(i+1),
				list[i]->query("name") + "(" + capitalize(list[i]->query("id")) + ")",
				list[i]->query("family")?list[i]->query("family/family_name"):"��ͨ����",
				get_score(list[i]));
		}
	}	
	
	msg += HIW+"����������������������������������������������������������������������������\n";
	
	if ( me->query("no_xyzx_top") )
		msg += NOR+YEL" ��"HIR"��Ŀǰ��û�вμ��ۺ����а������� "HIW"top yes"HIR" �������С�"NOR+YEL"��\n";
	else
	{
		if ( my_n == 0 )
			msg += NOR+YEL" ��"HIM"��ϲ������Ŀǰ�����Ӱ��ף������µ�һ������Ҳ"NOR+YEL"��\n";
		else
			msg += NOR+YEL" ��"HIG"���Ͱɣ���Ŀǰ��λ�� "HIY"��"+chinese_number(my_n+1)+"��"HIG" ������ "HIM"��"+chinese_number(my_n)+"��"HIG" �Ͳ���ô�����"NOR+YEL"��\n";
	}

	//msg += HIW"                                           " + NATURE_D->game_time() + "�ǡ�\n"+NOR;
	me->start_more(msg);
	return 1;
}

int top_list(object ob1, object ob2)
{
	int score1, score2;
	score1 = get_score(ob1);
	score2 = get_score(ob2);
	return score2 - score1;
}

int get_score(object ob)	
{
	int tlvl, i, score;
	string *ski;
	mapping skills;
	reset_eval_cost();

	tlvl = 0;
	score = 0;
	
	// û���κμ��ܣ������ۺ�����Ϊ 1
	if ( !sizeof(skills = ob->query_skills()) )
		score += 1;
	else
	{
		// �м��ܣ���ȡ����ƽ���ȼ�*15Ϊ��������
		ski  = keys(skills);
		for ( i = 0; i < sizeof(ski); i++ )
			tlvl += skills[ski[i]];
		
		tlvl = tlvl / sizeof(ski) * 15;
		score += tlvl;
	}
	
	score += ob->query("max_neili") / 10;
	score += ob->query("max_jingli") / 10;     	
	score += ((ob->query_str() + ob->query_int() + ob->query_dex() + ob->query_con() + ob->query("kar") + ob->query("per")) * 10);	
	score += ((int)ob->query("combat_exp") / 15000);
	score += (ob->query("xyzx_sys/level") * 1000);
	return score;	
}	

int help(object me)	
{	
write(@HELP	
ָ���ʽ : top 	
���ָ���������֪��������ҵ�״̬��ࡣ
�˳��ۺ��������У�top no
���²μ��ۺ����У�top yes
HELP	
);
return 1;	
}	
