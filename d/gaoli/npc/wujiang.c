
inherit NPC;

void create()
{
	set_name("武将",( { "wu jiang","jiang","wu" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long", "这是守卫高丽的武将，看起来十分威风。\n");

	set("combat_exp",800000);
	set("guard","高丽");
	set("attitude", "peaceful");

	set("str", 30);
	set("max_qi", 1000);
	set("max_jing", 500);
	set("max_mana", 700);
	set("neili", 400);
	set("max_neili", 500);
	set("force_factor", 25);
	set_skill("blade", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/armor/armor")->wear();
}
