int do_study(string arg)
{
	string *skill_name = ({
		"strike",          //�Կ��Ϻ�ӧ
		"sword",           //�⹳˪ѩ��
		"dodge",           //�����հ���
		"throwing",        //��������
		"pixie-jian",      //ʮ��ɱһ�� sword
		"qiankundanuoyi",//ǧ�ﲻ���� dodge
		"lingboweibu",     //���˷���ȥ dodge
		"qimen-wuxing",   //��������� dodge
		"unarmed",         //�й������� cuff or strike or unarmed
		"qimen-flee",      //�ѽ�ϥǰ�� sword
		"parry",           //������캥
		"blade",           //����Ȱ����
		"axe",              //������Ȼŵ force ��ʱ��count��
		"whip",            //������Ϊ�� cuff or strike or unarmed
		"staff",           //�ۻ����Ⱥ�   ³������
		"taoism",          //���������� cuff or strike or unarmed
		"hammer",          //���Իӽ� sword
		"buddhism",        //�������� force
		"hubo",            //ǧ���׳ʿ
		"xiaowuxiang",           //ب�մ����� force
		"checking",        //����������   ָ��
		"club",            //��������Ӣ   ��ü��
		"kuihua-xinfa",    //˭�������
		"taixuan-gong"     //����̫����
		});
		
		object me, where;
		int jing_cost, learn_pot, item, times, i, success=0;		
		
		me = this_player();
		
		if( !arg ) return notify_fail("��Ҫ����ʲôѽ��\n");
		
		if( sscanf(arg, "%s %d", arg, times)!=2)
			return notify_fail("ָ���ʽ��think wall <����>\n");
		
		if( ( arg != "wall" ) )
			return notify_fail("ָ���ʽ��think wall <����>\n");
		
		if (times < 1 || times > 20)
			return notify_fail("�������������һ�Σ�����Ƕ�ʮ�Ρ�\n");
		
		if ((int)me->query("xyzx_sys/level") < 100)
			return notify_fail("��ľ���̫��, û������ʯ�����ݡ�\n");
		
		if ((int)me->query_skill("literate",1) < 1)
                return notify_fail("�����˰�! ������ȥѧ���Ļ��ɡ�\n");
		
		jing_cost = 30 + random(me->query_int(1));
		if( me->query("jing") < jing_cost * times)
			return notify_fail("������̫���ˣ���������ô��Σ���Ϣһ��������ɡ�\n");
		
		where = environment(me);
		
		switch (file_name(where))
		{
			case "/d/xiakedao/shiroom01": item = 0; break;
			case "/d/xiakedao/shiroom02": item = 1; break;
			case "/d/xiakedao/shiroom03": item = 2; break;
			case "/d/xiakedao/shiroom04": item = 3; break;
			case "/d/xiakedao/shiroom05": item = 4; break;
			case "/d/xiakedao/shiroom06": item = 5; break;
			case "/d/xiakedao/shiroom07": item = 6; break;
			case "/d/xiakedao/shiroom08": item = 7; break;
			case "/d/xiakedao/shiroom09": item = 8; break;
			case "/d/xiakedao/shiroom10": item = 9; break;
			case "/d/xiakedao/shiroom11": item = 10; break;
			case "/d/xiakedao/shiroom12": item = 11; break;
			case "/d/xiakedao/shiroom13": item = 12; break;
			case "/d/xiakedao/shiroom14": item = 13; break;
			case "/d/xiakedao/shiroom15": item = 14; break;
			case "/d/xiakedao/shiroom16": item = 15; break;
			case "/d/xiakedao/shiroom17": item = 16; break;
			case "/d/xiakedao/shiroom18": item = 17; break;
			case "/d/xiakedao/shiroom19": item = 18; break;
			case "/d/xiakedao/shiroom20": item = 19; break;
			case "/d/xiakedao/shiroom21": item = 20; break;
			case "/d/xiakedao/shiroom22": item = 21; break;
			case "/d/xiakedao/shiroom23": item = 22; break;
			case "/d/xiakedao/shiroom24": item = 23; break;
			default: break;
		}
		
		message_vision("$N��������ʯ���ϵ�ͼ����ע�͡�\n",me);
		
		for (i = 1; i<=times; i++)
		{
			me->receive_damage("jing",jing_cost);
			
			// ���ǻ�����̫����Ҫ����͵ȼ�80
			if ( me->query_skill(skill_name[item],1) < 80 )
			{
				if(item != 23 && item != 18)
				{
					write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫����ˡ�\n");
					return 1;
				}
			}
			
			// ����10000Ϊ����
			if ( me->query_skill(skill_name[item],1) >= 20000 )
			{
				write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫ǳ���ˡ�\n");
				return 1;
			}
			
			if ( item == 4 || item == 22 )
			{
				if ( (string)me->query("gender") != "����" )
				{
					write("���Ǳ����Ǳ�а����ͼ�ף������񹦣������Թ���\n");
					return 1;
				}

				// ���Ʊ�а�ȼ�����
				if ( item == 4 && me->query_skill("pixie-jian", 1) >= 1000 )
				{
					write("��ı�а�����Ѿ��޷�������ˡ�\n");
					return 1;
				}
			}
			else
			{
				if( !SKILL_D(skill_name[item])->valid_learn(me) )
					return SKILL_D(skill_name[item])->valid_learn(me);
			}
			
			//if( (int)(me->query_skill(skill_name[item],1) * me->query_skill(skill_name[item],1) * 81 ) >= me->get_levelup_exp()/2*1.0*(me->query("xyzx_sys/level")+1) )
			if(me->query("xyzx_sys/level")*20 < me->query_skill(skill_name[item],1))
			{
				write("�����ʯ��ڤ˼������һ�ᣬ�����ջ�\n");
				return 1;
			}
			
			learn_pot = random(me->query("int"));
			
			if (learn_pot > 0)
			{
				// �����ķ�
				if( item == 22 )
				{
					me->improve_skill(skill_name[item], random((me->query_kar()/2 + me->query_int()/2)/150)+1, 1);
					me->add("qi", -learn_pot);
					success = 1;
				}
				else if( item == 4 || item == 5 ) // ��а���� | Ǭ����Ų��
				{
					me->improve_skill(skill_name[item], random((me->query_kar()/2 + me->query_int()/2)/100)+1, 1);
					me->add("qi", -learn_pot);
					success = 1;
				}
				else if( item == 23 || item == 19 ) // ̫���� | С����
				{
					if ( me->query("kar") >= 30 /*&& me->query_kar() >= 63 */)
					{
						me->improve_skill(skill_name[item], random((me->query_kar()/2 + me->query_int()/100)/20)+1, 1);
						me->add("qi", -learn_pot);
						success = 1;
					}
				}
				else if ( me->query_skill(skill_name[item], 1) > 1000 )
				{
					me->improve_skill(skill_name[item], random((me->query_kar()/2 + me->query_int()/2)/15)+1, 1);
					me->add("qi",-learn_pot);
					success=1;
				}
				else
				{
					me->improve_skill(skill_name[item], random((me->query_kar()/2 + me->query_int()/2)/10)+1, 1);
					me->add("qi",-learn_pot);
					success=1;
				}
			}
		}
		
		if (success == 1)
			write("�����ʯ��ڤ˼������"+chinese_number(times)+"�أ��ƺ���"+CHINESE_D->chinese(skill_name[item])+"��Щ�ĵá�\n");
		else
			write("�����ʯ��ڤ˼������һ�ᣬ���ǳɼ�̫��ƺ�ûɶ�ĵá�\n");
		success=0;
	
	return 1;
}
