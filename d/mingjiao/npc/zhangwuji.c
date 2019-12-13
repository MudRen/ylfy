// zhangwuji.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
object who = this_player();

void create()
{
    set_name("���޼�", ({ "zhang wuji", "zhang", "wuji"}));
	set("title",HIR"���̽���"NOR);
	set("long",
	"�����۾��ر����������������ر�Ӣ����\n"
	"��������������Ե�����֮�������������̵�34������--���޼ɡ�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("qi", 330050);
    set("max_qi", 330050);
    set("jing", 30050);
    set("max_jing", 30050);
    set("neili", 5000000);
    set("max_neili", 1000000);
    set("jiali", 22200);
    set("xyzx_sys/level", 1500);
    set("combat_exp", 129000000);
    set("score", 455000);

	set_skill("taiji-jian", 1050);
	set_skill("qiankundanuoyi", 1750);
    set_skill("shenghuo-ling",1050);	
	set_skill("sword", 2000);
	set_skill("force", 2900);
	set_skill("shenghuo-shengong", 1750);
	set_skill("dodge", 2000);
	set_skill("tiyunzong", 1350);
	set_skill("unarmed", 2700);
	set_skill("jiuyang-shengong", 2680);
	set_skill("parry", 2700);
	set_skill("literate", 2580);
    set_skill("qishang-quan", 1020);
	set_skill("taoism", 1680);
	set_skill("taiji-quan", 1050);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "jiuyang-shengong");
	map_skill("parry", "jiuyang-shengong");
	map_skill("sword", "taiji-jian");
	map_skill("dodge", "qiankundanuoyi");


	create_family("����", 34, "����");

	set("inquiry", ([
		"����" : "�������������̵�34�����������޼ɡ�\n",
		"лѷ" : "�������µ��常�������������ҵ������Ҷ�����л��! \n",
		"�ؼ�" : "�ұ������д��һ��������������ƪ,ȴ��֪���ҵ���ͯŪ�Ķ�ȥ��.\n",
		//"�����ؼ�" : (: ask_me :),
	]));

	set("no_get",1);
	set("book_count", 1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	set("chat_chance", 1);
	set("chat_msg", ({
		"���޼�����̾������֪���ǿ������常���ںδ�����\n",
		"���޼ɵ�����������������������\n",
	}) );

}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000) {
		command("shake");
		command("say ��Ŀ¶�׹⣬�������֮������������֮�ˣ��㻹�ǻ�ȥ�ɣ�");
		return;
	}
	if ((int)ob->query_skill("force", 1) < 100) {
		command("shake");
		command("say �ҵľ����������������Ļ����ڹ�Ϊ�����ģ�");
		command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
		command("sigh");
		return;
	}
	if ((int)ob->query_skill("taoism", 1) < 101) {
		command("shake");
		command("say ������������Ҫ���ľ���ģ�");
		command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
		return;
	}
	if ((int)ob->query("max_neili", 1) < 500) {
		command("shake");
		command("say ������������Ҫ����������");
		command("say ����������㣬������ûʲô���Խ���ģ�");
		return;
	}
	if ((int)ob->query_skill("parry", 1) < 90) {
		command("shake");
		command("say �ҵ��书�����ޱȣ�����мܲ�����");
		command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
		return;
	}
	if ((int)ob->query("score") < 2000 ) {
		command("say ��Ա��ŵĹ��׻�����,����Ŭ��ѽ��");
		return;
	}

	if (this_player()->query_temp("marks/�常")) {
		command("say �ðɣ��Ҿ��������ˡ�");
		command("recruit " + ob->query("id"));
		ob->set("title","�����Ž�����������");
		this_player()->delete_temp("marks/�常");
		command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
		command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "shizhe")
			ob->set("class", "shizhe");
//              ob->set("title",HIW"���̹�����ʹ"NOR);
	}
	else {
		command("say ��ƽ��ֻ��һ���常�ܹ�Т�������ܰ���֪̽����������");
	}
	return;
}

int accept_object(object who, object ob)
{
	object obj,me = this_player();
	obj=this_object();
	if ( ob->query("id") != "jin mao" || userp(ob) )
		return 0;
	tell_object(who,GRN"���޼ɼ�����˵�������ҵ��ҵ��常�ˡ�\n"NOR);
	if ( !me->query_temp("marks/�常") )
		me->set_temp("marks/�常", 1);
	remove_call_out("destrory");
	call_out("destrory",1,ob);
	return 1;
}

void destrory(object ob)
{
	destruct(ob);
}



void do_kill(string arg)
{
	object me = this_player();
	object obj;

	if (!arg || !objectp(obj = present(arg, environment(me))))
		return;

	if (arg == "zhang wuji" || arg == "zhang")
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

