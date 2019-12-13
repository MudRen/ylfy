// duanzc.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ( { "duan zhengchun", "duan" }));
	set("title",  "����������" );
	set("long", "�����Ǵ�������������������̫�ܣ��������İ���ʥ�֡�\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);

	set("max_qi", 5200);
	set("max_jing", 600);
	set("neili", 62000);
	set("max_neili", 2000);
	set("jiali", 2000);
	set("combat_exp", 7000000);

	set_skill("force", 600);             // �����ڹ�
	set_skill("kumu-shengong", 600);
	set_skill("shaolin-shenfa", 1000);
	set_skill("yiyang-zhi", 600);
	set_skill("unarmed", 600);           // ����ȭ��
	set_skill("dodge", 1000);             // ��������
	set_skill("parry", 600);             // �����м�
	set_skill("literate",550);           // ����ʶ��

	map_skill("force"  , "kumu-shengong");
	map_skill("unarmed", "yiyang-zhi");
	map_skill("dodge"  , "shaolin-shenfa");
	map_skill("parry"  , "yiyang-zhi");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 50);

	create_family("����μ�",18,"������");
}

void init()
{
	::init();
	/*
	        if( this_player()->query_temp("dalikill") )
	        {
	                 kill_ob(this_player());
	        }
	*/
	if((string) this_player()->query("class") == "officer" )
	{
		call_out("on_shengguan", 1);
	}
	add_action("do_kill","kill");
}

void attempt_apprentice(object ob)
{
	string oldtitle;
	oldtitle = ob->query("title");
	if ((int)ob->query("shen") < 10000  )
	{
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	if ((int)ob->query_skill("kumu-shengong",1) < 150 )
	{
		command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
		return;
	}

	else
	{
		command("nod");
		command("say " + RANK_D->query_respect(ob) + "�պ�سɴ��� ��\n");
		command("recruit " + ob->query("id") );
	}
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "officer");
}

void on_shengguan()
{
	int exp;
	exp = (int) this_player()->query("combat_exp");
	if( exp <= 32000 )
	{
		this_player()->set("title","�������Ʒ֥���");
		return ;
	}
	else if ( exp <= 64000 )
	{
		this_player()->set("title","�������Ʒ��");
		return ;
	}
	else if ( exp <= 128000 )
	{
		this_player()->set("title","�������Ʒ��");
		return ;
	}
	else if ( exp <= 256000 )
	{
		this_player()->set("title","�������Ʒ��");
		return ;
	}
	else if ( exp <= 512000 )
	{
		this_player()->set("title","�������Ʒ��");
		return ;
	}
	else if ( exp <= 1024000 )
	{
		this_player()->set("title","�������Ʒ��");
		return ;
	}
	else if ( exp <= 1536000 )
	{
		this_player()->set("title","�����һƷ��");
		return ;
	}
	else if ( exp <= 2304000 )
	{
		this_player()->set("title","������ղ��");
		return ;
	}
	else if ( exp <= 3456000 )
	{
		this_player()->set("title","���������ͳ��");
		return ;
	}
	else if ( exp <= 5187000 )
	{
		this_player()->set("title","�����������ͳ��");
		return ;
	}
	else if ( exp <= 26244000 )
	{
		this_player()->set("title","�������Զ����");
		return ;
	}
	else if ( exp <= 56244000 )
	{
		this_player()->set("title","����������󽫾�");
		return ;
	}
	else if ( exp <= 100000000 )
	{
		this_player()->set("title","�����������ͳ��");
		return ;
	}
	else if ( exp <= 300000000 )
	{
		this_player()->set("title","�����������������");
		return ;
	}
	else
		this_player()->set("title","����������ة��");
	return ;
}

int do_kill(string arg)
{
	if (this_object()->id(arg))
		this_player()->set_temp("dalikill", 1);
	return 0;
}

