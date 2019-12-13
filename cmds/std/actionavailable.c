//actionavailable.c
//�Ż�����ȫ�б�˵���ʹ�������򵥸��ʺ���������


#define TMA "\x19" //ASCII��25
#define TMB "\x1A" //ASCII��26
#define TMI(x) (TMA+x+TMB)

#include <ansi.h>

inherit F_CLEAN_UP;

#include <item_sx.h>

string wuse_name(string str);
int room_path(object, object, int);
int user_path(object, object, int);
int skill_path(object, string);

int main(object me, string arg)
{
	object ob, *inv, room;
	string id, *ids, *id_list, num, id1, id2, new_id;
	int win, i, m, v, k;

	m = 0;
	k = 0;

	if ( !stringp(arg) ) return 0;
	if ( me->query("xieyi/zmud")) return 0;
	if ( sscanf(arg, "%s,%d", id, win) != 2 ) return 0;

	if ( !sscanf(id, "%s %s", id1, id2) )
	{
		new_id = id; // �������⴦��ʱ�ģ������ id ���� new_id
		v = 0;
	}
	else
	{
		id_list = explode(id , " ");
		if ( !stringp(num = id_list[sizeof(id_list)-1]) ) return 0; // δ֪�����ͣ���ֱ���˳�

		if ( !(v = atoi(num)) ) new_id = id; // ���������⴦��ĸ�ʽ������Ϊ new_id ����ԭ���� id
		else new_id = replace_string(id, " "+v, ""); // �����⴦��ĸ�ʽ���������»����ȷ�� id(new_id)
	}
	// ���ǰѴ���ĳ����ʽ�������ָ����λ�õ������ʽ����
	if ( !v )
		v = 1;

	switch ( win )
	{
		// ͬ�����²˵�
		case 0 :
				// ��� me �Ƿ��л�����û����ֱ�ӷ���
				if ( !objectp(room = environment(me)) )
						return 1;
				// ͨ��������������� ob
				inv = all_inventory(room);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// ����������֤ ob ����ʵ id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						k++;
						if ( m == v )
						{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
						}
						else
							continue; // �粢����ָ����λ���ϣ������������һ��λ��
					}
					// ��֤αװ��� id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// �ҵ���αװ�˵� ob �� id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
							}
							else
								continue; // �粢����ָ����λ���ϣ������������һ��λ��
						}
					}
				}
				// û�ж��� ob ������ֻ�ܷ����û�һ���հ���Ϣ
				if ( !objectp(ob) )
					return 1;
				room_path(me, ob, k);
				break;

		case 1 :
				// ��� me �Ƿ���Ч���ڣ�û����ֱ�ӷ���
				if ( !objectp(me) )
						return 1;
				// ͨ��������������� ob
				inv = all_inventory(me);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// ����������֤ ob ����ʵ id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						k++;
						if ( m == v )
						{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
						}
						else
							continue; // �粢����ָ����λ���ϣ������������һ��λ��
					}
					// ��֤αװ��� id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// �ҵ���αװ�˵� ob �� id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
							}
							else
								continue; // �粢����ָ����λ���ϣ������������һ��λ��
						}
					}
				}
				// û�ж��� ob ������ֻ�ܷ����û�һ���հ���Ϣ
				if ( !objectp(ob) )
					return 1;
				user_path(me, ob, k);
				break;
		case 2:
			if ( !me->query_skill(new_id, 1) )
				return 1;
			skill_path(me, new_id);
			break;
	}
	return 1;
}

int room_path(object me, object ob, int v)
{
	mapping skills,meskills;
	object *inv;
	string *str, id, tmp, *goods, teamname, temp, arg;//temp arg������
	int i, my_skill, m;//m�������б�ʶ

	m = 0;

	if(stringp(tmp=ob->query_menu(me,0)))//��������ܽ��Ͳ˵�����ֱ�ӷ��ز˵�
	{
		write(tmp);
		return 1;
	}

	if ( v > 1 && !ob->query_temp("apply/id") )
		id = ob->query("id") + sprintf(" %d", v);
	else
		id = ob->query("id");

	tmp = TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem �۲�$U;look "+id);

	if ( !wizardp(me) && playerp(ob) && ob->query_temp("apply/id") )
	{
		tmp = TMI("mbegin "+ob->name(1)+";"+id);
		tmp += TMI("mitem �Է��ƺ��Ǿ������ݸİ�ģ��޷���������ʵ��;");
		tmp += TMI("mendd");
		tell_object(me, tmp);
		return 1;
	}

	if(living(ob))
	{
		if(interactive(ob))
		{
			tmp+=TMI("mitem ����$U...;tell "+id+" ...");
			tmp+=TMI("mitem ��$U����...;whisper "+id+" ...");

			if ( id == me->query_temp("reply") )
				tmp+=TMI("mitem �ش�$U...;reply ...");

			if ( !me->query("xieyi/zmud") )
				tmp+=TMI("mitem ��ѯ$U��װ��;arm "+id);
		}

		tmp+=(me->query_leader()==ob)?TMI("mitem ֹͣ����$U;follow none"):TMI("mitem ����$U;follow "+id);

		if(!environment(me)->query("no_fight"))
		{
			tmp+=TMI("mitem ��$U�д�;fight "+id);

			if ( (int)ob->query("age") > 17
				|| !playerp(ob)
				|| ob->query_condition("killer") )
				tmp+=TMI("mitem ����$U;hit "+id)+TMI("mitem ɱ��$U;kill "+id)+TMI("mitem ͵Ϯ$U;touxi "+id)+TMI("mitem ͵$U��...;steal ... from "+id);
		}

		if(ob->query("inquiry"))
		{
			str=keys(ob->query("inquiry"));
			for(i=0; i<sizeof(str); i++)
				tmp+=TMI("mitem ��$U��������"+str[i]+"����Ϣ;ask "+id+" about "+str[i]+"");
		}

		// ���ϵͳ
		if ( !stringp(teamname=me->query_temp("xyzx_team/name")) )
		{
			// �������
			if ( stringp(ob->query_temp("xyzx_team/name")) && ob->query_temp("xyzx_team/zhang") )
				tmp+=TMI("mitem ����$U�Ķ���;team jiaru "+id);
			// ��������
			tmp+=TMI("mitem ��������...;team found ...");
		}
		else
		{
			// �ӳ�
			if ( me->query_temp("xyzx_team/zhang") )
			{
				// �������
				tmp+=TMI("mitem ����...�������;team yaoqing ...");
				if ( !stringp(ob->query_temp("xyzx_team/name")) )
				{
					tmp+=TMI("mitem ����$U�������;team yaoqing "+id);
				}
				else if ( ob->query_temp("xyzx_team/name") == me->query_temp("xyzx_team/name") )
				{
					tmp+=TMI("mitem �Ѷӳ�ת�ø�$U;team rang "+id); // ת�öӳ�
					tmp+=TMI("mitem ��$U�߳�����;team out "+id); // ���˳���
				}
				tmp+=TMI("mitem �Ѷӳ�ת�ø�...;team rang ...");
				tmp+=TMI("mitem ��...�߳�����;team out ...");
				if ( TEAMD->get_allot_type(teamname)=="ƽ������" )
					tmp+=TMI("mitem ���Ķ������ģʽΪ���ȼ�����;team change level");
				else
					tmp+=TMI("mitem ���Ķ������ģʽΪ��ƽ������;team change average");
			}
			// �����Աͨ��ָ��
			tmp+=TMI("mitem �������;team out"); // �������
			tmp+=TMI("mitem �鿴������Ϣ;team"); // �鿴������Ϣ
			tmp+=TMI("mitem ���Ͷ���������Ϣ...;team talk ..."); // ��������
			// ������Ϣ����
			if ( me->query_temp("xyzx_team/block") )
				tmp+=TMI("mitem �������齱����Ϣ;team listen"); // �������齱����Ϣ
			else
				tmp+=TMI("mitem ���ζ��齱����Ϣ;team block"); // ���ζ��齱����Ϣ
		}

		//�������������ȫ�б�
		if ( inv = all_inventory(me) )
		{
			for (i=0; i<sizeof(inv); i++)
			{
				if ( base_name(ob) == "/clone/gem/zhang" && inv[i]->query("max_sockets")
					&& me->query_temp("paid/����ʦ") && inv[i]->query("sockets/max") < inv[i]->query("max_sockets") )
					tmp+=TMI("mitem ����"+wuse_name(inv[i]->short())+";show "+inv[i]->query("id"));

				//������ȫ�б�
				if ( !inv[i]->query("no_drop") || !inv[i]->query("no_give") )
				{
					if ( interactive(ob) || ob->id(inv[i]->query("target")) || function_exists("accept_object",ob) || (inv[i]->query("owner_id") && inv[i]->query("owner_id") == ob->query("id") && inv[i]->query("owner_name") == ob->query("name")) )
					{
						if ( inv[i]->query("money_id") )
						{
							tmp+=TMI("mitem �ó�..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +"��$U;give ... " + inv[i]->query("id") + " to " + id);
							tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "����$U;give " + inv[i]->query("id") + " to "+id );
						}
						else
							tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "��$U;give " + inv[i]->query("id") + " to "+id );
					}
				}

				//��ͨ��ʯ���
				if ( (ob->query("id") == "jin yinhua" || ob->query("id") == "jin juhua")
					&& inv[i]->query("zhubao_save") )
					tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "����鱦��;cun " + inv[i]->query("id"));

				//��������б�(���ۡ������䵱����)
				if ( !ob->query("no_diandang") && !ob->query("vendor_goods") && function_exists("do_value",ob) && function_exists("do_redeem",ob) && function_exists("do_pawn",ob) )
				{
					//����
					if ( inv[i]->query("value") && !inv[i]->query("money_id") && !inv[i]->query("shaolin") && !inv[i]->query("no_sell") && !inv[i]->query("no_drop") )
						tmp+=TMI("mitem ���" + wuse_name(inv[i]->short()) + "�ļ۸�;value " + inv[i]->query("id"));

					//���͵䵱
					if ( inv[i]->query("value") && !inv[i]->query("shaolin") && !inv[i]->query("no_drop") && !inv[i]->query("no_sell") && !inv[i]->query("money_id") )
					{
						if ( m == 0 )
						{
							temp = TMI("mitem ��" + wuse_name(inv[i]->short()) + ";sell " + inv[i]->query("id"));
							arg = TMI("mitem �䵱" + wuse_name(inv[i]->short()) + ";pawn " + inv[i]->query("id"));
						}
						else
						{
							temp += TMI("mitem ��" + wuse_name(inv[i]->short()) + ";sell " + inv[i]->query("id"));
							arg += TMI("mitem �䵱" + wuse_name(inv[i]->short()) + ";pawn " + inv[i]->query("id"));
						}

						m++;
					}
				}

				//Ǯׯ
				if ( function_exists("do_deposit",ob) && function_exists("do_withdraw",ob) && function_exists("do_convert",ob) )
				{
					//��Ǯ
					if ( inv[i]->query("money_id") )
						tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "���Ǯׯ;deposit all " + inv[i]->query("id"));
				}
			}

			if ( temp )
				tmp += temp;

			if ( arg )
				tmp += arg;
		}

		if(me->query("family/family_name") == "ؤ��" )
		{
			if ( me->query_skill("checking",1) >= 10 )
				tmp+=TMI("mitem ��̽...�ļ���;check ...");

			if(ob->query("family/family_name") != "ؤ��" )
				tmp+=TMI("mitem ����$U��...;beg ... from "+id);
		}

		if(ob->query("id")=="bigeye" && ob->query("name")=="ǧ����" && ob->query("where"))
			tmp+=TMI("mitem Ѱ��...��;where ...");

		if(ob->query("id") == "zhu banxian")
			tmp+=TMI("mitem ������ɴ����йء����񡹵���Ϣ;quest");

		if(ob->query("id") == "jin yinhua" || ob->query("id") == "jin juhua")
		{
			tmp+=TMI("mitem ��...���鱦����ȡ����;qu ...");
			tmp+=TMI("mitem ��ѯ��ŵ��鱦;chaxun");
		}

		if(me->query("dushu") && (ob->query("id") == "zhu danchen" || ob->query("id") == "zhu xi"))
			tmp+=TMI("mitem ѧϰ"+"����д��"+";learn literate at 1 from "+id);

		if(ob->query("xy_shoucheng"))
			tmp+=TMI("mitem ������������ڹ��͵���Ϣ;task over");

		if(ob->query("duchang/du"))
		{
			tmp+=TMI("mitem ��С��ѹ...����;bet 0 ... silver");
			tmp+=TMI("mitem ��С��ѹ...�ƽ�;bet 0 ... gold");
			tmp+=TMI("mitem ��С��ѹ...��Ʊ;bet 0 ... thousand-cash");
			tmp+=TMI("mitem ��С��ѹ...��Ʊ;bet 0 ... thousand-gold");
			tmp+=TMI("mitem �ڴ���ѹ...����;bet 1 ... silver");
			tmp+=TMI("mitem �ڴ���ѹ...�ƽ�;bet 1 ... gold");
			tmp+=TMI("mitem �ڴ���ѹ...��Ʊ;bet 1 ... thousand-cash");
			tmp+=TMI("mitem �ڴ���ѹ...��Ʊ;bet 1 ... thousand-gold");
			tmp+=TMI("mitem ��Χ����ѹ... ...;bet 2 ... ...");
			tmp+=TMI("mitem ��...��ѹ... ...;bet ... ... ...");
		}

		if(ob->query("id")=="taohua tong" && ob->query("name")=="�һ�ͯ")
			tmp+=TMI("mitem ���뽨��;apply house");

		if(ob->query("vendor_goods"))
		{
			//����Buy�˵��б�
			if (arrayp(goods = ob->query("vendor_goods")))
			{
				for (i = 0; i < sizeof(goods); i++)
				{
					tmp+=TMI("mitem ��"+wuse_name(goods[i]->short())+";buy "+goods[i]->query("id")+"\n");
				}
			}

			tmp+=TMI("mitem ��ѯ������Ʒ�۸�;list");
		}

		if ( !ob->query("no_diandang") && !ob->query("vendor_goods") && function_exists("do_value",ob) && function_exists("do_redeem",ob) && function_exists("do_pawn",ob) )
		{
			if(me->query("cwf"))
				tmp+=TMI("mitem ��ѯ�䵱�Ķ���;check");

			//����redeem�˵��б�
			if (arrayp(goods = me->query("pawns")))
			{
				for (i = 0; i < sizeof(goods); i++)
				{
					tmp+=TMI("mitem ���"+wuse_name(goods[i]->short())+";redeem "+goods[i]->query("id")+"\n");
				}
			}

			//����buy�˵��б�
			if ( inv = all_inventory(ob) )
			{
				for (i = 0; i < sizeof(inv); i++)
				{
					if (inv[i]->query("equipped") || inv[i]->query("money_id"))
						continue;

					tmp+=TMI("mitem ��"+wuse_name(inv[i]->short())+";buy "+inv[i]->query("id")+"\n");
				}
				tmp+=TMI("mitem �鿴...��...����ŵ�����;look_item ...Ӣ����,...���");
			}

			tmp+=TMI("mitem ��ѯ������Ʒ�۸�;list "+id);
		}

		if ( function_exists("do_deposit",ob) && function_exists("do_withdraw",ob) && function_exists("do_convert",ob) )
		{
			tmp+=TMI("mitem ��Ǯ;deposit ...");
			tmp+=TMI("mitem �һ�����;convert ...");
			tmp+=TMI("mitem ��1000���ƽ�һ��ɽ�Ʊ;convert 1000 gold to thousand-gold");
			tmp+=TMI("mitem ��2000���ƽ�һ��ɽ�Ʊ;convert 2000 gold to thousand-gold");
			tmp+=TMI("mitem ��...���ƽ�һ��ɽ�Ʊ;convert ... gold to thousand-gold");

			if(me->query("money") || me->query("more_money"))
			{
				tmp+=TMI("mitem ȡ10���ƽ�;withdraw 10 gold");
				tmp+=TMI("mitem ȡ50���ƽ�;withdraw 50 gold");
				tmp+=TMI("mitem ȡ100���ƽ�;withdraw 100 gold");
				tmp+=TMI("mitem ȡ500���ƽ�;withdraw 500 gold");
				tmp+=TMI("mitem ȡ1000���ƽ�;withdraw 1000 gold");
				tmp+=TMI("mitem ȡ2000���ƽ�;withdraw 2000 gold");
				tmp+=TMI("mitem ȡǮ;withdraw ...");
				tmp+=TMI("mitem ��ѯ���;check");
			}
		}

		//Ǳ������
		if ( function_exists("cun_qn",ob) && function_exists("qu_qn",ob) && function_exists("cha_qn",ob) )
		{
			tmp+=TMI("mitem ��ѯ����Ǳ�ܵ���;check");
			tmp+=TMI("mitem ����...��Ǳ��;cun ...");
			tmp+=TMI("mitem ��Ǳ�ܶ��������;cun " + me->query("potential"));
			tmp+=TMI("mitem ȡ��...��Ǳ��;qu ...");
			tmp+=TMI("mitem ��Ǳ�ܶ�ȡ����;qu " + me->query("temp_svqn"));
		}

		//̩ɽ������ʹ�������б�
		if ( ob->query("winner") == me->query("id") )
		{
			tmp+=TMI("mitem ���浵��;recopy");
			tmp+=TMI("mitem ��ȡ����;recover");
		}

		if ( !me->is_apprentice_of(ob) )
		{
			if(ob->query("attitude")=="peaceful")
				tmp+=TMI("mitem ��$UΪʦ;apprentice "+id);
		}
		else
		{
			tmp+=TMI("mitem ��ʦ��$U��ͷ;apprentice "+id);
			tmp+=TMI("mitem ��ѯʦ��$U����;skills "+id);

			if(ob->query_skills() && me->query("jing")>=1 && (int)me->query("potential")>(int)me->query("learned_points"))
			{
				skills=ob->query_skills();
				str=keys(skills);
				for(i=0; i<sizeof(str); i++)
				{
					if(me->query_skills())
					{
						meskills=me->query_skills();
						my_skill = me->query_skill(str[i], 1);

						if( (string)SKILL_D(str[i])->type()=="martial" && (int)((my_skill+1)*((my_skill+1)/10)*(my_skill+1))>(int)me->query("combat_exp") )
							continue;

						if(skills[str[i]]>my_skill && str[i]!="idle")
							tmp+=TMI("mitem ѧϰ"+to_chinese(str[i])+";learn "+str[i]+" at 1 from "+id);
					}
					else
						tmp+=TMI("mitem ѧϰ"+to_chinese(str[i])+";learn "+str[i]+" at 1 from "+id);
				}
			}
		}
	}
	else
	{
		if ( ob->is_character() && !ob->is_corpse() && !environment(me)->query("no_fight") )
		{
			if ( (int)ob->query("age") > 17 || !interactive(ob) )
				tmp+=TMI("mitem ɱ��$U;kill "+id);
		}

		if(!ob->query("no_get"))
			tmp+=TMI("mitem ��$U������;get "+id);

		if( ob->is_container() || (ob->is_character() && !living(ob)) )
		{
			//����ȡ�������ȫ�б�
			if ( inv = all_inventory(ob) )
			{
				for (i=0; i<sizeof(inv); i++)
				{
					if ( ob->is_character() )
					{
						if ( inv[i]->query("money_id") )
							tmp+=TMI("mitem ��$U�����ճ�..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +";get ... " + inv[i]->query("id") + " from " + id);

						tmp+=TMI("mitem ��$U�����ճ�" + wuse_name(inv[i]->short()) + ";get " + inv[i]->query("id") + " from "+id);
					}
					else
					{
						if ( inv[i]->query("money_id") )
							tmp+=TMI("mitem ��$U���ó�..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +";get ... " + inv[i]->query("id") + " from " + id);

						tmp+=TMI("mitem ��$U���ó�" + wuse_name(inv[i]->short()) + ";get " + inv[i]->query("id") + " from "+id);
					}
				}

				if ( sizeof(inv) > 0)
				{
					if ( ob->is_character() )
						tmp+=TMI("mitem ��$U���ϵĶ������ճ���;get all from "+id);
					else
						tmp+=TMI("mitem ��$U��Ķ������ó���;get all from "+id);
				}
			}

			//����������ȫ�б�
			if ( inv = all_inventory(me) )
			{
				for (i=0; i<sizeof(inv); i++)
				{
					if ( !inv[i]->query("no_put") )
					{
						if ( ob->is_character() )
						{
							if ( inv[i]->query("money_id") )
								tmp+=TMI("mitem ��..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +"����$U����;put ... " + inv[i]->query("id") + " in " + id);

							tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "����$U����;put " + inv[i]->query("id") + " in "+id);
						}
						else
						{
							if ( inv[i]->query("money_id") )
								tmp+=TMI("mitem ��..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +"װ��$U��;put ... " + inv[i]->query("id") + " in " + id);

							tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "װ��$U��;put " + inv[i]->query("id") + " in "+id);
						}
					}
				}
			}
		}

		if(ob->query("board_id"))
		{
			tmp+=TMI("mitem ����...Ϊ����;banzhu ...");
			tmp+=TMI("mitem ���µ�����;read new");
			tmp+=TMI("mitem ����...������;read ...");
			tmp+=TMI("mitem ����...����...���ظ�;read .......");
			tmp+=TMI("mitem д�µ�����;post ...");
			tmp+=TMI("mitem �ظ���...��;re ...");
			tmp+=TMI("mitem ɾ������...;discard ...");
		}

		if(id=="touzhu ban")
		{
			tmp+=TMI("mitem ������;read rules");
			tmp+=TMI("mitem ���ʹ���;read duijiang");
			tmp+=TMI("mitem Ͷע״��;read biao");
			tmp+=TMI("mitem Ͷע;touzhu");
			tmp+=TMI("mitem �Խ�;duijiang");
		}

		if(ob->query("id")=="bingqi pu")
		{
			tmp+=TMI("mitem ����$U;read "+id);
			tmp+=TMI("mitem ��������;ping "+id);
		}

		if ( base_name(ob) == "/clone/misc/swordjia" )
		{
			tmp+=TMI("mitem ȡ�����׽�;na fenglei jian from jia");
			tmp+=TMI("mitem ȡ������;na fenghuo gun from jia");
			tmp+=TMI("mitem ȡ�����Ƶ�;na fengyun dao from jia");
		}
	}

	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

int user_path(object me, object ob, int v)
{
	mapping prop;
	string id, tmp, *item_sx, ob_id;
	object *obj, *inv;
	int i, j, n, m, pinjie, item_levl;

	n = 1;// nΪ���ⱦʯ�ĺϳ������жϣ�����ֵΪ 1
	m = 1;// mΪ��ͨ��ʯ�ĺϳ������жϣ�����ֵΪ 1

	if(stringp(tmp=ob->query_menu(me,1)))//��������ܽ��Ͳ˵�����ֱ�ӷ��ز˵�
	{
		write(tmp);
		return 1;
	}

	if ( v > 1 && !ob->query_temp("apply/id") )
		id = ob->query("id") + sprintf(" %d", v);
	else
		id = ob->query("id");

	ob_id = ob->query("id");

	tmp=TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem �۲�$U;look "+id);

	if ( !ob->query("no_drop") || base_name(environment(me)) == "/d/city/drop" )
		tmp+=TMI("mitem ����$U;drop "+id);

	if(ob->query("liquid"))
	{
		if(ob->query("liquid/remaining"))
			tmp+=TMI("mitem ��$U;drink "+ob_id);
		if(environment(me)->query("resource/water"))
			tmp+=TMI("mitem ��$Uװ��ˮ;fill "+ob_id);
	}

	if(ob->query("food_remaining"))
		tmp+=TMI("mitem ��$U;eat "+ob_id);

	//����ȡ�������ȫ�б�
	if( ob->is_container() || (ob->is_character() && !living(ob)) )
	{
		if ( inv = all_inventory(ob) )
		{
			for (i = 0; i < sizeof(inv); i++)
			{
				if ( ob->is_character() )
				{
					if ( inv[i]->query("money_id") )
						tmp+=TMI("mitem ��$U�����ճ�..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +";get ... " + inv[i]->query("id") + " from " + id);

					tmp+=TMI("mitem ��$U�����ճ�" + wuse_name(inv[i]->short()) + ";get " + inv[i]->query("id") + " from "+id);
				}
				else
				{
					if ( inv[i]->query("money_id") )
						tmp+=TMI("mitem ��$U���ó�..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +";get ... " + inv[i]->query("id") + " from " + id);

					tmp+=TMI("mitem ��$U���ó�" + wuse_name(inv[i]->short()) + ";get " + inv[i]->query("id") + " from "+id);
				}
			}

			if ( sizeof(inv) > 0)
			{
				if ( ob->is_character() )
					tmp+=TMI("mitem ��$U���ϵĶ������ճ���;get all from "+id);
				else
					tmp+=TMI("mitem ��$U��Ķ������ó���;get all from "+id);
			}
		}
	}

	if(mapp(prop=ob->query("armor_prop"))&& stringp(ob->query("armor_type")) )
	{
		if(!ob->query("equipped"))
			tmp+=TMI("mitem ����$U;wear "+id);
		else
			tmp+=TMI("mitem ����$U;remove "+id);
	}

	if(mapp(prop=ob->query("weapon_prop")) && stringp(ob->query("skill_type")))
	{
		if(!ob->query("equipped"))
			tmp+=TMI("mitem װ��$U;wield "+id);
		else
			tmp+=TMI("mitem ���װ��$U;unwield "+id);
	}

	if(!ob->is_character() && !ob->query("money_id"))
	{
		tmp+=TMI("mitem �Ե׼�...���ƽ�����$U;auction "+id+" for "+"... gold");

		if ( file_size("/data/paimai/name") != -1 )
		{
			tmp+=TMI("mitem �Ӽ�...���ƽ𾺱�������Ʒ��" + wuse_name(read_file("/data/paimai/name")) + ";auction 1 add "+"... gold");
			tmp+=TMI("mitem �鿴Ŀǰ���ھ���״̬����Ʒ�嵥;auction -l");
			tmp+=TMI("mitem �鿴Ŀǰ���ھ���״̬����Ʒ����;auction -m");
		}
	}

	//Ƕ��ʯ��ȫ�б�
	if ( inv = all_inventory(me) )
	{
		for (i = 0; i < sizeof(inv); i++)
		{
			//����������Ʒ��ȫ�б�
			if( ob->is_container() || (ob->is_character() && !living(ob)) )
			{
				if ( !inv[i]->query("no_put") && inv[i] != ob )
				{
					if ( ob->is_character() )
					{
						if ( inv[i]->query("money_id") )
							tmp+=TMI("mitem ��..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +"��$U����;put ... " + inv[i]->query("id") + " in " + id);

						tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "����$U����;put " + inv[i]->query("id") +" in "+id);
					}
					else
					{
						if ( inv[i]->query("money_id") )
							tmp+=TMI("mitem ��..." + wuse_name(inv[i]->query("base_unit")) + wuse_name(inv[i]->name(1)) +"װ��$U��;put ... " + inv[i]->query("id") + " in " + id);

						tmp+=TMI("mitem ��" + wuse_name(inv[i]->short()) + "װ��$U��;put " + inv[i]->query("id") +" in "+id);
					}
				}
			}

			if ( inv[i]->query("equipped") )
				continue;

			//��ͨ��ʯ
			if( ob->query("zhubao_save") )
			{
				if ( inv[i]->query("armor_prop/armor") || inv[i]->query("weapon_prop/damage") )
					tmp+=TMI("mitem ��$UǶ��" + wuse_name(inv[i]->short()) + "��;inset " + inv[i]->query("id"));

				//�ϳ�
				if ( inv[i]->query("b_lvl") == ob->query("b_lvl") )
				{
					if ( m == 3 )
					{
						tmp+=TMI("mitem ��$U�ϳɸ���һ����ʯ;hecheng "+id);
						m = 0;
					}

					m += 1;
				}
			}

			// ��
			if ( inv[i]->query("armor_prop/armor") || inv[i]->query("weapon_prop/damage") )
			{
				if ( inv[i]->query("armor_prop/armor") )
				{
					pinjie = 0;
					item_sx = keys(armor_shuxing);
					for (j = 0; j < sizeof(item_sx); j++)
					{
						if ( inv[i]->query("armor_prop/" + item_sx[j]) )
							pinjie++;
					}
				}
				if ( inv[i]->query("weapon_prop/damage") )
				{
					pinjie = 0;
					item_sx = keys(weapon_shuxing);
					for (j = 0; j < sizeof(item_sx); j++)
					{
						if ( inv[i]->query("weapon_prop/" + item_sx[j]) )
							pinjie++;
					}
				}

				if ( inv[i]->query("weapon_prop") )
					item_levl = inv[i]->query("weapon_prop/level");
				else if ( inv[i]->query("armor_prop") )
					item_levl = inv[i]->query("armor_prop/level");

				// �󶨷�
				if( base_name(ob) == "/clone/map/obj/bangding-fu" )
				{
					if ( item_levl == !ob->query("xyzx_sys/bind_type", 1) && item_levl == !ob->query("xyzx_sys/bind_type", 2))
						tmp+=TMI("mitem ��$U��" + wuse_name(inv[i]->short()) + "��װ��[������];bang " + id + " to " + inv[i]->query("id"));
					else
						tmp+=TMI("mitem ��$U��" + wuse_name(inv[i]->short()) + "��װ��[����];bang " + id + " to " + inv[i]->query("id"));
				}
				// �����ȼ����Ż���				
				if( base_name(ob) == "/clone/map/obj/hanyu-jingtie" )
				{
					if ( item_levl == 30)
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[������];ronglian " + id + " to " + inv[i]->query("id"));
					else
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[����];ronglian " + id + " to " + inv[i]->query("id"));
				}
				if( base_name(ob) == "/clone/map/obj/jingang-shi" ) //���ʯ
				{
					if ( item_levl < 30)
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[������];ronglian1 " + id + " to " + inv[i]->query("id"));
					else
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[����];ronglian1 " + id + " to " + inv[i]->query("id"));
				}
				if( base_name(ob) == "/clone/map/obj/longwen-chijin" ) //���Ƴ��
				{
					if ( item_levl < 30)
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[������];ronglian2 " + id + " to " + inv[i]->query("id"));
					else
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[����];ronglian2 " + id + " to " + inv[i]->query("id"));
				}
				if( base_name(ob) == "/clone/map/obj/feixian-xuanjing" ) //��������
				{
					if ( item_levl < 30)
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[������];ronglian3 " + id + " to " + inv[i]->query("id"));
					else
						tmp+=TMI("mitem ��$U����" + wuse_name(inv[i]->short()) + "��װ��[����];ronglian3 " + id + " to " + inv[i]->query("id"));
				}
			}

			//���ⱦʯ
			if ( ob->query("liebiao_gem") )
			{
				//Ƕ
				if ( inv[i]->query("max_sockets") && inv[i]->query("sockets/max") > 0  )
				{
					for (j = 0; j < (int)inv[i]->query("sockets/max"); j++)
					{
						tmp+=TMI("mitem ��$UǶ��" + wuse_name(inv[i]->short()) + "�ĵ� " + (j+1) + " ���ӿ���;insert " + ob_id + " into " + inv[i]->query("id") +" at socket " + (j+1));
					}
				}

				//�ϳ�
				if ( inv[i]->name(1) == ob->name(1) && inv[i]->query("id") == ob->query("id") )
				{
					if ( n == 3 )
					{
						tmp+=TMI("mitem ��$U�ϳɸ���һ����ʯ;combine "+ob_id);
						n = 0;
					}

					n += 1;
				}
			}
		}
	}

	if ( ob->query("skill") )
	{
		tmp+=TMI("mitem ��$U;study "+id);
		tmp+=TMI("mitem ȫ����$U;study "+id+" at all");
	}
	else if ( function_exists("do_du",ob) && !living(ob) )
		tmp+=TMI("mitem ��$U;study "+id);

	//���ض������¶���Ʒ�����⶯���˵�
	obj = all_inventory(environment(me));
	for (i=0;i < sizeof(obj);i++)
	{
		//��Ʒ�����ʹ�ȡ��ȫ�б�
		if ( !userp(obj[i]) )
		{
			if ( living(ob) || ob->is_character() || ob->is_corpse() )
			continue;

			//��
			if ( !obj[i]->query("no_diandang") && !obj[i]->query("vendor_goods") && function_exists("do_value",obj[i]) && function_exists("do_redeem",obj[i]) && function_exists("do_pawn",obj[i]) )
			{
				if ( ob->query("zhubao_save") || ob->query("xyzx_save_item") || (!ob->query("shaolin") && !ob->query("no_drop") && !ob->query("no_sell") && !ob->query("money_id")) )
				{
					tmp+=TMI("mitem ����$U;sell "+id);
					if ( !ob->query("xyzx_save_item") && !ob->query("zhubao_save") )
						tmp+=TMI("mitem �䵱$U;pawn "+id);
				}

				//����
				tmp+=TMI("mitem ���" + wuse_name(ob->short()) + "�ļ۸�;value " + ob->query("id"));
			}

			//��Ǯ
			if ( function_exists("do_deposit",obj[i]) && function_exists("do_withdraw",obj[i]) && function_exists("do_convert",obj[i]) && ob->query("money_id") )
				tmp+=TMI("mitem ��$U���Ǯׯ;deposit all "+id);
		}

		//�����ȫ�б�
		if ( ob->query("name") == "���" && ob->query("id") == "mian ju" )
		{
			//�����
			if ( !obj[i]->query_temp("apply/name") )
			{
				if ( obj[i] == me )
					continue;

				//���Բ������ε���ʦ�����б���֤������Ч��
				if ( wizardp(obj[i]) && obj[i]->query("env/invisibility") > 9 )
					continue;

				if ( userp(obj[i]) )
					tmp+=TMI("mitem ʹ�����װ���" + wuse_name(obj[i]->query("name")) + " (���);pretend "+obj[i]->query("id"));
				else
					tmp+=TMI("mitem ʹ�����װ���" + wuse_name(obj[i]->query("name")) + " (NPC);pretend "+obj[i]->query("id"));
			}
		}

		//��Ʒ������ȫ�б�
		if ( !ob->query("no_drop") || !ob->query("no_give") )
		{
			if ( obj[i] == me )
				continue;

			//���Բ������ε���ʦ�����б���֤������Ч��
			if ( wizardp(obj[i]) && obj[i]->query("env/invisibility") > 9 )
				continue;

			// ��������
			if ( ob->query("target") == obj[i]->short() && function_exists("do_give",ob) )
				tmp+=TMI("mitem ��"+wuse_name(ob->short())+"����" + wuse_name(obj[i]->name()) + ";give "+id+" to " + obj[i]->query("id"));

			//ע�⣺�˴�������Ϊ��ʹ�б�򵥻��ӿ�ѭ���������򱾴�ѭ���Ľ�β���������Ҫ������������µ��б�˵�������ϸ���������Ҫ���Ƿ񱻸þ������ԡ�
			if ( !interactive(obj[i]) && obj[i]->query("id") != ob->query("target") && !function_exists("accept_object",obj[i]) && (!ob->query("owner_id") || ob->query("owner_id") != obj[i]->query("id") || ob->query("owner_name") != obj[i]->query("name")) )
				continue;

			if ( userp(obj[i]) )
			{
				if ( ob->query("money_id") )
				{
					tmp+=TMI("mitem �ó�..." + wuse_name(ob->query("base_unit")) + wuse_name(ob->name(1)) +"��"+wuse_name(obj[i]->name())+" (���);give ... " + ob->query("id") + " to " + obj[i]->query("id"));
					tmp+=TMI("mitem ��"+wuse_name(ob->short())+"����" + wuse_name(obj[i]->name()) + " (���);give "+id+" to " + obj[i]->query("id"));
				}
				else
					tmp+=TMI("mitem ��"+wuse_name(ob->short())+"��" + wuse_name(obj[i]->name()) + " (���);give "+id+" to " + obj[i]->query("id"));
			}
			else
			{
				if ( ob->query("money_id") )
				{
					tmp+=TMI("mitem �ó�..." + wuse_name(ob->query("base_unit")) + wuse_name(ob->name(1)) +"��"+wuse_name(obj[i]->name())+" (NPC);give ... " + ob->query("id") + " to " + obj[i]->query("id"));
					tmp+=TMI("mitem ��"+wuse_name(ob->short())+"����" + wuse_name(obj[i]->name()) + " (NPC);give "+id+" to " + obj[i]->query("id"));
				}
				else
					tmp+=TMI("mitem ��"+wuse_name(ob->short())+"��" + wuse_name(obj[i]->name()) + " (NPC);give "+id+" to " + obj[i]->query("id"));
			}
		}
	}

	//ȡ�����
	if ( ob->query("name") == "���" && ob->query("id") == "mian ju" && me->query_temp("apply/name") )
		tmp+=TMI("mitem ȡ����߻ظ�������Ŀ;pretend none");

	//���������б�
	if ( base_name(ob) == "/d/city/obj/gift" || base_name(ob) == "/clone/misc/gift" )
		tmp+=TMI("mitem ��" + wuse_name(ob->short()) + ";chai gift");

	//������װ��  //2015.10 ��� ��� my jia ��my sword ���������������
	if ( function_exists("do_hui",ob) || function_exists("do_hui1",ob) )
	{
		//��
		if ( ob->query("id") == "my jia" )
		tmp+=TMI("mitem �ݻ�" + wuse_name(ob->short()) + ";hui1 " + ob->query("id"));
        else
		tmp+=TMI("mitem �ݻ�" + wuse_name(ob->short()) + ";hui " + ob->query("id"));
	
		//����
		if ( function_exists("do_rename",ob) || function_exists("do_jianame",ob) )
		{
			if ( ob->query("id") == "my jia" )
				tmp+=TMI("mitem ��" + wuse_name(ob->short()) + "�����Ƹ�Ϊ...;jianame ...");
			else
				tmp+=TMI("mitem ��" + wuse_name(ob->short()) + "�����Ƹ�Ϊ...;rename ...");
		}

		//ʹ�û�������
		if ( function_exists("do_levelup",ob) || function_exists("do_levelup1",ob))
			if ( ob->query("id") == "my jia" )
			tmp+=TMI("mitem ����" + wuse_name(ob->short()) + ";jijia " + ob->query("id"));
		   else
			tmp+=TMI("mitem ����" + wuse_name(ob->short()) + ";jiwu " + ob->query("id")); 
	}

	//����ʯ
	if ( base_name(ob) == "/d/npc/m_weapon/tan/item/stone" )
	{
		tmp+=TMI("mitem ұ��" + wuse_name(ob->short()) + ";yelian " + id);
		tmp+=TMI("mitem ��" + wuse_name(ob->short()) + ";eat " + ob->query("id"));
	}

	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

int skill_path(object me, string skill)
{
	string tmp, *skill_types, enable_skill, use_text;
	int i;

	skill_types = ({"unarmed", "axe", "sword", "blade", "stick", "staff", "spear", "fork", "club", "throwing",
		"force", "parry", "hammer", "dodge", "magic", "spells",	"taoism", "whip", "poison", "finger", "hand",
		"cuff", "claw", "strike"});

	tmp = TMI("mbegin "+to_chinese(skill)+";"+skill);
	tmp+=TMI("mitem �鿴ʹ���е����⼼��;enable");
	tmp+=TMI("mitem ����(����)���ܣ�$U;abandon "+skill);
	// ���⼼��
	if ( member_array(skill, skill_types) == -1 )
	{
		// ս������
		if ( SKILL_D(skill)->type() == "martial" )
		{
			for ( i=0; i<sizeof(skill_types); i++ )
			{
				if( SKILL_D(skill)->valid_enable(skill_types[i]) )
				{
					if ( skill_types[i] == "force" )
					{
						use_text=TMI("mitem �鿴�����ڹ�("+to_chinese(skill)+")���˹�����;help "+skill);
						tmp += TMI("mitem ���������ڹ�("+to_chinese(skill)+")��["+to_chinese(skill_types[i])+"]��;enable "+skill_types[i]+" "+skill);
					}
					else
					{
						use_text=TMI("mitem �鿴���⼼��("+to_chinese(skill)+")�ľ���;help "+skill);
						tmp += TMI("mitem �������⼼��("+to_chinese(skill)+")��["+to_chinese(skill_types[i])+"]��;enable "+skill_types[i]+" "+skill);
					}
				}
			}
			tmp += use_text;
		}
		else // ��ս������
		{
			tmp+=TMI("mitem �鿴����ʹ��˵��;help "+skill);
			for ( i=0; i<sizeof(skill_types); i++ )
			{
				if( SKILL_D(skill)->valid_enable(skill_types[i]) )
					tmp += TMI("mitem �������⼼��("+to_chinese(skill)+")��["+to_chinese(skill_types[i])+"]��;enable "+skill_types[i]+" "+skill);
			}
		}
	}
	else // ��������
	{
		tmp+=TMI("mitem �鿴����ʹ��˵��;help "+skill);
		if ( stringp(enable_skill = me->query_skill_mapped(skill)) )
		{
			tmp+=TMI("mitem ���������$U�ϵ����⼼�ܣ�"+to_chinese(enable_skill)+";enable "+skill+" none");
			tmp+=TMI("mitem ����������$U�ϵ����⼼�ܣ�"+to_chinese(enable_skill)+";practice "+skill);
		}
	}
	// �����ܵ����⹦��
	//----------------------start-----------------------------
	if ( skill == "force" )
	{
		tmp+=TMI("mitem �˹��ָ��Լ��ľ���;exert regenerate");
		tmp+=TMI("mitem �˹��ָ��Լ�����Ѫ;exert recover");
		tmp+=TMI("mitem �˹����Լ����ξ����ϵ�����;exert jingheal");
		tmp+=TMI("mitem �˹����Լ�������Ѫ�ϵ�����;exert heal");
		tmp+=TMI("mitem �˹���...���ξ����ϵ�����;exert jingheal ...");
		tmp+=TMI("mitem �˹���...������Ѫ�ϵ�����;exert heal ...");
		tmp+=TMI("mitem ʹ��...����Ѫ������������;exercise ...");
		if ( stringp(me->query_skill_mapped(skill)) )
			tmp+=TMI("mitem ÿ��ʹ��...����������������;enforce ...");
	}
	if ( skill == "taoism" )
	{
		tmp+=TMI("mitem ʹ��...�㾫��������������;respitate ...");
		if ( stringp(me->query_skill_mapped(skill)) )
			tmp+=TMI("mitem ÿ��ʹ��...�㾫��������ͨ����;enchant ...");
	}
	if ( skill == "qimen-flee" )
	{
		tmp+=TMI("mitem ʹ����ͨ���ݵ�֮��;conjure drift");
		tmp+=TMI("mitem ʹ����ͨ������ݼ�;conjure dunjia");
	}
	if ( skill == "count" )
	{
		tmp+=TMI("mitem ʹ�ð����������...Ŀǰλ��;location ...");
	}
	//-----------------------end------------------------------
	tmp+=TMI("mendd");

	tell_object(me, tmp);
	return 1;
}

//��ɰ�Tomud�ͻ����б�˵����ܽ���ANSI���������ɫ�ַ�����ά������
string wuse_name(string str)
{
	if ( !stringp(str) ) str = "";

	str = replace_string(str,BLK,"");
	str = replace_string(str,RED,"");
	str = replace_string(str,GRN,"");
	str = replace_string(str,YEL,"");
	str = replace_string(str,BLU,"");
	str = replace_string(str,MAG,"");
	str = replace_string(str,CYN,"");
	str = replace_string(str,WHT,"");
	str = replace_string(str,HIR,"");
	str = replace_string(str,HIG,"");
	str = replace_string(str,HIY,"");
	str = replace_string(str,HIB,"");
	str = replace_string(str,HIM,"");
	str = replace_string(str,HIC,"");
	str = replace_string(str,HIW,"");
	str = replace_string(str,NOR,"");
	str = replace_string(str,BLINK,"");
	return str;

}