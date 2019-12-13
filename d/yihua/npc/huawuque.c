// huawuque.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����ȱ", ( { "hua wuque","hua","wuque"}) );
	set("long",
	    "���Ǹ��ƻ�����Ψһ��һ������,\n"+
	    "��ʵԭ���ƻ������˵ĺ��ˣ���������������������Ȼ\n������������ٷ磬�������.\n"+
	    "����ϸ������Ϊ��Ů��.\n");
	set("gender", "����" );
	set("age", 18);
	set("combat_exp", 8000000);
	set("shen_type",1000);
	set("str", 180);
	set("dex", 180);
	set("con", 180);
	set("int", 180);

	set("qi", 30000);
	set("max_qi", 30000);
	set("jing", 50000);
	set("max_jing", 5000);
	set("neili", 1000000);
	set("max_neili", 20000);
	set("jiali", 500);

	set_skill("force", 370);
	set_skill("dodge", 480);
	set_skill("parry", 370);
	set_skill("sword",400);
	set_skill("unarmed",400);

	set_skill("jueqing-zhang",380);
	set_skill("mingyu-shengong",380);
	set_skill("yihua-jiemu",480);
	set_skill("yifeng-jian",480);

	map_skill("unarmed", "jueqing-zhang");
	map_skill("force", "mingyu-shengong");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
	map_skill("sword", "yifeng-jian");

	prepare_skill("sword","yifeng-jian");
	create_family("�ƻ���",2,"����");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", (
	{
(: perform_action, "sword.yifeng" :),
	}) );
	setup();
	carry_object("/d/yihua/obj/jinlvyi")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("gold",15);
	set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg",(
	{
		"����ȱ̾����˵�����Ҳ���ɱС������в���Υ����ùõ���˼����֪����ô�죡��\n",
		"����ȱ������˵������Ȼ��ùò����ҵ����������һֱ��������\n",
		"����ȱ������������������������ѽ!��������ʲô�ط�ѽ��\n",
	}) );
	set("inquiry",([

                   "��" : "�ҵ���������ū��������Ҳ�ѹ��������ҵ�����\n",
                   "С���" : "�����ҵ��ֵܣ�������ô֪�����ģ���\n",
	               ]) );
	setup();
}

void init()
{
	object ob;

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("����ȱһ�����˽�����æ˵��" + RANK_D->query_respect(ob)
	    +"������ʲô����ô�ܵ��������������뿪!\n");
}
