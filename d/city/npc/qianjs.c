// banker.c
inherit NPC;
inherit F_QNSAVE;

void create()
{
	set_name("Ǯ����", ({"qian jishi", "qian", "jishi"}));
	set("title", "�����ϰ�");
	set("nickname", HIW"̸Ц����"NOR);
	set("long","Ǯ�������Ͼţ����š��������������ؽ󾭳�������Σ�ѣ�����Ҳ\n���˽���Ǯ��ү��\n");
	set("gender", "����");
	set("age", 34);
	set("str", 100);
	set("int", 24);
	set("dex", 18);
	set("con", 18);
    set("neili", 200);
	set("max_neili", 100);
	set("jiali", 10);
	set("shen", 0);
	set("combat_exp", 12500);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set("no_put",1);
	set_temp("apply/damage", 40);
	setup();
	add_money("silver", 10);
	carry_object("/clone/cloth/changpao")->wear();
}
void init()
{
    if ( base_name(environment()) != this_object()->query("startroom") )
		return;
	add_action("cha_qn", "check");
	add_action("cha_qn", "cha");
	add_action("cun_qn", "cun");
	add_action("qu_qn", "qu");
}
