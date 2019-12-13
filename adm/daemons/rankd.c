// rankd.c
// 1996-02-15 dts ranking related to "shen"
//modified by macrohard@sdyx

string query_rank(object ob)
{
	mapping fam;
	int shen,exp;
	int budd;
	string set_title,menpai;

	exp = (int)ob->query("xyzx_sys/level");
	menpai=ob->query("family/family_name");
	shen = ob->query("shen");
	if(wizardp(ob)&&ob->query("env/own_rank"))
		return NOR"��"HIW+ob->query("env/own_rank")+NOR" ��";
	if( ob->is_ghost() )
		return NOR "��"HIB"�»�Ұ��"NOR"��";


	if ( (fam = ob->query("family")) && fam["family_name"] == "������" )
		budd = ob->query_skill("buddhism",1);

	if( (int) ob->query("fight_rank") == 1 )
	{
		if( strlen((string) ob->query("env/my_title")) ==2)
		{
			set_title = ob->query("env/my_title");
			return NOR"��"HIW"���µ�һ"+set_title+NOR" ��";
		}
		else
			return NOR"��"HIW"���µ�һ"NOR"��";
	}
	if( (int) ob->query("fight_rank") == 2 )
	{
		if( strlen((string) ob->query("env/my_title")) ==2)
		{
			set_title = ob->query("env/my_title");
			return NOR"��"HIR"���µڶ�"+set_title+NOR" ��";
		}
		else
			return NOR"��"HIR"���µڶ�"NOR"��";
	}
	if( (int) ob->query("fight_rank") == 3)
	{
		if( strlen((string) ob->query("env/my_title")) ==2)
		{
			set_title = ob->query("env/title_race");
			return NOR"��"HIG"���µ���"+ set_title +NOR" ��";
		}
		else
			return NOR"��"HIG"���µ���"NOR"��";
	}

	switch(ob->query("gender"))
	{
	case "Ů��":
		switch(wizhood(ob))
		{
		case "(admin)":
			return NOR "��"HIW"������Ů"NOR"��";
		case "(arch)":
			return NOR "��"MAG"������Ů"NOR"��";
		case "(wizard)":
			return NOR "��"HIC"������Ů"NOR"��";
		case "(apprentice)":
			return NOR "��"GRN"������Ů"NOR"��";
		case "(immortal)":
			return NOR "��"CYN"�λþ���"NOR"��";
		default:
			if (exp >= 20000)
				return  "��"HIR"Ϧ������"NOR"��";
			else if (exp >= 10000)
				return  "��"HIM"Ϧ���콾"NOR"��";
			else if (exp >= 5000)
				return  "��"HIR"Ϧ��ս��"NOR"��";
			else if (exp >= 1000)
				return  "��"BLU"�ڰ�֮һ"NOR"��";
			else if( ((int)ob->query("PKS") > 30) )
				return  "��"HIB"��ѪŮħ"NOR"��";
			else if (shen >= 1000000)
				return  "��"HIC"һ���콿"NOR"��";
			else if (shen >= 500000)
				return  "��"HIM"����Ů��"NOR"��";
			else if (shen >= 100000)
				return  "��"HIY"����Ӣ��"NOR"��";
			else if (shen >= 50000)
				return  "��"YEL"Ů�к���"NOR"��";
			else if (shen >= 10000)
				return  "��"HIC"Ů �� ��"NOR"��";
			else if (shen >= 5000)
				return  "��"HIG"�糾��Ů"NOR"��";
			else if (shen <= -1000000)
				return  "��"HIW"��ѪŮħ"NOR"��";
			else if (shen <= -500000)
				return  "��"HIR"����ħŮ"NOR"��";
			else if (shen <= -100000)
				return  "��"HIM"��ѪħŮ"NOR"��";
			else if (shen <= -50000)
				return  "��"GRN"������Ů"NOR"��";
			else if (shen <= -10000)
				return  "��"RED"Ů �� ħ"NOR"��" ;
			else if (shen <= -5000)
				return  "��"CYN"������Ů"NOR"��" ;
			else if( (int)ob->query("thief") > 10 )
				return  "��"HIW"Ů �� ��"NOR"��";
			else
				switch(menpai)
				{
				case "�䵱��":
					if (exp > 1000 )
					{
						if (shen >= 0)
							return NOR "��"HIR"Ů �� ʦ"NOR"��";
						else
							return NOR "��"HIR"Ůħ��ʦ"NOR"��";
					}
					if (exp > 800 )
						return NOR "��"RED"Ů �� ʦ"NOR"��";
					if (exp > 500 )
						return NOR "��"GRN"Ů �� ��"NOR"��";
					if (exp > 300 )
						return NOR "��"YEL"Ů��ʦ"NOR"��";
					if (exp > 200 )
						return NOR "��"GRN"Ů �� ʦ"NOR"��";
					if (exp > 100 )
						return NOR "��"CYN"Ů �� ��"NOR"��";
					if (exp > 50)
						return NOR "��"MAG"Ů �� ��"NOR"��";
					if (exp > 10 )
						return NOR "��"HIB"Ů �� ��"NOR"��";
					if (exp > 1)
						return NOR "��"HIB" Ů  �� "NOR"��";
					return "��Ů �� �ڡ�";
				case "��ɽ��":
					if ( exp > 1000 )
					{
						if (shen >= 0 )
							return NOR "��"HIW"����һ��"NOR"��";
						else
							return NOR "��"HIW"��ħһ��"NOR"��";
					}
					if (exp > 800 )
					{
						if (shen >= 0)
							return NOR "��"HIR"Ů �� ʥ"NOR"��";
						else
							return NOR "��"HIM"Ů �� ħ"NOR"��";
					}
					if (exp > 500 )
					{
						if (shen >= 0)
							return NOR "��"GRN"Ů �� ��"NOR"��";
						else
							return NOR "��"GRN"Ů а ��"NOR"��";
					}
					if (exp > 300 )
						return NOR "��"YEL"Ů �� ��"NOR"��";
					if (exp > 200)
						return NOR "��"CYN"Ů �� ��"NOR"��";
					if (exp > 100 )
						return NOR "��"CYN"Ů�󽣿�"NOR"��";
					if (exp > 50)
						return NOR "��"RED"Ů �� ��"NOR"��";
					if (exp > 10 )
						return NOR "��"MAG"Ů��ʿ"NOR"��";
					if (exp > 1)
						return NOR "��"MAG" ��  ʿ "NOR"��";
					return "��Ů �� ͯ��";

				case "ؤ��":
					if (exp > 1000 )
						return NOR "��"HIR"Ů������"NOR"��" NOR;
					if (exp > 800)
						return NOR "��"HIM"Ů����"NOR"��" NOR;
					if (exp > 500 )
						return NOR "��"HIM"Ů �� ��"NOR"��" NOR;
					if (exp > 300)
						return NOR "��"YEL"Ů����ʹ"NOR"��" NOR;
					if (exp > 200 )
						return NOR "��"YEL"Ůִ��ʹ"NOR"��" NOR;
					if (exp > 100 )
						return NOR "��"RED"Ů �� ؤ"NOR"��" NOR;
					if (exp > 50 )
						return NOR "��"RED"ŮС��ؤ"NOR"��" NOR;
					if (exp > 10 )
						return HIW "��"GRN"Ů �� ؤ"NOR"��" NOR;
					if (exp > 1)
						return NOR "��"MAG"ŮС��ؤ"NOR"��" NOR;
					return "�� �� �� �� ��" ;

				case "������":
				case "�һ���":
					if (exp > 1000 )
					{
						if (shen >= 0)
							return NOR "��"HIR"ħ �� ��"NOR"��";
						else
							return NOR "��"HIR" ��  ħ "NOR"��";
					}
					if (exp > 800 )
						return NOR "��"HIM"������Ů"NOR"��";
					if (exp > 500 )
						return NOR "��"GRN"����Ů��"NOR"��";
					if (exp > 300 )
						return NOR "��"YEL"�� �� Ů"NOR"��";
					if (exp > 200 )
						return NOR "��"RED"Ů �� ��"NOR"��";
					if (exp > 100 )
						return NOR "��"MAG"Ů �� ��"NOR"��";
					if (exp > 50)
						return NOR "��"MAG" Ů  �� "NOR"��";
					if (exp > 10 )
						return NOR "��"CYN" Ů  �� "NOR"��";
					if (exp > 1 )
						return NOR "��"CYN"С Ů ��"NOR"��";
					return "���糾Ů�ӡ�"NOR ;

				case "����":
					if (exp > 1000 )
						return NOR "��"HIR"Ů������"NOR"��";
					if (exp > 800 )
						return NOR "��"HIM" ��  �� "NOR"��";
					if (exp > 500 )
						return NOR "��"GRN"Ů�ܻ���"NOR"��";
					if (exp > 300 )
						return NOR "��"YEL"Ů �� ��"NOR"��";
					if (exp > 200 )
						return NOR "��"YEL"Ů������"NOR"��";
					if (exp > 100)
						return NOR "��"CYN"Ů������"NOR"��";
					if (exp > 50)
						return NOR "��"CYN"Ů �� ��"NOR"��";
					if (exp > 10)
						return NOR "��"MAG"Ů������"NOR"��";
					if (exp > 1)
						return NOR "��"MAG"Ů �� ��"NOR"��";
					return "��  ��  ��  ��" ;
				default:
					switch(ob->query("class"))
					{
					case "bonze":
						return "�� Ů  �� ��";
					case "yishi":
						return "��Ů �� ʿ��";
					case "taoist":
						return "�� Ů  �� ��";
					case "bandit":
						return "��Ů �� ����";
					case "dancer":
						return "����ɫ�輧��";
					case "scholar":
						return "��ңң���ˡ�";
					case "officer":
						return "�� Ů  �� ��";
					case "fighter":
						return "���糾Ů�ӡ�";
					case "swordsman":
						return "���轣��Ů��";
					case "alchemist":
						return "��Ů �� ʿ��";
					case "shaman":
						return "��Ů �� ҽ��";
					case "beggar":
						return "��Ů�л��ӡ�";
					case "shiny":
					case "huanu":
						return "���ƻ�����ū��";
					case "yihuashinv":
						return "���ƻ�����Ů��";
					case "chuanren":
						return "���ƻ������ˡ�";
						return "������Ůʹ��";
					default:
						return NOR "��"MAG"ܷܷ��Ů"NOR"��";
					}
				}
		}
	default:
		switch(wizhood(ob))
		{
		case "(admin)":
			return NOR "��"HIR"����ܹ�"NOR"��" ;
		case "(arch)":
			return NOR "��"HIY"�˲�����"NOR"��" ;
		case "(wizard)":
			return NOR "��"HIC"��������"NOR"��" ;
		case "(apprentice)":
			return NOR "��"HIG"�칬����"NOR"��" ;
		case "(immortal)":
			return NOR "��"HIB"��ңɢ��"NOR"��" ;
		default:
			if (exp >= 20000 )
				return  "��"HIR"Ϧ������"NOR"��";
			else if (exp >= 10000 )
				return  "��"HIM"Ϧ���콾"NOR"��";
			else if (exp >= 5000 )
				return  "��"HIR"Ϧ��ս��"NOR"��";
			else if (exp >= 1000 )
				return  "��"BLU"�ڰ�֮һ"NOR"��";
			else if( ((int)ob->query("PKS") > 50) )
				return "��ɱ��ħ����";
			else if (shen >= 1000000)
				return  "��"HIG"����̩��"NOR"��" ;
			else if (shen >= 500000)
				return HIC "��"HIC"��������"NOR"��" ;
			else if (shen >= 100000)
				return HIC "��"HIC"��������"NOR"��" ;
			else if (shen >= 50000)
				return  "��"HIY"����һʱ"NOR"��";
			else if (shen >= 10000)
				return  "��"HIY"��������"NOR"��";
			else if (shen >= 5000)
				return  "��"HIG"��������"NOR"��";
			else if (shen >= 1000)
				return  "��"HIG"С������"NOR"��";
			else if (shen >= 500)
				return NOR"��"CYN"С������"NOR"��";
			else if (shen <= -1000000)
				return "��"HIW"�����Ϲ�"NOR"��" ;
			else if (shen <= -500000)
				return "��"HIR"����ħͷ"NOR"��";
			else if (shen <= -100000)
				return "��"RED"���һ��"NOR"��";
			else if (shen <= -50000)
				return "��"YEL"����Զ��"NOR"��";
			else if (shen <= -10000)
				return "��"YEL"С�ж���"NOR"��";
			else if (shen <= -500)
				return "��"HIB"����а��"NOR"��";
			else if( (int)ob->query("thief") > 10 )
				return NOR"��"YEL" ��  ͵ "NOR"��";
			else
				switch(menpai)
				{
				case "�䵱��":
					if (exp > 1000 )
					{
						if (shen >= 0 )
							return NOR "��"HIR" ��  ʦ "NOR"��";
						else
							return NOR "��"HIW"�� �� ʦ"NOR"��";
					}
					if (exp > 800 )
						return NOR "��"HIM" ��  ʦ "NOR"��";
					if (exp > 500 )
						return NOR "��"GRN" ��  �� "NOR"��";
					if (exp > 300 )
						return NOR "��"YEL"�� �� ʦ"NOR"��";
					if (exp > 200 )
						return NOR "��"YEL" ��  ʦ "NOR"��";
					if (exp > 100 )
						return NOR "��"CYN" ��  �� "NOR"��";
					if (exp > 50 )
						return NOR "��"CYN" ��  ʿ "NOR"��";
					if (exp > 10 )
						return NOR "��"HIB" ��  ʿ "NOR"��";
					if (exp > 1)
						return NOR "��"HIB"�� �� ͯ"NOR"��";
					return "�� ��  ͯ ��" ;

				case "��ɽ��":
					if (exp > 1000 )
					{
						if (shen >= 0 )
							return NOR "��"HIW"����һ��"NOR"��";
						else
							return NOR "��"HIW"��ħһ��"NOR"��";
					}
					if (exp > 800 )
					{
						if (shen >= 0)
							return NOR "�� "HIR"��  ʥ"NOR" ��";
						else
							return NOR "�� "HIM"��  ħ"NOR" ��";
					}
					if (exp > 500 )
					{
						if (shen >= 0)
							return NOR "�� "GRN"��  ��"NOR" ��";
						else
							return NOR "�� "GRN"а  ��"NOR" ��";
					}
					if (exp > 300 )
						return NOR "�� "YEL"��  ��"NOR" ��";
					if (exp > 200 )
						return NOR "�� "CYN"��  ��"NOR" ��";
					if (exp > 100 )
						return NOR "��"CYN"�� �� ��"NOR"��";
					if (exp > 50)
						return NOR "�� "RED"��  ��"NOR" ��";
					if (exp > 10)
						return NOR "��"MAG"�� �� ʿ"NOR"��";
					if (exp > 1)
						return NOR "��"MAG" ��  ʿ "NOR"��";
					return "�� ��  ͯ ��";

				case "ؤ��":
					if (exp > 1000 )
						return NOR "��"HIR"�� �� ��"NOR"��";
					if (exp > 800 )
						return NOR "��"HIW"ʮ������"NOR"��";
					if (exp > 500 )
						return NOR "��"HIM"�Ŵ�����"NOR"��";
					if (exp > 300 )
						return NOR "��"YEL"��������"NOR"��";
					if (exp > 200 )
						return NOR "��"YEL"ִ������"NOR"��";
					if (exp > 100 )
						return NOR "��"RED" ��  ؤ "NOR"��";
					if (exp > 50 )
						return NOR "��"CYN"С �� ؤ"NOR"��";
					if (exp > 10 )
						return NOR"��"CYN"  ��  ؤ "NOR"��";
					if (exp > 1 )
						return NOR "��"HIB"С �� ؤ"NOR"��";
					return "���� �� �ӡ�"NOR ;

				case "������":
				case "�һ���":
					if (exp > 1000 )
					{
						if (shen >= 0)
							return NOR "��"HIR"ħ �� ��"NOR"��";
						else
							return NOR "��"HIR" ��  ħ "NOR"��";
					}
					if (exp > 800 )
						return NOR "��"CYN"�������"NOR"��";
					if (exp > 500 )
						return NOR "��"GRN"��������"NOR"��";
					if (exp > 300 )
						return NOR "��"YEL"�� �� ��"NOR"��";
					if (exp > 200 )
						return NOR "��"YEL" ��  �� "NOR"��";
					if (exp > 100 )
						return NOR "��"GRN" ��  �� "NOR"��";
					if (exp > 50 )
						return NOR "��"GRN" ��  ʿ "NOR"��";
					if (exp > 10 )
						return NOR "��"CYN" ��  �� "NOR"��";
					if (exp > 1 )
						return NOR "��"HIC" ��  �� "NOR"��";
					return "���������"NOR ;

				case "����":
					if (exp > 1000 )
						return NOR "��"HIR"�� �� ��"NOR"��";
					if (exp > 800 )
						return NOR "��"HIM" ��  �� "NOR"��";
					if (exp > 500 )
						return NOR "��"GRN"�� �� ��"NOR"��";
					if (exp > 300 )
						return NOR "��"YEL" ��  �� "NOR"��";
					if (exp > 200 )
						return NOR "��"YEL"�� �� ��"NOR"��";
					if (exp > 100 )
						return NOR "��"CYN"�� �� ��"NOR"��";
					if (exp > 50 )
						return NOR "��"CYN" ��  �� "NOR"��";
					if (exp > 10 )
						return NOR "��"GRN"�� �� ��"NOR"��";
					if (exp > 1 )
						return NOR "��"HIB" ��  �� "NOR"��";
					return "�� ��  �� ��" ;

				default:
					switch(ob->query("class"))
					{
					case "bonze":
						if (budd >= 150)
							return  "��"HIY" ��  ��"NOR" ��";
						else if (budd >= 120)
							return  "��"HIY" ʥ  ɮ"NOR" ��" ;
						else if (budd >= 90)
							return  "��"HIY" ��  ��"NOR" ��" ;
						else if (budd >= 60)
							return  "��"YEL" ��  ��"NOR" ��" ;
						else if (budd >= 40)
							return "�� "YEL"��  ʦ"NOR" ��" ;
						else if (budd >= 30)
							return  "��"YEL" ��  ��"NOR" ��" ;
						else
							return "�� ɮ  �� ��";
					case "yishi":
						return "��������ʿ��";
					case "taoist":
						return "�����ε�ʿ��";
					case "bandit":
						return "�����Ͼ��ӡ�";
					case "scholar":
						return "��������ӡ�";
					case "officer":
						return "����    �ˡ�";
					case "swordsman":
						return "�����齣�͡�";
					case "alchemist":
						return "�� ��  ʿ ��";
					case "shaman":
						return "�� ��  ҽ ��";
					case "beggar":
						return "����л��ӡ�";
					case "shiny":
						return "������ʹ�ߡ�";
					default:
						return "������ƽ��";
					}
				}
		}
	}
}
string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender"))
	{
	case "Ů��":
		switch(ob->query("class"))
		{
		case "bonze":
			if( age < 18 ) return "Сʦ̫";
			else return "ʦ̫";
			break;
		case "taoist":
			if( age < 18 ) return "С�ɹ�";
			else return "�ɹ�";
			break;
		default:
			if( age < 18 ) return "С����";
			else if( age < 50 ) return "����";
			else return "����";
			break;
		}
	case "����":
	default:
		switch(ob->query("class"))
		{
		case "bonze":
			if( age < 18 ) return "Сʦ��";
			else return "��ʦ";
			break;
		case "taoist":
			if( age < 18 ) return "����";
			else return "����";
			break;
		case "fighter":
		case "swordsman":
			if( age < 18 ) return "С�ϵ�";
			else if( age < 50 ) return "׳ʿ";
			else return "��ǰ��";
			break;
		default:
			if( age < 20 ) return "С�ֵ�";
			else if( age < 50 ) return "׳ʿ";
			else return "��ү��";
			break;
		}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender"))
	{
	case "Ů��":
		switch(ob->query("class"))
		{
		case "bonze":
			return "����";
			break;
		case "taoist":
			return "��Ů";
			break;
		default:
			if( age < 30 ) return "С����";
			else return "����̫��";
			break;
		}
	case "����":
	default:
		switch(ob->query("class"))
		{
		case "bonze":
			if( age < 50 ) return "��ͺ¿";
			else return "��ͺ¿";
			break;
		case "taoist":
			return "��ţ����";
			break;
		default:
			if( age < 20 ) return "С���˵�";
			if( age < 50 ) return "����";
			else return "��ƥ��";
			break;
		}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender"))
	{
	case "Ů��":
		switch(ob->query("class"))
		{
		case "bonze":
			if( age < 50 ) return "ƶ��";
			else return "����";
			break;
		default:
			if( age < 30 ) return "СŮ��";
			else return "���";
			break;
		}
	case "����":
	default:
		switch(ob->query("class"))
		{
		case "bonze":
			if( age < 50 ) return "ƶɮ";
			else return "����";
			break;
		case "taoist":
			return "ƶ��";
			break;
		default:
			if( age < 50 ) return "����";
			else return "��ͷ��";
			break;
		}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender"))
	{
	case "Ů��":
		switch(ob->query("class"))
		{
		case "bonze":
			if( age < 50 ) return "ƶ��";
			else return "����";
			break;
		default:
			if( age < 30 ) return "������";
			else return "����";
			break;
		}
	case "����":
	default:
		switch(ob->query("class"))
		{
		case "bonze":
			if( age < 50 ) return "�������";
			else return "�Ϻ�����";
			break;
		case "taoist":
			return "��ɽ��";
			break;
		default:
			if( age < 50 ) return "��ү��";
			else return "����";
			break;
		}
	}
}

string query_close(object ob, int age, string rgender)
{
	int a1, a2;
	string gender;
	if (objectp(ob) )
	{
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( !rgender )
		gender = ob->query("gender");
	else    gender = rgender;

	switch ( gender )
	{
	case "Ů��" :
		if (a1 > a2)
			return "����";
		else
			return "���";
		break;
	default :
		if (a1 > a2)
			return "�ܵ�";
		else
			return "���";
	}
}

string query_self_close(object ob, int age)
{
	int a1, a2;
	string gender;
	if( objectp(ob) )
	{
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( age )
		gender = ob->query("gender");
	else
		gender = this_player()->query("gender");

	switch (gender)
	{

	case "Ů��" :
		if (a1 > a2)
			return "�����";
		else
			return "С����";
		break;
	default :
		if (a1 > a2)
			return "������";
		else
			return "С����";
	}
}

varargs string new_short(object ob)
{
	string icon = "", str;

	if ( !objectp(ob) )
	{
		CHANNEL_D->do_channel(this_player(),"chat","object��������");
		return "";
	}
	if ( !ob->query_temp("apply/id") && !ob->query_temp("apply/name") && !ob->query_temp("apply/short"))
		str = ob->query("name") + "(" +ob->query("id") + ")";
	else
		str = ob->query_temp("apply/name")[0] + "(" +ob->query_temp("apply/id")[0] + ")";


	//-Ĭ��OBJECT��ͼ��--------------------------------------------------------------
	icon="";
	//������Ʒ���ж�
	if(ob->query("icon"))
	{
		icon=ob->query("icon");
	}
	else
	{
		if(living(ob)) icon= "00002";   //Ĭ������Ϊ00002
		else icon ="00001";             //Ĭ����ƷΪ00001


	}
	return str + icon;

	return str + icon;
}

varargs string new_name(object ob)
{
	string icon="", str;

	if ( !objectp(ob) )
	{
		CHANNEL_D->do_channel(this_player(),"chat","object��������");
		return "";
	}

	if ( ob->query_condition("killer") )
		str = "$";
	else if ( ob->query_temp("netdead") )
		str = "#";
	else if ( interactive(ob) && query_idle(ob) > 300 )
		str = "*";
	else if ( ob->query("lixian/biguan") )
		str = "@";
	else if ( !ob->query("xieyi/zmud") )
		str = "T";
	else
		str = " ";

	if ( ob->query("gender") == "Ů��" )
		str += "[Ů]";
	else if ( ob->query("gender") == "����" )
		str += "[��]";
	else
		str += "[��]";

	str += ob->query("name") + "(" +ob->query("id") + ")";

	//-Ĭ��OBJECT��ͼ��--------------------------------------------------------------
	icon="";
	//������Ʒ���ж�
	if(ob->query("icon"))
	{
		icon=ob->query("icon");
	}
	else
	{
		if(living(ob)) icon= "00002";   //Ĭ������Ϊ00002
		else icon ="00001";             //Ĭ����ƷΪ00001


	}

	return str + icon;
}