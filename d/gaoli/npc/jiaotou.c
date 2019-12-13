//jiaotou.c

inherit NPC;

void create()
{
	set_name("½ÌÍ·", ( { "jiaotou" }));
	set("age", 28+random(10));
	set("gender", "ÄĞĞÔ");
	set("attitude", "peaceful");
	set("str", 20);
	set("combat_exp", 18000);
	set("max_qi", 600);
	set("max_mana", 400);
	set("max_jing", 600);
	set("max_neili", 400);
	set("neili", 400);
	set("force_factor", 20);
	set_skill("unarmed", 110);
	set_skill("dodge", 110);
	set_skill("parry", 110);
	set_skill("blade", 110);
	set_skill("force", 110);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
