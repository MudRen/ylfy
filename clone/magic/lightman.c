//����ʹ ������ !!! 

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIY"������"NOR, ({ "light angel" , "lightangel" }));
       set("gender", "����");
	   set("title",HIR+"����ʹ"+NOR);
       set("long",
       "һ���ߴ��ޱȣ�����������ľ���ʹ��
           ��\n");
		set("age", 30);
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("verbs", ({ "bite" , "claw"}) );
	    set("max_qi",50000000+random(50000000));
        set("max_jing",50000000+random(50000000));
		set("neili", 300000000+random(50000000));
        set("max_neili", 3000000+random(5000000));
	    set("jingli", 300000000+random(5000000));
        set("max_jingli", 3000000+random(5000000));
        set("per",40);
        set("zhuanbest",1);  
        set("magicgift",6);
        set("no_suck",1);
	    set("is_boss", 1);
        set("jiali", 30000);		
        set("dex",1500);
        set("con",1500);
        set("str" ,1500);
//      set("shen_type", -1);
        set("intellgent",1);
	    set("pursuer",1);
        
		set("xyzx_sys/level", 10000+random(8000));
        set("combat_exp", 12000000+random(8000000));
		set("xyzx_sys/fanying", 100000);
	    set("xyzx_sys/jingzhun", 100000);
	    set("xyzx_sys/minjie", 100000);
	    set("xyzx_sys/lingxing", 100000);
        set_temp("apply/attack", 400);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",500);
        set_skill("sword", 4000+random(5000));
        set_skill("parry", 4000+random(5000));
        set_skill("force", 4000+random(5000));
        set_skill("dodge", 4000+random(5000));
        set_skill("spells", 4000+random(5000));
        set_skill("magic-unarmed", 4000+random(5000));
        set_skill("magic-sword", 4000+random(5000));
        set_skill("magic-light", 4000+random(5000));
        set_skill("unarmed", 4000+random(5000));
        set_skill("dragon", 4000+random(5000));

       map_skill("spells", "magic-light");
       map_skill("sword", "magic-sword");
       map_skill("unarmed", "magic-unarmed");
       map_skill("parry", "magic-unarmed");
       map_skill("dodge", "dragon");

      set("chat_chance_combat", 60);
      set("chat_msg_combat", ({
    (: perform_action, "spells.moonlight lightangel" :),
    (: perform_action, "spells.sunfield" :),
    (: perform_action, "spells.sunbolt" :),
    (: perform_action, "spells.holyword" :),
    (: perform_action, "spells.delete" :),
 }) );
     
   setup();
    carry_object("clone/magic/obj/lightsword")->wield();
}


void invocation(object who, int level)
{
	int i;
	object *enemy;
        who=this_player();
if (!wizardp(who))
        who->apply_condition("zdizi_busy",4);
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
if (enemy[i]!=who)
{
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
}
		}
	}
	set_leader(who);
	set("possessed",who);
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
	message("vision",BLK"����ս���Ѿ�������\n"+ name() + BLK"��Ϊһ��ʥ�⣬��ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
