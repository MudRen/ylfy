//qiuchuji.c  �𴦻�
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("�𴦻�", ( {"master qiu","qiu chuji", "qiu", "chuji"}));
	set("nickname", HIC"������"NOR);
	set("gender", "����");
	set("age", 50);
	set("long",
	    "���������ᣬ��ɷ��˫Ŀ��������\n"
	    "�������������ϱ����������ĳ����ӡ�\n");
	set("attitude", "peaceful");
	set("class", "taoist");

	set("str", 50);
	set("int", 31);
	set("con", 35);
	set("dex", 31);
	set("per", 25);

	set("chat_chance", 1);
	set("chat_msg", (
	{
		"�𴦻�˵������û�̵ܽ��������Բ������ĸ��ס���\n",
		"�𴦻�̾�˿�������������ӽ��˻�����Ĺ�����������󾸶���������\n",
		"�𴦻��૵������������澭���ǵ�����ѻ��˼�ʮ����Ѫд�ɵ������书�ܼ������������޵� ���� \n",
//              (: random_move :),
	}));
	set("inquiry", ([
                    "������Ĺ":"��������������ǻ�����Ĺ��ȫ��̵��Ӳ������ڣ�Υ�����ʦ�š�\n",
                    "С��Ů":"������Ĺ�������ˣ��书��ɲ⡣\n",
	                ]));

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 2000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 150);
	set("no_get", 1);
	set("combat_exp", 5000000);
	set("score", 200000);

	set_skill("force", 350);                 // �����ڹ�
	set_skill("tiangang-zhengqi", 350);//�������
	set_skill("unarmed", 350);             // ����ȭ��
	set_skill("kongming-quan", 350);       //����ȭ
	set_skill("dodge", 300);             // ��������
	set_skill("qixing-huanwei", 350);//���ǻ�λ
	set_skill("parry", 320);             // �����м�
	set_skill("sword", 320);             // ��������
	set_skill("quanzhen-jianfa", 320);//�����
	set_skill("taoism", 330);            //��ѧ�ķ�
	set_skill("literate",320);           //����д��
	set_skill("qixing-array",340);
	map_skill("force", "tiangang-zhengqi");
	map_skill("unarmed", "kongming-quan");
	map_skill("dodge", "qixing-huanwei");
	map_skill("parry", "quanzhen-jianfa");
	map_skill("sword", "quanzhen-jianfa");

	create_family("ȫ���", 2, "���ƽ�");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", (
	{
(: perform_action, "sword.qixing" :),
(: exert_function, "recover" :),
	}) );


	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/obj/greyrobe")->wear();

}
void init()
{
	mapping mine;
	object me, room;

	me = this_player();

	if (!mapp(mine = me->query("family")))
		return;

	if(!( room = find_object("/d/quzanzhen/cangjingge1")) )
		room = load_object("/d/quanzhen/cangjingge1");
	if(me->query("family/master_id")=="master qiu"&&me->query_temp("warn_time")<time())
		if((me->query("PKS")>me->query("kar")&&(int)me->query("shen")<=-100)
		        ||(me->query("PKS")<me->query("kar")&&(int)me->query("shen")<=-10000))

		{
			me->add("hao_warning",1);
			me->set_temp("warn_time",time()+300);
			command("heng "+me->query("id"));
			command("say �������ڽ���ɱ��Խ����������Ϊ��Ī��Ϊʦû�о������㣡");
		}
		else  if (me->query("family/master_id")=="master qiu")
			command("say ��ͽ���������ˣ�\n");
	if((int)me->query("hao_warning") > 3)
	{
		command("chat "+HIR+me->query("name")+"ɱ��Խ��������Ϊ������ʦ�ţ��ӽ��Ժ�����ȫ��̵ĵ��ӡ�\n"NOR);
		command("expell "+ me->query("id"));
		this_player()->set("title","ȫ���" + RED + "��ͽ" NOR);
		me->delete("hao_warning");
	}


	if( (mapp(mine = me->query("family")) && mine["family_name"] != "ȫ���")
	        || (present("master qiu", room) && (!present("letter", me))&&me->query("family/master_id")!="master qiu")  )
	{
		command("say �󵨿�ͽ������ɱ�˴���ؾ��󣬿���!\n");
		call_out("kill_ob", 0, this_player());

		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		return;
	}
	return;
}

/*void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if(ob->query("family/master_id")=="master qiu"&&ob->query_temp("warn_time")<time())
        if((ob->query("PKS")>ob->query("kar")&&(int)ob->query("shen")<=-100)
        ||(ob->query("PKS")<ob->query("kar")&&(int)ob->query("shen")<=-10000))

       { ob->add("hao_warning",1);
         ob->set_temp("warn_time",time()+300);
         command("heng "+ob->query("id"));
         command("say �������ڽ���ɱ��Խ����������Ϊ��Ī��Ϊʦû�о������㣡");
       }
        if((int)ob->query("hao_warning") > 3)
        {
                command("chat "+HIR+ob->query("name")+"ɱ��Խ��������Ϊ������ʦ�ţ��ӽ��Ժ�����ȫ��̵ĵ��ӡ�\n"NOR);
                command("expell "+ ob->query("id"));
                this_player()->set("title","ȫ���" + RED + "��ͽ" NOR);
                ob->delete("hao_warning");
        }
}          */
void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam  = ob->query("family");
	mapping my_fam  = me->query("family");


	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");
		return;
	}

	if ((int)ob->query_str() < 35 || (int)ob->query_con() < 35)
	{
		command("say ����ʿ��Ҫ�ܳԿ����ͣ������徲���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ���ʿ��");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	        (string)ob->query("family/family_name") != "ȫ���")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������ݱ������أ�");
		return;
	}
	if ((int)ob->query_skill("tiangang-zhengqi", 1) < 120)
	{
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
		        "�Ƿ�Ӧ������������϶��µ㹦��");
		return;
	}
	if ((int)ob->query_skill("quanzhen-jianfa", 1) < 120)
	{
		command("say ��ȫ��̽����������£�������˫��");
		command("say " + RANK_D->query_respect(ob) +
		        "�Ƿ�Ӧ����ȫ�潣���϶��µ㹦��");
		return;
	}
	command("smile");
	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
	ob->set("title","ȫ��̳������˰�ͽ");
	ob->set("class","sworder");

}


