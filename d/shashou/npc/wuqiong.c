// wuqiong.c  ����

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "wu qiong", "wu" }));
        set("nickname", HIB "�ܵ�" NOR);
	set("long", 
		"��ʱ��������������ӣ�������ɫ����������Ƹ�ƽ���ĺ��ӡ�\n"
		"��üĿ֮��ɢ����һ��ͦ��֮���������˾���һͷ�ͻ���\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
set("max_qi", 1500000);
set("max_jing", 1000000);
set("neili", 10000000);
	set("max_neili", 3000);
set("jiali", 20000);
set("combat_exp", 1200000000);
	set("score", 70000);

set_skill("force", 2000);
set_skill("unarmed",1200);
set_skill("wuji-shengong", 1500);
set_skill("dodge", 1200);
set_skill("bugui-bufa", 1200);
set_skill("parry",1200);
set_skill("blade", 1500);
set_skill("liujue-dao", 1500);
set_skill("literate", 1500);

       map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("parry", "liujue-dao");
	map_skill("blade", "liujue-dao");

	create_family("ɱ��¥", 2, "��ɱ��");

set("chat_chance_combat", 300);
	set("chat_msg_combat", ({
		(: perform_action, "blade.wuqin" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
//         object me = this_player();

/*     string *prename =
	 ({ "��" });
	string name, new_name;*/

if ((int)ob->query("combat_exp") < 100000000) {	
		command("say ɱ���������Դ������ӵ��£����Խ�������һ��Ҫ�ḻ��");
		command("say ��ʵս���鷽�棬" + RANK_D->query_respect(ob) +
			"�Ƿ񻹲�����");
		return;
	}
	command("say �ðɣ��Ҿ��������ˡ�");
/*       name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say ���ǡ������ֱ��ģ��ӽ��Ժ�������־ͽ���" + new_name + "��");
	command("smile");
	me->set("name", new_name);
	me->set("K_record", me->query("PKS") + me->query("MKS"));
       command("recruit " + ob->query("id"));*/

	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "shashou")
		ob->set("class", "shashou");
}

