#include <ansi.h>
inherit NPC;

void create()
{
    set_name("蒙古百夫长", ({ "menggujiang", "jiang" }));
    set("gender", "男性" );//性别与上面对应
        set("long",
"一个身高大但满脸又是伤疤加横肉的蒙古兵。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIW"蒙古小将"NOR);
  set("force_factor",2+random(390));
  set("max_qi",400+random(590));
  set("max_jing",400+random(590));
  set("max_sen",400+random(590));
  set("max_neili",400+random(590));
  set("max_mana",400+random(590));
  set("eff_neili",400+random(390));
  set("neili",400+random(590));
        set("per", 1);
        set("age", 22);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 200000+random(300000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
		            (: random_move :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "蒙古百夫长喝道：杀啊的！！\n",
                "蒙古百夫长笑道：这次一定要消灭南蛮!\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 100+random(150));
        set_skill("blade", 100+random(150));
        set_skill("parry", 100+random(150));
        set_skill("dodge", 100+random(150));
        set_skill("kuangfeng-blade", 100+random(150));
        
        map_skill("blade", "kuangfeng-blade");
        map_skill("parry", "kuangfeng-blade");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
	add_money("silver", random(50));
}
void init( )
{
        call_out("hunting",180);
}

void hunting()
{
object ob=this_object();
write(HIW"只听，城外三声令响!蒙古百夫长撒出了襄阳!\n"NOR);
destruct(ob);
}

void die()
{
        object ob, me, corpse;
		int exp;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
	if ( objectp(me) )
	{
        message_vision(WHT"$N大叫一声,大汉万岁!!倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        //if((int)me->query("combat_exp") < 400000)   {
		exp = 2000 + random(1000);
        message("vision", me->name() + "由于成功的保卫了襄阳,增加了"+exp+"经验和"+(exp/4)+"潜能。\n", me);
        me->add("combat_exp",exp);
        me->add("potential",exp/4);
        destruct(ob);
        //}
        //message("vision", me->name() + HIG"成功的保卫了襄阳。\n"NOR, me);
        me->add("score",2);
        me->add("shen",10);
	}
	else
        destruct(ob);
        return;
}
