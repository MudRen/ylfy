#include <ansi.h>
inherit NPC;

int do_copy(object me);
int do_back(object me);

void create()
{
      string weapon;
        set_name("������ʦ", ({ "biaoshi"}));
        set("gender", "����");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "�ھֵ���ʦ��\n");
        set("combat_exp", 1080000 + random(4000000)); 
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
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
                (: random_move :),
        }) );
 
        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
//        map_skill("blade","fanliangyi-dao");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 4700); 
        set("max_neili", 4700);
        set("jiali", 30);
        weapon = "/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void die()
{
    int pot,exp;
	object killer;
	exp= random(50)+50;
	pot= exp/7;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
	::die();

return ;
}
int checking(object ob, object me)
{
	if(!me || !present(me, environment())) do_back(ob);
	else call_out("checking", 2, ob, me);
        return 1;
}

int do_copy(object me)
{
        object ob;
        ob = this_object();

      if(!me->query_temp("xx_rob")){
      	   do_back(me);
      	   return 0;
      	   }
        message_vision(HIR"ͻȻ�ӳ��Ӻ�ܳ�һ��$N��������˵��������$n��\n"NOR, ob, me);
        me->add_temp("biaoshi", 1);
        
        ob->kill_ob(me);
	 me->kill_ob(ob);
        checking(ob, me);    
        call_out("do_back", 350,  ob);  
        return 1;
}


