// attack.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT    4

//inherit F_TOMUD;

nosave object *enemy = ({});
nosave object *killer = ({});
nosave object *att_killer = ({});
        // ���������ĵ���
// prototypes
object *query_enemy() 
{
	if ( !arrayp(enemy) ) enemy = ({});
	return enemy;
}
object *query_killer() 
{ 
	if ( !arrayp(killer) ) killer = ({});
	return killer;
}
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;
	return member_array(ob, enemy)!=-1;
}
// �ж��Ƿ���������ĳ��ob
varargs int is_att_killing(object ob)
{
	if( !ob ) return sizeof(att_killer) > 0;
	return member_array(ob, att_killer)!=-1;
}
// ��������,����Ҳ���Ч
void att_kill_ob(object ob)
{
	 string uid, mid;
     object me=this_object();

    if ( !ob || ob==this_object() ) return;
    if ( !living(this_object()) )  return;
    if ( environment()->query("no_fight") ) return;
    if ( !userp(ob) || !userp(this_object()) ) return;

    if( member_array(ob, att_killer)==-1 )
		att_killer += ({ ob });

	mid = query("id");
	uid = ob->query("id");
	if ( playerp(me) && playerp(ob) 
		&& !me->is_fighting(ob) 
		&& !ob->is_fightingo(me) 
		&& base_name(environment())!="/d/wizard/fightroom3" ) 
	{
		if ( !query_temp("other_kill/"+uid) ) 
		{
			set_temp("kill_other/"+uid, 1);
			ob->set_temp("other_kill/"+mid, 1);
		} 
		else 
			ob->set_temp("kill_other/"+mid, 1);
	}

	me->fight_ob(ob);

	if ( me->query("env/myhp_show") && !me->query("xieyi/zmud") )
		tell_object(me, me->my_hp(me, ob));
	if ( ob->query("env/myhp_show") && !ob->query("xieyi/zmud") )
		tell_object(ob, me->my_hp(ob, me));
}
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(object ob)
{
	if( !ob ) return sizeof(killer) > 0;
	return member_array(ob, killer)!=-1;
}
//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	string uid, mid;
	int no_msg;
    object me=this_object();
    object env;
	
    if(!ob || ob==this_object()) return;
    if( member_array(ob, enemy) != -1 ) return;
    
    if( !living(this_object()) ) return;
    
    env = environment();
    if( environment(ob) != env || env->query("no_fight") ) return;
	if ( playerp(this_object()) && !playerp(ob) )
	{
		if ( no_msg=this_object()->query("env/no_combat_msg") )
			ob->set("env/no_combat_msg", no_msg);
		else
			ob->delete("env/no_combat_msg");
	}
	if ( !playerp(this_object()) && playerp(ob) )
	{
		if ( no_msg=ob->query("env/no_combat_msg") )
			this_object()->set("env/no_combat_msg", no_msg);
		else
			this_object()->delete("env/no_combat_msg");
	}

    set_heart_beat(1);

	mid = query("id");
	uid = ob->query("id");
	if ( playerp(me) && playerp(ob) 
		&& !me->is_fighting(ob) 
		&& !ob->is_fightingo(me) 
		&& base_name(environment())!="/d/wizard/fightroom3" ) 
	{
		if (!query_temp("other_kill/"+uid)) 
		{
			set_temp("kill_other/"+uid, 1);
			ob->set_temp("other_kill/"+mid, 1);
		} 
		else 
			ob->set_temp("kill_other/"+mid, 1);
	}

	if( member_array(ob, enemy)==-1 )
		enemy += ({ ob });
	if( member_array(this_object(), ob->query_enemy())==-1 )
		ob->fight_ob(this_object());

	if ( me->query("env/myhp_show") && !me->query("xieyi/zmud") )
		tell_object(me, me->my_hp(me, ob));
	if ( ob->query("env/myhp_show") && !ob->query("xieyi/zmud") )
		tell_object(ob, me->my_hp(ob, me));
}
// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
	 string uid, mid;
	 int no_msg;
	 object env;
     object me=this_object();

    if(!ob || ob==this_object()) return;
    if (!living(this_object()))  return;
	if( !living(me) ) return;

    env = environment();
    if( environment(ob) != env || env->query("no_fight") )return;

    if( ob->is_ghost() || me->is_ghost() ) return;
    if (environment()->query("no_fight") && !this_object()->query("demogorgon") ) return;

	if ( playerp(this_object()) && !playerp(ob) )
	{
		if ( no_msg=this_object()->query("env/no_combat_msg") )
			ob->set("env/no_combat_msg", no_msg);
		else
			ob->delete("env/no_combat_msg");
	}
	if ( !playerp(this_object()) && playerp(ob) )
	{
		if ( no_msg=ob->query("env/no_combat_msg") )
			this_object()->set("env/no_combat_msg", no_msg);
		else
			this_object()->delete("env/no_combat_msg");
	}

	mid = query("id");
	uid = ob->query("id");
	if ( playerp(me) && playerp(ob) 
		&& !me->is_fighting(ob) 
		&& !ob->is_fightingo(me) 
		&& base_name(environment())!="/d/wizard/fightroom3" ) 
	{
		if (!query_temp("other_kill/"+uid)) 
		{
			set_temp("kill_other/"+uid, 1);
			ob->set_temp("other_kill/"+mid, 1);
		} 
		else 
			ob->set_temp("kill_other/"+mid, 1);
	}

	if( member_array(ob, killer)==-1 )
        killer += ({ ob });

	if (environment(me)==environment(ob))
		tell_object(ob, HIR "������" + this_object()->name() + HIR + "��ɱ���㣡\n" NOR);
	fight_ob(ob);

	if ( me->query("env/myhp_show") && !me->query("xieyi/zmud") )
		tell_object(me, me->my_hp(me, ob));
	if ( ob->query("env/myhp_show") && !ob->query("xieyi/zmud") )
		tell_object(ob, me->my_hp(ob, me));
}

void clean_up_enemy()
{
    if( sizeof(enemy) > 0 ) 
	{
        for(int i=0; i<sizeof(enemy); i++) 
		{
            if( !objectp(enemy[i])
            ||  environment(enemy[i])!=environment()
            ||  (!living(enemy[i]) && !is_killing(enemy[i])) )
                enemy[i] = 0;
        }
        enemy -= ({ 0 });
    }
}
// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
    int which, max;

    if( !(max = sizeof(enemy)) ) return 0;
	which = random(max);
    return max < MAX_OPPONENT ? enemy[which] : enemy[0];
}
// Stop fighting ob.
int remove_enemy(object ob)
{
	object me;

	me = this_object();

    if ( !ob ) return 0;
	//________________BOSS��ȫ���ս���ظ�״̬______________
	if ( sizeof(enemy)==1 
		&& member_array(ob, enemy) != -1 
		&& environment()!=environment(ob) )
	{
		if ( living(me) && (me->query("end_boss") || me->query("is_boss")) )
			me->create();
		if ( living(ob) && (ob->query("end_boss") || ob->query("is_boss")) )
			ob->create();
		// ȥ��״̬������־
		me->delete_temp("fight_killer_id"); 
		ob->delete_temp("fight_killer_id");
	}
	//__________________________End_________________________
    if( is_killing(ob) ) return 0;
    enemy -= ({ ob });
	/*this_object()->delete_temp("kill_other");
	this_object()->delete_temp("other_kill");
	ob->delete_temp("kill_other");
	ob->delete_temp("other_kill");*/
    return 1;
}
// Stop killing ob.
int remove_killer(object ob)
{
    if( is_killing(ob) ) {
        killer -= ({ ob });
        remove_enemy(ob);
        return 1;
    }
    return remove_enemy(ob);
}
// Stop all fighting, but killer remains.
varargs void remove_all_enemy(int flag)
{
	object me, env;
	string room;

	me = this_object();
    me->delete_temp("last_perform_by");
    for ( int i=0; i<sizeof(enemy); i++ ) 
	{
		// �����̨��������������
		//___________________start_____________________________________
		env = environment();
		if ( env 
			&& ((room=base_name(env))=="/d/wizard/fightroom3" 
				|| room=="/d/wizard/fightroom2") )
		{
			me->delete_temp("kill_other");
			me->delete_temp("other_kill");
		}
		if ( flag )
		{
			me->delete_temp("kill_other");
			me->delete_temp("other_kill");
			me->delete_temp("last_unconcious_from");
			me->delete_temp("last_damage_from");
		}
		if ( objectp(enemy[i]) )
		{
			env = environment(enemy[i]);
			if ( env 
				&& ((room=base_name(env))=="/d/wizard/fightroom3" 
					|| room=="/d/wizard/fightroom2") )
			{
				enemy[i]->delete_temp("kill_other");
				enemy[i]->delete_temp("other_kill");
			}
			if ( flag )
			{
				enemy[i]->delete_temp("kill_other");
				enemy[i]->delete_temp("other_kill");
				enemy[i]->delete_temp("last_unconcious_from");
				enemy[i]->delete_temp("last_damage_from");
			}
		//__________________end________________________________________
			if ( (enemy[i]->query("end_boss") || enemy[i]->query("is_boss")) 
				&& environment(enemy[i])==env ) continue;
        // We ask our enemy to stop fight, but not nessessary to confirm
        // if the fight is succeffully stopped, bcz the fight will start
        // again if our enemy keeping call COMBAT_D->fight() on us.
			enemy[i]->remove_enemy(me);
			enemy[i] = 0;
		}
    }
    enemy = ({});
}
// Stop all fighting and killing.
varargs void remove_all_killer(int wiz)
{
	int i, is_boss;

	is_boss = 0;
	att_killer = ({});
    
    for ( i=0; i<sizeof(enemy); i++ )
	{
		if ( !objectp(enemy[i]) )
		{
			killer -= ({ enemy[i] });
			enemy -= ({ enemy[i] });
			continue;
		}

		/*this_object()->delete_temp("kill_other");
		this_object()->delete_temp("other_kill");
		enemy[i]->delete_temp("kill_other");
		enemy[i]->delete_temp("other_kill");*/

		// boss�޷�������
		if ( !wiz && environment(enemy[i]) == environment() )
		{
			if ( enemy[i]->query("end_boss") || enemy[i]->query("is_boss") )
			{
				is_boss = 1;
				continue;
			}
		}
		// �������
        if ( enemy[i]->query_leader()==this_object() )
            enemy[i]->set_leader(0);
        if( enemy[i]->remove_killer(this_object()) )
		{
			killer -= ({ enemy[i] });
			enemy -= ({ enemy[i] });
		}
    }
	if ( !is_boss )
	{
		killer = ({ });
		enemy -= ({ 0 });
	}
}
// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	mapping prepare;
    object me,ob;
    string type, skill;
    
	me = this_object();
	prepare = query_skill_prepare();
    
	if ( query_temp("secondly_weapon") )
	{
		if ( objectp(ob = query_temp("secondary_weapon")) ) type = ob->query("skill_type");
		else if (! prepare || sizeof(prepare) == 0) type = "unarmed";
		else if (sizeof(prepare) == 1) type = (keys(prepare))[0];
		else if (sizeof(prepare) == 2) type = (keys(prepare))[query_temp("action_flag")];
	}
	else
	{
		if ( objectp(ob = query_temp("weapon")) ) type = ob->query("skill_type");
		else if (! prepare || sizeof(prepare) == 0) type = "unarmed";
		else if (sizeof(prepare) == 1) type = (keys(prepare))[0];
		else if (sizeof(prepare) == 2) type = (keys(prepare))[query_temp("action_flag")];
	}
    
    if( stringp(skill = query_skill_mapped(type)) ) 
	{
        // If using a mapped skill, call the skill daemon.
        if ( ob )
             set("actions", (: call_other, SKILL_D(skill), "query_action", me, ob :) );
        else
             set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
    } 
	else 
	{
        // Else, let weapon handle it.
        if( ob ) 
			set("actions", ob->query("actions", 1) );
        else 
			set("actions", query("default_actions", 1) );
    }
}
// This is called in heart_beat() to perform attack action.
int attack()
{
    object opponent;
    clean_up_enemy();
    opponent = select_opponent();
    if( objectp(opponent) ) 
	{
        set_temp("last_opponent", opponent);
        COMBAT_D->fight(this_object(), opponent);
        return 1;
    } 
	else
        return 0;
}
//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
    object ob;
    string vendetta_mark, ip1, ip2;
    int shen, sb_shen;
    // We check these conditions here prior to handle auto fights. Although
    // most of these conditions are checked again in COMBAT_D's auto_fight()
    // function, these check reduces lots of possible failure in the call_out
    // launched by auto_fight() and saves some overhead.
    if( is_fighting()
    ||  !living(this_object())
    ||  !(ob = this_player()) 
    ||  environment(ob)!=environment()
    ||  !living(ob)
    ||  ob->query("linkdead") )
        return;
    sb_shen=ob->query("shen");
    shen=this_object()->query("shen");
    // Now start check the auto fight cases.
    if( is_killing(ob) 
		|| (!playerp(this_object()) && playerp(ob) && ob->query_condition("killer"))
		|| (playerp(this_object()) && playerp(ob) 
			&& stringp(ip1=query_ip_number(this_object())) 
			&& stringp(ip2=query_ip_number(ob)) 
			&& ip1==ip2 
			&& (ob->query_condition("killer") 
				|| this_object()->query_condition("killer")) )
		|| (this_object()->query_condition("killer") && ob->query_condition("killer")) )
	{
        COMBAT_D->auto_fight(this_object(), ob, "hatred");
        return;
//    } else if( stringp(vendetta_mark = query("vendetta_mark"))
    } else if(stringp((vendetta_mark = query("vendetta_mark")) || (vendetta_mark = query("party/id")))
    && ob->query("vendetta/" + vendetta_mark) )
	{
        COMBAT_D->auto_fight(this_object(), ob, "vendetta");
        return;
    } else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
        COMBAT_D->auto_fight(this_object(), ob, "aggressive");
        return;
    } else if ((shen<-5000 && sb_shen>5000 ) || (shen>5000 && sb_shen<-5000 ) ){
        COMBAT_D->auto_fight(this_object(), ob, "berserk");
        return;
    }
}

