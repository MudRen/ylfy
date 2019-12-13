// score.c
// Hzgg@HXQXZ

#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
inherit F_UNANSI;

string value_string(int value1,int value);
string display_attr(int gift, int value);
string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
string none_string = "                                                  ";

string display_attr(int gift, int value);
string tribar_graph(int val, int eff, int max, string color);
int check_cc(string str);
string chinese_more_number(string exp);

void create()
{
	seteuid(ROOT_UID);
}

int main(object me, string arg)
{
	string line,my_str,my_dex,my_con,my_int,my_kar,my_per,skill_type,master,couple,killer,my_jingzhun,my_lingxing,my_minjie,my_fanying, level;
	mapping my,pmap;
	object ob, weapon;
	int balance;
	//string hy;
	mixed attack_points, dodge_points, parry_points;
	
	seteuid(getuid());
	
	if(!arg)
		ob = me;
	else if (wizardp(me))
	{
		ob = present(arg, environment(me));
		
		if (!ob)
			ob = find_player(arg);
		
		if (!ob)
			ob = find_living(arg);
		
		if (!ob)
			return notify_fail("��Ҫ�쿴˭��״̬��\n");
		
		if( !ob->is_character() || ob->is_corpse() )
			return notify_fail("�㲻����" + ob->query("name") + "��״̬���뿴�ɣ���\n");
	}
	else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
	
	balance = (int)ob->query("money")+(int)ob->query("more_money")*10000*10000;
	my = ob->query_entire_dbase();
	my_str = display_attr(my["str"], ob->query_str());
	my_con = display_attr(my["con"], ob->query_con());
	my_int = display_attr(my["int"], ob->query_int());
	my_dex = display_attr(my["dex"], ob->query_dex());
	my_kar = display_attr(my["kar"], ob->query_kar());
	my_per = display_attr(my["per"], ob->query_per());
	
	if (!ob->query("xyzx_sys/jingzhun"))
		my_jingzhun = "-------";
	else
		my_jingzhun = display_attr(0, ob->query("xyzx_sys/jingzhun"));

	if (!ob->query("xyzx_sys/lingxing"))
		my_lingxing = "-------";
	else
		my_lingxing = display_attr(0, ob->query("xyzx_sys/lingxing"));

	if (!ob->query("xyzx_sys/minjie"))
		my_minjie = "-------";
	else
		my_minjie = display_attr(0, ob->query("xyzx_sys/minjie"));

	if (!ob->query("xyzx_sys/fanying"))
		my_fanying = "-------";
	else
		my_fanying = display_attr(0, ob->query("xyzx_sys/fanying"));

	killer = ob->query("kill/killer_die") ? " [" + ob->query("kill/killer_name") + "] ֮��":"�㻹û����ɱ��";
	pmap = me->query_skill_prepare();
	
	if( objectp(weapon = me->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else if ( sizeof(pmap) == 0)
		skill_type = "unarmed";
	else if ( sizeof(pmap) == 1)
		skill_type = (keys(pmap))[0];
	else if ( sizeof(pmap) == 2)
	{
		if ( (keys(pmap))[0] >= (keys(pmap))[1] )
			skill_type = (keys(pmap))[0];
		else
			skill_type = (keys(pmap))[1];
	}
	
	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DODGE);
	master = ob->query("family")?my["family"]["master_name"]:"Ŀǰ��û��" ;
	couple = mapp(my["couple"])?(my["couple"]["have_couple"]?my["couple"]["couple_name"]:"Ŀǰ��û��"):"Ŀǰ��û��";
	
	line = YEL"\n����������������������������������"NOR;
	line += YEL"\n�ǩ���������"+HIC"�����˵�����"NOR+YEL"���������贈����������������������������������\n"NOR;
	line +=YEL"��                              �ǩ���������������"HIM"�츳"NOR+YEL"����������������\n"NOR;
	line += sprintf(YEL"%s"HIC"%s"BRED"%-7s"NOR+HIC"%s"BRED"%-7s"NOR+HIC"%s\n"NOR,"�ǩ�������������������������������"," ������[",my_str,"]   ���ԣ�[",my_int,"]"NOR);
	line += sprintf(YEL"��"HIW"��������:  "HIC"%-19s"NOR""YEL"��%s"BRED"%-7s"NOR"%s"BRED"%-7s"NOR"%s\n"NOR,ob->name(), HIC" ���ǣ�["HIY,my_con,HIC"]   ����["HIY,my_dex,HIC"] "NOR);
	line += sprintf(YEL"%s"HIC"%s"BRED"%-7s"NOR+HIC"%s"BRED"%-7s"NOR+HIC"%s\n"NOR,"�ǩ�������������������������������"," ��Ե��[",my_kar,"]   ��ò��[",my_per,"]");
	line += sprintf(YEL"��"HIW"Ӣ������:  "HIY"%-19s"NOR""YEL"��%s"BRED"%-7s"NOR"%s"BRED"%-7s"NOR"%s\n"NOR,ob->query("id"), HIC" ��׼��["HIY,my_jingzhun,HIC"]   ���ԣ�["HIY,my_lingxing,HIC"] "NOR);
	line += sprintf("%s%s"BRED"%-7s"NOR"%s"BRED"%-7s"NOR"%s\n"NOR,YEL"�ǩ�������������������������������", HIC" ���ݣ�["HIY,my_minjie,HIC"]   ��Ӧ��["HIY,my_fanying,HIC"] "NOR);
	line +=YEL"�ǩ������������������������������贈����������������������������������\n"NOR;

	if ( strlen(level = chinese_number(ob->query("xyzx_sys/level"))) > 12 )
		level = sprintf("%d", ob->query("xyzx_sys/level"));

	line += sprintf("%s"HIW"%-12s"HIY" ��"NOR""YEL"    ��"HIW" ��  �� :"HIM"%12d"HIW"/"HIG"%12d"NOR""YEL"��\n",YEL"��"HIW+" ��  �� :  ",level,ob->query("xyzx_sys/levup_exp"),ob->get_levelup_exp());
	line +=YEL"�ǩ������������������������������贈����������������������������������\n"NOR;
	line += sprintf(YEL"��"HIW" ���Ե� :  "HIY"%-19s"NOR""YEL"��"HIW" ͷ  �� : "NOR"%s\n"NOR,sprintf("%-5d",ob->query("xyzx_sys/shuxingdian")), RANK_D->query_rank(ob));
	line +=YEL"�ǩ������������������������������ߩ�����������������������������������\n"NOR;
	
	if( ob->query("title") )
	{
		if( ob->query("degree") )
		{
			line += sprintf("%s%-15s\n"NOR,YEL"�� "HIW"��  ν :  ",ob->query("degree")+ob->query("title"));
		}
		else
		{
			line += sprintf("%s%-15s\n"NOR,YEL"��"HIW" ��  ν :  ",ob->query("title"));
		}
	}
	
	if( ob->query("nickname") )
	{
		line += sprintf("%s%-15s\n"NOR,YEL"��"HIW"��ı��:  ",ob->query("nickname"));
	}
	
	if (userp(ob))
		line += sprintf("%s""%-17s"NOR"%s""%-23s"NOR+YEL"��\n"NOR,YEL"��"HIW" ��  �� :  ",chinese_number(ob->query("age"))+"��",HIW"    ��    ��:  ", ob->query("gender"));
	else
		line += sprintf("%s""%-17s"NOR"%s""%-23s"NOR+YEL"��\n"NOR,YEL"��"HIW" ��  �� :  ",chinese_number(ob->query("age"))+"��",HIW"    ��    ��:  ", ob->query("gender"));
	
	line += sprintf("%s"HIC"%-55s"NOR""YEL"��\n"NOR,YEL"��"HIW"������� : ",CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60) ));
	line += sprintf("%s"HIY"%-55s"NOR""YEL"��\n"NOR,YEL"��"HIW"Ǯׯ��� : ",value_string(ob->query("more_money"),ob->query("money")));
	line += sprintf("%s"HIW"%-17s"NOR"%s"HIC"%-24s"NOR+YEL"��\n"NOR,YEL"��"HIW"�㹲ɱ�� : ",my["MKS"] + my["PKS"]+" ��",HIW"    ���ʦ��: ",master);
	line += sprintf("%s"HIY"%-17s"NOR"%s"HIY"%-24s"NOR+YEL"��\n"NOR,YEL"��"HIW"�㹲ɱ�� : ",my["PKS"]+" �����",HIW"    ���"+(ob->query("gender")=="����"?"����":"�Ϲ�")+": ",couple);
	line += sprintf("%s"HIR"%-17s"NOR"%s"HIR"%-18s"NOR+YEL"��\n"NOR,YEL"��"HIW"�㹲���� : ",ob->query("DIED")+ " ��",HIW"    ���������ɱ��: ",chinese_number(ob->query("PKD"))+" ��");
	line += sprintf("%s"HIR"%-17s"NOR"%s"HIR"%-22s"NOR+YEL"��\n"NOR,YEL"��"HIW"������ : ",ob->query("xyzx_sys/damage_me")?delete_all_ansi(ob->query("xyzx_sys/damage_me")):sprintf(HIW"%-15s","�������˺���"),HIW"    ���ɱ����: ",ob->query("xyzx_sys/kill_me")?delete_all_ansi(ob->query("xyzx_sys/kill_me")):sprintf(HIW"%-20s","��δ����ɱ��"));
	
	line += sprintf("%s"HIC"%-21s"NOR"%s"HIY"%-24s"NOR""YEL"��\n"NOR,
		YEL"��"HIW"�����﹥ : ", ob->query_temp("apply/damage")+"",
		HIW"�����￹: ", ob->query_temp("apply/armor")+"");

	line += sprintf("%s"HIG"%-55s"NOR+YEL"��\n"NOR,YEL"��"HIW" ��  ��  : ",
		floatp(attack_points)?(attack_points+1+"")[0..<8]:(attack_points+1+""));
	line += sprintf("%s"HIW"%-55s"NOR+YEL"��\n"NOR,YEL"��"HIW" ��  ��  : ",
		floatp(dodge_points)?(dodge_points+1+"")[0..<8]:(dodge_points+1+""));
	line += sprintf("%s"HIY"%-55s"NOR+YEL"��\n"NOR,YEL"��"HIW" ��  ��  : ",
		floatp(parry_points)?(parry_points+1+"")[0..<8]:(parry_points+1+""));

	
	if (ob->query("xy_huiyuan"))
	{
		if ((int)ob->query("potential")/(int)ob->query_int() > 100)
		{
			if (ob->query("shen") ==0)
				line += sprintf("%s""%-24s"NOR"%s"HIY"%-24s"NOR""YEL"\n",YEL"��"HIW"   ��    :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+"("+">100%)");
			else if (ob->query("shen") >0)
				line += sprintf("%s"HIC"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"\n",YEL"��"HIW"  ����   :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+"("+">100%)");
			else
				line += sprintf("%s"HIR"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"\n",YEL"��"HIW"  ����   :",0-ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+"("+">100%)");
		}
		else
		{
			if (ob->query("shen") ==0)
				line += sprintf("%s""%-24s"NOR"%s"HIY"%-24s"NOR""YEL"��\n",YEL"��"HIW"   ��    :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+" ("+(int)ob->query("potential")/(int)ob->query_int()+"%)");
			else if (ob->query("shen") >0)
				line += sprintf("%s"HIC"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"��\n",YEL"��"HIW"  ����   :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+" ("+(int)ob->query("potential")/(int)ob->query_int()+"%)");
			else
				line += sprintf("%s"HIR"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"��\n",YEL"��"HIW"  ����   :",0-ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+" ("+(int)ob->query("potential")/(int)ob->query_int()+"%)");
		}
	}
	else
	{
		if ((int)ob->query("potential")*10/(int)ob->query_int() > 100)
		{
			if (ob->query("shen") ==0)
				line += sprintf("%s""%-24s"NOR"%s"HIY"%-24s"NOR""YEL"\n",YEL"��"HIW"   ��    :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+"("+">100%)");
			else if (ob->query("shen") >0)
				line += sprintf("%s"HIC"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"\n",YEL"��"HIW"  ����   :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+"("+">100%)");
			else
				line += sprintf("%s"HIR"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"\n",YEL"��"HIW"  ����   :",0-ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+"("+">100%)");
		}
		else
		{
			if (ob->query("shen") ==0)
				line += sprintf("%s""%-24s"NOR"%s"HIY"%-24s"NOR""YEL"��\n",YEL"��"HIW"   ��    :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+" ("+(int)ob->query("potential")*10/(int)ob->query_int()+"%)");
			else if (ob->query("shen") >0)
				line += sprintf("%s"HIC"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"��\n",YEL"��"HIW"  ����   :",ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+" ("+(int)ob->query("potential")*10/(int)ob->query_int()+"%)");
			else
				line += sprintf("%s"HIR"%-24s"NOR"%s"HIY"%-24s"NOR""YEL"��\n",YEL"��"HIW"  ����   :",0-ob->query("shen")+"",HIW"Ǳ  �� :",(int)ob->query("potential")+" ("+(int)ob->query("potential")*10/(int)ob->query_int()+"%)");
		}
	}
	
	line += sprintf("%s""%-11s"NOR"%s"HIC"%-13s"NOR"%s"HIM"%-14s"NOR""YEL"��\n",YEL"��"HIW"�������� :",ob->query("score")+"",HIW"�������� :",sprintf("%d", my["weiwang"]), HIW"����ֵ :",sprintf("%d", my["meili"]));
	//line += YEL"�ǩ�������������������������������������������������������������������\n"NOR;
	line += YEL"����������������������������������������������������������������������\n"NOR;
	line += sprintf(HIG" %s"HIG"�ڽ������Ѿ�����"WHT" "+BLINK+HIR"%s\n"NOR, ob==me?"��":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")));
	
	if ( ob->query_condition("killer") )
		line += sprintf(HIG" %s"HIG"���ٸ�ͨ����ʱ�仹�ࣺ"HIR"%s"HIW"��"HIR"%s\n"NOR, ob==me?"��":ob->name(1), FINGER_D->age_string(ob->query_condition("killer")*10), 
		FINGER_D->age_string(ob->query_condition("killer")*30) );
	if ( ob->query("biguan_is_online") > 0 )
		line += sprintf(HIG" %s"HIG"������������ʱ�仹�У�"HIY"%s\n"NOR, ob==me?"��":ob->name(1), FINGER_D->age_string( ob->query("biguan_is_online")*2));
	if ( ob->query("exp_jiacheng") > time() )
		line += sprintf(HIG" %s"HIG"�����˫������ʱ�仹�ࣺ"HIY"%s\n"NOR, ob==me?"��":ob->name(1), FINGER_D->age_string(ob->query("exp_jiacheng")-time()));

	// ��Ա����
	/*if ( stringp(hy = ob->query("xy_huiyuan")) )
	{
		if ( ob->query("xyhy_type") == 2 )
			line += sprintf(HIG" %s����Ч��Ա("HIY"�ƽ�"HIG")����Ϊ��"HIY"%s"NOR, ob==me?"��":ob->name(1), hy);
		else if ( ob->query("xyhy_type") == 1 )
			//line += HIG" ��Ч��Ա("HIW"����"HIG")���ޣ�"HIY+hy+NOR;
			line += sprintf(HIG" %s����Ч��Ա("HIW"����"HIG")����Ϊ��"HIW"%s"NOR, ob==me?"��":ob->name(1), hy);
		else
			//line += HIG" ��Ч��Ա("NOR"��ͨ"HIG")���ޣ�"HIY+hy+NOR;
			line += sprintf(HIG" %s����Ч��Ա("NOR"��ͨ"HIG")����Ϊ��"NOR"%s"NOR, ob==me?"��":ob->name(1), hy);
	}*/
	
	line+=sprintf("\n");
	
	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift )
		return sprintf( HIY "%5d" NOR, value );
	else if( value < gift )
		return sprintf( CYN "%5d" NOR, value );
	else
		return sprintf("%5d", value);
}

string tribar_graph(int val, int eff, int max, string color)
{
	if ( max < 1 ) max = 1;
	return color + bar_string[0..(val*25/max)*2-1] + ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + ((max > eff) ? none_string[(eff*25/max)*2..49] : "") +NOR;
}

int check_cc(string str)
{
	int i, nn_len;
	
	for (nn_len=0,i=0;i<strlen(str);i++)
	{
		if (str[i]==27)
		{
			for (;str[i]!=109;i++)
			{
				nn_len++;
			}
			nn_len++;
		}
	}
	return nn_len;
}

string value_string(int value1,int value)
{
	string str;
	
	if (value1)
	{
		str=((int)(value1/10000)?chinese_number(value1/10000)+"��":"") +chinese_number(value1%10000)+ "��";
		
		if( value < 1 ) return str+"���ƽ�";
		else if( value < 100 )
			return str +"���ƽ�"+ chinese_number(value) + "��Ǯ";
		else if( value < 10000 )
			return str +"���ƽ�"+chinese_number(value/100) + "������"+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
		else
			return str + chinese_number(value/10000) + "���ƽ�"+( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")+( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
	}
	else
	{
		if( value < 1 )
			return "";
		else if( value < 100 )
			return chinese_number(value) + "��Ǯ";
		else if( value < 10000 )
			return chinese_number(value/100) + "������"+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
		else
			return chinese_number(value/10000) + "���ƽ�"+( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")+( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
	}
}

string chinese_more_number(string exp)
{
	string msg;
	msg = "";
/*
	if ( count_gt(exp, 100000000) )
	{
		more = atoi(count_div(exp, 100000000));
		over = atoi(count_sub(exp, count_mul(more, 100000000)));
		msg += chinese_number(more);
		msg += "����";
		msg += chinese_number(over);
	}
	else
		msg += chinese_number(atoi(exp));
*/
	return msg;
}