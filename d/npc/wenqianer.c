// wenqianer.c

inherit NPC;
inherit F_DEALER;
//    inherit F_BANKER;
void create()
{
	set_name(HIB"����"NOR,( { "wenqianer" }) );
	set("title",HIM"������Ů"NOR);
	set("nickname",HIC"��������"NOR);
	set("gender", "Ů��" );
	set("age", 24);
	set("long",
	    CYN"���������ף�üĿ���Դ���˼�����Գ�������绪��\n");
	create_family("����ɽׯ",3,"��ׯ��");
	set("max_qi", 3000000);
	set("max_jing", 3000000);
	set("neili", 3000000);
	set("max_jingli", 50000);
	set("max_neili", 50000);
	set("jingli", 3000000);
	set("combat_exp", 500000000);
//        set("shen", 0);
	set("str", 24);
	set("dex", 23);
	set("con", 20);
	set("per", 30);
	set("int", 24);
	set("inquiry", ([
                    "name" : "���Ǿ���ѽ��",
                    "�����Ž�" : "�����... �ǵ��������ε��彣��",
                    "��������" : "����������ﰡ���Ͳ������㡣��...",
                    "����" : "�����Ұ���",
                    "����ɽׯ" : "�����Ĵ�ʥ��֮һ��ɽׯ�������ƣ���֪ʲôԭ�򣬼��ټ��������ڽ������߶���",
                    "������" : "�����Ǳ���ɽׯ�Ĵ�ׯ������˵����ѧ�����Ѿ��ﵽ�����˺�һ�ľ��硣",
                    "����Ȼ" : "�����ҵĺ����ã�һ�����úö���MM���벻����ʶ��������ѽ����˵������ɻᶺ�˿����ˡ�",
	                ]) );
	set("attitude", "friendly");
	set_skill("parry", 3500);
	set_skill("sword", 3500);
	set_skill("unarmed", 3500);
	set_skill("force", 900);
	set_skill("dodge", 3500);
	set_skill("riyue-bian", 3500);
	set_skill("whip", 3500);
	set_skill("qufeng",350);
	set_skill("literate", 3500);
	set_skill("qiankundanuoyi", 3500);
	set_skill("xuantie-jianfa", 3500);
	set_skill("liumai-shenjian", 3500);
	set_skill("taixuan-gong", 900);
	set_skill("yan-shuangfei", 3500);
	map_skill("force", "taixuan-gong");
	map_skill("sword", "xuantie-jianfa");
	map_skill("parry", "xuantie-jianfa");
	map_skill("dodge", "yan-shuangfei");
	map_skill("unarmed", "liumai-shenjian");
	prepare_skill("sword", "xuantie-jianfa");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", (
	{
(: perform_action, "sword.haichao" :),
	}));
	set("jiali",2625);
	set("vendor_goods", (
	{
		"clone/drug/zhujingchan",
		"clone/gift/shenliwan",
		"clone/gift/xiandan",
		"clone/gift/xisuidan",
		"clone/drug/fmxsdan",
//"clone/gift/jiejue",
//"clone/gift/xianhai",
//"clone/gift/xianxing",
		"clone/drug/yydan",
		"clone/gift/unknowdan",
	}));
	setup();
	carry_object("clone/cloth/zixuan")->wear();
	carry_object("clone/cloth/lingyun")->wear();
	carry_object("clone/cloth/fengting")->wear();
	carry_object("kungfu/class/taohua/obj/ruanwei")->wear();
	carry_object("clone/drug/yydan");
//           carry_object("clone/drug/huanyang");
	carry_object("d/gumu/obj/xuantiejian")->wield();
	carry_object("clone/weapon/longyin")->wield();

	add_money("thousand-gold", 5);
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");

}
