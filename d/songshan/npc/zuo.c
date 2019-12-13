// zuo.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_book();
string ask_book1();
void create()
{
	set_name("左冷禅", ( { "zuo lengchan", "zuo" }) );
	set("title", HIR"五岳剑派盟主"HIY"嵩山派第十三掌门"NOR);
	set("gender", "男性");
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
                   "秘籍"	     : (: ask_book :),
                   "掌谱"	     : (: ask_book :),
                   "大嵩阳掌谱" : (: ask_book :),
                   "剑谱"	     : (: ask_book1 :),
                   "嵩山剑谱"   : (: ask_book1 :),
	               ]));

	create_family("嵩山派", 13, "掌门");
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
	command("say 我派为五岳盟主！入我门来，定须光大我嵩山一派。");
	command("recruit " + ob->query("id"));
}

string ask_book()
{
	object ob;

	if (this_player()->query("family/family_name")!="嵩山派")
		return RANK_D->query_respect(this_player()) +
		       "与本派毫无瓜葛，我派的武功典籍可不能交给你。";
	if (query("book_count") < 1) return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new("d/songshan/obj/songyang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到大嵩阳掌谱啦。\n");
	return "好吧，这本「大嵩阳掌谱」你拿回去好好钻研。";
}

string ask_book1()
{
	object ob;

	if (this_player()->query("family/family_name")!="嵩山派")
		return RANK_D->query_respect(this_player()) +
		       "与本派毫无瓜葛，我派的武功典籍可不能交给你。";
	if (query("book_count1") < 1) return "你来晚了，本派的秘籍不在此处。";
	add("book_count1", -1);
	ob = new("d/songshan/obj/sword_book4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到嵩山剑谱啦。\n");
	return "好吧，这本「嵩山剑谱」你拿回去好好钻研。";
}
