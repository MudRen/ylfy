#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
inherit NPC;

string give_cloth();
int qing_shen();
int chu_du();
int ask_mask(string str);	
int add_exp();
int give_gift();
int in_virtual_map();
int in_new_virtual_map();
int full_all();

void create()
{
	set_name(MAG"����"NOR, ({ "zi yin", "zi","yin"}));
	set("title", HIY"С��"NOR);
	set("nickname", HIC"���¾���"NOR);	
    set("str", 37);
    set("gender", "Ů��");
    set("age", 14);
	set("per",30);
    set("long","����һ��Ư����С��������۾��ﻹ͸��˿˿��������\n ��ר���������������ַ������\n");
	set("no_get",1);
	set("end_boss",1);
    set("xyzx_sys/level", 3000000);
	set("xyzx_sys/fanying",1000);
	set("str", 5000000);
    set("con", 5000000);
    set("int", 5000000);
    set("dex", 5000000);
	set("no_get", 1);
    set("max_qi", 5000000000);
    set("qi", 5000000000);
    set("max_jing", 5000000000);
    set("jing", 5000000000);
    set("neili", 3000000000);
    set("max_neili", 300000000);
    set("jingli", 3000000000);
    set("max_jingli", 300000000);
	set_temp("apply/attack",  12150);
    set_temp("apply/defense", 12130);
    set("combat_exp", 2100000000);
	set_skill("qimen-wuxing", 350000);
    set_skill("qufeng", 350000);
    set_skill("force", 350000);
    set_skill("king-of-dragon", 350000);	
    set_skill("dodge", 350000);
    set_skill("parry", 350000);
    set_skill("unarmed", 350000);
    set_skill("dragon", 350000);	
    set_skill("magic-old", 350000);	
    set_skill("spells", 350000);
    set_skill("magic", 350000);	
    map_skill("parry", "king-of-dragon");	
    map_skill("force", "king-of-dragon");           	
    map_skill("dodge", "king-of-dragon");           	
    map_skill("unarmed", "dragon");        	
    map_skill("spells", "magic-old"); 
    set("attitude", "friendly");
    set("inquiry", ([
		"����������":(: in_new_virtual_map :),
		//"���븱��"  :(: in_virtual_map :),
		"�·�"      :(: give_cloth :),
		"����"      :(: qing_shen :),	
		"����"      :(: chu_du :),
		"���"      :(: ask_mask :),
		"״̬�ظ�"  :(: full_all :),
		"����"      :(: give_gift :),
		"˫������"  :(: add_exp :),
		"Ǳ������"  :HIM"Ǳ������....������������ط����������...�����뿴��.....\n...��...����...����.....�������ˣ������������ģ�һֱ�����߾͵�����....."
	]));
    
    setup();
	
	carry_object("/clone/cloth/female1-cloth")->wear();	
}

string give_cloth()
{
	object me,obj;
	me = this_player();
	
	if (me->query("gender")=="Ů��")
		obj=new("/clone/cloth/female1-cloth");
	else
		obj=new("/clone/cloth/cloth");
	
	obj->move(me);
	command("xixi");
	return "�Ͽ촩�ϰɣ���";
}

int ask_mask(string arg)	
{
	object me,obj;
	object zi;
	me = this_player();
	zi=this_object();
	
	if(present("mian ju", me) /*|| present("mian ju", environment())*/)
	{
		command("say �Ѿ����˻�����,����ô���̰��������?");
		return 1;
	}
	
	//ֻ���������ʺ�������30���ID 2015.10ȡ�� �ƽ��Ա������
/*	if ( me->query("xyhy_type")!=2 && time() - me->query("birthday",1) > 3600*24*30 )
	{
		command("say �ϴ�С����,��ֻ�᷹���ſ�,��������,��ѧѧ����������!");
		return 1;
	}
	else
	{*/
		message_vision(CYN "����΢Ц���ó�����ߣ����˸�$N \n" NOR,me);
		obj=new("/clone/misc/mask-new");
		obj->move(me);
		command("love");
		return 1;
	//}
}

int qing_shen()
{
	object me,ob;

	me = this_object();
	ob = this_player();

	//ֻ���������ʺ�������30���ID
/*	if ( ob->query("xyhy_type")!=2 && time() - ob->query("birthday",1) > 3600*24*30 )
	{
		command("say ���Ѿ�����������Ү����Ҫ�����չ����ѽ��\n");
		return 1;
	}
*/
	ob->set("shen",0);
	message_vision(CYN "����Ц���������ֳ�$Nһ���������������������� \n" NOR,ob);
	return 1;
}

int chu_du()
{
	object me,ob;
	
	me = this_object();
	ob = this_player();

	//ֻ���������ʺ�������30���ID
/*	if ( ob->query("xyhy_type")!=2 && time() - ob->query("birthday",1) > 3600*24*30 )
	{
		command("say ���Ѿ�����������Ү����Ҫ�����չ����ѽ��\n");
		return 1;
	}
*/
	ob->clear_condition();
	message_vision(CYN "����Ц���������ֳ�$Nһ���������������������� \n" NOR,ob);
	return 1;
}

int add_exp()
{
	object me, ob;
	string now_time, my_time;

	me = this_object();
	ob = this_player();
	now_time = CHINESE_D->chinese_time(11, ctime(time()));
	my_time = ob->query("get_exp_time");
	if ( !my_time ) my_time = "";
	if ( atoi(CHINESE_D->chinese_time(9,ctime(time()))) > 19 )
	{
		message_vision(HIW"ÿ��20~24���Ϊ˫������ʱ�䣬����������˫������ʱ���$N���ǹ�һ��������ɡ�\n"NOR,ob);
		return 1;
	}
	if ( my_time == now_time )
	{
		message_vision(HIW"$N�����˫������ʱ���ƺ��Ѿ������˵İ�.....��\n"NOR,ob);
		return 1;
	}
	if ( ob->query("xy_huiyuan") )
	{
		ob->set("exp_jiacheng",time()+3600*2); 
		//message("channel:chat", HIY"������ˮ�¡���"HIW+ob->query("name")+HIG" ��ȡ��Сʱ��˫������ʱ�俪ʼ��ʱ��\n"NOR,users() );
		message_vision(HIW"$N��ȡ��Сʱ��˫������ʱ�俪ʼ��ʱ.....��\n"NOR,ob);
		log_file("cmds/Add_exp", sprintf("%s(%s) ��ȡ2Сʱ˫������ʱ�� on %s\n",ob->query("name"),ob->query("id"),CHINESE_D->chinese_time(5,ctime(time()))) );
	}
	else
	{
		ob->set("exp_jiacheng",time()+3600*1);
		//message("channel:chat", HIY"������ˮ�¡���"HIW+ob->query("name")+HIG" ��ȡһСʱ��˫������ʱ�俪ʼ��ʱ��\n"NOR,users() );
		message_vision(HIW"$N��ȡһСʱ��˫������ʱ�俪ʼ��ʱ.....��\n"NOR,ob);
		log_file("cmds/Add_exp", sprintf("%s(%s) ��ȡ1Сʱ˫������ʱ�� on %s\n",ob->query("name"),ob->query("id"),CHINESE_D->chinese_time(5,ctime(time()))) );
	}
	ob->set("get_exp_time", now_time);
	return 1;
}

int give_gift()
{
	object me,obj;
	
	me = this_player();
	
	if ( me->query(THIS_PAR + "_pick") )
	{
		command("say �����Ͼ�������\n\n");
		tell_object(me,HIW"�㳯����һ�飬Ү~������и������Ү���㲻�ɷ�˵���־��������ץȥ.....\n"NOR);
		tell_object(me,CYN "һ��Ư������ӰͻȻ������һ������֮�С�\n");
		tell_object(me,HIR "�������������һ�ã�ÿ��ֻ��һ�������Ŷ~��\n");
		tell_object(me,CYN "ֻ��һ��������ᣬ�Ǹ�Ư������Ӱ�Ѿ������ˡ�\n"NOR);
		return 1;
	}

	command("say �����Ͼ�������\n\n");
	tell_object(me,HIW"�㳯����һ�飬Ү~������и������Ү���㲻�ɷ�˵���־��������ץȥ.....\n"NOR);
	
	obj = new("/d/city/obj/gift.c");
	obj->move(me);
	
	message_vision("$N��ʯ��������һ���������\n",me );
	me->command("chai gift");
	
	//ÿ�μ���������ϴεĲ������������ӱ����õĲ�����
	me->delete(LAST_PAR + "_pick");
	me->set(THIS_PAR + "_pick",1);
	me->start_busy(3);
	
	return 1;
}

int in_virtual_map()
{
	object me, ob, *teams;
	string place, place_link, tmp;
	int i, stop;

	me = this_player();
	stop = 0;

	if ( !stringp(place = me->query_temp("xyzx_team/name")) ) 
	{
		tell_object(me, "�㻹û�ж��飬ֻ�ж�����ܽ��븱����\n");
		return 1;
	}
	if ( !me->query_temp("xyzx_team/zhang") ) 
	{
		if ( VRM_SERVER->valid_place_name(place) )
		{
			tell_object(me, "�㲻�Ƕӳ���ֻ�ж���ӳ����ܴ���������\n");
			return 1;
		}
	}
	else
	{
		if ( VRM_SERVER->valid_place_name(place) )
		{
			teams = TEAMD->get_team_member(me);
			if ( me->query("vrm_in_busy") > time() )
			{
				message("party", HIR"��"HIM"��������"HIR"��"HIW"���ڶӳ��ϴθ�������ʧ�ܣ�ʮ��������޷��ٴ���������\n"NOR, teams);
				return 1;
			}
			if ( VRM_SERVER->make_check_user(me, 3) )
			{
				message("party", HIM"��"HIG"��������"HIM"��"HIW"���ڶӳ� IP �����Ѿ�������һ���������޷��ټ���������һ��������\n"NOR, teams);
				return 1;
			}
			tmp = HIW"���ڶ����Ա( "HIY;
			for ( i=0; i<sizeof(teams); i++ )
			{
				if ( objectp(teams[i]) )
				{
					if ( teams[i]->query("vrm_in_busy") > time() )
					{
						tmp += teams[i]->query("id") + " ";
						stop = 1;
					}
				}
			}
			tmp += HIW")�ϴθ�������ʧ�ܣ�ʮ������޷��ٽ��븱������������ʧ�ܡ�\n";
			if ( stop )
			{
				message("party", HIR"��"HIM"��������"HIR"��"+tmp+NOR, teams);
				return 1;
			}
			VRM_SERVER->make_check_user(me, 1);	
            me->set("vrm_in_busy", time()+900);// ������ �ڸ����� ��ɢ���飬��������			
			//message("party", HBBLU+HIR"��"HIY"��������"HIR"��"HIW"����["HIM+place+HIW"]������һ����������ʼ����ž�֮ɭ��\n"NOR, users());
			message("party", HBBLU+HIR"��"HIY"��������"HIR"��"HIW"����["HIM+place+HIW"]������һ����������ʼ����ž�֮ɭ��\n"NOR, teams);
		}
	}
	place_link = sprintf("%s/%s/entry", VRM_SERVER, place);
	ob = find_object(place_link);
	if ( !ob ) ob = load_object(place_link);
	me->move(ob);
	return 1;
}

int in_new_virtual_map()
{
	object me, ob;
	string place;

	me = this_player();
	
	if ( me->query("xyzx_sys/level") < 100 )
	{
		place = sprintf("%s/new/entry", VRM_SERVER);
		ob = find_object(place);
		if ( !ob ) ob = load_object(place);
		me->move(ob);
	}
	else
		tell_object(me, "���ڽ��������ǵ¸����أ�����Ҫ�ٽ������ָ����ˡ�\n");
	return 1;
}

// ���ָֻ�
int full_all()
{
	object me, ob;
	int max;
	
	me = this_object();
	ob = this_player();

	//ֻ���ŵȼ�������1000��������С��18��ĵ�ID
	if ( ob->query("xyhy_type")!=2 && ob->query("age") > 17 && ob->query("xyzx_sys/level") > 2000 )
	{
		command("say ���Ѿ�����������Ү����Ҫ�����չ����ѽ��\n");
		return 1;
	}

	max = ob->query("max_jing");
	ob->receive_curing("jing", max);
	ob->receive_heal("jing", max);
	max = ob->query("max_qi");
	ob->receive_curing("qi", max);
	ob->receive_heal("qi", max);
	max = ob->query("max_neili");
	if ( ob->query("xyhy_type") == 2 )
		ob->set("neili", max*2);
	else
		ob->set("neili", max);
	max = ob->query("max_jingli");
	if ( ob->query("xyhy_type") == 2 )
		ob->set("jingli", max*2);
	else
		ob->set("jingli", max);
	ob->set("food", ob->max_food_capacity());
	ob->set("water", ob->max_water_capacity());
	message_vision(CYN "����Ц���������ֳ�$Nһ���������������������� \n" NOR,ob);
	return 1;
}