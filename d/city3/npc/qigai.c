// qigai.c ��ؤ

inherit NPC;

void create()
{
        set_name("��ؤ", ({ "qi gai", "qi" }));
	set("gender", "����");
        set("age", 21);
        set("long", "����һ�����춫���������ؤ��������ؤ����ˡ�\n");
	
        set("combat_exp", 2000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
        set_skill("unarmed", 25);
        set_skill("dodge", 25);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",2);
}
