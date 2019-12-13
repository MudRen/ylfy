// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
inherit NPC;
inherit F_BANKER;
void create()
{
	set_name("Ǯ����", ({"qian bukai", "qian", "bukai"}));
	set("title", "Ǯׯ�ϰ�");
	set("nickname", "һë����");
	set("gender", "����");
	set("age", 34);
	set("str", 100);
	set("int", 24);
	set("dex", 18);
	set("con", 18);
        set("banker","cun/qu");
        set("neili", 200);
	set("max_neili", 100);
	set("jiali", 10);
	set("shen", 0);
        set("combat_exp", 12500);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	"Ǯ����������˵�����������Ѿ����ϰ������ʷ���ڽ��Ͽ���˵�ǵ�һ�ҡ�\n",
	"Ǯ����˵�������������Կ���һ��ɱ�ְ������ȡǮ������ɱ�ְ��س������ˡ�\n"
	"Ǯ����Ц��˵����ɱ�ְ��س������Ա�������˵��������֮����ѽ����\n"
	"Ǯ����Ц��˵������������¥�ڱ����Ŵ��Ǯ����˵�������ˡ�\n",
	"Ǯ����Ц��˵�����ڱ����Ǯ����Ϣ��ȡǮ�հٷ�֮һ�������ѣ��͹������Ű�ɡ�\n",
	"Ǯ����΢΢һЦ��˵�������껹����ͬ�����ҵĶһ�ҵ������ѵġ�\n",
	}));
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
    if (base_name(environment())!=this_object()->query("startroom")) return;
	add_action("do_check", "check");
	add_action("do_check", "cha");
	add_action("do_convert", "convert");
	add_action("do_convert", "huan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
}
