// yiren.c  �η�����

inherit NPC;

void create()
{
        set_name("�η�����", ({ "Yi ren", "yi", "ren" }));
	set("gender", "����");
        set("age", 25);
        set("long", "����һ���ĺ�Ϊ�ҵ��η����ˣ�ÿ����������ϵر���������ա�\n");
	
        set("combat_exp", 1800);
        set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",2);
}
