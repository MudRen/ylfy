inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("������", ( { "wang chongyang", "wang" }));
	set("nickname", HIC "����ͨ" NOR);
	set("long",
	    "������ȫ��̿�ɽ��ʦ������ͨ��������\n"
	    "��һ�����ɫ���ۣ���һ�����ǽ���\n"
	    "��ɫ���󣬿������ڹ�һ���ܸ��\n");
	set("gender", "����");
	set("age", 70);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 80);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 2128000);
	set("max_jing", 1225000);
	set("neili", 2000000);
	set("max_neili", 1000000);
	set("jiali", 3100);
	set("combat_exp", 80000000);
	set("score", 500000);
	set("xyzx_sys/level", 1500);

	set_skill("force", 2900);
	set_skill("tiangang-zhengqi", 1100);
	set_skill("dodge", 2900);
	set_skill("qixing-huanwei", 1300);
	set_skill("unarmed", 2900);
	set_skill("kongming-quan", 1200);
	set_skill("parry", 2900);
	set_skill("sword", 2900);
	set_skill("quanzhen-jianfa", 1400);
	set_skill("xiantian-qigong", 1000);
	set_skill("qixing-array", 1500);
	set_skill("taoism", 2500);
	set_skill("literate", 2700);

	map_skill("force", "xiantian-qigong");
	map_skill("dodge", "qixing-huanwei");
	map_skill("unarmed", "kongming-quan");
	map_skill("parry", "quanzhen-jianfa");
	map_skill("sword", "quanzhen-jianfa");

	create_family("ȫ���", 1, "��ɽ��ʦ");
	set("class", "taoist");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", (
	{
(: perform_action, "sword.qixing" :),
(: perform_action, "sword.jianzhen" :),
(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
                    "�����澭"  :HIM"�����澭....�����Ȿ�����͸���ʦ�ܱ�����.....\n...�������<һ������>�������һ����͸��ҵĻ�.....�һ������������....."
	                ]));
	setup();
	carry_object("/d/quanzhen/obj/qixingjian")->wield();
	carry_object("/d/quanzhen/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name")!="ȫ���" || (string)ob->query("class")!="sworder")
	{
		command("say ��ȫ�����ǵ������ɡ�");
		command("say " + RANK_D->query_respect(ob) + "����������������ҵ���");
		return;
	}
	if ((int)ob->query_skill("tiangang-zhengqi", 1) < 300)
	{
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
		        "�Ƿ�Ӧ������������϶��µ㹦��");
		return;
	}
	if ((int)ob->query("shen") < 100000)
	{
		command("say ѧ��֮�ˣ�����Ϊ�ȣ������֮��");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
		        "�Ƿ����ò�����");
		return;
	}
	if (ob->query_int() < 60)
	{
		command("say ��ȫ����书ȫ�ӵ��������");
		command("say Ҫ�ܴﵽ¯����֮�������ԵͲ��á�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("chat �ã��ã����ã�����");
	command("chat ϣ��" + RANK_D->query_respect(ob) + "���ܹ�ѧ����ȫ��̵����裡��");
	command("chat* pat " + ob->query("id"));

	command("recruit " + ob->query("id"));
	ob->set("title",HIC"ȫ����������˴���"NOR);
}


void init()
{
	object ob;
	::init();
	ob = this_player();
	/*        if ( (int)ob->query("shen") <-2000 && (string)ob->query("family/master_id") == "wang chongyang")
	        {
	                  command("chat "+ob->query("name")+"!����ɱ��Խ����������Ϊ���������������ʦ����\n");
	                command("expell "+ ob->query("id"));
	                this_player()->set("title","ȫ���" + RED + "��ͽ" NOR);

	        }*/
}


void do_kill(string arg)
{
	object me = this_player();
	object obj;

	if (!arg || !objectp(obj = present(arg, environment(me))))
		return;

	if (arg == "zhang sanfeng" || arg == "zhang")
		obj->kill_ob(me);
	else obj->fight_ob(me);

	me->fight_ob(obj);
}


int accept_fight(object ob)
{
	object me  = this_object();

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));

	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	if ( !present(ob, environment()) ) return 1;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if( me->is_fighting() )
	{
		if ( (int)me->query("qi")*100/my_max_qi <= 80 )
		{

			me->set("eff_qi", me->query("max_qi"));
			me->set("qi",     me->query("max_qi"));
			me->set("jing",   me->query("max_jing"));
			me->set("neili",  me->query("max_neili"));
		}
		if ( present(ob, environment()) )
			call_out("checking", 1, me, ob);
	}


	return 1;
}

int accept_object(object me, object ob)
{

	if ( (string) ob->query("id") =="jiuyin zhenjing1" )
	{
		message_vision("$N��$n˵��������Ϊ�˱��⽭������������֯�˻�ɽ�۽������书����߻�á������澭��\n", this_object(),me);
		message_vision("$N��$n˵�����Ȿ��ѧ�ؼ�֮������������д�������ϰ�������ԣ������书���ϣ�������������\n", this_object(),me);
		message_vision("$N��$n˵�������ҵ����ᾭ�飬��������ҵ�������.........\n", this_object(),me);
		me->set_temp("tmark/jiuyin1", 1);
		return 1;
	}

	if ( (string) ob->query("id") =="jiuyin zhenjing2" )
	{
		if ((int)me->query_temp("tmark/jiuyin1") && me->query("shen") > 100000000 )
		{
			message_vision("$N��$n˵�����Ե�Ƭ�̣��ҽ���2���ؼ���������ɲ�......\n", this_object(),me);
			message_vision("$N��$n˵������������ѧ�мǲ����ĸ�����!!!!!!!!!\n", this_object(),me);
			message_vision("$N��$n˵�������ˣ��Ȿ�������澭����������������ϣ������͸��㣡����\n", this_object(),me);
			message_vision("$N��$n˵����<��������ĳ�����¶��ھ����澭��һ���ĵã������Ե������ȥ����һ�£�>\n", this_object(),me);
			message_vision("$N��$n˵����ϣ�����Ժ�Ҫ�ô���ѧ��ɱ�޹����ұ��Ѳ������뽭���Ƿǣ��㻹��������ȥ�ɣ�\n", this_object(),me);
			ob = new("/clone/book/jiuyin.c");
			ob->move(this_player());
			return 1;
		}
		else
			message_vision("���������˿�$N�����ľ��飬˵������л�ˣ��˾������ʱ���������ܰɣ������������֮��..�ؽ����𳡽����ƽ١�\n",this_object(),me);
		return 1;
	}
	else
		return 0;
}