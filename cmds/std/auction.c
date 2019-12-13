// ��ʼ������ By lisa
// �����Ż�(�޸Ĵ��ڵ�BUG������ת�Ʋ���Ǯׯת�ʣ�)
// ֧�ֶ�̬��Ʒ����ϸ���ϲ�ѯ
// auction.c �����뾺�۳���
// call_out() ӳ����ư�
/*-----------------------------------------------------------------------------
key  string ob_id      ��ƷID
v[0] object obj        ������Ʒ     
v[1] int    ob_price   ����۸�               
v[2] object ob_auction ������                 
v[3] object ob_onwer   ��Ʒ������             
v[4] string ob_desc    ��Ʒ�����߶Ը���Ʒ�Ľ���
v[5] string auction_id ������ID
v[6] string onwer_id   ����ID
v[7] string ob_name    ��Ʒ����
v[8] string ob_long    ��Ʒ����

mapping structure:
auction[obj : {ob, ob_price, ob_auction, ob_onwer, ob_desc, auction_id, ...} ]
*/
//-----------------------------------------------------------------------------


#include <ansi.h>
inherit F_DBASE;
inherit F_CLEAN_UP;

#define PRICE_DIFFERENCE 100
// �����Ƿ�֧�ֲ�ѯ�����Ķ�̬��Ʒ����ϸ����
#define XYZX_NEW_ITEM

static mapping auction = ([]);

// ״̬�仯�Ŀ�������
void auction_chat(string msg);  
void auction_state_check(int times, int s_times, int last_price, string obj_id); 
// ��ֹ��״̬�л�
void auction_end(string ob_name, int ob_price, mixed ob_auction, object ob_onwer, object ob, string ob_id);
void auction_cancel(string ob_id, object discredit_1, object discredit_2);
// ʵ������
void get_ob_desc(string desc, object me, string str, int num);
void choise_secret(string decide, object me, string ob_id, string desc, int num);
// ���ݷ���
int player_demand(int num, string unit, object me);
int player_bank(object ob);
int player_pay(object who, int amount);
int help();

int clean_up()
{
	return 1;
}

void create()
{
	seteuid(ROOT_UID);
	set("name", "����ָ��");
	set("id", "auction");
	set("channel_id","");
}

void auction_chat(string msg) 
{	
	msg = replace_string(msg,NOR,HIY);
	CHANNEL_D->do_channel(this_object(),"jypm",msg);	
}

void auction_state_check(int times, int s_times, int last_price, string obj_id)
{
	int i, ob_price, flag1 = 0, flag2 = 0;
	object ob, ob_auction, ob_onwer, new_auction, new_onwer, nul;
	mixed *v;
	string *k, ob_name, ob_id, str;
	
	// ���¶�λ����Ʒ��������Ϊ������Ʒ��������������ű仯
	k = keys(auction);
	i = member_array(obj_id,k); 
	v = values(auction)[i];
	ob_id      = k[i];
	ob         = v[0];
	ob_price   = v[1];
	ob_auction = v[2];
	ob_onwer   = v[3];
	ob_name    = v[7];
	
	if(!objectp(ob_auction) && !stringp(ob_auction))
	{
		flag1++;
		if(objectp(new_auction = find_player(v[5])))
		{
			ob_auction = new_auction;
			flag1 = 0;
		}
	}

	if(!objectp(ob_onwer))
	{
		flag2++;
		if(objectp(new_onwer = find_player(v[6])))
		{
			ob_onwer = new_onwer;
			flag2 = 0;
		}
	}

	if(flag2 && !flag1) 
	{
		str="��������ȱϯ��ȡ��"+ob_name+HIW"������";

		//ɾ���ļ�
		rm("/data/paimai/name");

		auction_chat(str);
		auction_cancel(ob_id, ob_auction, nul);
		return;
	}
	
	if(!objectp(ob) || !objectp(present(ob,ob_onwer)))
	{
		str="�����������ܲ�����������Ʒ"+ob_name+HIW"��ʧ����������ȡ����\n";

		//ɾ���ļ�
		rm("/data/paimai/name");

		auction_chat(str);
		ob_onwer->delete_temp("auctioning");
		auction_cancel(ob_id, ob_auction, nul);
		return;
	}
	
	if ( times < 23 )
	{
		times++;
		
		if(ob_price > last_price)
		{
			s_times = 0;
			call_out("auction_state_check", 20, times, s_times, ob_price, ob_id);
		}
		else
		{
			s_times++;
			
			if(s_times<4)
			{
				str = "��"+CHINESE_D->chinese_number(s_times)+"�κ���:����"+ob_name+HIW"���ּ�"+MONEY_D->price_str(ob_price)+"!!";
				auction_chat(str);
				call_out("auction_state_check", 15, times, s_times, ob_price, ob_id);	
			}
			else
			{
				if(flag1 && !flag2)
				{
					str="������ȱϯ��ȡ��"+ob_name+HIW"��������";

					//ɾ���ļ�
					rm("/data/paimai/name");

					auction_chat(str);
					auction_cancel(ob_id, ob_onwer, nul);
					return;
				}
				
				if(flag1 && flag2)
				{
					str="��������˫��ȱϯ��ȡ��"+ob_name+HIW"��������";

					//ɾ���ļ�
					rm("/data/paimai/name");

					auction_chat(str);
					auction_cancel(ob_id, nul, nul);
					return;
				}	
				
				auction_end(ob_name, ob_price, ob_auction, ob_onwer, ob, ob_id);
			}
		}
	}
	else
	{
		if(flag1 && !flag2)
		{
			str="������ȱϯ��ȡ��"+ob_name+HIW"��������";

			//ɾ���ļ�
			rm("/data/paimai/name");

			auction_chat(str);
			auction_cancel(ob_id, ob_onwer, nul);
			return;
		}
		
		if(flag1 && flag2)
		{
			str="��������˫��ȱϯ��ȡ��"+ob_name+HIW"��������";

			//ɾ���ļ�
			rm("/data/paimai/name");

			auction_chat(str);
			auction_cancel(ob_id, nul, nul);
			return;
		}
		
		str = "ʱ���ѵ�������"+ob_name+HIW"�Ĺ��̵���Ϊֹ��\n";

		//ɾ���ļ�
		rm("/data/paimai/name");

		auction_chat(str);
		auction_end(ob_name, ob_price, ob_auction, ob_onwer, ob, ob_id);
		return;
	}
	
	return ;
}

void auction_end(string ob_name, int ob_price, mixed ob_auction, object ob_onwer, object ob, string ob_id)
{

	object  *inv, *en_inv, nul;
	string onwer_id, str;

	// ��Ȼ��̫���ܷ������������ж��±���
	if(!objectp(ob_onwer)) return;

	if ( ob_onwer->is_ghost() )
	{
		//ɾ���ļ�
		rm("/data/paimai/name");
		str = "���������Ѿ�����������������Ч��\n";
		auction_cancel(ob_id, ob_onwer, nul);
		ob_onwer->set("auction_fail", ob_onwer->query("mud_age"));
		auction_chat(str);
		return;
	}
	
	onwer_id = ob_onwer->query_temp("auction/"+ob_id);
	
	if(stringp(ob_auction))
	{
		str=onwer_id+ " �Ե׼� "+MONEY_D->price_str(ob_price)+" ���� "+
		ob_name+HIW"�����κ��ۺ�����Ͷ�꣬����������Ч��\n";

		//ɾ���ļ�
		rm("/data/paimai/name");

		auction_cancel(ob_id, ob_onwer, nul);
		ob_onwer->set("auction_fail",ob_onwer->query("mud_age"));
	}
	else
	{
		if ( ob_auction->is_ghost() )
		{
			//ɾ���ļ�
			rm("/data/paimai/name");
			str = "�������Ѿ�����������������Ч��\n";
			ob_auction->delete_temp("auctioning");
			auction_cancel(ob_id, ob_onwer, nul);
			auction_chat(str);
			return;
		}

		str=ob_auction->query("name")+"("+ob_auction->query("id")+")"+ " ���� "+MONEY_D->price_str(ob_price)+" ���� "+
		ob_name+HIW"�ɹ������������ɽ���\n";

		//ɾ���ļ�
		rm("/data/paimai/name");
			
		// ����˫����Ǯ��Ʒ�Ľ������������ɽ���10%�������ѣ�����֮ǰ�Ѿ������׼�10%�ı�֤��
		inv = all_inventory(ob_auction); 
		en_inv = all_inventory(environment(ob_auction)); 

		if ( sizeof(all_inventory(ob)) > 0 )
		{
			str="����������������������Ʒ������������������Ч��\n";
			ob_onwer->delete_temp("auctioning");
			auction_cancel(ob_id, ob_auction, nul);
		} else if ( !player_pay(ob_auction, (int)ob_price / 10 + ob_price) ) 
		{
			str="����������֧�����ۣ�����������Ч��\n";
			ob_auction->delete_temp("auctioning");
			auction_cancel(ob_id, ob_onwer, nul);
		}
		else
		{
			tell_object(ob_auction,"��ϲ���㾺��ɹ����õ��� "+ob_name+"\n");
			
			if(!ob->move(ob_auction) || (inv && sizeof(inv) > 49))
			{
				if(en_inv && sizeof(en_inv) < 49)
				{
					tell_object(ob_auction, "����ͷ�Ѿ��ò�����,�����䵽����Ľű�..\n");
					ob->move(environment(ob_auction)); 
				}
				else
				{
					tell_object(ob_auction, "�˴����������������������ܶ��չ���У�\n");
				 	destruct(ob);
				}
			}	
			
			tell_object(ob_onwer,ob_name+"�����ɹ������ÿ��Ѿ�ת�����Ǯׯ�ʻ���\n");
			
			//����Ǯׯ������������
			if ( ob_onwer->query("money") + ob_price > 99999999 )
			{
				ob_onwer->add("more_money", (int)(ob_onwer->query("money") + ob_price) / 100000000);
				ob_onwer->set("money", (ob_onwer->query("money")+ob_price) % 100000000);
			}
			else
				ob_onwer->add("money", ob_price);
			
			auction_cancel(ob_id, ob_auction, ob_onwer);
		}
	}
	
	auction_chat(str);
	return;
}

void auction_cancel(string ob_id, object discredit_1, object discredit_2)
{
	if(member_array(ob_id, keys(auction)) != -1)
		map_delete(auction, ob_id);

	if(objectp(discredit_1))
		discredit_1->delete("discredit");
	if(objectp(discredit_2))
		discredit_2->delete("discredit");
}

int main(object me,string arg)
{
	int i, guaranty, num, index;
	float coin;
	mixed *ob_value;
	string str, unit, *tuned_ch, *ob_key;
	object ob;
	
	ob_key = keys(auction);
	ob_value = values(auction);
	
	//������Ƶ��
	if(!arg)
	{
		tuned_ch = me->query("channels");
		
		if( !pointerp(tuned_ch) )//û��ͨ�κ�Ƶ��ʱ
			me->set("channels", ({ "jypm" }) );
		else if( member_array(auction, tuned_ch) == -1 )//û��ͨ����Ƶ��ʱ
			me->set("channels", tuned_ch + ({ "jypm" }) );
		
		//����Ƶ����ͨ��Ϣ
		tell_object(me,"\n�������Ƶ��(jypm)���ڴ��ڿ�ͨ״̬\n");
		return 1;
	}	
		
	if(arg == "-l")
	{
	    if(!sizeof(auction))
		{
			tell_object(me,"Ŀǰû����Ʒ��������\n");
			return 1;
		}
		
		str=HIG"��ǰ������Ʒ�嵥��\n\n";
		str += "����������������������������������������������������������������������������\n";
		str += "���  ��Ʒ����                    ��ǰ���                  ��߾�����\n";
		str += "����������������������������������������������������������������������������\n"NOR;
		
		for(i=0; i < sizeof(auction); i++)
		{
			mixed  *v = ob_value[i];

			str += sprintf("%-5s ",  i+1+".");
			str += sprintf("%-27s ", v[7]);
			str += sprintf("%-25s ", MONEY_D->price_str(v[1]));
			str += sprintf("%-15s\n", (!stringp(v[2]))? v[5] : "");
		}
		str += HIG"����������������������������������������������������������������������������\n"NOR;
		str += "\n\n";
        me->start_more(str);
		return 1;
	}
	
	if(arg == "-m")
	{
		if(!sizeof(auction))
		{
			tell_object(me,"Ŀǰû����Ʒ��������\n");
			return 1;
		}
		
		write(HIG"��ǰ������Ʒ��ϸ���ܣ�\n\n"NOR);

#ifdef XYZX_NEW_ITEM
		for(i=0; i < sizeof(auction);i++)
		{
			mixed  *v = ob_value[i];

			//str = HIG+(i+1)+".\n����������������������������������������������������������������������������"NOR"\n��Ʒ���ƣ� "+v[7]+
			//�����µ�look���������л����������
			str = HIG+(i+1)+".\n����������������������������������������������������������������������������"NOR+
			"\n�������ܣ�"+v[4]+
			"\n����    ��"+v[6]+
			"\n��Ʒ������\n";
			write(str);
			__DIR__"look"->look_item(me, v[0]);
		}
		
		write("\n\n");
#else
		for(i=0; i < sizeof(auction);i++)
		{
			mixed  *v = ob_value[i];

			//str = HIG+(i+1)+".\n����������������������������������������������������������������������������"NOR"\n��Ʒ���ƣ� "+v[7]+
			//�����µ�look���������л����������
			str = HIG+(i+1)+".\n����������������������������������������������������������������������������"NOR+
			"\n��Ʒ������"+v[8]+
			"\n�������ܣ�"+v[4]+
			"\n������"+v[6]+"\n\n";
		}
		
		me->start_more(str);
#endif

		return 1;
	}

	if(sscanf(arg,"%s for %d %s",str,num,unit) == 3)
	{
		str = lower_case(str);
		
		/*if(me->query("combat_exp") < 10000)
		{
			tell_object(me,"�����ѳ��꣬������������̫�٣��޷����Լ���������Ϊ����\n");
			return 1;
		}*/
		
		if(me->is_busy())
		{
			tell_object(me,"����æ���ء�\n");
			return 1;
		}
		
		if(me->is_ghost())
		{
			tell_object(me,"����޷�����������Ϊ�����ǵȻ����Ժ���˵�ɡ�\n");
			return 1;
		}
		
		if(me->query("discredit") && !me->query_temp("auctioning"))
		{
			if(me->query("mud_age") - me->query("discredit") < 3600)	
			{
				tell_object(me,"���������ϴ���������������ֵ���ͣ���ʱ��Ȩ���롣\n");
				return 1;
			}
			else
				me->delete("discredit");			
		}
		
		if(me->query("mud_age") - me->query("auction_fail") < 30)	
		{
			tell_object(me,"���ϴ���������Ʒ�����ʽ���ػ����Ȼ���ʱ������г��ɡ�\n");
			return 1;		
		}
		
		//����ͬʱ�����ж����������̿��Բ���
		if ( !wizardp(me) && sizeof(auction) >= 1 )
		{
			tell_object(me,"�����������ڽ������������ٺ�\n");
			return 1;
		}
		
		if(!objectp(ob = present(str,me)))
		{
			tell_object(me,"������û�� "+HIG+str+NOR+" �����Ʒ��\n");
			return 1;
		}		
		
		if(member_array(ob->query("id"),ob_key)!= -1)
		{
			tell_object(me,"������һ����������Ʒ�Ѿ����������ˡ�\n");
			return 1;
		}
		
		if(!wizardp(me) && !ob->query("buy_sell") && (ob->query("no_drop") || ob->query("no_sell") || ob->query("no_give") || ob->query("no_get") || ob->query("ownmake") || ob->query("no_put") || ob->query("money_id") || ob->is_character()) )  	
		{
			tell_object(me,"�����Ʒ���ܲμ�������\n");
			return 1;
		}
		
		//��ֹ�����ƶ���ֹ�������������������Ʒ���ٷ�����������
		if(sizeof(all_inventory(ob)) > 0 )
		{
			tell_object(me,"���ǰ�����Ķ������ó����ٲμ������ɣ�\n");
			return 1;
		}

		if ( mapp(ob->query("bind_master_level")) )
		{
			tell_object(me,"�Ѱ󶨵���Ʒ���ܲμ�������\n");
			return 1;
		}
		
		//�˿�����������10%
		guaranty = (int)(ob->query("value")/10);
		
		if (guaranty < 10)
			guaranty = 10;
		
		if(!player_pay(me, guaranty)) 
		{
			tell_object(me,"��ȫ������ҲƲ��в����Խ���������֤��\n");
			return 1;
		}

		unit = lower_case(unit);
		
		if(!(num = player_demand(num, unit, me)))
			return 1;
		
		write("����Ҫ��������Ʒ��"+ob->query("name")+"�� �׼ۣ�"+MONEY_D->price_str(num)+"\n\n");
		write("��������Ը���Ʒ�Ľ��ܣ�������50���ַ��ڣ�\nֱ�Ӱ��س�(enter)���Ժ��Դ��\n");
		input_to("get_ob_desc", me, ob->query("id"), num);
		return 1;
	}
	
	if(sscanf(arg,"%d add %d %s", index,num,unit) == 3)
	{
		object obj;
		mixed *v; 
		int ob_price; 

		/*if(me->query("combat_exp") < 10000)
		{
			tell_object(me,"�����ѳ��꣬������������̫�٣��޷����Լ���������Ϊ����\n");
			return 1;
		}*/
		
		if(me->is_ghost())
		{
			tell_object(me,"����޷�����������Ϊ�����ǵȻ����Ժ���˵�ɡ�\n");
			return 1;
		}
		
		if(me->is_busy())
		{
			tell_object(me,"����æ���ء�\n");
			return 1;
		}
		
		if(me->query("discredit") && !me->query_temp("auctioning"))
		{
			if(me->query("mud_age") - me->query("discredit") < 3600)	
			{
				tell_object(me,"���������ϴ���������������ֵ���ͣ���ʱ��Ȩ���롣\n");
				return 1;
			}
			else
				me->delete("discredit");			
		}
		
		if(index < 1 || index > sizeof(auction))
		{
			tell_object(me,"û�������ŵ���Ʒ��\n���� auction -l ָ���ѯĿǰ������Ʒ�嵥��\n");
			return 1;
		}
		
		v = ob_value[index-1];
		obj = v[0];
		ob_price = v[1];
		
		if(objectp(obj) && v[3] == me)
		{
			tell_object(me,"�������Լ���������Ʒ���밵���м۲��ɣ�\n");
			return 1;
		}
		
		coin = player_bank(me);
		unit = lower_case(unit);

		//��龺���Ƿ��ڹ滮��Χ��
        if(!(num = player_demand(num, unit, me)))
			return 1;
		
		if(num < ob_price/10)	
		{
			tell_object(me,"���Ĺ��򣺲�������ļ۵�10%Ϊ���ߡ�\n");	
			return 1;
		}
		
		if ( to_float(num) + ob_price > coin)
		{
			tell_object(me,"��û����ô��Ǯ���Գ���������ۡ�\n");
			return 1;
		}

		//������Ƿ��ܸ�����10%��������
		if ( (to_float(num) + ob_price)*11/10 > coin)
		{
			tell_object(me,"�����߻��轻����������10%�������ѣ���û����ô��Ǯ���Գ���������ۡ�\n");
			return 1;
		}

		if ( (to_float(num) + ob_price)*11/10 > 2100000000)
		{
			tell_object(me,"�Բ��𣬱��в�֧���޶����ۣ��������м��ѳ����˶��ߡ�\n"
				HIM"�� ��ܰ��ʾ��\n"
				HIW"------------------------------------------------------\n"
				HIY"�� ���¹�ʽ\n"
				HIR"�� (Ŀǰ��Ʒ�Ľ��ļ۸�+��ļӼ�)*11/10 < 21�����ƽ�\n"
				HIG"�� ��������Ľм۲�����Ч�ġ�\n"
				HIW"------------------------------------------------------\n"NOR);	
			return 1;
		}

		me->set("discredit",me->query("mud_age"));
		me->set_temp("auctioning",1);
		me->start_busy(10);
		v[1] = num + ob_price;
		v[2] = me;
		v[5] = me->query("id");
		str = me->query("name")+"("+me->query("id")+")Ͷ��"+v[7]+HIW"�����ۣ�"+MONEY_D->price_str(v[1])+"!\n"NOR;
		auction_chat(str);
		return 1;
	}
	else return help();
}

//������Ʒ����������ֻ����ʹ�����ģ����ⱻд��Ƿ�����
void get_ob_desc(string desc, object me, string str, int num)
{
	int i;
	i = strlen(desc);

	write("\n");
	//��Ʒ��������Ϊ30������(60���ֽ�)
	if (strlen(desc) > 60)
	{
		write("������Ʒ�Ľ���̫���ˣ���ע���Լ����ࡣ\n");
	        input_to("get_ob_desc", me, str, num);
                return ;
	}
	
	while(i--)
	{
		if( desc[i]<=' ' )
		{
			write("��Ʒ�Ľ��ܲ���ʹ�ÿ�����Ԫ��\n");
			input_to("get_ob_desc", me, str, num);
			return ;
		}
		if( i%2==0 && !is_chinese(desc[i..<0]) )
		{
			write("��Ʒ�Ľ��ܱ��������ġ�\n");
			input_to("get_ob_desc", me, str, num);
			return ;
		}
	}
	
	write("��Ϊ���������Ƿ�Ը��������������͸¶�Լ�������(y/n)\n");
	input_to("choise_secret", me, str, desc, num);
	return;
}

//��ʼ������������ж�
void choise_secret(string yn, object me, string ob_id, string desc, int num)
{
	mixed *values;	
	string ob_name, onwer_id, str, query_who;
	object ob;

	if (yn[0] != 'y' && yn[0] != 'Y')
		me->set_temp("auction/"+ob_id, "ĳ��");
	else 
		me->set_temp("auction/"+ob_id, me->query("name")+"("+me->query("id")+")");
	
	if(!objectp(ob = present(ob_id, me)))
	{
		tell_object(me,"�������Ѿ�û����������ˣ����ܲμ�������\n");
		return;
	}        	
	
	if(sizeof(auction) && member_array(ob_id,keys(auction))!= -1)
	{
		tell_object(me,"������һ����������Ʒ�Ѿ��������������ˡ�\n");
		return;
	}
	
	onwer_id = me->query_temp("auction/"+ob_id);
	query_who = me->query("name")+"("+me->query("id")+")";
	ob_name = ob->short();

	//�����������ԣ��ж�Υ��������������
	me->set("discredit",me->query("mud_age"));
	me->set_temp("auctioning",1);
	me->start_busy(10);
	
	values = ({ob, num, "", me , desc, "", onwer_id, ob_name, ob->long()});
	auction[ob_id] = values;
	
	str = onwer_id+"���ڿ�ʼ����"+ob_name+HIW"��"+"�׼ۣ�"+MONEY_D->price_str(num)+"��\n";

	//��¼������Ʒ����TomudЭ������
	write_file("/data/paimai/name",sprintf(ob_name));
	auction_chat(str);
	CHANNEL_D->do_channel( this_object(), "sys", query_who + "���ڿ�ʼ����" + ob_name + HIW"��" + "�׼ۣ�" + MONEY_D->price_str(num)+"��");
	call_out("auction_state_check", 10, 0, 0, num,ob_id);
	return;
}

//���Ƶ׼ۺ;�������(�趨Ϊ10����)
int player_demand(int num, string unit, object me)
{
	switch(unit)
	{
		case "coin":break;
		case "silver":num*=100;break;
		case "gold":num*=10000;break;
		case "thousand-cash":num*=100000;break;
		case "thousand-gold":num*=10000000;break;
		default:tell_object(me,"�Ƿ��Ļ��ҵ�λ��\n");
		return 0;
	}

	if (num < 10000)	
	{
		tell_object(me,"�Բ��𣬱��в�֧���޵׼�������һ���ƽ��ǳ��۵��ߡ�\n");	
		return 0;
	}
	
	if (num > 1000000000)
	{
		tell_object(me,"�Բ��𣬱��в�֧�����޸ߵ׼�������ʮ�����ƽ��ǳ������ޡ�\n");
		return 0;
	}
	
	return num;
}

//ȡ����Ǯׯ�����Ŀ
int player_bank(object ob)
{
	float total;
	
	total = ob->query("money");
	
	if ( ob->query("more_money") )
		total = total + to_float(ob->query("more_money")) * 100000000;
	
	return total;
}

//Ǯׯת�ʷ�ʽ
int player_pay(object who, int amount)
{
	float all_m;

	seteuid(getuid());

	all_m = who->query("money");
	all_m = all_m + who->query("more_money") * to_float(100000000);

	//����ʧ��
	if ( all_m < amount )
		return 0;

	who->add("more_money", -(int)amount / 100000000);

	if ( who->query("money") < amount % 100000000 )
	{
		who->add("more_money", -1);
		who->add("money", 100000000 - (int)amount % 100000000);
	}
	else
		who->add("money", -(int)amount % 100000000);

	tell_object(who,"���������ֱ�Ӵ�Ǯׯ�ʻ��Ͽ۳���\n\n");
	return 1;
}

int help()
{	
    write(@HELP
	�����ʽ��
    
��  ��������Ƶ����auction
��  �ر�����Ƶ����tune jypm
�����鿴Ŀǰ���ھ���״̬����Ʒ�嵥��auction -l
�����鿴Ŀǰ���ھ���״̬����Ʒ���ܣ�auction -m
����������Ʒ��auction <��ƷID> for <�׼�ֵ> <���ҵ�λ>
����������Ʒ��auction <��Ʒ���к�> add <�Ӽ�ֵ> <���ҵ�λ>
    
    ˵���ĵ���
��  1. ���������в���Ǯׯת�ʷ�ʽ�����н���Ǯׯ�ʻ���ֱ��ת�ơ�	
����2. ������������Ʒʱ������������ʽ��ʼ����ʱ��ҿ���������1���ƽ�     	
       ����Ͳ��ֵ�μӾ��ģ����һ��ʱ��������Ͷ�꣬�����к��ۣ����
       ���κ��ۺ���Ȼ���˳��ۣ���������ֹ�����һֱ����Ͷ�꣬���˹涨
       ʱ�䣬�˴�������Իᱻ��ֹ��
    3. �������ֹ����������Ϊʤ������������ֱ߼�Ǯׯ��ȡ����Ʒ
       ֱ��ת�Ƶ��������ϣ������������������������ڷ���֮�У������
       ��Ҳ�޷�װ�£���Ʒ��û�մ����мǣ��������ÿ��ֱ��ת����Ǯׯ
       �ʻ����������������10%�������ѡ���������������ʼ������Ͷ�꣬
       ������������ʧ�ܣ�������ˡ���˻�������    
    4. ���������У������Ϊ����˫�����뿪��Ϸ������Ʒ�뿪���������ˣ�
       �������������жϣ�����Υ���������������η������Ȼή�ͣ�
       �ͷ���һСʱ�ڲ��òμ��κ��������йصĻ������������Ʒ���κ�
       ��֮����Ϊ���˾����ȡ��������������Ҳ�ή�ͣ�������ڲ�������
       ��������Ʒ��
HELP
    );
    return 1;
}
