#include <ansi.h>
inherit NPC;
void create()
{
      string weapon;
        set_name("����", ({ "tufei"}));
        set("gender", "����");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("eff_neili", 8000);
        set("max_neili", 8000);
        set("dex", 23);
        set("long", "ɽ���ٷˡ�\n");
        set("combat_exp", 1080000 + random(4000000)); 
       
        set("no_quest", 1);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuangfeng-jian", 80+random(180));
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 120);
        set_skill("zixia-shengong",100);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
        }) );
 
        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
//        map_skill("blade","fanliangyi-dao");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        weapon = "/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checking");
                call_out("checking", 0, ob);
        }
}

void checking(object ob)
{
        object me = this_object();
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

        if( !ob || !present(ob, environment(this_object())) || !present("biao yin", ob) ) {
                if(ob == query_leader() )       set_leader(0);
                return;
        }

        command("say "+ob->name()+"�����������£�������·����\n");
        set_leader(ob);

//        kill_ob(ob);
//        ob->fight_ob(me);
//        command("kill "+ob->query("id") );


/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["max_qi"]);
		me->set("qi",        hp_status["max_qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["max_jing"]);
		me->set("jing",      hp_status["max_jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["max_neili"] * 2);
		me->set("jiali",     hp_status["jiali"] + 1);
		me->set("combat_exp",hp_status["combat_exp"]);

        kill_ob(ob);
        ob->fight_ob(me);

}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB+name()+"����ææ���߿��ˡ�\n" NOR, 
                environment(), this_object() );
        destruct(this_object());
}
