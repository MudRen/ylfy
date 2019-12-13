// bgargoyle.c
#include <ansi.h>
#include <command.h>
#include <login.h>
inherit NPC;
int ask_me();
int is_ghost(){	return 1;}
string *death_msg = ({
	HIB "黑无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
	HIB "黑无常用奇异的眼光盯著你，好像要看穿你的一切似的。\n\n" NOR,
	HIB "黑无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
	HIB "黑无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
	HIB "黑无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
		"一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});
void create()
{
	set_name("黑无常", ({ "black gargoyle", "gargoyle" }) );
	set("long",
		"黑无常伸著长长的舌头瞪著你，黝黑的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
	
	set("age", 217);
	set("no_die",1);		//不分配杀它的任务.
	set("end_boss",1);
    set("xyzx_sys/level", 30000000);
	set("str", 5000000);
    set("con", 5000000);
    set("int", 5000000);
    set("dex", 5000000);
	set("no_get", 1);
    set("max_qi", 5000000000);
    set("qi", 5000000000);
    set("max_jing", 5000000000);
    set("jing", 5000000000);
    set("neili", 3000000000);
    set("max_neili", 300000000);
    set("jingli", 3000000000);
	set("jiali", 30000000);
    set("max_jingli", 300000000);
	set_temp("apply/attack",  12150);
    set_temp("apply/defense", 12130);
	set_skill("dodge", 400000);
	set_skill("unarmed", 400000);
	set_skill("dodge", 400000);
	set_skill("force", 400000);
	set_skill("parry", 400000);
	set_skill("sword", 400000);
	set_skill("tianmo-dao", 400000);
	set_skill("piaomiao-shenfa", 400000);
	set_skill("tianmo-zhang", 400000);
	set_skill("tianmo-shengong", 400000);
	map_skill("parry", "tianmo-dao");	
    map_skill("force", "tianmo-shengong");           	
    map_skill("dodge", "piaomiao-shenfa");           	
    map_skill("unarmed", "tianmo-zhang");
    map_skill("sword", "tianmo-dao"); 	
	set("chat_chance", 15);
	set("chat_msg", ({
		"黑无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",
		"黑无常把长长的舌头伸出来，缓缓地舔了舔自己又黑又长的手指。\n"
	}) );
	set("inquiry", ([
		"地刹炼魂"       : (: ask_me :),
	]));
	setup();
	carry_object("/clone/weapon/longya")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}
void death_stage(object ob, int stage)
{
	int i, lvl;
	object *inv;
	if( !ob || !present(ob) ) return;
	if( !ob->is_ghost() ) {
		command("say 喂！阳人来阴间做什么？");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();
	inv = all_inventory(ob);
	for (i = 0; i < sizeof(inv); i++)
	{
		if ( intp(lvl=inv[i]->query("bind_master_level/"+ob->query("id"))) 
				&& lvl>1 ) continue; 
		DROP_CMD->do_drop(ob, inv[i]);
	}
	
ob->clear_condition();
ob->clear_condition(1);	
if(ob->query("block"))
ob->move("/clone/misc/block");
else    ob->move(REVIVE_ROOM);	
ob->delete_temp("last_damage_from");
ob->delete_temp("die_for");
ob->set("startroom","/d/city/wumiao");
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
}
int ask_me()
{
        mapping my_fam;
 
        object  me;
        int my_age, already_age;
	me = this_player();
my_fam = (mapping)me->query("family");     	
	my_age = me->query("age");
	already_age = (int)me->query("already_age");
//    if (my_fam["family_name"] != "星宿派")          	
if (me->query("class",1) != "taoist")                	
		return notify_fail("你不是星宿派的弟子，不能地刹炼魂。\n");
	if( already_age >= my_age)
		return notify_fail("你今年的地刹炼魂次数已经用完了！\n");
	if( (int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够完成地刹炼魂大法！\n");
	if(random(5) >= 2)
	{
                me->set_skill("force",me->query_skill("force",1)+10);
		me->add("con_improve_time", 1);
		me->add("max_neili", -50);
		me->set("already_age", my_age);
	        message("vision", HIY"只见黑无常举起手中的哭丧棒，喃喃地念了几局咒语，漆黑的天空中突然出\n" +
			"现一道闪电，击中你的头顶。你只觉得浑身象是被浸泡在一股暖流中。你的\n" +
			"体质提升了！\n"NOR, me);
	}
	else
		message("vision", HIY"只见黑无常举起手中的哭丧棒，喃喃地念了几局咒语，结果什么也没发生！\n"NOR, me);
	return 1;
	
}
