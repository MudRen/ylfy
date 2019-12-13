// migong lev15

#include <ansi.h>

inherit NPC;


void create()
{
	set_name(HIR"ǧ�������"NOR, ({ "huo long" , "long" , "dragon" }));
	set("race", "Ұ��");
	set("long","һ���޴�������������Ż𣬿������㣬�������˹��������������������Ѩ����پ�������ѹ�֣�������ʮ�ֵؿ��¡�\n");
	set("attitude", "aggressive");
	set("vendetta/authority",1);
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" , "claw"}) );
	set("qi",5000000);
	set("eff_qi",5000000);
	set("max_qi",5000000);
	set("eff_jing",5000000);
	set("jing",5000000);
	set("max_jing",5000000);
	set("neili",15000000);
	set("no_suck",1);
	set("max_neili",15000000);
	set("max_fashufali",109999);
	set("fashufali",109999);
	set("dex",150);
	set("con",150);
	set("int",150);
	set("str" ,150);
	set("no_get",1);
	set("no_suck", 1);
    set("age", 999);
	set("shen_type", -1);
	set("intellgent",1);
	set("pursuer",1);
	set("end_boss", 1);
	set("combat_exp", 2100000000);
	set("jiali",5000);
	set_temp("apply/attack", 1500);
	set_temp("apply/damage", 1400);
	set_temp("apply/armor", 1800);
	set_temp("apply/defence",1500);
	set_skill("dodge", 2100);
	set_skill("force", 3500);
	set_skill("unarmed", 3500);
	set_skill("dragon", 3500);
	set_skill("spells",3500);
	set_skill("magic-old",3500);
	map_skill("unarmed", "dragon");
	map_skill("dodge", "dragon");
	map_skill("spells", "magic-old");
	prepare_skill("unarmed", "dragon");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.penhuo" :),
		(: perform_action, "unarmed.tuwu" :),
		(: perform_action, "unarmed.yaoyao" :),
		(: perform_action, "spells.magic1" :),
		(: perform_action, "spells.magic2" :),
		(: perform_action, "spells.magic3" :),
		(: perform_action, "spells.magic4" :),
		(: perform_action, "spells.magic5" :),
		(: perform_action, "spells.magic6" :),
		(: perform_action, "spells.magic7" :),
		}) );
		
	setup();
}

void init( )
{
	object ob, me;

	me = this_object();
	
	remove_call_out("hunting");
	if( playerp(ob = this_player())  )
	{
		call_out("hunting", 1);
		if ( me->is_fighting() ) return;
		if ( me->query_temp("fight_killer_id") == ob->query("id") ) return;
		
		me->set_temp("fight_killer_id", ob->query("id"));
		me->set("xyzx_sys/level", ob->query("xyzx_sys/level"));
		/*me->set("xyzx_sys/jingzhun", ob->query("xyzx_sys/jingzhun"));
		me->set("xyzx_sys/minjie", ob->query("xyzx_sys/minjie"));
		me->set("xyzx_sys/lingxing", ob->query("xyzx_sys/lingxing"));
		me->set("xyzx_sys/fanying", ob->query("xyzx_sys/fanying"));*/
	} 
	else if( !environment()->query("no_fight") && random(10) < 5 )
        call_out("hunting",1);
}

void hunting()
{
	int i;
	object *ob;
	ob = all_inventory(environment());
	
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i]) || !playerp(ob[i]) )
			continue;
		
		if(ob[i]->query("vendetta/authority"))
			continue;
		
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
		call_out("check",0);
	}
}

void die()
{
	object corpse, killer;
	object jla , jlb;
	
	if( !living(this_object()) )
		revive(1);
	
	if( wizardp(this_object()) && query("env/immortal") )
		return;
	
	this_object()->clear_condition();
	
	COMBAT_D->announce(this_object(), "dead");
	
	if( objectp(killer = query_temp("last_damage_from")) )
	{
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}
	
	if (!killer)
		return;
	
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());
	
	if (random(10) < 1)
	{
		jla=new("/clone/gem/gem");
		message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
		command("rumor "HIM+killer->query("name")+"�õ�һ��"+jla->query("name")+"!\n"NOR);
		jla->move(killer);
	}
	
	if (userp(killer) && time() > environment(this_object())->query("already"))
	{
		if(random(10) < 7)
		{
			jla=new("/clone/gem/robe");
			message_vision("$N�õ�һ��ħ��ʦ�ۡ�\n",killer);
			command("rumor "HIM+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
			jla->move(killer);
		}

		if(random(10) < 1)
		{
			jla=new("/clone/gem/ring"+random(10));
			message_vision("$N�õ�һ��ħ����ָ��\n",killer);
			command("rumor "HIM+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
			jla->move(killer);
		}
		
		if(random(10) < 2)
		{
			jla=new("/clone/gem/gem");
			message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
			command("rumor "HIM+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
			jla->move(killer);
		}
		
		if(random(10) < 3)
		{
			jla=new("/clone/gem/gem");
			message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
			command("rumor "HIM+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
			jla->move(killer);
		}

		if(random(10) < 5)
		{
			message_vision("$N�õ�һ��ǧ������ס�\n",killer);
			command("rumor "HIM+killer->query("name")+"�õ�һ��"HIR"ǧ�������"NOR"��\n");
			jla=new("/d/migong/obj/jia3");
			jla->move(killer);
		}
		
		message_vision("$N�õ�һ��ǧ���������\n",killer);
		command("rumor "HIM+killer->query("name")+"�õ�һ��"HIR"ǧ�������"NOR"��\n");
		jlb=new("/d/migong/obj/dan4");
		jlb->move(killer);
	}
	
	environment(this_object())->set("already",time()+3600);
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	this_object()->dismiss_team();
	destruct(this_object());
}

void check()
{
	object ob=this_object();
	object me=this_player();
	
	if (!ob)
	{
		remove_call_out("check");
		return;
	}
	
	if (!me)
	{
		remove_call_out("check");
		return;
	}
	
	if(! present(me,environment()) )
	{
		remove_call_out("check");
		return;
	}
	
	if( me->is_ghost() )
	{
		remove_call_out("check");
		return;
	}
	
	if (ob->is_busy() && ob->is_fighting())
	{
		message_vision(HIW"$N"HIW"����ʥ��һ�����ָֻ����ж���\n",ob,me);
		ob->interrupt_me();
		ob->start_busy(0);
	}
	
	remove_call_out("check");
	call_out("check",1+random(3));
}

int hit_ob(object me, object ob, int damage)
{
	ob->apply_condition("wugong_poison", 50);
	ob->apply_condition("chanchu_poison", 50);
	ob->apply_condition("xiezi_poison", 50);
	ob->apply_condition("snake_poison", 50);
	ob->apply_condition("zhizhu_poison", 50);
	ob->apply_condition("fire_poison", 50);
	tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
}
