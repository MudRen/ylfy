// shusheng.c ����

inherit NPC;

void create()
{
        set_name("����", ({ "shu sheng", "shu" ,"sheng" }));
	set("gender", "����");
        set("age", 25);
        set("long", "������һ���飬���ڿ��ţ�������֪�����ڿ�����\n");
	
        set("combat_exp", 600);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
        add_money("coin",30);
}
