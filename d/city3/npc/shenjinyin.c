// shenjinyin.c �����

inherit NPC;

void create()
{
	set_name("�����", ({ "shen jinyin", "shen", "jinyin" }));
	set("gender", "Ů��");
	set("age", 19);
	set("long", "�ű��ֵ�С���ӣ���������ʩ������\n");
	
	set("combat_exp", 1500);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 22);
	set_skill("dodge", 22);
	set_temp("apply/attack", 11);
	set_temp("apply/defense", 11);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",8);
}
