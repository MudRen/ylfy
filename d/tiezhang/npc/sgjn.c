// qqren.c �Ϲٽ���

inherit NPC;
int ask_qiubai();
inherit F_MASTER;

void create()
{
	set_name("�Ϲٽ���", ( { "shangguan jiannan", "shang", "shangguan", "jiannan"}));
	set("nickname", "����ˮ��Ư");
	set("long",
	    "��λ�Ϲٰ�������һλ����֮ʿ�����ư��������κ��������٣�������\n"
	    "��֮�£������������ƴ����ڽ�������Ѱ�ѿ����뱱����ؤ���ͥ�����ˡ�ֻ�Ǻ�����\n"
	    "Ȼ�����伣����֪�����ˡ�\n");
	set("gender", "����");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 45);
	set("int", 40);
	set("con", 48);
	set("dex", 44);

	set("max_qi", 1500000);
	set("max_jingli", 500000);
	set("jingli", 500000);
	set("max_jing", 1000000);
	set("neili", 15000000);
	set("max_neili", 1000);
	set("jiali", 50000);
	set("combat_exp", 1500000000);
	set("score", 500000);

	set_skill("force", 2500);
	set_skill("guiyuan-tunafa", 1800);
	set_skill("dodge", 2500);
	set_skill("shuishangpiao", 2300);
	set_skill("unarmed", 1500);
	set_skill("tiezhang-zhangfa", 1450);
	set_skill("parry", 2000);
	set_skill("literate", 2400);
	set_skill("tiexue-hammer",1800);
	set_skill("duanyun-fu", 1800);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	set("chat_chance_combat", 300);
	set("chat_msg_combat", (
	{
(: perform_action, "unarmed.tianlei" :),
(: perform_action, "unarmed.tianlei" :),
(: perform_action, "unarmed.tiezhangxianglong" :),
(: perform_action, "unarmed.tiezhangxianglong" :),
(: perform_action, "unarmed.zhangdao" :),
(: perform_action, "unarmed.zhangdao" :),
	}) );

	create_family("���ư�", 13, "����");


	setup();
	carry_object("d/tiezhang/obj/black-cloth")->wear();
}

void attempt_apprentice(object me)
{
	if ((int)me->query("shen") < 50000)
	{
		command("hehe");
		command("say ���Ϲٽ��Ͽɲ����ĵز���������ͽ�ܡ�");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
	command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}
