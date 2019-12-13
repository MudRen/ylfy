inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��������", ({"huixin zunzhe",	"huixin", "zunzhe"}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n" + 
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);
	
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 50);
	//set("str", 50);
	//set("int", 30);
	//set("con", 30);
	set("no_get", 1);
	//set("dex", 50);
	set("max_qi", 50000);
	set("max_jing", 5000);
	set("neili", 3500000);
	set("max_neili", 72000);
	set("jiali", 1000);
	set("combat_exp", 150000);

	//-------------------------------
	set("xyzx_sys/jingzhun", 1);
	set("xyzx_sys/lingxing", 1);
	set("xyzx_sys/minjie", 1);
	set("xyzx_sys/fanying", 1);
	//-------------------------------
	
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 80);
	set_skill("unarmed", 90);
	set_skill("yizhi-chan", 90);
	set_skill("unarmed", 70);
	set_skill("banruo-zhang", 70);
	set_skill("sword", 150);
	set_skill("damo-jian", 150);
	set_skill("parry", 80);
	set_skill("buddhism", 100);
	set_skill("literate", 100);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "yizhi-chan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	
	create_family("������", 38, "����");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.sanjue" :),
		}) );
	
	setup();
	
	 carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}