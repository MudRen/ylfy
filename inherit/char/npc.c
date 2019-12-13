// NPC���ܻ� 

#include <command.h>
#include <weapon.h>
inherit CHARACTER;

// ���Ӷ�̬�����Ψһ�Լ�顣ע�⣺Ϊ�˲�����ϵͳ��Դ�����ģ���
// �ﲻ��ȫ��������飬����ؽ���̬�������������
varargs object carry_object(string file, int m)
{
	object ob, obj, *inv;
	int i;
	
	if( !objectp(ob = new(file)) )
		return 0;
	
	if ( !m || m == 0 )
	{
		if (obj=present(ob->query("id"), this_object()))
		{
			destruct(ob);
			return obj;
		}
	}
	else if ( m == 1 )
	{
		inv = all_inventory(this_object());
		for (i = 0; i < sizeof(inv); i++)
		{
			if ( base_name(ob) == base_name(inv[i]) )
			{
				destruct(ob);
				return inv[i];
			}
		}
	}
	
	ob->move(this_object());
	return ob;
}

object add_money(string type, int amount)
{
	object ob;
	
	ob = carry_object("/clone/money/" + type);
	
	if( !ob )
		return 0;
	
	ob->set_amount(amount);
}

int accept_fight(object who)
{
	string att;
	
	att = query("attitude");
	
	if( is_fighting() )
	switch(att)
	{
		case "heroism":
			command("say �ߣ����аɣ�\n");
		break;
		
		default:
			command("say ���ж�Ϊʤ���ⲻ������̫����\n");
		return 0;
	}
	
	if( (int)query("jing") * 100 / (int)query("max_jing") >= 90 
		&& (int)query("qi") * 100 / (int)query("max_qi") >= 90 )
	{
		switch(att)
		{
			case "friendly":
				command("say " + RANK_D->query_self(this_object()) + 
				"��ô������" + RANK_D->query_respect(who) + 
				"�Ķ��֣�\n");
			return 0;
			
			case "aggressive":
			case "killer":
				command("say �ߣ����аɣ�\n");
			break;
			
			default:
			if( !is_fighting() )
				command("say ��Ȼ" + RANK_D->query_respect(who) + 
				"�ͽ̣�" + RANK_D->query_self(this_object()) + 
				"ֻ�÷��㡣\n");
		}	
		return 1;
	}
	else
		return 0;
}

int return_home(object home)
{
	object ob = this_object();
	mapping exits;

	if ( !objectp(ob) || !clonep(ob) || !objectp(home) ) return 0;
	
	//�޻�����
	if( !objectp(environment()) )
	{
		destruct(this_object()); // �޻�����ֱ�������
		return 1;
	}
	
	exits = environment()->query("exits");
	
	// Are we able to leave?
	if( !living(ob) 
		|| is_fighting() 
		|| !mapp(exits) 
		|| !sizeof(exits) )
	{
		/*remove_call_out("return_home");
		call_out("return_home",20,home);*/ // ע�͵������ֻ�� reset ʱִ��һ�Ρ�
		return 0; // �����ﷵ��0�����������ã�����ʱ���ܻ�ȥ��room��������
    }
	
	ob->set("water",ob->max_water_capacity());
	ob->set("food",ob->max_food_capacity());
	ob->create();
	
	//�Զ��ؼ�
	if ( environment()!=home )
	{
		message("vision", ob->name() + "����ææ���뿪�ˡ�\n", environment(), this_object());
		message("vision", ob->name() + "���˹�����\n", home, ob);
		return move(home);
	}
	
	return 1;
}

// ��home��NPC�ָ�״̬
int full_home_npc(object home)
{
	object ob = this_object();
	
	if ( !objectp(ob) || !clonep(ob) ) return 0;
	
	//�޻�����
	if( !objectp(environment()) )
	{
		destruct(this_object()); // �޻�����ֱ�������
		return 0;
	}
	
	if( !living(ob) || is_fighting() )
	{
		/*remove_call_out("full_home_npc");
		call_out("full_home_npc",20,home);*/ // ע�͵������ֻ�� reset ʱִ��һ�Ρ�
		return 0;
    }
	
	ob->set("water",ob->max_water_capacity());
	ob->set("food",ob->max_food_capacity());
	ob->create();
	
	return 1;
}

//��������
int chat()
{
	string *msg;
	int chance, rnd;
	
	if( !environment() || !living(this_object()) ) return 0;
	if( is_busy() ) return 0;
	//���⶯�����ʱ�ʶ
	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;
	
	//ָ�����⶯��
	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) 
	{
		if( random(100) < chance )
		{
			rnd = random(sizeof(msg));
			
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}
}

//�����ƶ�
int random_move()
{
	object ob, env;
	mapping exits;
	string *dirs;
	
	if ( !objectp(env=environment()) || !living(this_object()) 
             || is_busy() || is_fighting()) return 0;
	if ( objectp(ob==this_object()->query_leader()) ) 
	{
		command("follow none");
		return 0;
	}
	if ( !mapp(exits = environment()->query("exits")) || !sizeof(exits) ) return 0;
	
	dirs = keys(exits);
	
     if (!dirs)  return 0;
	command("go " + dirs[random(sizeof(dirs))]);
	return 1;
}

//����ʩΪ
void cast_spell(string spell)
{
	string spell_skill;
	
	if( !environment() || !living(this_object()) )
		return;
	
	if( stringp(spell_skill = query_skill_mapped("spells")))
		SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

//�ڹ�����
int exert_function(string func)
{
        string force_skill;

        if( !environment() || !living(this_object()) ) return 0;
        if( !stringp(force_skill = query_skill_mapped("force")) )
                return 0;
        if( this_object()->query_condition("no_exert") )
                return 0;

        if( SKILL_D(force_skill)->exert_function(this_object(), func) )
                return 1;

        return SKILL_D("force")->exert_function(this_object(), func);
}

//�����⹦ʹ��
int perform_action(string action)
{
        string martial_skill, act;

        if( !environment() || !living(this_object()) ) return 0;
		
        if( this_object()->query_condition("no_perform") ) return 0;
		
        if( !stringp(action))   return 0;
		
        if( sscanf(action, "%s.%s", martial_skill, act) != 2 ) return 0;
		
        martial_skill = query_skill_mapped(martial_skill);
        if( stringp(martial_skill) )
                return SKILL_D(martial_skill)->perform_action(this_object(), act);
}

//��ʦ
void attempt_apprentice(object ob)
{
    command("sigh "+ob->query("id"));
    command("say "+RANK_D->query_self(this_object())+"����ѧǳ�����������ӵܣ���λ"+RANK_D->query_respect(ob)+"��ı�߾Ͱɣ�");
}

// Here, the NPC will process the heal/recover.
int heal_self()
{
	object me;
	mapping my;
	string skill;
	me = this_object();

	if ( !environment() || !living(me) ) return 0;
	if ( is_busy() || is_fighting() ) return 0;
	if ( me->query_skill("force", 1) < 100 ) return 0;
	if ( me->query("neili") < 50 ) return 0;
    if (query_temp("no_exert")) return 0;  // ���������ֹʹ���ڹ�
                
	my = query_entire_dbase();

	if ( my["eff_jing"] && my["jing"] * 10 / my["eff_jing"] < 8 )
	{ // �ָ�����
		me->command("exert regenerate");
		return 1;
	}

	if ( my["eff_qi"] && my["qi"] * 10 / my["eff_qi"] < 8 )
	{ // �ָ���Ѫ
		me->command("exert recover");
		return 1;
	}

	if ( !stringp(skill = me->query_skill_mapped("force")) ) return 0;
	if ( me->query_skill(skill, 1) < 100 ) return 0;

	if (my["eff_jing"] < my["max_jing"] && my["eff_qi"] > my["max_qi"]/2 )
	{ // ���˾���
		me->command("exert jingheal");
		return 1;
	}
	if ( my["eff_qi"] < my["max_qi"] )
	{ // ������Ѫ
		 me->command("exert heal");
		return 1;
	}
    if ( my["neili"] < my["max_neili"]/10 )
	{ // ����
		me->command("exercise "+(my["qi"]/10));
		return 1;
	}
	return 0;
}

/*void recover()
{
        mapping p;

        clear_condition(0);
        p = query_entire_dbase();
        p["eff_qi"] = p["max_qi"];
        p["qi" ] = p["max_qi"];
        p["eff_jing"] = p["max_jing"];
        p["jing" ] = p["max_jing"];
}*/