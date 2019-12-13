//zhang.c ����ʦ
//����װ������ʦ�����Ż� 

#include <ansi.h>

inherit NPC;

int ask_me();

void create()
{
	set_name("����ʦ", ({ "zhang tianshi", "zhang" }));
	set("age", 57);
	set("gender", "����");
	set("long", "����һλ�ɷ���ǣ���ò��Ȼ�ķ�ʦ��\n");
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 35);
	set("con", 38);
	set("dex", 31);
	set("per", 35);
	set("max_qi", 8000);
	set("max_jing", 8000);
	set("max_neili", 8000);
	set_skill("magic", 200);
	set_skill("taoism", 350);
	set("chat_chance_combat", 3);
	set("chat_msg_combat", ({
		"����ʦҡҡ���������������飬�����㣬̫���Ͼ��������飿\n",
		"����ʦ�����Ĵ��˼�������\n",
		}));
	set("inquiry", ([
		"����" : (: ask_me :),
		"ûǮ" : "ûǮ��ȥ׬������˵ʲô��",
		"��"   : "����Ҳ��һ��������",
		"ħ��" : "ħ����ʲô���գ�",
		"����" : "�������ֺܶ����أ�������������������һ���㡣",
		"����" : "����������Ǳ�Դ���ڣ�",
		"����" : "�������������³ˣ�����Ϊ�ᡣ",
		"����" : "����ֻ�������гˣ����ǲ��ܺ͵�����ȡ�",
		]));
	
	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

void init()
{
	add_action("do_show", "show");
	add_action("do_summon", "summon");
}

int ask_me()
{
	command("heihei");
	command("say ��ֻ������������⣬Ѱ������Ī�ᣡ��Ҫ���㱾�˵ġ��ҿɲ��ܰ��������£�");
	tell_object(this_player(), GRN "����ʦ�����������˵�������Ҫ������ó������ҿ���(show)����\n" NOR);
	return 1;
}

int do_summon(string arg)
{
	if ( !wizardp(this_player()) )
	{
		command("say ��������ǰϹץ��ʲô���������ȥ��");
		return 1;
	}
	
	return 0;
}

int do_show(string arg)
{
	object ob, me;
	string type;

	me = this_player();
	
	if (! arg)
		return notify_fail("��Ҫ����ʲô������\n");
	
	if ( !objectp(ob = present(arg, me)) )
		return notify_fail("������û�����ֶ�����\n");
	
	if (ob->query("equipped"))
		return notify_fail("���Ƚ��" + ob->name() + "��װ����˵��\n");
	
	message_vision("$n�ó�һ" + ob->query("unit") + ob->name() + "��$N˵�������а���...��\n",this_object(), me);
	
	if (ob->query("money_id"))
	{
		command("say ������Ǯ��ʲô�����׸�����Ǿ͸��Һ��ˡ�");
		return 1;
	}
	
	if ( !me->query_temp("paid/����ʦ", 1) )
	{
		command("heihei");
		command("say ��...��ôҲ���е���˼��˼�ɣ���˵һǧ���ƽ���ô������Ȼ��Щ��Ҳ�����ԡ�");
		return 1;
	}
	
	if (!ob->query("max_sockets"))
	{
		command("say Ŷ���ҿ������ܿ��⣡");
		return 1;
	}
	
	if (ob->query("sockets/max") >= ob->query("max_sockets"))
	{
		command("say Ŷ���ҿ��������Ѿ�����Ҫ�ٿ����ˣ�");
		return 1;
	}
	
	if ((int)ob->query("sockets/max") >= 4)
	{
		command("say Ŷ���ҿ��������Ѿ�����Ҫ�ٿ����ˣ�");
		return 1;
	}
	
	if (ob->query("sockets/max",1) >= 4)
	{
		command("say Ŷ���ҿ��������Ѿ�����Ҫ�ٿ����ˣ�");
		return 1;
	}
	
	if (mapp(ob->query("weapon_prop")))
		type = ob->query("skill_type");//��������
	else if (mapp(ob->query("armor_prop")))
		type = ob->query("armor_type");//װ������
	
	//���ӱ�ʶÿ������װ����ֻ��ѡ��һ����Ϊ����ħ����Ʒ��ѡ����޷�����
	if ( me->query("diablo/" + type + "/file_name") )
	{
		if ( me->query("diablo/" + type + "/file_name") != base_name(ob) )
		{
			command("say Ŷ���㲻���Ѿ�ѡ��" + me->query("diablo/" + type + "/name") + NOR + CYN"��Ϊ����ħ����Ʒ�ˣ�\n" + "Ҫ֪��ÿ����һ������ÿ�����͵�װ����ֻ��ѡ������һ�������ħ����Ʒ���㻹����ذɣ�"NOR);
			return 1;
		}
	}
	
	message("vision", HIM + name() + "�ӿڴ�������һ�Ż�ɫ�ķ�ֽ������������ľ�������Ƿ�ֽ��ȼ�ˣ�ɨ��" + ob->name() + HIM "��\n" + 
		"Ȼ������ľ�����ˣ������㵸�����������дʣ���̫���Ͼ��������ɴ����˵��һ�����н����ȵ�����������\n" NOR, environment());
	message_vision("��⻮��һ���⻪��$N���˷�����Ҳ��֪��������ô���¡�\n",me);
	command("say ���ˣ����ˣ���������ˡ�");
	me->delete_temp("paid/����ʦ");
	me->set("diablo/" + type + "/id", ob->query("id"));
	//���ӱ���־
	me->set("diablo/" + type + "/name", ob->query("name"));
	me->set("diablo/" + type + "/file_name", base_name(ob));
	me->add("diablo/" + type + "/sockets/max", 1);
	seteuid(ROOT_UID);
	reload_object(ob);
	seteuid(getuid());
	return 1;
}

int accept_object(object who, object ob)
{
	if ( !ob->query("money_id") )
	{
		command("say �������ҿ�ûɶ��Ȥ��");
		return 0;
	}
	
	//����һǧ���������Ǯ��ȡ
	if (ob->value() < 10000000)
	{
		command("shake " + who->query("id"));
		command("say �������Ǹ���������ô��");
		return 1;
	}
	
	command("say ��������Ҳ���е����⣬�Ҿ����㿪һ�ι�ɣ�");
	who->set_temp("paid/����ʦ", 1);
	return 1;
}

void fight_ob(object ob)
{
	::fight_ob(ob);//����
	message_vision("$N��Цһ��������������ͷ��ʲô�˶��С���˵������һָ$n��\n",this_object(), ob);
	ob->unconcious();
}

int accept_fight(object who)
{
	command("say û��Ȥ��");
	return 0;
}

int accept_ansuan(object who)
{
	return notify_fail("����밵�㣬������ǰһ��������̫�����\n");
}

void receive_damage(string type, int n)
{
	return;
}

void receive_wound(string type, int n)
{
	return;
}
