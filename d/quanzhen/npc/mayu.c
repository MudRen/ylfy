//mayu.c ����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();

void create()
{
	set_name("����", ( {"master ma","ma yu", "ma", "yu"}));
	set("nickname", HIC"������"NOR);
	set("gender", "����");
	set("age", 60);
	set("long",
	    "�����봹�أ���ɫ����ü��Ŀ�ƣ�һ�����һ����Ⱦ��\n"
	    "����������������ͽ��ȫ��̵ڶ����ƽ����ڡ�\n");
	set("attitude", "peaceful");
	set("class", "taoist");


	set("str", 33);
	set("int", 30);
	set("con", 33);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", (
	{
		"����˵��������һ�λ�ɽ�۽�����ʦ�����˵�һ���õ��ˡ������澭������\n",
		"���ڵ���������а�������ϵ۱�ؤ������ͨ������ʮһ����\n��������һ�������е���λ�������֡���\n",
		"�����૵���������а������ɮ���� ����ͯ���������˵��������е���λ�������֡��� \n",

	}));
	set("inquiry", ([
                    "�����澭":"ʦ�������Ժ󣬾����澭������ʦ�塰����ͯ���ܲ�ͨ�����ϡ�\n",
                    "�ܲ�ͨ":"��˵ʦ�屻����а����ҩʦ�������һ�����\n",
                    "����" : (: ask_me :),
	                ]));


	set("letter_count", 1);


	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1700);
	set("max_jing", 1700);
	set("neili",1000);
	set("max_neili",2000);
	set("jiali", 115);

	set("combat_exp",4500000);
	set("score", 200000);

	set_skill("force", 300);             // �����ڹ�
	set_skill("tiangang-zhengqi", 300);    //�������
	set_skill("unarmed", 290);           // ����ȭ��
	set_skill("kongming-quan", 290);    //����ȭ
	set_skill("dodge",290);              // ��������
	set_skill("qixing-huanwei", 290);        //���ǻ�λ
	set_skill("parry", 300);             // �����м�
	set_skill("sword", 300);             // ��������
	set_skill("quanzhen-jianfa", 300);        //�����
	set_skill("taoism", 300);             //��ѧ�ķ�
	set_skill("literate",300);           //����д��
	set_skill("qixing-array",320);
	map_skill("force", "tiangang-zhengqi");
	map_skill("unarmed", "kongming-quan");
	map_skill("dodge", "qixing-huanwei");
	map_skill("parry", "quanzhen-jianfa");
	map_skill("sword", "quanzhen-jianfa");

	create_family("ȫ���", 2, "�ƽ�");

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
	object ob;
	add_action("do_decide", "decide");
	::init();
	ob = this_player();
	if(ob->query("family/master_id")=="master ma"&&ob->query_temp("warn_time")<time())
		if((ob->query("PKS")>ob->query("kar")&&(int)ob->query("shen")<=-100)
		        ||(ob->query("PKS")<ob->query("kar")&&(int)ob->query("shen")<=-10000))

		{
			ob->add("hao_warning",1);
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
}

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

	if ((int)ob->query_str() < 28 || (int)ob->query_con() < 28)
	{
		command("say ����ʿ��Ҫ�ܳԿ����ͣ������徲�����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ���ʿ��");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	        (string)ob->query("family/family_name") != "ȫ���")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������ݱ������أ�");
		return;
	}
	if ((int)ob->query_skill("tiangang-zhengqi", 1) < 110)
	{
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
		        "�Ƿ�Ӧ������������϶��µ㹦��");
		return;
	}
	command("smile");
	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
	ob->set("title","ȫ����ƽ����˰�ͽ");
	ob->set("class","sworder");
}


string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
		return RANK_D->query_respect(this_player()) +
		       "�뱾��������������֪�˻��Ӻ�̸��";

	if (  present("shou yu", this_player()) )
		return RANK_D->query_respect(this_player()) +
		       "�����ϲ�����������������Ҫ�ˣ� ��ȥ�ɣ�";

	if (query("letter_count") < 1) return "�Բ����������ˣ��Ժ���Ŭ���ɡ�";

	ob = new("d/quanzhen/obj/allow-letter");
	ob->move(this_player());

	add("letter_count", -1);

	message_vision("$N���һ�����͡�\n",this_player());
	return "����ؾ����Ժ��Ҫ�ú�Ŭ����Ϊȫ������⣬��Ҫ�������ҵĺ�����";

}

