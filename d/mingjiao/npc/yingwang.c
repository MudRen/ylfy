// yingwang.c ��üӥ��
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
	set_name("������",({"yin tianzheng","yin","yingwang"}));
	set("title","���̻��̷���");
	set("long",
		"���������̵��Ĵ󻤽̷������϶���\n"
		"��һ�������������棬�׷�ͯ�գ���һ�Գ���˫��İ�üӭ��һƮһƮ��������ɫ��\n");
	set("nickname",HIW"��üӥ��"NOR);
	set("age", 64);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 25);
	set("int", 25);
	set("con", 26);
	set("dex", 25);
	set("per", 22);

	set("max_qi",3000);
	set("max_jing", 1500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 65);
	set("combat_exp", 8000000);
	set("sword_count", 1);

	set_skill("sword",280);
	set_skill("dodge",280);
	set_skill("strike",280);
	set_skill("literate",300);
	set_skill("force",280);
	set_skill("shenghuo-shengong",280);
	set_skill("qingyunwu", 200);
	set_skill("shenghuo-jian",280);
	set_skill("blade",280);
	set_skill("parry",200);
set_skill("sougu",300);	


	map_skill("dodge", "qingyunwu");
	map_skill("force","shenghuo-shengong");
	map_skill("sword","shenghuo-jian");
	map_skill("unarmed","shenghuo-quan");
map_skill("parry","sougu");	

	create_family("����",34,"����");

	set("inquiry", ([
	"���޼�" : "�����������޼��������̵�34��������Ҳ���ҵĺ����\n",
	"�׺罣" : "�ߣ��׺罣�����ҵĳ�������������Ҫ�׺罣����Ҫ�ش��Ҽ��仰��\n",
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
/*
void init()
{
       object ob;
       ::init();

	ob = this_player();
	if( ((int)ob->query("score") < 120 || ob->query("shen") < 2000 ) && ob->query("family/master_id")=="yin tianzheng")
	{
		command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","����" + RED + "��ͽ" NOR);
	}
	add_action("do_answer", "answer");
}
*/
int do_answer(string arg)
{
	if( !arg ) return notify_fail("��˵ʲô��\n");
	message_vision("$N������Ȼ��˵����" + arg + "\n", this_player());
	if ((int)this_player()->query_temp("marks/�׺罣")) {
	       return notify_fail("ӥ�����Ű�ü������˵����Ҳ̫̰���˰ɣ�\n");
	}
	if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�ǻ�ʵ��") >=0
	|| strsrch(arg, "��������") >=0 && strsrch(arg, "ͬ�����") >=0 )) {
		if ( this_player()->query("combat_exp") < 400000 ) {
			command("say ��Ȼ��˵�úܶԣ�������Ľ������黹̫�١���ȥĥ��һ�°ɡ�");
			return notify_fail("");
		}
		command("smile");
		command("say ԭ����ˡ�\n");
		if ( query("sword_count") < 1 ) {
			command("say �����ҵ������������Ѿ��͸�һ����ɫ�ĵ����ˡ�");
			return notify_fail("");
		}
	       "/d/mj/obj/baihong-jian"->move(this_player());
		this_player()->set_temp("marks/�׺罣", 1);
		message_vision("��üӥ����������İ׺罣������$N��\n",this_player());
		add("sword_count", -1);
	} else {
		command("say ������˵���Ҳ������ģ�");
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_int() < 30) {
		command("say " + RANK_D->query_respect(ob) +
			"����Ƿ�ϣ���ѧ������һ���书��");
		return;
	}
	if ((int)ob->query_dex() < 25) {
		command("say " + RANK_D->query_respect(ob) +
			"���ֲ��ݣ����������ʦ�ɡ�");
		return;

	  }
       if ((string)ob->query("family/family_name")!="����" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "����������ɣ��������ȥ����");
                return;
        }        

	if ((int)ob->query("score") < 120) {
		command("say ��λ" + RANK_D->query_respect(ob) +
			"�ƺ��Ա��̻��������ģ��һ��������㡣");
		return;
	  }
	if ((int)ob->query("shen") < 5000) {
		command("say " + RANK_D->query_respect(ob) +
			"������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ��������������书���ˡ�");
		return;
	}
	command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "shizhe")
	ob->set("class", "shizhe");
	ob->set("title","���̰�üӥ�����½���");
}
