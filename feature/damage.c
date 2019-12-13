
#include <dbase.h>
#include <login.h>
#include <move.h>
#define PVP_DAMAGE_SCALE        1
#define PVP_WOUND_SCALE         2

inherit F_TOMUD;
private nosave int counter=0;
int ghost = 0;

int is_ghost()
{
	return ghost;
}

varargs void die(int);

varargs int receive_damage(string type, int damage, object who)
{
	int val, lianzhao;
	
	if( damage < 0 )
	{
		damage = 0;
		error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	}

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query(type) - damage;

	if( val >= 0 )
		set(type, val);
	else
		set( type, -1 );
    if (!query_heart_beat())
	set_heart_beat(1);
	//��Щ���ܵ�perform�����receive_damage����ûָ����������������ûָ���˺�ʵʩ��
	if(!objectp(who))
		who = query_temp("last_perform_by");
	delete_temp("last_perform_by");
	if( who && playerp(who) && playerp(this_object()) &&this_object()->is_fighting(who) )
	{
		damage = (int)damage * PVP_DAMAGE_SCALE / 100;
	}
	if(who && who->query_temp("lianzhao") > 10 && playerp(who) )//�����������̫�ߵ�����
	{
	lianzhao = (int)who->query_temp("lianzhao");
	damage = (int)damage * (lianzhao / 10);
	}
	if( objectp(who) )
	{
		set_temp("last_damage_from", who);

		if ( who->query("env/myhp_show") && !who->query("xieyi/zmud") )
			tell_object(who, my_hp(who, this_object()));
	}

	if ( damage > 0 && query("env/myhp_show") && !query("xieyi/zmud") )
		tell_object(this_object(), my_hp(this_object(), who));

	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
	int val, lianzhao;
	
	if( damage < 0 )
	{
		damage = 0;
		error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	}

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query("eff_" + type) - damage;

	if( val >= 0 )
		set("eff_" + type, val);
	else
	{
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val )
		set(type, val);
    if (!query_heart_beat())
	set_heart_beat(1);
	if( who && playerp(who) && playerp(this_object()) && this_object()->is_fighting(who) )
	{
		damage = (int)damage * PVP_DAMAGE_SCALE / 100;
	}
	if(who && who->query_temp("lianzhao") > 10 && playerp(who))//�����������̫�ߵ�����
	{
	lianzhao = (int)who->query_temp("lianzhao");
	damage = (int)damage * (lianzhao / 10);
	}
	//��Щ���ܵ�perform�����receive_wound����ûָ����������������ûָ���˺�ʵʩ��
    if(!objectp(who))
		who = query_temp("last_perform_by");
	delete_temp("last_perform_by");
	if( objectp(who) )
	{
		set_temp("last_damage_from", who);

		if ( who->query("env/myhp_show") && !who->query("xieyi/zmud") )
			tell_object(who, my_hp(who, this_object()));
	}

	if ( damage > 0 && query("env/myhp_show") && !query("xieyi/zmud") )
		tell_object(this_object(), my_hp(this_object(), who));
    
	
	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 )
		error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) )
		set(type, (int)query("eff_" + type));
	else
		set( type, val );

	if ( query("env/myhp_show") && !query("xieyi/zmud") )
		tell_object(this_object(), my_hp(this_object()));

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 )
		error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");

	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max )
	{
		set("eff_" + type, max);

		if ( query("env/myhp_show") && !query("xieyi/zmud") )
			tell_object(this_object(), my_hp(this_object()));

		return max - val;
	}
	else
	{
		set( "eff_" + type, val + heal);

		if ( query("env/myhp_show") && !query("xieyi/zmud") )
			tell_object(this_object(), my_hp(this_object()));

		return heal;
	}
}

void unconcious()
{
	object defeater;
	int con;

	if( !living(this_object()) )
		return;

	if( wizardp(this_object()) && query("env/immortal") )
		return;

	if (is_ghost())
	{
		die();
		return;
	}

	if ( !userp(this_object()) )
	{
		if ( function_exists("do_deposit", this_object()) || function_exists("do_sell", this_object()) )
		{
			this_object()->set("no_put", 1);
		}
	}

	if( objectp(defeater = query_temp("last_damage_from")) )
		COMBAT_D->winner_reward(defeater, this_object());

	this_object()->remove_all_enemy();
	set("hunmi",1);
	message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,this_object());
	this_object()->disable_player(" <���Բ���>");
	set("jingli", 0);
	set("neili", 0);
	set("jing", 0);
	set("qi", 0);

	if ( query("env/myhp_show") && !query("xieyi/zmud") )
		tell_object(this_object(), my_hp(this_object()));

	set_temp("block_msg/all",1);
	COMBAT_D->announce(this_object(), "unconcious");

	//����ʱ��
	con = random(100 - this_object()->query_con()) + 20;

	if ( con > 90 )
		con = 90;

	if ( con < 1 )
		con = 1;

	call_out("revive",con);
}

varargs void revive(int quiet)
{
	remove_call_out("revive");
	this_object()->enable_player();

	if (userp(this_object()))
	{
		delete("no_get");
		delete("no_get_from");
	}

	if ( !query_temp("block_msg/all") )
		set_temp("block_msg/all", 1);

	while( environment()->is_character() || environment()->is_container())
		this_object()->move(environment(environment()));

	//���������������ִ�᳡�����ٸ�NPC
	if(!userp(this_object()))
	{
		if( file_name(environment()) == "/d/wizard/fightroom2"
		        || file_name(environment()) == "/d/city/wumiao"
		        || file_name(environment()) == "/d/wizard/fightroom3" )
			destruct(this_object());
	}

	if ( !objectp(this_object()) ) return;

	if( !quiet )
	{
		COMBAT_D->announce(this_object(), "revive");
		set("hunmi",0);
		delete_temp("block_msg");
		message_vision(HIY "\n������$N����������֪��....\n\n"NOR,this_object() );
		delete_temp("last_unconcious_from");
	}

	if ( this_object()->query_temp("temp_no_die") )
		this_object()->delete_temp("temp_no_die");//�����̨��������

	if ( !this_object()->is_busy() )
		this_object()->start_busy(1);//����Busy

	if ( query_temp("block_msg/all") )
		delete_temp("block_msg");

	if ( query("env/myhp_show") && !query("xieyi/zmud") )
		tell_object(this_object(), my_hp(this_object()));
}

varargs void die(int flag)
{
	object corpse, killer, victim, env;
	int add_exp, ob_levl_1 = 0;
	mapping quest;

	if( !living(this_object()) )
		revive(1);

	if( wizardp(this_object()) && query("env/immortal") )
		return;

	// ��̨���Բ���
	if ( playerp(this_object()) )
	{
		//��̨���䲻��
		if ( !flag
		        && !this_object()->query_condition("killer")
		        && (this_object()->query_temp("temp_no_die")
		            || file_name(environment(this_object())) == "/d/wizard/fightroom2"
		            || file_name(environment(this_object())) == "/d/wizard/fightroom3") )//�Ļ�ԭ���ģ�����̨����ط�����
		{
			if(this_object()->query("qi") < 0)
				this_object()->set("qi",0);

			if(this_object()->query("eff_qi") < 0)
				this_object()->set("eff_qi",0);

			if(this_object()->query("jing") < 0)
				this_object()->set("jing",0);

			if(this_object()->query("eff_jing") < 0)
				this_object()->set("eff_jing",0);

			if ( query("env/myhp_show") && !query("xieyi/zmud") )
				tell_object(this_object(), my_hp(this_object()));
			return;
		}
	}

	if (objectp(previous_object()))
		if( !SECURITY_D->valid_set( this_object(), previous_object()) )
			return;

	if ( !playerp(this_object()) )
	{
		if ( function_exists("do_deposit", this_object()) || function_exists("do_sell", this_object()) )
		{
			message_vision(HIW"\n$N����������ȥ���ȳ��������ʧ����....\n\n" NOR, this_object());
			destruct(this_object());
			return;
		}
	}

	ob_levl_1 = this_object()->query("xyzx_sys/level");

	if ( playerp(this_object()) && this_object()->is_ghost() )
	{
		message_vision(HIC "����û�а취����һ�Ρ�\n" NOR, this_object());
		message_vision(HIG "$N�Ļ��ǻص������䡣\n" NOR, this_object());
		this_object()->set("jing", 1);
		this_object()->set("eff_jing", 1);
		this_object()->set("qi", 1);
		this_object()->set("eff_qi", 1);
		this_object()->set("neili", 0);
		this_object()->set("jingli", 0);
		if(!environment(this_object()) || strsrch(base_name(environment(this_object())),"/d/death/")!=0)
			this_object()->move("/d/death/gate");
		this_object()->clear_condition(1);	
        this_object()->remove_all_killer();//������г��
        all_inventory(environment(this_object()))->remove_killer(this_object());//������
        this_object()->dismiss_team();//����Ŷ�ս�����
		return;
	}

	COMBAT_D->announce(this_object(), "dead");
	victim = this_object();

	if ( !objectp(killer = query_temp("last_damage_from")) )
		killer = query_temp("last_unconcious_from");

	if( objectp(killer) )
	{
		set_temp("my_killer", killer->query("id"));

		if ( !playerp(victim) && playerp(killer) && mapp(quest = killer->query("quest")) )
		{
			if ( quest["quest_type"] == "ɱ" && quest["quest"]==victim->short() )
			{
				if( quest["task_time"] >  time() )
				{
					add_exp = victim->query("combat_exp")/1000+40;

					if (add_exp>250)
						add_exp=250;

					add_exp = quest["diff"]*add_exp+1;

					if( !(killer->query_temp("quest_count")%8) )
						add_exp*=2;

					add_exp = (add_exp/3+1)*8/5;
					tell_object(killer, sprintf(HIR"��ϲ�㣡���������һ������\n������%s��ս�����飡\n", chinese_number(add_exp*killer->query_exp_times())) );
					killer->add("combat_exp", add_exp);
					add_exp = random(add_exp) +1;
					tell_object(killer, sprintf(YEL"%s��Ǳ�ܣ�\n"NOR,chinese_number(add_exp)) );
					killer->add("potential",add_exp);
					add_exp=random(add_exp)/2+20;
					tell_object(killer,sprintf(RED"��������������%s��!\n"NOR,chinese_number(add_exp)) );
					killer->add("score",add_exp);
					killer->delete("quest");
				}
				else
				{
					killer->set("quest_failed",(int)killer->query("quest/task_time") + (int)killer->query("quest/time"));

					if( time() >= killer->query("quest_failed") )
					{
						killer->delete_temp("quest_count");
						killer->delete("quest_failed");
					}

					tell_object(killer, YEL"��û���ڹ涨ʱ�������������������ʧ���ˣ�\n"NOR);
					killer->delete_temp("count");
					killer->delete("quest");
				}
			}
			else
				COMBAT_D->killer_reward(killer, this_object());
		}
		else
			COMBAT_D->killer_reward(killer, this_object());
	}
	else
		COMBAT_D->die_for(this_object());

	if ( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());

	this_object()->remove_all_killer();//������г��
	all_inventory(environment(this_object()))->remove_killer(this_object());//������
	this_object()->dismiss_team();//����Ŷ�ս�����

	//����ж�״̬
	this_object()->clear_condition(1);

	if( playerp(this_object()) )
	{
		env = environment(this_object());

		if (this_object()->is_busy())
			this_object()->interrupt_me();

		set("jing", 1);
		set("neili", 0);
		set("jingli", 0);
		set("eff_jing", 1);
		set("qi", 1);
		set("eff_qi", 1);
		ghost = 1;
		delete_temp("last_unconcious_from");//��������μ�¼���˺��߼�¼��С�׺�С�������������������ԭ��
		this_object()->move(DEATH_ROOM);
		//DEATH_ROOM->start_death(this_object());//��֪����������Ǹ����õģ�ϵͳ��Ҳ�Ҳ����������

		if ( query("env/myhp_show") && !query("xieyi/zmud") )
			tell_object(this_object(), my_hp(this_object()));
	}
	else
		destruct(this_object());
}

void reincarnate()
{
	if ( !ghost )
		return;

	ghost = 0;
	set("eff_jing", query("max_jing"));
	this_object()->start_busy(0);
	set("eff_qi", query("max_qi"));
	UPDATE_D->check_user(this_object());
	if ( query("env/myhp_show") && !query("xieyi/zmud") )
		tell_object(this_object(), my_hp(this_object()));
}

int max_food_capacity()
{
	return query_weight() / 200;
}

int max_water_capacity()
{
	return query_weight() / 200;
}

int heal_up()
{
	int update_flag;
	mapping my;
	object me;
	me = this_object();

	if ( ghost && userp(this_object()) )
	{
		set("eff_qi",1);

		if ( query("env/myhp_show") && !query("xieyi/zmud") )
			tell_object(this_object(), my_hp(this_object()));

		return -1;
	}

	if (environment() && environment()->query("freeze")) 
		return -1;

	update_flag = 0;
	my = query_entire_dbase();

	counter++;
	if( my["water"] > 0 && counter >= 5 )
	{
		my["water"] -= 1;
		update_flag++;
	}

	if( my["food"] > 0 && counter >= 5 )
	{
		my["food"] -= 1;
		update_flag++;
	}

	if(counter>=5) counter=0;

	if ( userp(me) )
	{
		if( my["water"] < 1 || my["food"] < 1 )
		{
			if (my["jing"] > 0)
				my["jing"] -= my["max_jing"]/10;

			if ( living(me) )
			{
				if ( my["food"] < 1 )
					tell_object(this_object(),YEL "���Ѿ�����ͷ���ۻ��ˣ�\n" NOR);

				if ( my["water"] < 1 )
					tell_object(this_object(),YEL "���Ѿ��ʵú�������ð�������ˣ�\n" NOR);
			}
			else
				me->set_temp("die_for","��");

			if ( query("env/myhp_show") && !query("xieyi/zmud") )
				tell_object(this_object(), my_hp(this_object()));

			return update_flag;
		}
	}

	if( userp(me) && me->is_fighting())
		return -1;

	my["jing"] += me->query_con() / 3 + my["max_jingli"] / 10;

	if( my["jing"] >= my["eff_jing"] )
	{
		my["jing"] = my["eff_jing"];

		if( my["eff_jing"] < my["max_jing"] )
		{
			my["eff_jing"] ++;
			update_flag++;
		}
	}
	else update_flag++;

	my["qi"] += me->query_con()  / 3 + my["max_neili"] / 10;

	if( my["qi"] >= my["eff_qi"] )
	{
		my["qi"] = my["eff_qi"];

		if( my["eff_qi"] < my["max_qi"] )
		{
			my["eff_qi"] ++;
			update_flag++;
		}
	}
	else update_flag++;

	if( my["max_jingli"] && my["jingli"] < my["max_jingli"] )
	{
		if (userp(me))
			my["jingli"] += (int)me->query_skill("taoism", 1) / 2;
		else
			my["jingli"] += my["max_jingli"] / 5;

		if( my["jingli"] > my["max_jingli"] )
			my["jingli"] = my["max_jingli"];

		update_flag++;
	}

	if( my["max_neili"] && my["neili"] < my["max_neili"] )
	{
		my["neili"] += (int)me->query_skill("force", 1) / 2;

		if( my["neili"] > my["max_neili"] )
			my["neili"] = my["max_neili"];

		update_flag++;
	}

	if ( query("env/myhp_show") && !query("xieyi/zmud") )
		tell_object(this_object(), my_hp(this_object()));

	return update_flag;
}
