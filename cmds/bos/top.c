
#include <ansi.h>

inherit F_CLEAN_UP;

int top_list(object ob1,object ob2);
int get_score(object ob);

int main(object me, string arg)
{	
	object *list, *ob;
	string msg;
	int i, num, my_n;
	
	ob = filter_array(children(USER_OB), (: environment($1) :));
	list = sort_array(ob, (: top_list :));
	my_n = 0;

	if ( sizeof(ob) < 10 )
		num = 10;
	else
		num = sizeof(ob);

	msg =  "\n\t\t\t\t\t\t\t\t\t\t"+BBLU+HIM"��"HIY"��Ϧ������֮������ӡ��"HIR"���߸������а�"HIM"��\n"NOR+HIW;
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
	
	if ( my_n == 0 )
		msg += NOR+YEL"��"HIM"��ϲ������Ŀǰ�����Ӱ��ף������µ�һ������Ҳ"NOR+YEL"��\n";
	else
		msg += NOR+YEL"��"HIG"���Ͱɣ���Ŀǰ��λ�� "HIY"��"+chinese_number(my_n+1)+"��"HIG" ������ "HIM"��"+chinese_number(my_n)+"��"HIG" �Ͳ���ô�����"NOR+YEL"��\n";

	msg += HIW"                                                   " + NATURE_D->game_time() + "�ǡ�\n"+NOR;
	
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
	score += ob->query("max_jingli") / 5;     	
	score += ((ob->query_str() + ob->query_int() + ob->query_dex() + ob->query_con() + ob->query("kar") + ob->query("per")) * 10);	
	score += ((int)ob->query("combat_exp") / 15000);
	score += (ob->query("xyzx_sys/level") * 1000);
	score += ((ob->query("xyzx_sys/jingzhun") + ob->query("xyzx_sys/lingxing") + ob->query("xyzx_sys/minjie") + ob->query("xyzx_sys/fanying") + ob->query("xyzx_sys/shuxingdian")) * 120);
	return score;	
}	

int help(object me)	
{	
write(@HELP	
ָ���ʽ : top 	
���ָ���������֪��������ҵ�״̬��ࡣ	
HELP	
);
return 1;	
}	
