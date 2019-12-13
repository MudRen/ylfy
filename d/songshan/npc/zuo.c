// zuo.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_book();
string ask_book1();
void create()
{
	set_name("������", ( { "zuo lengchan", "zuo" }) );
	set("title", HIR"������������"HIY"��ɽ�ɵ�ʮ������"NOR);
	set("gender", "����");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 30);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2240000);
	set("max_neili", 224000);
	set("jiali", 11230);
	set("max_qi",1200000);
	set("max_jing",521200);
	set("xyzx_sys/level", 1000);
	set("combat_exp", 8000000);
	set("shen", -200000);
	set("book_count", 1);
	set("book_count1", 1);

	set_skill("literate", 1000);
	set_skill("sword", 3200);
	set_skill("unarmed", 3200);
	set_skill("force", 3200);
	set_skill("parry", 3200);
	set_skill("dodge", 3200);
	set_skill("songshan-jian", 1380);
	set_skill("songyang-zhang", 1380);
	set_skill("hanbing-zhenqi", 1380);
	set_skill("lingxu-bu", 1380);
	map_skill("unarmed", "songyang-zhang");
	map_skill("sword", "songshan-jian");
	map_skill("parry", "songshan-jian");
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "hanbing-zhenqi");

	set("chat_chance_combat", 90);
	
	set("inquiry",([
                   "�ؼ�"	     : (: ask_book :),
                   "����"	     : (: ask_book :),
                   "����������" : (: ask_book :),
                   "����"	     : (: ask_book1 :),
                   "��ɽ����"   : (: ask_book1 :),
	               ]));

	create_family("��ɽ��", 13, "����");
	setup();

	carry_object("d/songshan/obj/kuojian")->wield();

	carry_object("d/songshan/obj/yellow-cloth")->wear();
}
void init()
{
	add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	command("say ����Ϊ������������������������������ɽһ�ɡ�");
	command("recruit " + ob->query("id"));
}

string ask_book()
{
	object ob;

	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		       "�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count") < 1) return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("d/songshan/obj/songyang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ���������������\n");
	return "�ðɣ��Ȿ�����������ס����û�ȥ�ú����С�";
}

string ask_book1()
{
	object ob;

	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		       "�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count1") < 1) return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count1", -1);
	ob = new("d/songshan/obj/sword_book4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ���ɽ��������\n");
	return "�ðɣ��Ȿ����ɽ���ס����û�ȥ�ú����С�";
}
