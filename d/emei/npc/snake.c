//snake.c

inherit NPC;

void create()
{
	set_name("����", ({ "snake", "she" }) );
	set("race", "Ұ��");
	set("age", 20);
	set("long", "һֻ��Ȼ������������,����Ҫһ�ڰ������¡�\n");
	set("attitude", "aggressive");
	set("qi", 350);
	set("max_qi", 350);
	set("jing", 200);
	set("max_jing", 200);

	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 10000);

	setup();
}