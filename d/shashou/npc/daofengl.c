
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("刀锋冷", ({ "dao fengleng","dao", "fengleng" }));
        set("nickname", HIW "刀剑笑" NOR);
	set("long", 
		"他就是杀手楼的楼主，这是个杀性深不可测的人物。\n"
		"他正值壮年，身材瘦长，沉默寡言。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
set("max_qi", 3000000);	
set("max_jing", 500000);	
set("neili", 15000000);	
set("max_neili", 5000);	
set("jiali", 30000);	
set("combat_exp", 1500000000);	
	set("score", 300000);

set_skill("force", 3200);	
set_skill("wuji-shengong", 1500);	
set_skill("dodge", 1300);	
set_skill("bugui-bufa", 1300);	
set_skill("strike", 1300);	
set_skill("fanyun-zhang", 1500);	
set_skill("parry",1500);	
set_skill("unarmed",1500);	
set_skill("blade", 1500);	
set_skill("qishen-dao", 1500);	
set_skill("literate", 2500);	
 
        map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
map_skill("strike", "fanyun-zhang");	
map_skill("unarmed", "fanyun-zhang");	
        map_skill("parry", "qishen-dao");
        map_skill("blade", "qishen-dao");

	create_family("杀手楼", 1, "楼主");
	set("book_count", 1);

set("chat_chance_combat", 300);	
           set("chat_msg_combat", ({
                  (: perform_action, "blade.shaqi" :),
(: perform_action, "unarmed.yunkai" :),     	
		(: exert_function, "recover" :),
	}) );
            set("no_get",1);
	setup();
	carry_object("/d/shashou/obj/wuqing")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
if ((int)ob->query("combat_exp") < 150000000) {	
		command("say 杀手是提着脑袋过日子的事，所以江湖经验一定要丰富。");
		return;
	}
	command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "shashou")
		ob->set("class", "shashou");

}

