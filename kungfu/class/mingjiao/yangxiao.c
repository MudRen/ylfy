// YangXiao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();
string ask_ling();

void create()
{
    set_name("����", ({"yang xiao","yang","xiao",}));
	set("long",
        "����һλ�������������ײ����ۡ�\n"
        "����ò���ţ�ֻ��˫ü�����´������¶��������������ƣ������Դ�˥�����\n"
        "֮�ࡣ�����Բ�������ɫĮȻ���ƺ��ĳ�Զ����������ʲô���顣\n"
	);

	set("title",HIG "����" HIR "������ʹ" NOR);
	set("level",11);
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 4000000);
	set("score", 800000);

	set_skill("force", 280);
	set_skill("dodge", 240);
	set_skill("parry", 210);
	set_skill("blade", 270);
	set_skill("sword", 270);
	set_skill("literate", 250);

	set_skill("hunyuan-yiqi", 280);
	set_skill("shaolin-shenfa",210);
	set_skill("nianhua-zhi", 280);
	set_skill("sanhua-zhang", 280);
	set_skill("fengyun-shou", 210);
	set_skill("longzhua-gong", 210);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "nianhua-zhi");
	map_skill("unarmed", "sanhua-zhang");
	map_skill("unarmed", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("unarmed", "nianhua-zhi");
	prepare_skill("unarmed", "sanhua-zhang");

	set("inquiry", 
	([
        	"����ʥ����"	: (: ask_me :),
        	"������"     	: (: ask_ling :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform qianlibingfeng") :),
	}) );

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}
/*
void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}
*/
string ask_ling()
{
	mapping party, skl; 
	string *sname;
	object ob;
	int i;
	
	if ( !(party = this_player()->query("party")) || party["party_name"] != HIG "����" NOR )
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";

	skl = this_player()->query_skills();
	sname  = sort_array( keys(skl), (: strcmp :) );

	for(i=0; i<sizeof(skl); i++) 
	{
		if (skl[sname[i]] < 30) 
		return RANK_D->query_respect(this_player()) + 
		"����������������ȡ�����";
	}

	ob = new("d/mingjiao/obj/tieyanling");
	ob->move(this_player());
	message_vision("$NҪ��һ�������\n",this_player());

	return "�ðɣ�ƾ�������������������������ս��";

}

#include "yangxiao.h"
