
// yabo.c 哑伯
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("哑伯", ({ "ya bo", "bo" }));
        set("long", 
                "这是个年约6０的老年人，身披一淡灰素衣，正弯着腰在这里细心地扫着地。\n"
		"好象扫地是一种很伟大的工作似的。\n");
	set("gender", "男性");
	set("age", 58);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
set("max_qi", 55000);
set("max_jing", 35000);
set("neili", 4000000);
	set("max_neili", 4000);
set("jiali", 1000);
set("combat_exp", 80000000);
	set("score", 30000);

set_skill("force", 700);
set_skill("unarmed",700);
set_skill("dodge", 700);
set_skill("parry",700);
set_skill("sword", 700);
set_skill("literate", 200);
set_skill("strike",700);
set_skill("huanhua-jian",700);
set_skill("tiexian-quan",770);
set_skill("guiyuan-dafa",700);	
set_skill("feihua-wuping",700);

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");



set("chat_chance_combat", 300);
	set("chat_msg_combat", ({
(: perform_action, "sword.snow" :),
		(: perform_action, "sword.zhenjian" :),
	}) );

	setup();
carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
		set("chat_chance",5);
	set("chat_msg",({
	    "哑伯放下手中的扫帚，捶了锤腰：人老了，骨头也酸了。￣\n",
	    "哑伯抬头看了看，叹了口气：老爷不知道什么时候才回来。\n",
	    "哑伯骄傲地说道：长歌可不是一般的兵器，锋利的了得。￣\n"
	   }) );
 
}

