// ��̬��ͼ����2

#include <ansi.h>

inherit NPC;


void create()
{
	set_name(MAG"����"NOR, ({ "du long" , "long" , "dragon" }));
	set("race", "Ұ��");
	set("long", "һ�������ϣ���ª�����ľ������������㣬�������˹�����\n");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" , "claw"}) );
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("max_qi",500000+random(500000));
	set("max_jing",500000+random(500000));
	set("neili",1500000+random(3000000));
	set("max_neili",500000);
	set("jiali",3000);
	set("no_suck",1);
	set("dex",100);
	set("con",100);
	set("str" ,100);
	set("is_boss", 1);
	set("age", 80);
	set("combat_exp", 500000000+random(300000000));
	set_temp("apply/attack", 400);
	set_temp("apply/damage", 400);
	set_temp("apply/armor", 400);
	set_temp("apply/defence",400);
	set_skill("dodge", 1400+random(700));
	set_skill("unarmed", 1400+random(700));
	set_skill("dragon", 1400+random(700));
	set_skill("spells", 1400+random(700));
	set_skill("magic-old", 1400+random(700));
	map_skill("unarmed", "dragon");
	map_skill("dodge", "dragon");
	prepare_skill("unarmed", "dragon");
	map_skill("spells", "magic-old");
	set("chat_chance_combat", 50);
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
	carry_object("/d/migong/obj/longdan");
}

void init( )
{	
	object ob, me;
	
	me = this_object();
    ob = this_player();
	::init();

	if ( !living(me) ) return;
    
	if ( me->is_fighting() || !playerp(ob) ) return;
	
	if( environment() && !environment()->query("no_fight") )
	{
		remove_call_out("hunting");
		call_out("hunting", 1);
	}

	//command("follow "+ob->query("id"));
}

void hunting()
{
	int i;
	object *ob;
	
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) 
	{
		if( !ob[i]->is_character() || ob[i] == this_object() || !living(ob[i]) || !playerp(ob[i]) )
			continue;
		
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
		call_out("check",0);
	}
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
		ob->start_busy(1);
	}
	
	remove_call_out("check");
	call_out("check",1+random(3));
}

void die()
{
	object ob, me, corpse, env;
	string room;
	int m;

	ob = this_object();

	if ( !objectp(env=environment(ob)) 
		|| !stringp(room=env->query("short")) ) 
	{
		::die();
		return;
	}

	if ( ob->query_temp("last_damage_from") )
	{
		me = ob->query_temp("last_damage_from");
		m = random(5000);
		
		if ( interactive(me) )
		{
			message_vision(HIG"\n��ɱ���� "+ob->name(1)+HIG" �������� "HIY+(me->query_exp_times()*m)+HIG" �㾭��� "HIY+(m/10)+HIG" Ǳ�ܡ�\n"NOR, me);
			message("party", HIW"��"+room+"��"+HIG+me->name(1)+HIM" ɱ���� "+ob->name(1)+HIM" �������� "HIC+(m*me->query_exp_times())+HIM" �㾭��� "HIY+(m/10)+HIM" Ǳ�ܡ�\n"NOR,users() );
			me->add("combat_exp",m);
			me->add("potential",m / 10);
		}
	}
	
	if ( objectp(corpse = CHAR_D->make_corpse(ob, me)) )
		corpse->move(environment(ob));

	/*if ( random(100) > 50 )
	{
		baoshi = new("/clone/gem/gem");
		message("party", HIW"��"+room+"��"+HIM"��˵ "HIG+me->name(1)+HIM" �� "+ob->name(1)+HIM" ʬ���Ϸ����� "+baoshi->name(1)+HIM"��\n"NOR,users() );	
		baoshi->move(corpse);
	}*/

	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}


