// ҩʦ

#include <ansi.h>
inherit NPC;
string ask_liao();
string ask_me();

void create()
{
	set_name("ҩʦ", ({ "yao shi", "yao" }));
	set("long",
		"���������̵ļ�������ҽ�ɺ���ţ�ĵ��ӡ�\n"
		"ȫ���������ƣ�����Щ��ʦ�緶��\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("no_get", 1);

	set("max_qi", 250);
	set("max_jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 10000);
	set("shen",500);
	set("score", 10);

	set_skill("force", 30);
	set_skill("shenghuo-shengong", 30);
	set_skill("dodge", 30);
	set_skill("qingyunwu", 30);
	set_skill("shenghuo-quan", 30);
	set_skill("parry", 30);
	set_skill("literate", 40);

	map_skill("force", "shenghuo-shengong");
	map_skill("unarmed", "shenghuo-quan");
	map_skill("parry", "shenghuo-quan");
	create_family("����", 35, "����");
	set("inquiry", ([
	      "����" : (: ask_liao :),
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_liao()
{
	mapping fam;
	int i, j;

	object ob;
	ob=this_player();
	write( "ҩʦ�������㿴����֪����Щʲô���⡣\n");
	if ( ob->is_busy() )
		return "����æ���ء�\n";
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
		return RANK_D->query_respect(this_player()) +
		"�뱾��������������֪�˻��Ӻ�̸��";
	if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi"))
		return RANK_D->query_respect(this_player()) + "��Ѫ���㣬����ҽ�ΰ���";
	i = ob->query("max_jing") - ob->query("eff_jing");
	j = ob->query("max_qi") - ob->query("eff_qi");
	ob->add("eff_jing", i/2);
	ob->add("jing", i/2);
	ob->add("eff_qi", j/2);
	ob->add("qi", j/2);
	write( HIW "ҩʦ�������϶��˼��£�����û���ù���Щ������ʧȥ��һЩ��Ѫ�ص������� \n"NOR);
	ob->start_busy(3);

	return "�ұ��²�����ֻ�������ˣ�";
}
