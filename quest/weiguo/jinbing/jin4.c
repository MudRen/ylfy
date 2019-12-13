#include <ansi.h>
inherit NPC;

string *nm1_jp =(
{
	"完颜",
});

string *nm2_jp =(
{
	"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
	"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
	"多","才","长","子","永","友","自","人","为","铁","康","洪烈",
});

void create()
{
	int i = random(sizeof(nm1_jp));
	set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ( {"yuanshuai"}));
	set("gender", "男性" );//性别与上面对应
	set("long", "一个全身披挂的金兵特务。\n");
	set("attitude", "aggressive");
	set("vendetta/authority",1);
	set("nickname",HIR"金兵特务"NOR);
	set("force_factor",2+random(1390));
	set("max_qi",300+random(1690));
	set("max_jing",300+random(1890));
	set("max_sen",300+random(1890));
	set("max_neili",300+random(1890));
	set("max_mana",300+random(1890));
	set("eff_neili",300+random(1390));
	set("neili",300+random(1390));
	set("per", 25);
	set("age", 22);
	set("shen", -10000);
	set("intellgent",1);
	set("pursuer",1);
	set("combat_exp", 400000+random(2000000));
	set("bellicosity", 10000);

	set_skill("unarmed", 80+random(180));
	set_skill("club", 80+random(180));
	set_skill("parry", 80+random(180));
	set_skill("dodge", 180+random(180));
	set_skill("zhong-qiang", 80+random(180));

	map_skill("club", "zhong-qiang");
	map_skill("parry", "zhong-qiang");
	set_temp("apply/attack", 20);
	set_temp("apply/defense",50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 20);
	set("chat_chance_combat", 90);
	set("chat_chance", 30);
	set("chat_msg", ({
     (: random_move :),
	}) );

	setup();

	carry_object("/clone/armor/tiejia")->wear();
	carry_object(__DIR__"obj/changqiang")->wield();
	add_money("gold", random(500));
}
void init( )
{
	object ob;
	remove_call_out("hunting");
	if( interactive(ob = this_player())  )
	{
		call_out("hunting",1);
	}
	if(!environment()->query("no_fight") && random(100) < 1)
		call_out("hunting",1);
}

void hunting()
{
	int i;
	object *ob;
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
		if(ob[i]->query("vendetta/authority")) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
}

void die()
{
	object ob, me, corpse, obn;

	ob = this_object();
	me = query_temp("last_damage_from");

	if(me)
	{
		message_vision(WHT"$N大叫一声,大金万岁!!倒地而亡。\n"NOR,ob,me);
		if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
			corpse->move(environment(this_object()));
		message("vision", me->name() + "从金兵特务身上发现了大量的银两。\n", me);
		obn=new("/clone/money/thousand-gold");
		obn->set_amount(random(5)+1);
		obn->move(me);
		me->add("score",50);
		destruct(ob);
		return;
	}
}
