// jinshe.c �����ɾ�

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ѩ��", ( {"xia xueyi", "xia", "xueyi"}));
	set("nickname", HIY"�����ɾ�"NOR);
	set("gender", "����");
	set("age", 25);
	set("long",
	    "�������˳ơ������ɾ�����һ���ֽܡ�����ѩ�ˡ�\n"
	    "������ȫƾ�ö�ʱ��ʱа���˵��Ƕ����������ò�������\n"
	    "��˵���������ܲң���Ҳ���ƫ��������\n"
	    "���������������˵��ˣ���ɫ���ѿ���\n");
	set("attitude", "peaceful");
	set("per", 21);
	set("str", 50);
	set("int", 150);
	set("con", 150);
	set("dex", 150);

	set("chat_chance", 15);
	set("chat_msg", (
	{
		"��ѩ��ͻȻ��ݺݵ�˵�����Ƕ����㵽��ΪʲôҪ���ң���\n",
		"��ѩ�����з·�Ҫ���������\n",
		"ͻȻ����ѩ�ˡ��ۡ���һ�����³�һ��ڴ��ڵ�Ѫ��\n",
	}));

	set("inquiry", ([
                    "����": "��....��..... \n",
	                ]));

	set("max_qi", 3500000);
	set("jing", 3500000);
	set("max_jing", 3500000);
	set("neili", 15000000);
	set("max_neili", 500000);
	set("no_suck",1);
	set("jiali", 50000);

	set("combat_exp", 2010000000);

	set_skill("force", 2000);                // �����ڹ�
	set_skill("huntian-qigong", 1550);       // ��������
	set_skill("unarmed", 1800);              // ����ȭ��
	set_skill("dodge", 1800);                // ��������
	set_skill("parry", 1700);                // �����м�
	set_skill("sword", 1500);                // ��������
	set_skill("jinshe-zhui", 1700);
	set_skill("jinshe-zhang", 1900);
	set_skill("throwing", 1900);
	set_skill("jinshe-jian",1500);         // ���߽���
	set_skill("youlong-shenfa",1500);

	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("throwing", "jinshe-zhui");
	map_skill("unarmed", "jinshe-zhang");
	map_skill("dodge", "youlong-shenfa");
	map_skill("parry", "jinshe-jian");
	set("chat_chance_combat", 350);
	set("chat_msg_combat", (
	{
(: perform_action, "sword.hengkong" :),
(: perform_action, "sword.suo" :),
(: perform_action, "throwing.tuwu" :),
(: perform_action, "unarmed.youshen" :),
(: perform_action, "unarmed.fugu" :),
	}));
	set("chat_chance",15);
	set("chat_msg", (
	{
(: command("unwield zhui"):),
			(: command("unwield jian"):),
			(: command("wield jian"):),
			(: command("wield zhui"):),
			(: command("exercise 150"):),
			(: random_move :),
		}));

	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/book/jinshe1");
	carry_object("/d/jinshe/obj/jinshe-zhui")->wield();
	carry_object("/d/city3/obj/jinshejian")->wield();
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");

	if (  (string)ob->query("id") != "shou pa")
		return notify_fail("��ѩ�˲���Ҫ���������\n");
	write(HIY "��ѩ�˽ӹ������������س���ͻȻ����Ȼ���¡� \n" NOR);
	write(HIR "��ѩ���૵����Ƕ�������֪��������⣬��ʵ��������ģ���Ҳ���ں��ġ�\n" NOR);
	write(HIY "��ѩ��ת��ͷ������˵���Ҹ�������л���أ�\n" NOR);
	write(HIY "����ת��ȥ����Ĭ���������˼����ʲô��\n" NOR);
	write(HIY "��ѩ��ͻȻ�����˺ܴ�����Ƶض���˵���ҿ�\n" NOR);
	write(HIY "��Ҳ���������ˣ������б��ұ�����Ѫ�ġ����߽��ס���\n" NOR);
	write(HIY "������������˵�Ѿ�û��ʲô���ˣ������ȥ�ɡ�\n" NOR);
	write(HIY "��ѩ��̾�˿����������ǳ�������Ҳ�ã���������Ҳ�ã�������ΪҲ�ã�ͨͨ�����޹ء�\n" NOR);
	write(HIY "��ѩ�˻��˻��֣����ˣ���������ˡ�\n" NOR);

	obn = new("/d/city3/wenzai/npc/obj/jianpu");
	obn->move(who);
	destruct(ob);
	return 1;
}
