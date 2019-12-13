// miejue.c ���
// create by host dec,12

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���", ( { "mie jue", "mie", "jue"}));
	set("long",
	    "����һλ�׷��ԲԵ����ᣬ�Ƕ����ɵ��������ţ�����������������ޱ��顣\n");

	set("gender", "Ů��");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 28);
	set("con", 30);
	set("dex", 30);

	set("qi", 3000000);
	set("max_qi", 3000000);
	set("jing", 1000000);
	set("max_jing", 1000000);
	set("neili", 5000000);
	set("max_neili", 600000);
	set("jiali", 2000);
	set("xyzx_sys/level", 1000);
	set("combat_exp", 20000000);
	set("score", 300000);

	set_skill("force", 2500);
	set_skill("dodge", 2550);
	set_skill("blade", 2580);
	set_skill("unarmed",2580);
	set_skill("parry", 2500);
	set_skill("sword", 2500);
	set_skill("linji-zhuang",1500);
	set_skill("jinding-zhang",1500);
	set_skill("huifeng-jian",1500);
	set_skill("yanxing-dao", 1580);
	set_skill("tiangang-zhi", 1580);
	set_skill("zhutian-bu",1550);
	set_skill("yugalism", 1580);
	set_skill("dushi-jiren",1500);
	set_skill("literate", 1500);
	map_skill("dodge","zhutian-bu");
	map_skill("parry", "huifeng-jian");
	map_skill("sword", "huifeng-jian");
	map_skill("force","linji-zhuang");
	map_skill("unarmed","tiangang-zhi");
	map_skill("blade","yanxing-dao");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("unarmed", "tiangang-zhi");
	set("chat_chance_combat", 100);
set("chat_msg_combat", ( {(: perform_action, "sword.mie" :),}) );
set("chat_msg_combat", ( {(: perform_action, "sword.juemie" :),}) );

	create_family("������", 3,"����");
	set("class","bonze");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
//        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/emei/obj/yitian-jian")->wield();
}

void attempt_apprentice(object ob)
{

	string *prename = ( { "��" });
	string name, new_name;
	if ((string)ob->query("gender") != "Ů��")
	{
		command("say ����ô�ܹ�������Ϊͽ�أ�");
		return;
	}
	if((string)ob->query("class")!="bonze" )
	{
		command("say �����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ���������ܽ䡣");
		return ;
	}
	if ((int)ob->query("shen") < 0)
	{
		command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
		        "�Ƿ����ò�����");
		return;
	}

	if ( ob->query("married") )
	{
		command("say �������ߣ����������Ե��"+RANK_D->query_respect(ob)+"������ذɣ�");
		return ;
	}
	if ( ob->query_skill("linji-zhuang",1) < 80 )
	{
		command("say ��λ"+RANK_D->query_respect(ob)+"���Ҷ����ڹ��ƺ����Ĳ�����");
		command("say �Ƿ�Ӧ�ö����������µ㹦��");
		return ;
	}
	if ( ob->query_con() < 28 && ob->query_int() < 28 )
	{
		command("sigh");
		command("say ��λ"+RANK_D->query_respect(ob)+"�������ʲ���һ�㡣");
		command("say �����д���Ǳ���������Ȼ�ȥĥ��ĥ����");
		return ;
	}
	name = ob->query("name");
	new_name = prename[random(sizeof(prename))] + name[2..3];
	ob->set("name", new_name);
	command("smile");
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("recruit " + ob->query("id"));
}
